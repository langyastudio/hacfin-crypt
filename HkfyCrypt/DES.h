#ifndef _AFXSTD_3D6ED50C_A0F8_47D5_B238_A63C9BDEC809_INCLUDE_H_
#define _AFXSTD_3D6ED50C_A0F8_47D5_B238_A63C9BDEC809_INCLUDE_H_

#if _MSC_VER >= 1200
#pragma once
#endif//!_MSC_VER >= 1200

#include <bitset>
#include <vector>

using namespace std;


class deskey
{
private:
	static int cp1[];		//�û�����1
	static int cp2[];		//�û�����2
	static int totrot[];	//λ�ƾ���
	vector<string> keys;

public:
	deskey(string const key);
	vector<string> subkeyinit(int flag);
};

class tripledes
{
private:
	static int ip1[];
	static int ip2[];
	static int e[];
	static int p_box[];
	static int s_box[];

public:
	static void loopf(string &input,vector<string> key,bool flag);						//ʵ��des����,flag=1��ʾ���ܣ�flag=0��ʾ����
	static void f(string &input,const string key);										//���ڵ��ּ���
	static string encrypt(string &input,string key,bool flag);							//ʵ��3des����,flag=1��ʾ���ܣ�flag=0��ʾ����
};

class tool
{
public:
	static string s_to_b(string str);					//�ַ���ת����������ƴ������
	static string b_to_s(string b);						//�������ư�unicode��ת�����ַ���
	static string d_to_b(unsigned long long a);			//ʮ����ת���ɶ�����
	static string d_to_b(string a);						//����ת���ϳ��Ķ�������
	static unsigned long long b_to_d(string b);			//������ת��Ϊʮ����
	static string b_to_ds(string b);	                //����ת������64λ�Ķ�������
	static string format_b_g(string &b,size_t n);		//ͨ����λ������ȡ��λ�ķ�ʽʹ�����ƴ����nλ
	static string format_b_d(string &b,size_t n);		//ͨ����λ������ȡ��λ�ķ�ʽʹ�����ƴ����nλ
	static string c_to_b(char c);						//���ַ�ת���ɶ�������
	static string h_to_b(string b);						//���ַ���ʽ��ʮ����������ת���ɶ�����
	static string b_to_h(string b);						//��������ת�����ַ���ʽ��ʮ����������
	static string off_z(string &str);					//ȥ����λ����
};

//--------------------------------------------------------------------------
//								DES Encrypt
//--------------------------------------------------------------------------
class CAES
{
private:
	vector<string> b64;								//���ڴ������ı��ָ�ת���õ�����ʮ��λ�����ƴ�
	string key;

public:
	CAES(string input,string key);					//�ָ�input������b64
	string encrypt();								//����
	string decrypt();								//����
};

#endif  

