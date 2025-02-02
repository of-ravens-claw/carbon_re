// Used later on, not sure where this would be placed:
enum eMenuSoundTriggers // TODO: Taken straight from ProStreet - may not match Carbon perfectly.
{
	UISND_NONE = -1,
	UISND_COMMON_UP = 0,
	UISND_COMMON_DOWN = 1,
	UISND_COMMON_SELECT = 2,
	UISND_COMMON_BACK = 3,
	UISND_COMMON_LEFT_AND_RIGHT = 4,
	UISND_COMMON_WRONG = 5,
	UISND_COMMON_TRIGGER_LEFT = 6,
	UISND_COMMON_TRIGGER_RIGHT = 7,
	UISND_COMMON_DLGBOX_APPEAR = 8,
	UISND_COMMON_DLGBOX_DISAPPEAR = 9,
	UISND_COMMON_DLGBOX_DOWN = 10,
	UISND_COMMON_DLGBOX_LEFT = 11,
	UISND_COMMON_DLGBOX_RIGHT = 12,
	UISND_COMMON_DLGBOX_UP = 13,
	UISND_ENTER_TRIGGER = 24,
	UISND_COMMON_ExpandingTree_Left_BASIC = 31,
	UISND_COMMON_ExpandingTree_Left_P0 = 32,
	UISND_COMMON_ExpandingTree_Left_P1 = 33,
	UISND_COMMON_ExpandingTree_Left_P2 = 34,
	UISND_COMMON_ExpandingTree_Left_P3 = 35,
	UISND_COMMON_ExpandingTree_Left_P4 = 36,
	UISND_COMMON_ExpandingTree_Left_P5 = 37,
	UISND_COMMON_ExpandingTree_Left_P6 = 38,
	UISND_COMMON_ExpandingTree_Left_P7 = 39,
	UISND_COMMON_ExpandingTree_Left_P8 = 40,
	UISND_COMMON_ExpandingTree_Left_P9 = 41,
	UISND_COMMON_ExpandingTree_Right_BASIC = 42,
	UISND_COMMON_ExpandingTree_Right_P0 = 43,
	UISND_COMMON_ExpandingTree_Right_P1 = 44,
	UISND_COMMON_ExpandingTree_Right_P2 = 45,
	UISND_COMMON_ExpandingTree_Right_P3 = 46,
	UISND_COMMON_ExpandingTree_Right_P4 = 47,
	UISND_COMMON_ExpandingTree_Right_P5 = 48,
	UISND_COMMON_ExpandingTree_Right_P6 = 49,
	UISND_COMMON_ExpandingTree_Right_P7 = 50,
	UISND_COMMON_ExpandingTree_Right_P8 = 51,
	UISND_COMMON_ExpandingTree_Right_P9 = 52,
	UISND_COMMON_e3_Transition = 73,
	UISND_COMMON_e3_Move_Left = 74,
	UISND_COMMON_LIGHT_TREE_TICK = 76,
	UISND_COMMON_LIGHT_TREE_GO = 77,
	UISND_COMMON_OPTION_SLIDER_TICK = 78,
	UISND_HUD_RACE_COMPLETE_IN = 79,
	UISND_HUD_COUNTDOWN = 80,
	UISND_HUD_COUNTDOWN_GO = 83,
	UISND_HUD_MATCHUP_TEXT_IN = 84,
	UISND_HUD_MATCHUP_TEXT_OUT = 85,
	UISND_HUD_STUTTER_TEXT_OVERLAY_IN = 86,
	UISND_HUD_STUTTER_TEXT_OVERLAY_OUT = 87,
	UISND_HUD_BURNOUT_RATING_IN = 88,
	UISND_HUD_BURNOUT_RATING_OUT = 89,
	UISND_HUD_DRAG_COUNTDOWN = 92,
	UISND_HUD_DRAG_COUNTDOWN_GO = 93,
	UISND_COMMON_CHYRON_IN = 94,
	UISND_COMMON_CHYRON_OUT = 95,
	UISND_COMMON_CHYRON_NOTIFICATION = 96,
	UISND_HUD_COUNTDOWN_1 = 97,
	UISND_HUD_COUNTDOWN_2 = 98,
	UISND_HUD_COUNTDOWN_3 = 99,
	UISND_COMMON_MUSIC_CHYRON_IN = 100,
	UISND_COMMON_MUSIC_CHYRON_OUT = 101,
	UISND_COMMON_LARGE_MENU_IN = 102,
	UISND_COMMON_LARGE_MENU_OUT = 103,
	UISND_COMMON_PAUSE_MENU_IN = 104,
	UISND_COMMON_PAUSE_MENU_OUT = 105,
	UISND_COMMON_YOU_WON = 106,
	UISND_COMMON_EXP_TREE_DRAW = 107,
	UISND_COMMON_UNLOCK = 108,
	UISND_POINTS_TALLY_SLIDE = 109,
	UISND_POINTS_TALLY_SCORE = 110,
	UISND_POINTS_TALLY_CASH = 111,
	UISND_COMMON_SWIRLING_INTRO = 112,
	UISND_COMMON_MAX_NUM = 199,
	UISND_MAIN_UP_AND_DOWN = 200,
	UISND_MAIN_LEFT_AND_RIGHT = 201,
	UISND_MAIN_SCROLL_LEFT = 202,
	UISND_MAIN_SCROLL_RIGHT = 203,
	UISND_MAIN_SELECT = 204,
	UISND_MAIN_BACK = 205,
	UISND_MAIN_WRONG = 207,
	UISND_MAIN_TRANSITION_IN = 208,
	UISND_MAIN_TRANSITION_OUT = 209,
	UISND_MAIN_DLGBOX_IN = 210,
	UISND_MAIN_DLGBOX_OUT = 211,
	UISND_UGNEW_KBTYPE = 224,
	UISND_UGNEW_ENTER = 225,
	UISND_UGNEW_DELETE = 226,
	UISND_MAIN_END_OF_LIST = 228,
	UISND_MAIN_KBCURSOR_UPDOWN = 230,
	UISND_MAIN_KBCURSOR_LEFTRIGHT = 231,
	UISND_MAIN_TRANSITION_ANIMATION_1 = 232,
	UISND_MAIN_TRANSITION_ANIMATION_2 = 233,
	UISND_MAIN_TRANSITION_ANIMATION_3 = 234,
	UISND_MAIN_TRANSITION_ANIMATION_4 = 235,
	UISND_MAIN_TRANSITION_ANIMATION_5 = 236,
	UISND_MAIN_TRANSITION_ANIMATION_6 = 237,
	UISND_MAIN_TRANSITION_ANIMATION_7 = 238,
	UISND_MAIN_TRANSITION_ANIMATION_8 = 239,
	UISND_MAIN_TRANSITION_ANIMATION_9 = 240,
	UISND_MAIN_CUST_INST_PAINT = 306,
	UISND_MAIN_CUST_PAINT_COLOUR_LEFT = 307,
	UISND_MAIN_CUST_PAINT_COLOUR_RIGHT = 308,
	UISND_MAIN_CUST_PAINT_COLOUR_UP = 309,
	UISND_MAIN_CUST_PAINT_COLOUR_DOWN = 310,
	UISND_MAIN_CUST_VINYL_INSTALL = 311,
	UISND_CUST_INST_EXHAUST = 316,
	UISND_CUST_INST_GENERIC = 317,
	UISND_CUST_INST_TURBO = 318,
	UISND_CUST_INST_NOS = 319,
	UISND_CUST_INST_TRANSMISSION = 320,
	UISND_CUST_INST_TIRES = 321,
	UISND_EA_MSGR_OPEN = 322,
	UISND_EA_MSGR_LOGOFF = 323,
	UISND_EA_MSGR_CHAT_REQ = 324,
	UISND_EA_MSGR_MAIL_RECEIVE = 325,
	UISND_EA_MSGR_CHALLENGE_REQ = 326,
	UISND_MAIN_MENU_ENTER = 346,
	UISND_MAIN_MENU_EXIT = 347,
	UISND_MAIN_SUB_ENTER = 348,
	UISND_MAIN_SUB_EXIT = 349,
	UISND_MAIN_MAP_AREA_SELECT = 350,
	UISND_MAIN_MAP_MENU_APPEAR = 351,
	UISND_MAIN_MAP_MENU_DISAPPEAR = 352,
	UISND_MAIN_MAP_MENU_NAV_UP = 353,
	UISND_MAIN_MAP_MENU_NAV_DOWN = 354,
	UISND_MAIN_MAP_MENU_NAV_LEFT = 355,
	UISND_MAIN_MAP_MENU_NAV_RIGHT = 356,
	UISND_MAIN_MAP_ZOOM_IN = 357,
	UISND_MAIN_MAP_ZOOM_OUT = 358,
	UISND_MAIN_KEYBOARD_ACCEPT = 359,
	UISND_MAIN_KEYBOARD_BACK = 360,
	UISND_MAIN_KEYBOARD_NAV = 361,
	UISND_MAIN_KEYBOARD_SELECT = 362,
	UISND_MAIN_MAP_MENU_NAV_LEFTRIGHT = 363,
	UISND_MAIN_MAP_MENU_NAV_UPDOWN = 364,
	UISND_MAIN_FEICECAM_CAM1 = 368,
	UISND_MAIN_FEICECAM_CAM1BCK = 369,
	UISND_MAIN_FEICECAM_CAM2 = 370,
	UISND_MAIN_FEICECAM_CAM2BCK = 371,
	UISND_MAIN_FEICECAM_CAM3 = 372,
	UISND_MAIN_FEICECAM_CAM3BCK = 373,
	UISND_MAIN_FEICECAM_CAM4 = 374,
	UISND_MAIN_FEICECAM_CAM4BCK = 375,
	UISND_MAIN_FEICECAM_CAM5 = 376,
	UISND_MAIN_FEICECAM_CAM5BCK = 377,
	UISND_MAIN_FEICECAM_CAM6 = 378,
	UISND_MAIN_FEICECAM_CAM6BCK = 379,
	UISND_MAIN_FEICECAM_CAM7 = 380,
	UISND_MAIN_FEICECAM_CAM7BCK = 381,
	UISND_MAIN_FEICECAM_CAM8 = 382,
	UISND_MAIN_FEICECAM_CAM8BCK = 383,
	UISND_MAIN_FEICECAM_CAM9 = 384,
	UISND_MAIN_FEICECAM_CAM9BCK = 385,
	UISND_MAIN_FEICECAM_CAM10 = 386,
	UISND_MAIN_FEICECAM_CAM10BCK = 387,
	UISND_FRONTEND_MAX_NUM = 399,
	UISND_COMMON_DRIFT_NICE = 400,
	UISND_COMMON_DRIFT_GOOD = 400,
	UISND_COMMON_DRIFT_AWESOME = 401,
	UISND_COMMON_DRIFT_AMAZING = 401,
	UISND_COMMON_DRIFT_GREAT = 401,
	UISND_COMMON_DRIFT_OUTRAGEOUS = 402,
	UISND_COMMON_DRIFT_MULTIPLIER = 403,
	UISND_COMMON_DRIFT_DRIFT_ENDED = 404,
	UISND_COMMON_DRIFT_PERFECT_ENTRY = 405,
	UISND_DRIFT_MAX_NUM = 420
};


