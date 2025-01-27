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

