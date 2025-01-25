// A few left for reference - they are not correct.
enum EasterEggsSpecial_MW_A121
{
	EASTER_EGG_UNLOCK_ALL_THINGS = 0,
	EASTER_EGG_SKIP_DDAY = 1,
	EASTER_EGG_DISABLE_MIKE_MANN_BUILD = 2,
	EASTER_EGG_BURGER_KING = 3,
	EASTER_EGG_CASTROL = 4,
	EASTER_EGG_SPECIAL_LANGUAGES_TOGGLE = 5,
	EASTER_EGG_SPECIAL_XBOX_SAFEZONE = 6,
	EASTER_EGG_EREG2_200 = 7,
	EASTER_EGG_EREG2_VINYL = 8,
	EASTER_EGG_PREORDER = 9
};

enum EasterEggsType_MW_A121
{
	EASTER_EGG_CARS = 0,
	EASTER_EGG_VISUAL_PARTS = 1,
	EASTER_EGG_PERF_PARTS = 2,
	EASTER_EGG_DRIFT_PHYSICS = 3,
	EASTER_EGG_TRACK = 4,
	EASTER_EGG_SPECIAL = 5,
	EASTER_EGG_PRESETCARS = 6,
	EASTER_EGG_MANUFACTURER_VINYL = 7
};


enum EasterEggsItem_ProStreet
{
	EASTER_EGG_UNLOCK_ALL_THINGS = 0,
	EASTER_EGG_LEIPZIG = 1,
	EASTER_EGG_CASTROL_CASH = 2,
	EASTER_EGG_ENERGIZER_DECAL = 3,
	EASTER_EGG_ENERGIZER_CAR = 4,
	EASTER_EGG_PROGRESSIVE_CAR = 5,
	EASTER_EGG_K_N_DECAL = 6,
	EASTER_EGG_EA_MOBILE_CASH_1 = 7,
	EASTER_EGG_EA_MOBILE_CASH_2 = 8,
	EASTER_EGG_EA_MOBILE_CASH_3 = 9,
	EASTER_EGG_EA_MOBILE_CASH_4 = 10,
	EASTER_EGG_COKE_ZERO = 11,
	EASTER_EGG_EA_REGISTER = 12,
	EASTER_EGG_EXTRA_CASH = 13,
	EASTER_EGG_FREE_REPAIRS = 14,
	EASTER_EGG_EVO_UNLOCK = 15,
	EASTER_EGG_SUBARU = 16,
	EASTER_EGG_MAX = 17
};

enum EasterEggsType_ProStreet
{
	EASTER_EGG_GENERAL = 0,
	EASTER_EGG_CARS = 1,
	EASTER_EGG_VISUAL_PARTS = 2,
	EASTER_EGG_PERF_PARTS = 3,
	EASTER_EGG_DRIFT_PHYSICS = 4,
	EASTER_EGG_TRACK = 5,
	EASTER_EGG_SPECIAL = 6,
	EASTER_EGG_PRESETCARS = 7,
	EASTER_EGG_MANUFACTURER_VINYL = 8
};

enum EasterEggGroups_ProStreet
{
	EASTER_EGG_NO_GROUP = 0,
	EASTER_EGG_RENDERING_GROUP = 1,
	v = 2 // ? what
};

// New ones from Carbon - names derived from what little information I could find.

enum EasterEggsType // 4 bytes
{
	// todo: compare with MW/PS and match the names where possible.
	// I feel like it probably matches ProStreet 1:1
	EASTER_EGG_GENERAL = 0,
	EASTER_EGG_UNKTYPE1 = 1,
	EASTER_EGG_UNKTYPE2 = 2,
	EASTER_EGG_UNKTYPE3 = 3,
	EASTER_EGG_UNKTYPE4 = 4,
	EASTER_EGG_UNKTYPE5 = 5,
	EASTER_EGG_SPECIAL = 6,
	EASTER_EGG_UNKTYPE7 = 7,
	EASTER_EGG_UNKTYPE8 = 8
};

enum EasterEggGroups // 4 bytes
{
	EASTER_EGG_NO_GROUP = 0,
	// All entries use 0...
	// Maybe there's no other groups?
};

