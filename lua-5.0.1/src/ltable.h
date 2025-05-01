/*
** $Id: ltable.h,v 1.44 2003/03/18 12:50:04 roberto Exp $
** Lua tables (hash)
** See Copyright Notice in lua.h
*/

#ifndef ltable_h
#define ltable_h

#include "lobject.h"


#define gnode(t,i)	(&(t)->node[i])
#define gkey(n)		(&(n)->i_key)
#define gval(n)		(&(n)->i_val)


const TObject *luaH_getnum (LuaTable *t, int key);
TObject *luaH_setnum (lua_State *L, LuaTable *t, int key);
const TObject *luaH_getstr (LuaTable *t, TString *key);
const TObject *luaH_get (LuaTable *t, const TObject *key);
TObject *luaH_set (lua_State *L, LuaTable *t, const TObject *key);
LuaTable *luaH_new (lua_State *L, int narray, int lnhash);
void luaH_free (lua_State *L, LuaTable *t);
int luaH_next (lua_State *L, LuaTable *t, StkId key);

/* exported only for debugging */
Node *luaH_mainposition (const LuaTable *t, const TObject *key);


#endif
