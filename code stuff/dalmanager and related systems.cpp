enum DAL_INTERFACE
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
	DAL_INTERFACE_WORLD_MAP = 9,
	DAL_INTERFACE_PLAYER = 10,
	DAL_INTERFACE_PURSUIT = 11,
	DAL_INTERFACE_REWARDS = 12,
	DAL_INTERFACE_CREW_MEMBER = 13,
	DAL_INTERFACE_STATISTICS = 14,
	DAL_INTERFACE_ONLINE = 15,
	DAL_INTERFACE_CHALLENGE = 16,
	DAL_INTERFACE_TOTAL = 17
};

struct DALInterface_vtbl
{
	void* __codewarrior_dummy[2]; // I don't know why it exists either.
	void* dtor; // Signature is compiler-specific and doesn't really matter.
	
	bool (*IsInterfaceValid)(DALInterface* this, int valueType, int arg1, int arg2, int arg3);
	
	bool (*GetFloat)(DALInterface* this, int valueType, float& getVal, int arg1, int arg2, int arg3);
	bool (*SetFloat)(DALInterface* this, int valueType, float setVal, int arg1, int arg2, int arg3);
	bool (*IncrementFloat)(DALInterface* this, int valueType, float incVal, int arg1, int arg2, int arg3);
	bool (*DecrementFloat)(DALInterface* this, int valueType, float decVal, int arg1, int arg2, int arg3);
	
	bool (*GetInt)(DALInterface* this, int valueType, int& getVal, int arg1, int arg2, int arg3);
	bool (*SetInt)(DALInterface* this, int valueType, int setVal, int arg1, int arg2, int arg3);
	bool (*IncrementInt)(DALInterface* this, int valueType, int incVal, int arg1, int arg2, int arg3);
	bool (*DecrementInt)(DALInterface* this, int valueType, int decVal, int arg1, int arg2, int arg3);
	
	bool (*GetString)(DALInterface* this, int valueType, char* getVal, int getLen, int arg1, int arg2, int arg3);
	bool (*SetString)(DALInterface* this, int valueType, const char* setVal, int setLen, int arg1, int arg2, int arg3);
	
	bool (*GetDefaultInt)(DALInterface* this, int valueType, int& getVal, int arg1, int arg2, int arg3);
	bool (*GetDefaultFloat)(DALInterface* this, int valueType, float& getVal, int arg1, int arg2, int arg3);
};

struct __cppobj DALInterface
{
	DALInterface_vtbl *__vftable /*VFT*/;
	int mInterfaceIndex;
};

struct __cppobj DALManager : DALInterface
{
	DALInterface* mInterfaces[DAL_INTERFACE_TOTAL];
	bool mInited;
};

