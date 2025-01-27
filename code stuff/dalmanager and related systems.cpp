// Enums and structures are below.

// If a function does NOT return `true`, then it usually means the operation is not supported. Or that it failed.
// If it does return `true`, it worked.
//
// All DAL enums have the following prefixes:
// INT, FLT, STR, DAL.
// The DAL prefix seems to be used for booleans, do note that they are returned as 32-bit values...
// The rest are self-explanatory.
//
// EDIT: THIS IS NOT ALWAYS THE CASE!!!!
// Still not sure what exactly causes them to use one type over another, but welp..
// 
// DECOMP NOTE: I'll be using the UNK prefix when I do not know the type.
// This is because you can't tell integers and booleans apart, since they're both returned by DALxyz::GetInt.

// DALInterface
enum DALInterface::DAL_INTERFACE
{
	DAL_INTERFACE_TEMPLATE = 0,
	DAL_INTERFACE_RACER = 1,
	DAL_INTERFACE_VEHICLE = 2,
	DAL_INTERFACE_EVENT = 3,
	DAL_INTERFACE_LANGHASH = 4,
	DAL_INTERFACE_OPTIONS = 5,
	DAL_INTERFACE_CAREER = 6,
	DAL_INTERFACE_FEVEHICLE = 7,
	DAL_INTERFACE_PAUSE_STATES = 8,
	DAL_INTERFACE_WORLD_MAP = 9, // DECOMP: guessed
	DAL_INTERFACE_PLAYER = 10,
	DAL_INTERFACE_PURSUIT = 11,
	DAL_INTERFACE_REWARDS = 12,
	DAL_INTERFACE_CREW_MEMBER = 13, // DECOMP: guessed
	DAL_INTERFACE_STATISTICS = 14,
	DAL_INTERFACE_ONLINE = 15,
	DAL_INTERFACE_CHALLENGE = 16,
	DAL_INTERFACE_TOTAL = 17
};

struct DALInterface_vtbl
{
	void* __codewarrior_dummy[2]; // I don't know why it exists either, always 0.
	void (*dtor)(DALInterface* this, short should_delete); // The signature is compiler and architecture specific. This is for CodeWarrior on the Nintendo Wii.
	
	// I'm pretty sure that arg1 through arg3 are default params with the value of `-1`.
	// They're called far too often with these values for them to be manually typed in.
	
	bool (*IsInterfaceValid)(DALInterface* this, const int valueType, const int arg1, const int arg2, const int arg3);
	
	bool (*GetFloat)(DALInterface* this, const int valueType, float& getVal, const int arg1, const int arg2, const int arg3);
	bool (*SetFloat)(DALInterface* this, const int valueType, float setVal, const int arg1, const int arg2, const int arg3);
	bool (*IncrementFloat)(DALInterface* this, const int valueType, float incVal, const int arg1, const int arg2, const int arg3);
	bool (*DecrementFloat)(DALInterface* this, const int valueType, float decVal, const int arg1, const int arg2, const int arg3);
	
	bool (*GetInt)(DALInterface* this, const int valueType, int& getVal, const int arg1, const int arg2, const int arg3);
	bool (*SetInt)(DALInterface* this, const int valueType, const int setVal, const int arg1, const int arg2, const int arg3);
	bool (*IncrementInt)(DALInterface* this, const int valueType, const int incVal, const int arg1, const int arg2, const int arg3);
	bool (*DecrementInt)(DALInterface* this, const int valueType, const int decVal, const int arg1, const int arg2, const int arg3);
	
	bool (*GetString)(DALInterface* this, const int valueType, char* getVal, const int getLen, const int arg1, const int arg2, const int arg3);
	bool (*SetString)(DALInterface* this, const int valueType, const char* setVal, const int setLen, const int arg1, const int arg2, const int arg3);
	
