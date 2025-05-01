// Based on DWARF data found in Need for Speed Nitro for the Wii (Japanese build), Need for Speed Most Wanted for the GameCube, and the Simpsons Hit and Run source code.
// The latter two are for the GameCube variant, but their public interfaces are almost identical.

// The structures are the only thing that I am sure are correct.
// The macros _should_ be correct, but I cannot be 100% certain.
// The functions should be correct as well.

// NOTE: This header seems to be under the `lgFF` folder, and not `revolution`.
// Which makes sense, I suppose, but it was a bit of a shocker at first.
#ifndef __LGFF_H__
#define __LGFF_H__

#include <revolution/types.h>
#include <revolution/mem.h>

#ifdef __cplusplus
extern "C" {
#endif

// -----------------------
// Macros
// -----------------------

// Button bitmasks
// NOTE: These match the ones in pad.h perfectly.
// TODO: Confirm if these match for Wii
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


// These are used by LGFFForceEffect's type field
#define LG_TYPE_CONSTANT 0 // CConstantEffect
#define LG_TYPE_UNKNOWN1 1 // CRampEffect
#define LG_TYPE_UNKNOWN2 2 // CSineEffect
#define LG_TYPE_SQUARE   3 // CSquareEffect
#define LG_TYPE_TRIANGLE 4 // CTriangleEffect
#define LG_TYPE_UNKNOWN5 5 // CSawUpEffect
#define LG_TYPE_UNKNOWN6 6 // CSawDownEffect
#define LG_TYPE_SPRING   7 // CCougarSpringEffect
#define LG_TYPE_DAMPER   8 // CCougarDamperEffect


// TODO: This should probably be an error code...
// TODO: Seems like invalid handles are also set to -1 (or it really just means invalid device? idk)
// I think we should rename this to LG_INVALID_HANDLE.
// Or add another case for invalid effects (which are handles, too)
#define LG_INVALID_DEVICE (-1)

// Error codes
#define LG_SUCCESS 0
// -3 is already initialized
// -4 is invalid argument
// -6 is failed to find device by handle? (maybe generic fail?)
// -8 is invalid device/invalid handle?

// Properties
#define LG_PROPERTY_FF_DEVICE_GAIN 1
#define LG_PROPERTY_DEFAULT_SPRING 2
#define LG_PROPERTY_CONNECTED 3

// -----------------------
// Enumerations 
// NOTE: I AM SO NOT SURE ABOUT THESE
// -----------------------

typedef enum ForceType
{
    LG_FORCE_NONE = -1,
    LG_FORCE_SPRING = 0,
    LG_FORCE_CONSTANT = 1,
    LG_FORCE_DAMPER = 2,
    LG_FORCE_SIDE_COLLISION = 3,
    LG_FORCE_FRONTAL_COLLISION = 4,
    LG_FORCE_DIRT_ROAD = 5,
    LG_FORCE_BUMPY_ROAD = 6,
    LG_FORCE_SLIPPERY_ROAD = 7,
    LG_FORCE_SURFACE_EFFECT = 8,
    LG_NUMBER_FORCE_EFFECTS = 9, // this makes no sense...
    LG_FORCE_CAR_AIRBORNE = 10,
} ForceType;

typedef enum ConditionForceNumber
{
    LG_CONDITION_0 = 0,
    LG_CONDITION_1 = 1,
    LG_CONDITION_2 = 2,
    LG_CONDITION_3 = 3,
    LG_CONDITION_4 = 4,
    LG_CONDITION_5 = 5,
    LG_CONDITION_6 = 6,
    LG_CONDITION_7 = 7,
} ConditionForceNumber;

typedef enum PeriodicForceNumber
{
    LG_PERIODIC_0 = 0,
    LG_PERIODIC_1 = 1,
    LG_PERIODIC_2 = 2,
    LG_PERIODIC_3 = 3,
    LG_PERIODIC_4 = 4,
    LG_PERIODIC_5 = 5,
    LG_PERIODIC_6 = 6,
    LG_PERIODIC_7 = 7,
} PeriodicForceNumber;

typedef enum ConstantForceNumber
{
    LG_CONSTANT_0 = 0,
    LG_CONSTANT_1 = 1,
    LG_CONSTANT_2 = 2,
    LG_CONSTANT_3 = 3,
    LG_CONSTANT_4 = 4,
    LG_CONSTANT_5 = 5,
    LG_CONSTANT_6 = 6,
    LG_CONSTANT_7 = 7,
} ConstantForceNumber;

typedef enum RampForceNumber
{
    LG_RAMP_0 = 0,
    LG_RAMP_1 = 1,
    LG_RAMP_2 = 2,
    LG_RAMP_3 = 3,
    LG_RAMP_4 = 4,
    LG_RAMP_5 = 5,
    LG_RAMP_6 = 6,
    LG_RAMP_7 = 7,
} RampForceNumber;

// -----------------------
// Structures
// -----------------------

typedef struct LGFFPosition 
{
    // total size: 0x8
    u16 button; // offset 0x0, size 0x2
    s16 wheel; // offset 0x2, size 0x2
    u8 accelerator; // offset 0x4, size 0x1
    u8 brake; // offset 0x5, size 0x1
    s8 combined; // offset 0x6, size 0x1
    s8 err; // offset 0x7, size 0x1
} LGFFPosition;

typedef struct LGFFEnvelopeParams 
{
    // total size: 0xC
    u32 attackTime; // offset 0x0, size 0x4
    u32 fadeTime; // offset 0x4, size 0x4
    u8 attackLevel; // offset 0x8, size 0x1
    u8 fadeLevel; // offset 0x9, size 0x1
    u8 pad[2]; // offset 0xA, size 0x2
} LGFFEnvelopeParams;

typedef struct LGFFConstantForceParams 
{
    // total size: 0x10
    s16 magnitude; // offset 0x0, size 0x2
    u16 direction; // offset 0x2, size 0x2
    LGFFEnvelopeParams envelope; // offset 0x4, size 0xC
} LGFFConstantForceParams;

typedef struct LGFFRampForceParams 
{
    // total size: 0x6
    s16 magnitudeStart; // offset 0x0, size 0x2
    s16 magnitudeEnd; // offset 0x2, size 0x2
    u16 direction; // offset 0x4, size 0x2
} LGFFRampForceParams;

typedef struct LGFFPeriodicForceParams 
{
    // total size: 0x18
    u8 magnitude; // offset 0x0, size 0x1
    u8 pad; // offset 0x1, size 0x1
    u16 direction; // offset 0x2, size 0x2
    u16 period; // offset 0x4, size 0x2
    u16 phase; // offset 0x6, size 0x2
    s16 offset; // offset 0x8, size 0x2
    u8 pad2[2]; // offset 0xA, size 0x2
    LGFFEnvelopeParams envelope; // offset 0xC, size 0xC
} LGFFPeriodicForceParams;

typedef struct LGFFConditionForceParams 
{
    // total size: 0xA
    s16 offset; // offset 0x0, size 0x2
    u16 deadband; // offset 0x2, size 0x2
    u8 saturation; // offset 0x4, size 0x1
    u8 pad; // offset 0x5, size 0x1
    s16 coefficientNeg; // offset 0x6, size 0x2
    s16 coefficientPos; // offset 0x8, size 0x2
} LGFFConditionForceParams;

typedef struct LGFFForceEffect 
{
    // total size: 0x24
    u8 type; // offset 0x0, size 0x1
    u8 pad[3]; // offset 0x1, size 0x3
    u32 duration; // offset 0x4, size 0x4
    u32 startDelay; // offset 0x8, size 0x4
    union
	{
        LGFFRampForceParams ramp; // offset 0x0, size 0x6
        LGFFConditionForceParams condition; // offset 0x0, size 0xA
        LGFFConstantForceParams constant; // offset 0x0, size 0x10
        LGFFPeriodicForceParams periodic; // offset 0x0, size 0x18
    } p; // offset 0xC, size 0x18
} LGFFForceEffect;

// The following structure is fully guessed!
// The name is real, though.
typedef struct LGFFInitParams
{
    // total size: 0x2C
    MEMAllocator mem1; // Calculate as follows: 0x54 bytes per each effect, plus 0x288 (per-device data), multiplied by how many devices you have.
                       // assuming 4 devices, and 64 effects, you'd need 0x5E20 bytes total.
                       // Of course, you will rarely ever need 64 effects at once, so you should tweak this.
                       // In other words, (((0x54 * maxEffects) + 0x288) * maxDevices)

    MEMAllocator mem2; // needs 0x180 bytes assuming 4 devices, 0x60 for each device.
                       // (0x60 * maxDevices)

    u8 maxDevices; // up to 4
    u8 maxEffects; // up to 64
    u8 pad[2];
    void* samplingCallback; // TODO: Proper type! // (void (*)(ulong,LGFFPosition const *))
    void* attachDetachCallback; // TODO: Proper type!, takes 3 unsigned longs though, probably returns void
} LGFFInitParams;

// -----------------------
// Functions
// -----------------------

// Negative values are error codes.

void LGFFInit(LGFFInitParams* initParams);
int LGFFOpen(u32 deviceId, u32* pOutHandle);
int LGFFRead(u32 handle, LGFFPosition* pOut);
int LGFFGetDeviceProperty(u32 handle, u32 property /* TODO: Macro definitions for all properties */, s32* pOut);
int LGFFClose(u32 handle);

// Looks like the effect is the lower 6 bits (0-63), with the upper 24 being the device handle
// NOTE: Shouldn't matter, though. It looks like you first call Download to get the effectId (which effectively is a handle)
// And then you can call the other functions.
//
// Looks like Update is called to modify the current effect

int LGFFStartForceEffect(u32 effectId);
int LGFFUpdateForceEffect(u32 effectId, LGFFForceEffect* pNewEffect /* IN */);
int LGFFDownloadForceEffect(u32 devHandle, u32* pEffectId, LGFFForceEffect* pEffect /* IN */)
int LGFFStopForceEffect(u32 effectId);
int LGFFDestroyForceEffect(u32 effectId);

// NOTE: These may not be part of the public interface, they're only called by an internal function.
// They might return int regardless... idk
u16 LGFFGetWifiChannel(void);
u8 LGFFGetWifiChannelSkip(void);

#ifdef __cplusplus
}
#endif

#endif  // __LGFF_H__
