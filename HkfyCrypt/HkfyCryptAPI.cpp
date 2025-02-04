#include "stdafx.h"
#include "HkfyCryptAPI.h"
#include "Ci_HkfyCrypt.h"

#define  MD5_ENCRYPT_LEN	32+1	//文件的MD5的长度

#pragma warning(once : 4267)

//Ansi字符串转Unicode字符串
wchar_t* Ansi2Unicode(const char* szAnsi)  
{  
	if (NULL == szAnsi)
	{
		return(NULL);
	}

	// 预转换，得到所需空间的大小      
	int wcsLen = ::MultiByteToWideChar(CP_ACP, NULL, szAnsi, strlen(szAnsi), NULL, 0);  
	
	// 分配空间要给'/0'留个空间，MultiByteToWideChar不会给'/0'空间      
	wchar_t* wszString = new wchar_t[wcsLen+1];  
	
	::MultiByteToWideChar(CP_ACP, NULL, szAnsi, strlen(szAnsi), wszString, wcsLen);   
	
	// 最后加上结束符'/0'      
	wszString[wcsLen] = '\0\0';  
	return wszString;  
}  

//Unicode字符串转Ansi字符串
char* Unicode2Ansi(const wchar_t* wszString)  
{  
	if (NULL == wszString)
	{
		return(NULL);
	}

    int ansiLen = ::WideCharToMultiByte(CP_ACP, NULL, wszString, wcslen(wszString), NULL, 0, NULL, NULL);
	char* szAnsi = new char[ansiLen + 1];   
	
	// Unicode版对应的strlen是wcslen   
	::WideCharToMultiByte(CP_ACP, NULL, wszString, wcslen(wszString), szAnsi, ansiLen, NULL, NULL);   
	
	// 最后加上'/0'   
	szAnsi[ansiLen] = '\0';  
	return szAnsi;  
}  

int MD5_GetFile( TCHAR *pSorFilePath, TCHAR *pSzEncrypt, int len /*=MD5_ENCRYPT_LEN*/)
{
	if (NULL == pSorFilePath)
	{
		return(E_FAIL);
	}

	ifstream ifStr(pSorFilePath);
	Ci_RSA   iMD5(ifStr);
	string   str = iMD5.ToString();
	
	wchar_t* pszWStr =  Ansi2Unicode(str.c_str());
	if (NULL == pszWStr)
	{
		return(E_FAIL);
	}
	memcpy(pSzEncrypt, pszWStr, sizeof(TCHAR)*len);

	//释放内存
	delete []pszWStr;

	return(S_OK);
}

//--------------------------------------------------------------------------
//								Sentinel Encrypt
//--------------------------------------------------------------------------
CHKFY::CHKFY()
{
	m_pHKFY = new Ci_HKFY();
}

CHKFY::~CHKFY()
{
	delete m_pHKFY;
}

const char * CHKFY::GetErrorName( int errorCode )
{
	return(m_pHKFY->GetErrorName(errorCode));
}

int CHKFY::LogIn( unsigned long lFeatureId )
{
	return(m_pHKFY->LogIn(lFeatureId));
}

int CHKFY::LogOut()
{
	return(m_pHKFY->LogOut());
}

int CHKFY::CheckRom()
{
	return(m_pHKFY->CheckRom());
}

int CHKFY::CheckRam()
{
	return(m_pHKFY->CheckRam());
}

int  CHKFY::ClearRam()
{
    return(m_pHKFY->ClearRam());
}

int CHKFY::GetPointNum()
{
	return(m_pHKFY->GetPointNum());
}