	bool (*GetDefaultInt)(DALInterface* this, const int valueType, int& getVal, const int arg1, const int arg2, const int arg3);
	bool (*GetDefaultFloat)(DALInterface* this, const int valueType, float& getVal, const int arg1, const int arg2, const int arg3);
};

struct DALInterface
{
	DALInterface_vtbl* __vftable;
	int mInterfaceIndex;
};

// DALManager
struct DALManager : DALInterface
{
	DALInterface* mInterfaces[DAL_INTERFACE_TOTAL]; // [17]
	bool mInited;
};

// DALTemplate
enum DALTemplate::DAL_TEMPLATE
{
	DAL_TEMPLATE_TYPE = 0
};

struct DALTemplate : DALInterface {};

// DALRacer
enum DALRacer::DAL_RACER
{
	DAL_RACER_TOP_SPEED = 1000,
	DAL_RACER_AVG_SPEED = 1001,
	DAL_RACER_PERCENT_COMPLETED = 1002,
	DAL_RACER_DISTANCE_AHEAD = 1003,
	DAL_RACER_TIME_AHEAD = 1004,
	DAL_RACER_POINTS_AHEAD = 1005,
	FLT_POINTS = 1006,
	DAL_RACER_RACE_TIME = 1007,
	DAL_RACER_TOTAL_TIME = 1008,
	DAL_RACER_SUMMED_TIME = 1009,
	DAL_RACER_ELAPSE_TIME = 1010, // DECOMP: blackbox typo? or perhaps intentional in order for alignment?
	DAL_RACER_REMAIN_TIME = 1011,
	DAL_RACER_LAP_TIME = 1012,
	DAL_RACER_SPLIT_TIME = 1013,
	DAL_RACER_SPLIT_TIME_TOTAL = 1014,
	
	DAL_RACER_TIME_BEHIND_LEAD = 1015,
	DAL_RACER_BEST_LAP_TIME = 1016,
	DAL_RACER_TOP_SPEED_RAW = 1017,
	FLT_RACER_SPEEDTRAP_SPEED = 1018,
	FLT_FINAL_SCORE = 1019,
	
	FLT_RACER_SPEEDTRAP_TOTAL_SPEED = 1020,
	FLT_RACER_SPEEDTRAP_TOTAL_SPEED_RAW = 1021,
	FLT_RACER_SPEEDTRAP_BEST_SPEED = 1022,
	FLT_RACER_SPEEDTRAP_BEST_SPEED_RAW = 1023,
	FLT_RACER_SPEEDTRAP_AVERAGE_SPEED = 1024,
	FLT_RACER_SPEEDTRAP_TOTAL_SPEED_BEHIND = 1025,
	
	// Canyon stuff begins here  - I'm stubbing it out with unknowns for now.
	UNK_RACER_CANYON_1026 = 1026, // [flt] DALRacer::GetCanyonScore
	UNK_RACER_CANYON_1027 = 1027, // [flt] DALRacer::GetRawCanyonScore
	UNK_RACER_CANYON_1028 = 1028, // [flt] DALRacer::SetRawCanyonScore
	UNK_RACER_CANYON_1029 = 1029, // [flt] DALRacer::GetCanyonScore
	UNK_RACER_CANYON_1030 = 1030, // [flt] DALRacer::GetCanyonHudScore
	UNK_RACER_CANYON_1031 = 1031, // [flt] DALRacer::GetCanyonSplitScore
	UNK_RACER_CANYON_1032 = 1032, // [flt] DALRacer::GetCanyonTugScore
	UNK_RACER_CANYON_1033 = 1033, // [flt] DALRacer::GetCanyonCurrZonePercent
	UNK_RACER_CANYON_1034 = 1034, // [flt] DALRacer::GetCanyonDistanceBehind
	UNK_RACER_CANYON_1035 = 1035, // [flt] DALRacer::GetCanyonCurrTimeAheadOfZone
	UNK_RACER_CANYON_1036 = 1036, // [flt] DALRacer::GetCanyonCurrTimeBehindZone
	UNK_RACER_CANYON_1037 = 1037, // [flt] DALRacer::GetCanyonTimePerStage
	UNK_RACER_CANYON_1038 = 1038, // [flt] DALRacer::GetCanyonTimeStageOne
	UNK_RACER_CANYON_1039 = 1039, // [flt] DALRacer::GetCanyonTimeStageTwo
	