// QR prefix is used for cheats meant to unlock vehicles for Quick Race.
// TODO: Maybe improve on the names a bit?
enum EasterEggsItem // 4 bytes
{
	EASTER_EGG_AUTOZONE_VINYL = 0,
	EASTER_EGG_CASTROL_VINYL = 1,
	EASTER_EGG_CASTROL_CASH = 2,
	EASTER_EGG_CHROME_CARS = 3,
	EASTER_EGG_COOPER_TIRE_LOGO = 4,
	EASTER_EGG_QR_POLICE_CORVETTE = 5,
	EASTER_EGG_QR_CROSS_CORVETTE = 6,
	EASTER_EGG_QR_DUMP_TRUCK = 7,
	EASTER_EGG_QR_FIRE_TRUCK = 8,
	EASTER_EGG_INFINITE_CREW_CHARGE = 9,
	EASTER_EGG_INFINITE_NOS = 10,
	EASTER_EGG_INFINITE_RACE_BREAKER = 11,
	EASTER_EGG_MAZDA_CARLOT = 12,
	EASTER_EGG_CARBON_LOGO_VINYLS = 13,
	EASTER_EGG_CARBON_SPECIAL_LOGO_VINYLS = 14,
	EASTER_EGG_QR_RHINO = 15, // What's a "Rhino"? - PC Cheat string is 'watchoutthebigtruckishere'
	EASTER_EGG_PHARRELL_VINYL = 16,
	EASTER_EGG_UNLOCK_ALL_THINGS = 17, // Both Debug and Milestone have this! Release does not!
	
	EASTER_EGG_MAX = 18
};

00 00 00 2c 00 00 00 29 00 00 00 29 00 00 00 2a

// Structures!
struct EasterEggsData
{
	EasterEggButtons buttons[8]; // char buttons[32]; on PC
	EasterEggsType type;
	EasterEggsItem item;
	EasterEggGroups group;
	uint32_t unlock_message;
	bool unlocked;
	bool persistent;
	bool enabled;
};

struct EasterEggs
{
	EasterEggs_vtbl* __vftable;
	
	ActionQueue* EasterEggActionQ[2]; // [1] on PC
	bool ButtonsEnabled;
	bool HaveUnlockMessage;
	uint32_t UnlockMessage;
	EasterEggsData* EasterEggsTable;
	uint32_t NumberOfEasterEggs;
	EasterEggButtons ButtonBuffer[8]; // char ButtonBuffer[32]; on PC
	uint32_t NumberOfCurrentButtons;
	uint32_t CurrentStartButton;
	bool Activated;
};

// Some easter eggs are saved to the profile.
// These are: 0, 1, 2, 4, 12, 13, 14, and 16.
// TODO: Table of what they unlock (maybe use the `unlock_message` field to help figure it out)
// TODO: These are probably the ones that have the `persistent` field set to true?

// Messages they print, English, no capitalization changes.
// If the box is ticked, that means it's enabled by default.
// [ ]  0: Autozone Vinyl Unlocked!
// [ ]  1: Castrol Syntec Vinyl Unlocked!
// [x]  2: Castrol Cash Unlocked!
// [ ]  3: Chrome Cars Unlocked!
// [ ]  4: Cooper Tire Logo Unlocked!
// [ ]  5: Corvette Z06 Interceptor Unlocked For Quick Race!
// [ ]  6: Cross Corvette Z06 Unlocked For Quick Race!
// [ ]  7: Dump Truck Unlocked For Quick Race!
// [ ]  8: Fire Truck Unlocked For Quick Race!
// [x]  9: Infinite Crew Charge!
// [x] 10: Infinite Nitrous!
// [x] 11: Infinite Speedbreaker!
// [x] 12: Mazda Dealership Unlocked!
// [x] 13: Need for Speed™ Carbon Logo Vinyls Unlocked!
// [x] 14: Need for Speed™ Carbon Special Logo Vinyls Unlocked!
// [ ] 15: Rhino Unlocked For Quick Race!
// [x] 16: Pharrell Vinyl Unlocked!
// [x] 17: DEFAULT STRING
// NOTE THAT 17 IS ONLY ON DEBUG/MILESTONE BUILDS