// FEStateManager
enum FEStateManager::ePadButton
{
	BUTTON_0 = 0,
	BUTTON_1 = 1,
	BUTTON_2 = 2,
	BUTTON_3 = 3,
	BUTTON_4 = 4,
	BUTTON_5 = 5,
	BUTTON_6 = 6,
	BUTTON_7 = 7,
	BUTTON_8 = 8,
	BUTTON_9 = 9,
	PAD_LTRIGGER = 10,
	PAD_RTRIGGER = 11,
	PAD_ACCEPT = 12,
	PAD_START = 13,
	PAD_BUTTON_PRESSED = 14,
	PAD_BUTTON_UNDEFINED = 15,
};

enum FEStateManager::eGlobalStates
{
	FESTATE_MANAGER_PUSHED_TO_TOP = 0xFFFFFFFF,
};

enum FEStateManager::eSubStates
{
	FESUBSTATE_INVALID = 0xFFFFFFFF,
	FESUBSTATE_NONE = 0,
	FESUBSTATE_SWITCHING_DIALOG = 1,
	FESUBSTATE_EXIT_ALL = 2,
	FESUBSTATE_EXITING = 3,
};

struct FEStateManager_vtbl
{
	void* __codewarrior_dummy[2];
	void (*dtor)(FEStateManager* this, short should_delete);
	