	FLT_CHECKPOINT_TIME_AHEAD_FOR_BOOTH = 1040,
	FLT_NOS_USED = 1041,
	FLT_SPEED_BREAKER_TIME_USED = 1042,
	FLT_JUMP_TIME = 1043,
	FLT_ONLINE_XP_RACER_GAINED = 1044,
	
	UNK_RACER_1045 = 1045, // [int] DALRacer::GetPursuitKOLapScore
	UNK_RACER_1046 = 1046, // [int] DALRacer::GetPursuitKOBestScore
	UNK_RACER_1047 = 1047, // [flt] DALRacer::GetPursuitKOPercAsPolice
	UNK_RACER_1048 = 1048, // [flt] DALRacer::GetPursuitTagTimeAsRacer
	UNK_RACER_1049 = 1049, // [flt] DALRacer::GetPursuitTagPercAsRacer
	
	DAL_RACER_POSITION = 1050,
	DAL_RACER_LAPS_COMPLETED = 1051,
	DAL_RACER_CURR_LAP_NUM = 1052,
	DAL_RACER_CURR_CAR_HANDLE = 1053,
	DAL_RACER_IS_BUSTED = 1054,
	DAL_RACER_IS_KOED = 1055,
	DAL_RACER_IS_FINISHED = 1056,
	INT_RACER_IS_TIMOUT_AHEAD = 1057, // DECOMP: blackbox typo
	INT_RACER_IS_TIMOUT_BEHIND = 1058, // DECOMP: blackbox typo
	DAL_RACER_IS_OVERBOARD = 1059, // DECOMP: guessed
	INT_RACER_DNF = 1060,
	DAL_RACER_IS_DISCONNECTED = 1061,
	DAL_RACER_IS_CHALLENGE_COMPLETE = 1062,
	DAL_RACER_TRAFFIC_COLLISIONS = 1063,
	DAL_RACER_POSITION_ON_LAP = 1064,
	DAL_RACER_SPLIT_POSITION = 1065,
	
	DAL_RACER_CURRDRIFT_SCORE = 1066,
	DAL_RACER_CURRDRIFT_CHAINSCORE = 1067,
	DAL_RACER_CURRDRIFT_MULTIPLIER = 1068,
	INT_CURRDRIFT_NUM_WHEELS_IN_BONUS_ZONE = 1069,
	DAL_RACER_LASTAWARDED_MULTIPLIER = 1070,
	DAL_RACER_DRIFT_TOTAL_POINTS = 1071,
	DAL_RACER_DRIFT_LAP_SCORE = 1072,
	DAL_RACER_DRIFT_LAP_POSITION = 1073,
	DAL_RACER_DRIFT_SPLIT_SCORE = 1074,
	DAL_RACER_DRIFT_SPLIT_POSITION = 1075,
	INT_RACER_SPEEDTRAP_POSITION_AT_TRAP = 1076,
	INT_RACER_SPEEDTRAP_NUM_SPEEDTRAPS = 1077,
	DAL_RACER_DRIFT_HIGHEST = 1078,
	DAL_RACER_DRIFT_LONGEST_DISTANCE = 1079,
	DAL_RACER_DRIFT_LONGEST_TIME = 1080,
	DAL_RACER_DRIFT_AVERAGE_SCORE = 1081,
	DAL_RACER_DRIFT_BEST_LAP_SCORE = 1082,
	DAL_RACER_DRIFT_AVERAGE_LENGHT_DISTANCE = 1083, // DECOMP NOTE: blackbox typo
	DAL_RACER_DRIFT_AVERAGE_LENGHT_TIME = 1084, // DECOMP NOTE: blackbox typo
	
