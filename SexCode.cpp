// Win32Project1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "windows.h"

typedef char*(*StartfuncPtrAdd)(char* p0);
typedef void(*StopfuncPtrAdd)(char* p0);
typedef int(*IsRunningfuncPtrAdd)(char* p0);

int _tmain(int argc, _TCHAR* argv[])
{
	// ����ģ��
	HMODULE hModuleHandle = LoadLibraryA("proxy-sdk.dll");
	if (NULL == hModuleHandle || INVALID_HANDLE_VALUE == hModuleHandle)
	{
		// �Ҳ���dll
		return -1;

	}
	// ��ȡģ�麯����ַ
	StartfuncPtrAdd pFuncStart = (StartfuncPtrAdd)GetProcAddress(hModuleHandle, "Start");
	StopfuncPtrAdd pFuncStop = (StopfuncPtrAdd)GetProcAddress(hModuleHandle, "Stop");
	IsRunningfuncPtrAdd pFuncIsRunning = (IsRunningfuncPtrAdd)GetProcAddress(hModuleHandle, "IsRunning");
	// ��麯���Ƿ��ȡ�ɹ�
	if (pFuncStart == NULL)
	{
		printf("Start ������ַ��ȡʧ��");
		return -1;
	}
	if (pFuncStop == NULL)
	{
		printf("Stop ������ַ��ȡʧ��");
		return -1;
	}
	if (pFuncIsRunning == NULL)
	{
		printf("IsRunning ������ַ��ȡʧ��");
		return -1;
	}
	
	char* pSexVar = "http -p :7771";
	//GoString sGoStr = { pSexVar, strlen(pSexVar) };

	// �������� ���ؿ��ַ���˵�������ɹ�;���طǿ��ַ���˵������ʧ��,���ص��ַ����Ǵ���ԭ��
	char* pRetMessage = pFuncStart(pSexVar);
	printf("%s\r\n", pRetMessage);

	// �رշ��� û�з���ֵ
	pFuncStop(pSexVar);
	printf("have already stopped\r\n");

	// �������Ƿ������� 0û�� 1������
	int iRet = pFuncIsRunning(pSexVar);
	printf("current status %d\r\n", iRet);
	getchar();
	return 0;
}