	eMenuSoundTriggers (*OnNotifySound)(FEStateManager* this, unsigned int msg, eMenuSoundTriggers currrentUISND);
	void (*OnPadButton)(FEStateManager* this, FEStateManager::ePadButton button);
	void (*OnPadButtonRelease)(FEStateManager* this, FEStateManager::ePadButton button);
	void (*OnScreenTick)(FEStateManager* this);
	void (*SetCanSkipMovie)(FEStateManager* this, bool);
	bool (*GetCanSkipMovie)(FEStateManager* this);
	
#ifdef MILESTONE // Juice builds - you can build Milestone without Juice (see Undercover Wii), but this is close enough.
	int (*JUICE_GetMaxStates)(FEStateManager* this);
#endif
	
	void (*Start)(FEStateManager* this); // TODO: Set to NULL, Probably a purecall?
	void (*SetInitialOption)(FEStateManager* this, MenuScreen* pScreen);
	void (*HandleAutosave)(FEStateManager* this);
	void (*HandleButtonPressed)(FEStateManager* this, unsigned int nameHash); // DECOMP NOTE: `option` is used in ProStreet, however, OnButtonPressed (which calls this), takes in `nameHash` and just passes it in without doing anything to it.
	void (*HandleButtonHighlight)(FEStateManager* this, unsigned int nameHash);
	void (*HandleChildFlowStart)(FEStateManager* this);
	void (*HandleChildFlowDone)(FEStateManager* this, int exitPoint);
	void (*HandleEasterEggActivated)(FEStateManager* this, int egg);
	void (*HandleEnterComplete)(FEStateManager* this);
	void (*HandleEvent)(FEStateManager* this, int eventId);
	void (*HandleExitAll)(FEStateManager* this);
	void (*HandleExitComplete)(FEStateManager* this);
	void (*HandleFlowDone)(FEStateManager* this);
	bool (*HandleIsGameMode)(FEStateManager* this, int gameMode);
	void (*HandleMouseChanged)(FEStateManager* this);
	void (*HandleMouseWheelDown)(FEStateManager* this);
	void (*HandleMouseWheelUp)(FEStateManager* this);
	void (*HandleMovieComplete)(FEStateManager* this);
	void (*HandleMovieStarted)(FEStateManager* this);
	eMenuSoundTriggers (*HandleNotifySound)(FEStateManager* this, unsigned int msg, eMenuSoundTriggers currentUISND);
	void (*HandleOnlineDisconnect)(FEStateManager* this);
	void (*HandleOptionHighlighted)(FEStateManager* this, unsigned int option);
	void (*HandleOptionSelected)(FEStateManager* this, unsigned int option, FEStateManager::ePadButton button);
	void (*HandlePadAccept)(FEStateManager* this);
	void (*HandlePadBack)(FEStateManager* this);
	void (*HandlePadDown)(FEStateManager* this);
	void (*HandlePadButton0)(FEStateManager* this);
	void (*HandlePadButton1)(FEStateManager* this);
	void (*HandlePadButton2)(FEStateManager* this);
	void (*HandlePadButton3)(FEStateManager* this);
	void (*HandlePadButton4)(FEStateManager* this);
	void (*HandlePadButton5)(FEStateManager* this);
	void (*HandlePadButton6)(FEStateManager* this);
	void (*HandlePadButton7)(FEStateManager* this);
	void (*HandlePadButton8)(FEStateManager* this);
	void (*HandlePadButton9)(FEStateManager* this);
	void (*HandlePadButton0Release)(FEStateManager* this);
	void (*HandlePadButton1Release)(FEStateManager* this);
	void (*HandlePadButton2Release)(FEStateManager* this);
	void (*HandlePadButton3Release)(FEStateManager* this);
	void (*HandlePadButton4Release)(FEStateManager* this);
	void (*HandlePadButton5Release)(FEStateManager* this);
	void (*HandlePadButton6Release)(FEStateManager* this);
	void (*HandlePadButton7Release)(FEStateManager* this);
	void (*HandlePadButton8Release)(FEStateManager* this);
	void (*HandlePadButton9Release)(FEStateManager* this);
	void (*HandleLTrigger)(FEStateManager* this);
	void (*HandleLTriggerRelease)(FEStateManager* this);
	void (*HandlePadLeft)(FEStateManager* this, unsigned int nameHash);
	void (*HandlePadUp)(FEStateManager* this);
	void (*HandlePadRight)(FEStateManager* this, unsigned int nameHash);
	void (*HandlePadStart)(FEStateManager* this);
	void (*HandlePadQuit)(FEStateManager* this);
	void (*HandleRefresh)(FEStateManager* this);
	void (*HandleRTrigger)(FEStateManager* this);
	void (*HandleRTriggerRelease)(FEStateManager* this);
	void (*HandleScreenConstructed)(FEStateManager* this);
	void (*HandleScreenDestructed)(FEStateManager* this);
	void (*HandleScreenTick)(FEStateManager* this);
	void (*HandleScreenTimeout)(FEStateManager* this);
	void (*HandleShowDialog)(FEStateManager* this);
	void (*HandleSignInComplete)(FEStateManager* this);
	void (*HandleStateChange)(FEStateManager* this);
	void (*HandleWidgetValueChanged)(FEStateManager* this, unsigned int desc, unsigned int data);
};

