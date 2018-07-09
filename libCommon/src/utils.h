//==========================================================================
//==========================================================================
#ifndef _INC_UTILS_H
#define _INC_UTILS_H

//==========================================================================
//==========================================================================
#include <time.h>
#include <string>

//==========================================================================
//==========================================================================
extern unsigned long GetTick (void);
extern unsigned long TickElapsed (unsigned long aTick);
extern void GenDateString (char *aDest, time_t aTimeStamp, int aDestLen, int aLong = false);
extern void GenDateCode (char *aDest, time_t aTimeStamp, int aDestLen, int aWithTime = false);
extern double AveragingInt (int *aBuf, int *aNewValue, int aBufLen);
extern const char *FileNameOnly (const char *aSrc);
extern int WritePidFile (const char *aName, const char *aPath = NULL);
extern void RemovePidFile (void);
extern bool Cross5Min (time_t aCurrTime, time_t aLastTime);
extern bool Cross1Hour (time_t aCurrTime, time_t aLastTime);
extern unsigned long FromHexString (char *aDest, int aDigit);
extern void ToBinaryString (char *aDest, unsigned long aValue, int aDigit, bool aMsbFirst = true);
extern void StringToLower (char *aSrc);
extern void StringToUpper (char *aSrc);
extern void TrimTail (char *aStr);
extern void Trim (char *aStr);
extern std::string LTrimStdString (std::string str);
extern std::string RTrimStdString (std::string str);
extern std::string TrimStdString (std::string str);

//==========================================================================
//==========================================================================
#endif