	UNK_RACER_1085 = 1085, // [int] DALRacer::GetRacersTeam
	
	INT_VOIP_STATUS_SCRIPT_HASH = 1086,
	INT_CANYON_IS_PLAYER_LEADER = 1087,
	INT_CANYON_CURR_ZONE = 1088,
	INT_CANYON_PERFECT_DUEL = 1089,
	INT_CANYON_COLLIDE_RACER = 1090,
	INT_CANYON_COLLIDE_WORLD = 1091,
	INT_DRIFT_WAS_TOO_SLOW = 1092,
	
	UNK_RACER_1093 = 1093, // [int] DALRacer::GetDriftWasOverboard
	UNK_RACER_1094 = 1094, // [int] DALRacer::GetTollboothWasOverboard

	INT_RACER_BREAKERS_ACTIVATED = 1095,
	
	UNK_RACER_1096 = 1096, // [int] DALRacer::GetPursuitKOBestMoveScore
	UNK_RACER_1097 = 1097, // [int] DALRacer::GetPursuitTagNumberOfBusts
	UNK_RACER_1098 = 1098, // [int] DALRacer::GetPursuitTagNumberTimesBusted
	
	DAL_RACER_PLAYER_WAS_SHOWBOATING = 1099,
	DAL_RACER_PLAYER_GAVE_HEADSTART = 1100,
	
	UNK_RACER_1101 = 1101, // [int] DALRacer::GetRacerIsFollower
	
	INT_IS_CAMERA_ATTACHED = 1102,
	DAL_RACER_NAME = 1103,
	DAL_RACER_CURR_CAR_NAME = 1104,
	STR_CANYON_SPLIT_SCORE_RATING = 1105,
};

// Almost certainly used by the functions that take in `int dalRacerNum`, which is to say, most of them.
// This is `arg1` when passed to GetInt/GetFloat/etc
enum DALRacer::DAL_RACER_NUM
{
	DAL_RACER_NUM_PLAYER_ONE = 0,
	DAL_RACER_NUM_PLAYER_TWO = 1,
	
	DAL_RACER_NUM_PLAYER_MAX = 1,
	
	DAL_RACER_NUM_POSITION_ONE = 2,
	DAL_RACER_NUM_POSITION_MAX = 5
};

struct DALRacer : DALInterface {};

// DALLangHash
enum DALLangHash::DAL_LANGHASH
{
	INT_LOCUNITS_KPH = 4000,
	INT_LOCUNITS_POINTS = 4001,
	INT_LOCUNITS_METERS = 4002,
	INT_LOCUNITS_POUNDS = 4003,
	INT_LOC_RACETYPE = 4004,
	
	// DECOMP: The following are guessed
	// Caps stands for Capitalized.
	// Primary role is Race Skills, Secondary role is Crew Skills
	INT_LOC_PRIMARY_ROLE = 4005,
	INT_LOC_PRIMARY_ROLE_CAPS = 4006,
	INT_LOC_SECONDARY_ROLE = 4007,
	INT_LOC_SECONDARY_ROLE_CAPS = 4008,
	INT_LOC_SECONDARY_ROLE_DESC = 4009, // Most likely description? NOTE: The strings it returns seem to be placeholders...
	
	INT_LOC_RACE_POSITION = 4010,
	INT_LOC_RACING_RESOLUTION = 4011,
	INT_LOC_PHYSICS_UPGRADE_LABEL = 4012,
	INT_CONVERT_TO_LOCALIZED_DISTANCE = 4013,
	INT_CONVERT_TO_LOCALIZED_SPEED = 4014,
	STR_GET_EA_TRAX_TICKER = 4015
};

struct DALLangHash : DALInterface {};