struct FEStateManager
{
	FEStateManager_vtbl* __vftable;
	int mCurState;
	int mEntryPoint;
	int mExitPoint;
	int mNextState;
	int mPrevState;
	int mSubState;
	char mLastScreenPushed[128];
	char* mNextScreen;
	bool mNextStateValid;
	bool mExitingAllStateManagers;
	int mNumScreensPushed;
	int mNumScreensToPop;
	FEStateManager* mParentManager;
	FEStateManager* mChildManager;
	FEStateManager* mNextManager;
	bTList<FEStateOption> mStateOptions;
	bool mCanSkipMovie;
};

// FEBootFlowStateManager
enum FEBootFlowStateManager::eEntryPoint
{
	ENTRY_MAIN = 0x0,
	ENTRY_ATTRACT = 0x1,
};

enum FEBootFlowStateManager::eExitPoint
{
	EXIT_NORMAL = 0x0,
	EXIT_TIMEOUT = 0x1,
	NUM_EXIT_POINTS = 0x2,
};

enum FEBootFlowStateManager::eFEBootFlowState
{
	// TODO: ALTER THIS TO MATCH CARBON
	STATE_TERMINAL_STATE = -1, // match
	STATE_ATTRACT = 0,
	STATE_AUTOLOAD = 1,
	STATE_BACKDROP = 2, // match
	STATE_BOOTCHECK = 3, // match
	STATE_CONTROLLER_CHECK = 4, // match
	STATE_EA_LOGO = 5, // match
	STATE_HI_DEF = 6, // match
	STATE_ENABLE_HOME_MENU = 7, // match
	STATE_LANGUAGE_SELECT = 8, // match
	STATE_PSA = 9, // match
	STATE_SPLASH = 10, // match
	STATE_NUM_MAIN_STATES = 11,
	
