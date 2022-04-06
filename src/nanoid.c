#include <lua.h>     
#include <lauxlib.h> 
#include <lualib.h>  
#include <sys/time.h>

#include "nanoid.h"

#if LUA_VERSION_NUM < 502
#define luaL_newlib(L, l) (lua_newtable(L), luaL_register(L, NULL, l))
#endif

static int l_generate( lua_State *L )
{
    lua_Integer n = lua_tointeger(L, 1);
    char *id = generate(n);
    lua_pushstring(L, id);
    return 1;
}

static int l_simple( lua_State *L )
{
    char *id = simple();
    lua_pushstring(L, id);
    return 1;
}

static int l_safe_simple( lua_State *L )
{
    char *id = safe_simple();
    lua_pushstring(L, id);
    return 1;
}


int luaopen_nanoid( lua_State *L )
{
    static const luaL_Reg nanoid[] = {
        { "generate", l_generate },
        { "simple", l_simple },
        { "safe_simple", l_safe_simple },
        { NULL, NULL } /* Sentinel item */
    };

    luaL_newlib( L, nanoid );
    return 1;
}
