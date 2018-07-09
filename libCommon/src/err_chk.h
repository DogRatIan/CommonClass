//==========================================================================
//==========================================================================
#ifndef _INC_ERR_CHK_H
#define _INC_ERR_CHK_H

//==========================================================================
//==========================================================================

//==========================================================================
//==========================================================================
class CErrorCheck
{
  public:
    CErrorCheck (void);
    ~CErrorCheck (void);

    static unsigned char Crc8 (unsigned char aCrc, unsigned char aData);
    static unsigned char Crc8 (unsigned char aCrc, const unsigned char *aData, int aLen);
    static unsigned char Crc8 (unsigned char aCrc, const char *aData);

    static unsigned short Crc16 (unsigned short aCrc, unsigned char aData);
    static unsigned short Crc16 (unsigned short aCrc, const unsigned char *aData, int aLen);
    static unsigned short Crc16 (unsigned short aCrc, const char *aData);

    static unsigned short Crc16Ccitt (unsigned short aCrc, unsigned char aData);
    static unsigned short Crc16Ccitt (unsigned short aCrc, const unsigned char *aData, int aLen);
    static unsigned short Crc16Ccitt (unsigned short aCrc, const char *aData);

    static unsigned long Crc32 (unsigned long aCrc, unsigned char aData);
    static unsigned long Crc32 (unsigned long aCrc, const unsigned char *aData, int aLen);
    static unsigned long Crc32 (unsigned long aCrc, const char *aData);

  private:
};


//==========================================================================
//==========================================================================
#endif