	STATE_DO_AUTOLOAD = 12,
	STATE_DO_BACKDROP = 13,
	STATE_DO_BOOTCHECK = 14, // match
	STATE_DO_CONTROLLER_CHECK = 15, // match
	STATE_DO_LANGUAGE_SELECT = 16, // match
	STATE_DO_SPLASH = 17, // match
	STATE_POP_BACKDROP = 18,
	STATE_SHOWING_SCREEN = 19,
	STATE_PLAYING_ATTRACT = 20,
	STATE_PLAYING_EA_LOGO = 21,
	STATE_PLAYING_HI_DEF = 22,
	STATE_PLAYING_MOVIE = 23,
	STATE_NUM_TOTAL_STATES = 24,
	
};

struct FEBootFlowState_vtbl
{
	void* __codewarrior_dummy[2];
	void (*dtor)(FEBootFlowState* this, short should_delete);
};

struct FEBootFlowState : bTNode<FEBootFlowState>
{
	FEBootFlowState_vtbl* __vftable;
	int mState;
};

struct FEBootFlowStateManager_vtbl // I don't think we can use inheritance here?
{
	#if 1 // so we can collapse it
	void* __codewarrior_dummy[2];
	void (*dtor)(FEBootFlowStateManager* this, short should_delete);
	
	eMenuSoundTriggers (*OnNotifySound)(FEBootFlowStateManager* this, unsigned int msg, eMenuSoundTriggers currrentUISND);
	void (*OnPadButton)(FEBootFlowStateManager* this, FEStateManager::ePadButton button);
	void (*OnPadButtonRelease)(FEBootFlowStateManager* this, FEStateManager::ePadButton button);
	void (*OnScreenTick)(FEBootFlowStateManager* this);
	void (*SetCanSkipMovie)(FEBootFlowStateManager* this, bool);
	bool (*GetCanSkipMovie)(FEBootFlowStateManager* this);
	
#ifdef MILESTONE // Juice builds - you can build Milestone without Juice (see Undercover Wii), but this is close enough.
	int (*JUICE_GetMaxStates)(FEBootFlowStateManager* this);
#endif
	
