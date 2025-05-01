/*
** $Id: lzio.h,v 1.15 2003/03/20 16:00:56 roberto Exp $
** Buffered streams
** See Copyright Notice in lua.h
*/


#ifndef lzio_h
#define lzio_h

#include "lua.h"


#define EOZ	(-1)			/* end of stream */

typedef struct Zio ZIO;


#define char2int(c)	cast(int, cast(unsigned char, (c)))

#define zgetc(z)  (((z)->n--)>0 ?  char2int(*(z)->p++) : luaZ_fill(z))

#define zname(z)	((z)->name)

void luaZ_init (ZIO *z, lua_Chunkreader reader, void *data, const char *name);
lua_size_t luaZ_read (ZIO* z, void* b, lua_size_t n);	/* read next n bytes */
int luaZ_lookahead (ZIO *z);



typedef struct Mbuffer {
  char *buffer;
  lua_size_t buffsize;
} Mbuffer;


char *luaZ_openspace (lua_State *L, Mbuffer *buff, lua_size_t n);

#define luaZ_initbuffer(L, buff) ((buff)->buffer = NULL, (buff)->buffsize = 0)

#define luaZ_sizebuffer(buff)	((buff)->buffsize)
#define luaZ_buffer(buff)	((buff)->buffer)

#define luaZ_resizebuffer(L, buff, size) \
	(luaM_reallocvector(L, (buff)->buffer, (buff)->buffsize, size, char), \
	(buff)->buffsize = size)

#define luaZ_freebuffer(L, buff)	luaZ_resizebuffer(L, buff, 0)


/* --------- Private Part ------------------ */

struct Zio {
  lua_size_t n;			/* bytes still unread */
  const char *p;		/* current position in buffer */
  lua_Chunkreader reader;
  void* data;			/* additional data */
  const char *name;
};


int luaZ_fill (ZIO *z);

#endif
