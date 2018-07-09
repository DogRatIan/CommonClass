//==========================================================================
//==========================================================================
#ifndef _INC_DEBUG_H
#define _INC_DEBUG_H

//==========================================================================
//==========================================================================
#ifndef DEBUG
#define DEBUG 0
#endif

//==========================================================================
//==========================================================================
#if (DEBUG)

#define DEBUG_INIT()            DebugInit ()
#define DEBUG_EXIT()            DebugExit ()
#define DEBUG_PRINTF(x...)      DebugPrintf (x)
#define DEBUG_HEX2STRING(x,y)   DebugHex2String (x,y)

#else   // #if (DEBUG)

#define DEBUG_INIT()            {}
#define DEBUG_EXIT()            {}
#define DEBUG_PRINTF(x...)      {}
#define DEBUG_HEX2STRING(x,y)   {}

#endif   // #if (DEBUG)


//==========================================================================
//==========================================================================
void DebugInit (void);
void DebugExit (void);
void DebugPrintf (const char *aMsg, ...);
void DebugHex2String (const unsigned char *aSrc, int aLen);

//==========================================================================
//==========================================================================
#endif