	void (*Start)(FEBootFlowStateManager* this); // TODO: Set to NULL, Probably a purecall?
	void (*SetInitialOption)(FEBootFlowStateManager* this, MenuScreen* pScreen);
	void (*HandleAutosave)(FEBootFlowStateManager* this);
	void (*HandleButtonPressed)(FEBootFlowStateManager* this, unsigned int nameHash); // DECOMP NOTE: `option` is used in ProStreet, however, OnButtonPressed (which calls this), takes in `nameHash` and just passes it in without doing anything to it.
	void (*HandleButtonHighlight)(FEBootFlowStateManager* this, unsigned int nameHash);
	void (*HandleChildFlowStart)(FEBootFlowStateManager* this);
	void (*HandleChildFlowDone)(FEBootFlowStateManager* this, int exitPoint);
	void (*HandleEasterEggActivated)(FEBootFlowStateManager* this, int egg);
	void (*HandleEnterComplete)(FEBootFlowStateManager* this);
	void (*HandleEvent)(FEBootFlowStateManager* this, int eventId);
	void (*HandleExitAll)(FEBootFlowStateManager* this);
	void (*HandleExitComplete)(FEBootFlowStateManager* this);
	void (*HandleFlowDone)(FEBootFlowStateManager* this);
	bool (*HandleIsGameMode)(FEBootFlowStateManager* this, int gameMode);
	void (*HandleMouseChanged)(FEBootFlowStateManager* this);
	void (*HandleMouseWheelDown)(FEBootFlowStateManager* this);
	void (*HandleMouseWheelUp)(FEBootFlowStateManager* this);
	void (*HandleMovieComplete)(FEBootFlowStateManager* this);
	void (*HandleMovieStarted)(FEBootFlowStateManager* this);
	eMenuSoundTriggers (*HandleNotifySound)(FEBootFlowStateManager* this, unsigned int msg, eMenuSoundTriggers currentUISND);
	void (*HandleOnlineDisconnect)(FEBootFlowStateManager* this);
	void (*HandleOptionHighlighted)(FEBootFlowStateManager* this, unsigned int option);
	void (*HandleOptionSelected)(FEBootFlowStateManager* this, unsigned int option, FEStateManager::ePadButton button);
	void (*HandlePadAccept)(FEBootFlowStateManager* this);
	void (*HandlePadBack)(FEBootFlowStateManager* this);
	void (*HandlePadDown)(FEBootFlowStateManager* this);
	void (*HandlePadButton0)(FEBootFlowStateManager* this);
	void (*HandlePadButton1)(FEBootFlowStateManager* this);
	void (*HandlePadButton2)(FEBootFlowStateManager* this);
	void (*HandlePadButton3)(FEBootFlowStateManager* this);
	void (*HandlePadButton4)(FEBootFlowStateManager* this);
	void (*HandlePadButton5)(FEBootFlowStateManager* this);
	void (*HandlePadButton6)(FEBootFlowStateManager* this);
	void (*HandlePadButton7)(FEBootFlowStateManager* this);
	void (*HandlePadButton8)(FEBootFlowStateManager* this);
	void (*HandlePadButton9)(FEBootFlowStateManager* this);
	void (*HandlePadButton0Release)(FEBootFlowStateManager* this);
	void (*HandlePadButton1Release)(FEBootFlowStateManager* this);
	void (*HandlePadButton2Release)(FEBootFlowStateManager* this);
	void (*HandlePadButton3Release)(FEBootFlowStateManager* this);
	void (*HandlePadButton4Release)(FEBootFlowStateManager* this);
	void (*HandlePadButton5Release)(FEBootFlowStateManager* this);
	void (*HandlePadButton6Release)(FEBootFlowStateManager* this);
	void (*HandlePadButton7Release)(FEBootFlowStateManager* this);
	void (*HandlePadButton8Release)(FEBootFlowStateManager* this);
	void (*HandlePadButton9Release)(FEBootFlowStateManager* this);
	void (*HandleLTrigger)(FEBootFlowStateManager* this);
	void (*HandleLTriggerRelease)(FEBootFlowStateManager* this);
	void (*HandlePadLeft)(FEBootFlowStateManager* this, unsigned int nameHash);
	void (*HandlePadUp)(FEBootFlowStateManager* this);
	void (*HandlePadRight)(FEBootFlowStateManager* this, unsigned int nameHash);
	void (*HandlePadStart)(FEBootFlowStateManager* this);
	void (*HandlePadQuit)(FEBootFlowStateManager* this);
	void (*HandleRefresh)(FEBootFlowStateManager* this);
	void (*HandleRTrigger)(FEBootFlowStateManager* this);
	void (*HandleRTriggerRelease)(FEBootFlowStateManager* this);
	void (*HandleScreenConstructed)(FEBootFlowStateManager* this);
	void (*HandleScreenDestructed)(FEBootFlowStateManager* this);
	void (*HandleScreenTick)(FEBootFlowStateManager* this);
	void (*HandleScreenTimeout)(FEBootFlowStateManager* this);
	void (*HandleShowDialog)(FEBootFlowStateManager* this);
	void (*HandleSignInComplete)(FEBootFlowStateManager* this);
	void (*HandleStateChange)(FEBootFlowStateManager* this);
	void (*HandleWidgetValueChanged)(FEBootFlowStateManager* this, unsigned int desc, unsigned int data);
	#endif
	
