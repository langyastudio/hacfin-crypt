#include "stdafx.h"
#include "HkfyCryptAPI.h"
#include "Ci_HkfyCrypt.h"


//Ansi�ַ���תUnicode�ַ���
wchar_t* Ansi2Unicode(const char* szAnsi)  
{  
	if (NULL == szAnsi)
	{
		return(NULL);
	}

	// Ԥת�����õ�����ռ�Ĵ�С      
	int wcsLen = ::MultiByteToWideChar(CP_ACP, NULL, szAnsi, strlen(szAnsi), NULL, 0);  
	
	// ����ռ�Ҫ��'/0'�����ռ䣬MultiByteToWideChar�����'/0'�ռ�      
	wchar_t* wszString = new wchar_t[wcsLen+1];  
	
	::MultiByteToWideChar(CP_ACP, NULL, szAnsi, strlen(szAnsi), wszString, wcsLen);   
	
	// �����Ͻ�����'/0'      
	wszString[wcsLen] = '\0\0';  
	return wszString;  
}  

//Unicode�ַ���תAnsi�ַ���
char* Unicode2Ansi(const wchar_t* wszString)  
{  
	if (NULL == wszString)
	{
		return(NULL);
	}

	int ansiLen = ::WideCharToMultiByte(CP_ACP, NULL, wszString, wcslen(wszString), NULL, 0, NULL, NULL);  
	char* szAnsi = new char[ansiLen + 1];   
	
	// Unicode���Ӧ��strlen��wcslen   
	::WideCharToMultiByte(CP_ACP, NULL, wszString, wcslen(wszString), szAnsi, ansiLen, NULL, NULL);   
	
	// ������'/0'   
	szAnsi[ansiLen] = '\0';  
	return szAnsi;  
}  

HKFYCRYPT_EXPORTS_API int MD5_GetFile( TCHAR *pSorFilePath, TCHAR *pSzEncrypt, int len /*=MD5_ENCRYPT_LEN*/)
{
	if (NULL == pSorFilePath)
	{
		return(E_FAIL);
	}

	ifstream ifStr(pSorFilePath);
	Ci_MD5   iMD5(ifStr);
	string   str = iMD5.ToString();
	
	wchar_t* pszWStr =  Ansi2Unicode(str.c_str());
	if (NULL == pszWStr)
	{
		return(E_FAIL);
	}
	memcpy(pSzEncrypt, pszWStr, sizeof(TCHAR)*len);

	//�ͷ��ڴ�
	delete []pszWStr;

	return(S_OK);
}
