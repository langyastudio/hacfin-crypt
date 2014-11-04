#ifndef _AFXSTD_620892B6_BE7B_449F_BF8F_F7448162389B_INCLUDE_H_
#define _AFXSTD_620892B6_BE7B_449F_BF8F_F7448162389B_INCLUDE_H_

#if _MSC_VER >= 1200
#pragma once
#endif//!_MSC_VER >= 1200

  
//--------------------------------------------------------------------------
//								AES Encrypt
//--------------------------------------------------------------------------
class  CDSA  
{  
public:  
    //! #����ENUM����AES��Կ�ĳ���  
    /*! 
        ��������ENUM����������Կ���ȵ�ѡ�� 
        @see enum ENUM_KeySize_ 
        @attention ��ͬ���ȵ���Կ��Ӧ�ļ��ܵ��ַ������Ȳ�ͬ 
    */  
    typedef enum ENUM_KeySize_  
	{  
		BIT128 = 0,  
        BIT192,  
        BIT256  
    }ENUM_KEYSIZE;  
public:  
    //! #AES�Ĺ��캯��  
    /*! 
      @see AES( ENUM_KEYSIZE keysize, BYTE *key ) 
      @param[ENUM_KEYSIZE] ����Կ���Ƚ��г�ʼ������ 
      @param[BYTE]		   ������Ӧ����Կ 
      ����Ӧ�ö�AES���е�һЩ����������Ӧ�ĳ�ʼ�� 
    */  
    CDSA( ENUM_KEYSIZE keysize, BYTE *key );  
    //! #AES����������  
    /*! 
     @see ~AES(void) 
      �ͷ��ڴ� 
    */  
    ~CDSA(void);  
    //! #AES�㷨�еļ��ܺ���ģ��  
    /*! 
      @see void Cipher( BYTE *input, BYTE *output ); 
      @param[in]  inputΪ��������� 
      @param[out] outputΪ����֮������� 
      @return[void] �������κ�ֵ 
    */  
    void Cipher( BYTE *input, BYTE *output );  
    //! #AES�㷨�еĽ��ܺ���ģ��  
    /*! 
      @see void InvCipher( BYTE *input, BYTE *output ); 
      @param[in]  inputΪ��������� 
      @param[in]  outputΪ����֮������� 
      @return[void] �������κ�ֵ 
    */  
    void InvCipher( BYTE *input, BYTE *output );  

private:  
    BYTE *RotWord( BYTE *word );  
    BYTE *SubWord( BYTE *word );  
    void AddRoundKey(int round);  
    void SubBytes();  
    void InvSubBytes();  
    void ShiftRows();  
    void InvShiftRows();  
    void MixColumns();  
    void InvMixColumns();  
    static BYTE gfmultby01(BYTE b)  //��1  
    {  
        return b;  
    }  
  
    static BYTE gfmultby02(BYTE b) //��2  
    {  
        if (b < 0x80)  
            return (BYTE)(int)(b <<1);  
        else  
            return (BYTE)( (int)(b << 1) ^ (int)(0x1b) );  
    }  
  
    static BYTE gfmultby03(BYTE b)  
    {  
        return (BYTE) ( (int)gfmultby02(b) ^ (int)b );//GF��ļӷ�����������  
    }  
  
    static BYTE gfmultby09(BYTE b)  
    {  
        return (BYTE)( (int)gfmultby02(gfmultby02(gfmultby02(b))) ^  
            (int)b );  
    }  
  
    static BYTE gfmultby0b(BYTE b)  
    {  
        return (BYTE)( (int)gfmultby02(gfmultby02(gfmultby02(b))) ^  
            (int)gfmultby02(b) ^  
            (int)b );  
    }  
  
    static BYTE gfmultby0d(BYTE b)  
    {  
        return (BYTE)( (int)gfmultby02(gfmultby02(gfmultby02(b))) ^  
            (int)gfmultby02(gfmultby02(b)) ^  
            (int)(b) );  
    }  
  
    static BYTE gfmultby0e(BYTE b)  
    {  
        return (BYTE)( (int)gfmultby02(gfmultby02(gfmultby02(b))) ^  
            (int)gfmultby02(gfmultby02(b)) ^  
            (int)gfmultby02(b) );  
    }  

    //! #��������Ϊ��λ�Ŀ鳤  
    /*! 
    @Brief ��������Ϊ��λ�Ŀ鳤 
    */  
    int Nb; //  
    //! #��������Ϊ��λ����Կ����  
    /*! 
    @Brief ��������Ϊ��λ����Կ���� 
    */  
    int Nk;//  
    //! #���� ,������10��12��14�е�����һ�������ǻ����������ѧ���۵�  
    /*! 
    @Brief ���� ,������10��12��14�е�����һ�������ǻ����������ѧ���۵� 
    @attention ��ֱ��ȡ������Կ���� 
    */  
    int Nr;//���� ,������10��12��14�е�����һ�������ǻ����������ѧ���۵ġ�  
    //  
    //! #the seed key  
    /*! 
    @Brief   size will be 4 * keySize from ctor 
    */  
    BYTE *key;//  
    typedef struct BYTE4_  
    {  
        BYTE w[4];  
    }BYTE4;  
    BYTE4 *w;  
    LPBYTE State[4];    
};  


#endif //!_AFXSTD_620892B6_BE7B_449F_BF8F_F7448162389B_INCLUDE_H_