	// New things begin here! For now, they are dummies!
	void (*AddState)(FEBootFlowStateManager* this, int lnState);
	/*HACK WARNING*/ int32_t (*CalculateLastJoyEventTime)(FEBootFlowStateManager* this); // protected: virtual class Timer __cdecl FEBootFlowStateManager::CalculateLastJoyEventTime(void)
	int (*CheckForScreenTimeout)(FEBootFlowStateManager* this);
	int (*DoControllerCheck)(FEBootFlowStateManager* this);
	FEBootFlowState* (*FindAttractNode)(FEBootFlowStateManager* this);
	float (*GetScreenTimeoutValue)(FEBootFlowStateManager* this);
	void (*JumpToAttract)(FEBootFlowStateManager* this);
	void (*PopToNextState)(FEBootFlowStateManager* this);
	void (*GotoNextState)(FEBootFlowStateManager* this);
	void (*ShowBackdrop)(FEBootFlowStateManager* this);
	void (*InitStateList)(FEBootFlowStateManager* this); // purecall
};

struct FEBootFlowStateManager : FEStateManager
{
	Timer mTimer;
	bTList<FEBootFlowState> mStateList;
	FEBootFlowState* mpAttractStateNode;
	FEBootFlowState* mpCurStateNode;
	bool mBootCheckFailed;
};

enum WiiBootFlowStateManager::eFEBootFlowState // We can't inherit enums, but anyway.
{
	STATE_WII_CONTROLLER_SAFETY = 24, // shows a message about the wii strap
	STATE_WII_CONTROLS_WARNING = 25, // shows "the nunchuk is needed to play this title" warning
	
	STATE_NUM_TOTAL_STATES = 26, // guess
}

struct WiiBootFlowStateManager : FEBootFlowStateManager
{
	bool mbPlayingMovie; // DECOMP NOTE: guessed
};

// FEManager  - TODO FIX FOR CARBON
enum eGarageType
{
	GARAGETYPE_NONE = 0,
	GARAGETYPE_MAIN_FE = 1,
	GARAGETYPE_CAREER_SAFEHOUSE = 2,
	GARAGETYPE_CUSTOMIZATION_SHOP = 3,
	GARAGETYPE_CUSTOMIZATION_SHOP_BACKROOM = 4,
	GARAGETYPE_CAR_LOT = 4,
};


enum FEManager::eFEEntryPoints
{
	FEENTRY_NONE = 0x0,
	FEENTRY_BOOTFLOW = 0x1, // match
	FEENTRY_DEBUG_CAR_CUSTOMIZE = 0x2,
	FEENTRY_MAIN_MENU = 0x3, // match
	FEENTRY_MAZDA = 0x4,
	FEENTRY_CAR_CLASS_SELECT = 0x5, // Match
	FEENTRY_CAR_LOT = 0x6, // Match
	FEENTRY_QUICKRACE = 0x7,
	FEENTRY_CAREER_MAIN = 0x8, // Seems to match
	FEENTRY_CAREER_MANAGER = 0x9,
	FEENTRY_CAREER_CAR_SELECT = 0xA,
	FEENTRY_CAREER_BUSTED = 0xB,
	FEENTRY_CAREER_NEW_WINGMAN = 0xC, // Match
	FEENTRY_CAREER_NEW_WINGMAN_JUST_MOVIE = 0xD,
	FEENTRY_CAREER_CREW_TUTORIAL = 0xE,
	FEENTRY_BOSS_DEFEATED = 0xF, // Match
	FEENTRY_WORLD_MAP = 0x10,
	FEENTRY_CHALLENGE_SERIES = 0x11,
	FEENTRY_GAME_ROOM = 0x12,
	FEENTRY_CUSTOMMATCH_JOIN = 0x13,
	FEENTRY_POSTRACE_JOIN = 0x14,
	FEENTRY_WINGMAN_SELECT_FROM_INGAME = 0x15,
	FEENTRY_GAME_WON = 0x16, // Match
	FEENTRY_GAME_OVER = 0x17,
	
