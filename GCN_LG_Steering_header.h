// Based on DWARF data found in Need for Speed Most Wanted for the GameCube, and the Simpsons Hit and Run source code.

// The structures are the only thing that I am sure are correct.
// The macros _should_ be correct, but I cannot be 100% certain.
// The functions are, unfortunately, mostly guessed.

#if 0
// Simpsons Hit and Run's wheeldefines.h
// Used to map PS2 steering defines into their GameCube equivalents.

#ifndef WHEEL_DEFINES
#define WHEEL_DEFINES

#ifdef RAD_PS2
typedef struct lgDevForceEffect LGForceEffect;
#endif

#ifdef RAD_PS2
//Why the hell are these different?
#define LG_TYPE_DAMPER LGTYPE_DAMPER
#define LG_TYPE_SPRING LGTYPE_SPRING
#define LG_TYPE_CONSTANT LGTYPE_CONSTANT
#define LG_TYPE_TRIANGLE LGTYPE_TRIANGLE
#define LG_TYPE_SQUARE LGTYPE_SQUARE
#define LG_DURATION_INFINITE LGDURATION_INFINITE
#define type Type
#define duration Duration
#define startDelay StartDelay
#define magnitude Magnitude
#define direction Direction
#define offset Offset
#define deadband Deadband
#define saturationNeg SaturationNeg
#define saturationPos SaturationPos
#define coefficientNeg CoefficientNeg
#define coefficientPos CoefficientPos
#define period Period
#define phase Phase
#define attackTime AttackTime
#define fadeTime FadeTime
#define attackLevel AttackLevel
#define fadeLevel FadeLevel
#endif

#ifdef RAD_WIN32
enum eForceTypes
{
    CONSTANT_FORCE, 
    RAMP_FORCE,
    SQUARE, 
    SINE,
    TRIANGLE,
    SAWTOOTH_UP, 
    SAWTOOTH_DOWN, 
    SPRING, 
    DAMPER,
    INERTIA, 
    FRICTION, 
    CUSTOM_FORCE 
};
#endif

#endif

#endif

#ifndef __LG_H__
#define __LG_H__

#include <dolphin/types.h>

