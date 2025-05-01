#ifndef NULL
#define NULL 0
#endif

#pragma region Some WPAD defines

// device type
#define WPAD_DEV_CORE                 0
#define WPAD_DEV_FREESTYLE            1
#define WPAD_DEV_CLASSIC              2
#define WPAD_DEV_FUTURE             251
#define WPAD_DEV_NOT_SUPPORTED      252
#define WPAD_DEV_NOT_FOUND          253
#define WPAD_DEV_UNKNOWN            255

#define WPAD_BUTTON_LEFT              0x0001
#define WPAD_BUTTON_RIGHT             0x0002
#define WPAD_BUTTON_DOWN              0x0004
#define WPAD_BUTTON_UP                0x0008
#define WPAD_BUTTON_PLUS              0x0010
#define WPAD_BUTTON_2                 0x0100
#define WPAD_BUTTON_1                 0x0200
#define WPAD_BUTTON_B                 0x0400
#define WPAD_BUTTON_A                 0x0800
#define WPAD_BUTTON_MINUS             0x1000
#define WPAD_BUTTON_HOME              0x8000

#define WPAD_BUTTON_Z                 0x2000
#define WPAD_BUTTON_C                 0x4000

#pragma endregion

#pragma region Game structures / enumerations

// The structure in question:
enum DeviceScalarType
{
	kJoyAxis = 0,
    kAnalogButton = 1,
    kDigitalButton = 2,
};

// Wii DeviceScalarInfo, comes from NFS Nitro DWARF data 
struct DeviceScalarInfo // Size: 0x10
{
    unsigned int dev_type;
    DeviceScalarType type;
    const char* name;
    unsigned int subtype;
};

// Custom enumeration made by me to display the `subtype` field in IDA better.
// I don't know if this actually existed, I assume it probably did, but anyway.
enum DeviceScalarSystemIndex
{
	// Nunchuk analog stick
	NC_R = 0,
	NC_L = 1,
	NC_U = 2,
	NC_D = 3,
	
	NC_SENSOR_FB_F = 4,
	NC_SENSOR_FB_B = 5,
	NC_SENSOR_LR_L = 6,
	NC_SENSOR_LR_R = 7,
	NC_SENSOR_UD_U = 8,
	NC_SENSOR_UD_D = 9,
	
	NC_DIVE          = 10,
	NC_PITCH         = 11,
	NC_DIVE_REVERSE  = 12,
	NC_PITCH_REVERSE = 13,
	NC_ROLL_R        = 14,
	NC_ROLL_L        = 15,
	COMBINED_ROLL_R  = 16,
	COMBINED_ROLL_L  = 17,
	
	// Wii Remote
	RC_DIVE          = 18,
	RC_PITCH         = 19,
	RC_DIVE_REVERSE  = 20,
	RC_PITCH_REVERSE = 21,
	RC_ROLL_R        = 22,
	RC_ROLL_L        = 23,
	
	RC_SENSOR_FB_F = 24,
	RC_SENSOR_FB_B = 25,
	RC_SENSOR_LR_L = 26,
	RC_SENSOR_LR_R = 27,
	RC_SENSOR_UD_U = 28,
	RC_SENSOR_UD_D = 29,
	
	// Nunchuk
	NC_TILT_L = 30,
	NC_TILT_R = 31,
	NC_TILT_F = 32,
	NC_TILT_B = 33,
	
	// Wii Remote
	RC_TILT_L  = 34,
	RC_TILT_R  = 35,
	RC_TILT_F  = 36,
	RC_TILT_B  = 37,
	RC_POINT_L = 38,
	RC_POINT_R = 39,
	RC_POINT_U = 40,
	RC_POINT_D = 41,
	
	// GameCube KPAD leftovers
	NGC_LJOY_L = 42,
	NGC_LJOY_R = 43,
	NGC_LJOY_U = 44,
	NGC_LJOY_D = 45,
	
	NGC_RJOY_L = 46,
	NGC_RJOY_R = 47,
	NGC_RJOY_U = 48,
	NGC_RJOY_D = 49,
	
	MAX_ENTRIES = 50,
};

#pragma endregion