	// TODO: All of these are probably ProStreet only.
	FEENTRY_HUB = 0x18,
	FEENTRY_HUBMAP = 0x19,
	FEENTRY_HUBMAP_RACE_DAY = 0x1A,
	FEENTRY_HUBMAP_CAR_SELECT = 0x1B,
	FEENTRY_HUBMAP_KING_INTRO = 0x1C,
	FEENTRY_HUBMAP_KING_PROGESS = 0x1D,
	FEENTRY_HUBMAP_KING_DEFEATED = 0x1E,
	FEENTRY_HUBMAP_KING_INTRO_SPEED = 0x1F,
	FEENTRY_HUBMAP_KING_INTRO_DRIFT = 0x20,
	FEENTRY_HUBMAP_KING_INTRO_DRAG = 0x21,
	FEENTRY_HUBMAP_KING_INTRO_GRIP = 0x22,
};

enum FEManager::ePauseReason
{
	PAUSE_MENU = 0x0,
	CONFIRM_SAFEHOUSE = 0x1,
	CONFIRM_CARLOT = 0x2,
	POSTRACE_MENU = 0x3,
	POSTHEAT_MENU = 0x4,
	POSTEVENT_MENU = 0x5,
	PURSUIT_EVADE_MENU = 0x6,
	WORLD_MAP = 0x7,
	SHOW_SMS_MAILBOX = 0x8,
	SHOW_SMS_MESSAGE = 0x9,
	PLAY_MOVIE = 0xA,
	AUTOSAVE_ERROR = 0xB,
};

enum FEManager::eFERichPresence
{
	MAIN = 0x0,
	CAR_CUSTOMIZATION = 0x1, // Used only by My Cars
	// The following entries were guessed by me!
	CAREER = 0x2,
	CHALLENGE_SERIES = 0x3,
	QUICK_RACE = 0x4,
	// More?
};

enum FEManager::eFEEvents
{
	FEEVENT_GARAGE_CAR_LOADED = 0x0,
	FEEVENT_CHAT_BUTTON_PRESSED = 0x1,
	FEEVENT_ANIMATION_DONE = 0x2,
	FEEVENT_CONTROLLER_ERROR_CLEARED = 0x3,
};


enum FEManager::eFELoadingDirection 
{
	// TODO: Probably incorrect...
	LS_LOADING_NONE = 0,
	LS_LOADING_HUB_FROM_FE = 1,
	LS_LOADING_FE_FROM_HUB = 2,
	LS_LOADING_EVENT_FROM_HUB = 3,
	LS_LOADING_HUB_FROM_EVENT = 4,
	LS_LOADING_DDAY = 5
};

enum FEManager::eFEManagerState
{
	FESTATE_AUTOSAVE = 0,
	FESTATE_BOOTFLOW = 1,
	FESTATE_DEBUG_CAR_CUSTOMIZE = 2,
	FESTATE_MAIN_MENU = 3,
	FESTATE_HUB = 4,
	FESTATE_WAITING_FOR_HUB = 5,
	FESTATE_PAUSE = 6,
	FESTATE_CONFIRMSAFEHOUSE = 7,
	FESTATE_CONFIRMCARLOT = 8,
	FESTATE_POSTRACE = 9,
	FESTATE_SERIESPOSTRACE = 10,
	FESTATE_PRERACE = 11,
	FESTATE_SPECTATOR = 12,
	FESTATE_SMS = 13,
	FESTATE_MOVIE = 14,
	FESTATE_CAREERMAP = 15,
	FESTATE_GAMEROOM = 16,
	FESTATE_INVITE_GAMEROOM = 17,
	FESTATE_TUTORIAL = 18,
	FESTATE_LOADING_MAIN = 19,
	FESTATE_CRASHFLOW = 20,
	FESTATE_ICE_GRADIENT = 21,
	FESTATE_IDLE = 22,
	NUM_STATES = 23
};

struct FEManager : FEStateManager
{
	int mCurrControllingPlayer;
	int mCurrErroringPlayer;
	
	int8_t* mPlayerJoyports;
	int8_t* mLastUsedFeJoyport;
	UserProfile** mUserProfiles; // DECOMP NOTE: Guessed
	
	eGarageType mGarageType;
	eGarageType mPreviousGarageType;
	int mEATraxDelay;
	bool mEATraxFirstButton;
	int mEventHash;
	FEManager::eFELoadingDirection mCurrentLoadingState;
	unsigned int mEventIndex;
	bool mNISIntroFlasherPlaying;
};
