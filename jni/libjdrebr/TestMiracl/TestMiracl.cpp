// TestMiracl.cpp : 定义控制台应用程序的入口点。
//
extern "C"
{
#include "p1363.h"
}
#include <string.h>

#pragma  comment(lib, "miracl")

int main(int argc, char* argv[])
{
	char* pPsw;
	GenerateAESKey(&pPsw);
	//char* szInputstring = "abcdefghijklmnopqrstuvwxyz1234567890²âÊÔ";
	//char* szInputstring = "ab12²âÊÔ";
	char* szInputstring = "abcdefghijklmnopqrstuvwxyz123456";
	int nLen = strlen(szInputstring);
	printf("Input: %s\n", szInputstring);

	char* szEncode;
	int nEncodeLen;
	string_AES_encrypt(pPsw, szInputstring, nLen, &szEncode, &nEncodeLen, FALSE);
	printf("Encode: %s\n", szEncode);

	char* szDecode;
	int nDecodeLen;
	string_AES_decrypt(pPsw, szEncode, nEncodeLen, &szDecode, &nDecodeLen, FALSE);
	printf("Decode: %s\n", szDecode);

	FreePtr_AES(szEncode);
	printf("Free szEncode\n");
	FreePtr_AES(szDecode);
	printf("Free szDecode\n");

	FreePtr_AES(pPsw);

	return 0;
}


