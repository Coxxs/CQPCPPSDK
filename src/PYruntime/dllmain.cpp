#include "stdafx.h"
#include "init.h"

MUST_AppInfo_RETURN(CQAPPID)

BOOL APIENTRY DllMain(
	HMODULE hModule,
	DWORD   ul_reason_for_call,
	LPVOID  lpReserved
)
{
	load_runtime();//��ʼ������



	return TRUE;
}