#ifdef __cplusplus
extern "C" {
#endif

// -----------------------
// Macros
// -----------------------

// Button bitmasks
// NOTE: These match the ones in pad.h perfectly.
#define LG_BUTTON_LEFT     0x0001
#define LG_BUTTON_RIGHT    0x0002
#define LG_BUTTON_DOWN     0x0004
#define LG_BUTTON_UP       0x0008
#define LG_TRIGGER_Z       0x0010
#define LG_TRIGGER_R       0x0020
#define LG_TRIGGER_L       0x0040
#define LG_BUTTON_A        0x0100
#define LG_BUTTON_B        0x0200
#define LG_BUTTON_X        0x0400
#define LG_BUTTON_Y        0x0800
#define LG_BUTTON_START    0x1000


#define LG_INVALID_DEVICE (-1)

// Error codes
#define LG_SUCCESS 0 /* TODO: Is this correct? ... probably */

// -----------------------
// Enumerations 
// NOTE: I AM SO NOT SURE ABOUT THESE
// -----------------------

typedef enum ForceType
{
    NONE = -1, // NOTE: This may not exist!
    SPRING = 0,
    CONSTANT = 1,
    DAMPER = 2,
    SIDE_COLLISION = 3,
    FRONTAL_COLLISION = 4,
    DIRT_ROAD = 5,
    BUMPY_ROAD = 6,
    SLIPPERY_ROAD = 7,
    SURFACE_EFFECT = 8,
    CAR_AIRBORNE = 9,
    NUMBER_FORCE_EFFECTS = 10,
} ForceType;

typedef enum ConditionForceNumber
{
    CONDITION_0 = 0,
    CONDITION_1 = 1,
    CONDITION_2 = 2,
    CONDITION_3 = 3,
    CONDITION_4 = 4,
    CONDITION_5 = 5,
    CONDITION_6 = 6,
    CONDITION_7 = 7,
} ConditionForceNumber;

typedef enum PeriodicForceNumber
{
    PERIODIC_0 = 0,
    PERIODIC_1 = 1,
    PERIODIC_2 = 2,
    PERIODIC_3 = 3,
    PERIODIC_4 = 4,
    PERIODIC_5 = 5,
    PERIODIC_6 = 6,
    PERIODIC_7 = 7,
} PeriodicForceNumber;

typedef enum ConstantForceNumber
{
    CONSTANT_0 = 0,
    CONSTANT_1 = 1,
    CONSTANT_2 = 2,
    CONSTANT_3 = 3,
    CONSTANT_4 = 4,
    CONSTANT_5 = 5,
    CONSTANT_6 = 6,
    CONSTANT_7 = 7,
} ConstantForceNumber;

typedef enum RampForceNumber
{
    RAMP_0 = 0,
    RAMP_1 = 1,
    RAMP_2 = 2,
    RAMP_3 = 3,
    RAMP_4 = 4,
    RAMP_5 = 5,
    RAMP_6 = 6,
    RAMP_7 = 7,
} RampForceNumber;

// -----------------------
// Structures
// -----------------------

typedef struct LGPosition 
{
    // total size: 0xA
    u16 button; // offset 0x0, size 0x2
    u8 misc; // offset 0x2, size 0x1
    s8 wheel; // offset 0x3, size 0x1
    u8 accelerator; // offset 0x4, size 0x1
    u8 brake; // offset 0x5, size 0x1
    s8 combined; // offset 0x6, size 0x1
    u8 triggerLeft; // offset 0x7, size 0x1
    u8 triggerRight; // offset 0x8, size 0x1
    s8 err; // offset 0x9, size 0x1
} LGPosition;

typedef struct LGEnvelopeParams 
{
    // total size: 0xC
    u32 attackTime; // offset 0x0, size 0x4
    u32 fadeTime; // offset 0x4, size 0x4
    u8 attackLevel; // offset 0x8, size 0x1
    u8 fadeLevel; // offset 0x9, size 0x1
    u8 pad[2]; // offset 0xA, size 0x2
} LGEnvelopeParams;

typedef struct LGConstantForceParams 
{
    // total size: 0x10
    s16 magnitude; // offset 0x0, size 0x2
    u16 direction; // offset 0x2, size 0x2
    LGEnvelopeParams envelope; // offset 0x4, size 0xC
} LGConstantForceParams;

typedef struct LGRampForceParams 
{
    // total size: 0x6
    s16 magnitudeStart; // offset 0x0, size 0x2
    s16 magnitudeEnd; // offset 0x2, size 0x2
    u16 direction; // offset 0x4, size 0x2
} LGRampForceParams;

typedef struct LGPeriodicForceParams 
{
    // total size: 0x18
    u8 magnitude; // offset 0x0, size 0x1
    u8 pad; // offset 0x1, size 0x1
    u16 direction; // offset 0x2, size 0x2
    u16 period; // offset 0x4, size 0x2
    u16 phase; // offset 0x6, size 0x2
    s16 offset; // offset 0x8, size 0x2
    u8 pad2[2]; // offset 0xA, size 0x2
    LGEnvelopeParams envelope; // offset 0xC, size 0xC
} LGPeriodicForceParams;

typedef struct LGConditionForceParams 
{
    // total size: 0x8
    s8 offset; // offset 0x0, size 0x1
    u8 deadband; // offset 0x1, size 0x1
    u8 saturationNeg; // offset 0x2, size 0x1
    u8 saturationPos; // offset 0x3, size 0x1
    u16 coefficientNeg; // offset 0x4, size 0x2
    u16 coefficientPos; // offset 0x6, size 0x2
} LGConditionForceParams;

typedef struct LGForceEffect 
{
    // total size: 0x24
    u8 type; // offset 0x0, size 0x1
    u8 pad[3]; // offset 0x1, size 0x3
    u32 duration; // offset 0x4, size 0x4
    u32 startDelay; // offset 0x8, size 0x4
    union 
	{
        LGConstantForceParams constant; // offset 0x0, size 0x10
        LGRampForceParams ramp; // offset 0x0, size 0x6
        LGPeriodicForceParams periodic; // offset 0x0, size 0x18
        LGConditionForceParams condition[2]; // offset 0x0, size 0x10
    } p; // offset 0xC, size 0x18
} LGForceEffect;

// -----------------------
// Functions
// -----------------------

// Negative values are error codes.

void LGInit(void);
int LGOpen(u32 deviceId, u32* pOutHandle);
int LGRead(LGPosition* pOut);
int LGClose(u32 handle);

// TODO: Force feedback functions
int LGStartForceEffect(u32 effectId);
int LGUpdateForceEffect(u32 effectId, LGFFForceEffect* pNewEffect /* IN */);
int LGDownloadForceEffect(UNKNOWN /* seems to be a pointer; maybe the handle, like on Wii? */, u32* pEffectId, LGFFForceEffect* pEffect /* IN */)
int LGStopForceEffect(u32 effectId);
int LGDestroyForceEffect(u32 effectId);

#ifdef __cplusplus
}
#endif

#endif  // __LG_H__