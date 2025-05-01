// You can get `T` from the mangled name, if it is available.
template <typename T>
static void BindVoidFunction(lua_State* luaState, const char* funcName, T funcptr, const char* tableName);

// TODO: Handle functions that return types
// Possibly the same thing? Not extremely familiar with C++ templates...
// void BindFunction<bool>(lua_State* luaState, const char* funcName, bool (* funcptr)(void), const char* tableName);