DeviceScalarInfo device_infos[56] =
{
	// Analog stick
	{ WPAD_DEV_FREESTYLE,  kJoyAxis,        "NC_L",               1 }, // [0]
	{ WPAD_DEV_FREESTYLE,  kJoyAxis,        "NC_R",               0 }, // [1]
	{ WPAD_DEV_FREESTYLE,  kJoyAxis,        "NC_U",               2 }, // [2]
	{ WPAD_DEV_FREESTYLE,  kJoyAxis,        "NC_D",               3 }, // [3]
  
	{ WPAD_DEV_FREESTYLE,  kJoyAxis,        "NC_DIVE",           10 }, // [4]
	{ WPAD_DEV_FREESTYLE,  kJoyAxis,        "NC_PITCH",          11 }, // [5]
	{ WPAD_DEV_FREESTYLE,  kJoyAxis,        "NC_DIVE_REVERSE",   12 }, // [6]
	{ WPAD_DEV_FREESTYLE,  kJoyAxis,        "NC_PITCH_REVERSE",  13 }, // [7]
	{ WPAD_DEV_FREESTYLE,  kJoyAxis,        "NC_ROLL_R",         14 }, // [8]
	{ WPAD_DEV_FREESTYLE,  kJoyAxis,        "NC_ROLL_L",         15 }, // [9]
	{ WPAD_DEV_FREESTYLE,  kJoyAxis,        "COMBINED_ROLL_R",   16 }, // [10]
	{ WPAD_DEV_FREESTYLE,  kJoyAxis,        "COMBINED_ROLL_L",   17 }, // [11]
  
	{ WPAD_DEV_FREESTYLE,  kDigitalButton,  "NC_Z",   WPAD_BUTTON_Z }, // [12]
	{ WPAD_DEV_FREESTYLE,  kDigitalButton,  "NC_C",   WPAD_BUTTON_C }, // [13]
  
	{ WPAD_DEV_FREESTYLE,  kJoyAxis,        "NC_TILT_L",         30 }, // [14]
	{ WPAD_DEV_FREESTYLE,  kJoyAxis,        "NC_TILT_R",         31 }, // [15]
	{ WPAD_DEV_FREESTYLE,  kJoyAxis,        "NC_TILT_F",         32 }, // [16]
	{ WPAD_DEV_FREESTYLE,  kJoyAxis,        "NC_TILT_B",         33 }, // [17]
	{ WPAD_DEV_FREESTYLE,  kJoyAxis,        "NC_SENSOR_FB_F",     4 }, // [18]
	{ WPAD_DEV_FREESTYLE,  kJoyAxis,        "NC_SENSOR_FB_B",     5 }, // [19]
	{ WPAD_DEV_FREESTYLE,  kJoyAxis,        "NC_SENSOR_LR_L",     6 }, // [20]
	{ WPAD_DEV_FREESTYLE,  kJoyAxis,        "NC_SENSOR_LR_R",     7 }, // [21]
	{ WPAD_DEV_FREESTYLE,  kJoyAxis,        "NC_SENSOR_UD_U",     8 }, // [22]
	{ WPAD_DEV_FREESTYLE,  kJoyAxis,        "NC_SENSOR_UD_D",     9 }, // [23]
  
	{ WPAD_DEV_CORE,       kJoyAxis,        "RC_DIVE",           18 }, // [24]
	{ WPAD_DEV_CORE,       kJoyAxis,        "RC_PITCH",          19 }, // [25]
	{ WPAD_DEV_CORE,       kJoyAxis,        "RC_DIVE_REVERSE",   20 }, // [26]
	{ WPAD_DEV_CORE,       kJoyAxis,        "RC_PITCH_REVERSE",  21 }, // [27]
	{ WPAD_DEV_CORE,       kJoyAxis,        "RC_ROLL_R",         22 }, // [28]
	{ WPAD_DEV_CORE,       kJoyAxis,        "RC_ROLL_L",         23 }, // [29]
  
	{ WPAD_DEV_CORE,       kDigitalButton,  "RC_U",     WPAD_BUTTON_UP    }, // [30]
	{ WPAD_DEV_CORE,       kDigitalButton,  "RC_D",     WPAD_BUTTON_DOWN  }, // [31]
	{ WPAD_DEV_CORE,       kDigitalButton,  "RC_L",     WPAD_BUTTON_LEFT  }, // [32]
	{ WPAD_DEV_CORE,       kDigitalButton,  "RC_R",     WPAD_BUTTON_RIGHT }, // [33]
	{ WPAD_DEV_CORE,       kDigitalButton,  "RC_A",     WPAD_BUTTON_A     }, // [34]
	{ WPAD_DEV_CORE,       kDigitalButton,  "RC_B",     WPAD_BUTTON_B     }, // [35]
	{ WPAD_DEV_CORE,       kDigitalButton,  "RC_MINUS", WPAD_BUTTON_MINUS }, // [36]
	{ WPAD_DEV_CORE,       kDigitalButton,  "RC_HOME",  WPAD_BUTTON_HOME  }, // [37]
	{ WPAD_DEV_CORE,       kDigitalButton,  "RC_PLUS",  WPAD_BUTTON_PLUS  }, // [38]
	{ WPAD_DEV_CORE,       kDigitalButton,  "RC_1",     WPAD_BUTTON_1     }, // [39]
	{ WPAD_DEV_CORE,       kDigitalButton,  "RC_2",     WPAD_BUTTON_2     }, // [40]
  
	{ WPAD_DEV_CORE,       kJoyAxis,        "RC_TILT_L",         34 }, // [41]
	{ WPAD_DEV_CORE,       kJoyAxis,        "RC_TILT_R",         35 }, // [42]
	{ WPAD_DEV_CORE,       kJoyAxis,        "RC_TILT_F",         36 }, // [43]
	{ WPAD_DEV_CORE,       kJoyAxis,        "RC_TILT_B",         37 }, // [44]
	{ WPAD_DEV_CORE,       kJoyAxis,        "RC_POINT_L",        38 }, // [45]
	{ WPAD_DEV_CORE,       kJoyAxis,        "RC_POINT_R",        39 }, // [46]
	{ WPAD_DEV_CORE,       kJoyAxis,        "RC_POINT_U",        40 }, // [47]
	{ WPAD_DEV_CORE,       kJoyAxis,        "RC_POINT_D",        41 }, // [48]
	{ WPAD_DEV_CORE,       kJoyAxis,        "RC_SENSOR_FB_F",    24 }, // [49]
	{ WPAD_DEV_CORE,       kJoyAxis,        "RC_SENSOR_FB_B",    25 }, // [50]
	{ WPAD_DEV_CORE,       kJoyAxis,        "RC_SENSOR_LR_L",    26 }, // [51]
	{ WPAD_DEV_CORE,       kJoyAxis,        "RC_SENSOR_LR_R",    27 }, // [52]
	{ WPAD_DEV_CORE,       kJoyAxis,        "RC_SENSOR_UD_U",    28 }, // [53]
	{ WPAD_DEV_CORE,       kJoyAxis,        "RC_SENSOR_UD_D",    29 }, // [54]
  
	{ 0, kJoyAxis, NULL, 0 } // [55]
};

