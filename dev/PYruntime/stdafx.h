// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // �� Windows ͷ���ų�����ʹ�õ�����
// Windows ͷ�ļ�: 
#include <windows.h>

#ifdef _DEBUG
#pragma comment(lib,"SDK_Debug.lib")
#else
#pragma comment(lib,"SDK_Release.lib")
#endif

#define CQAPPID "cn.mikupy2001.PYruntime"

// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�
#include <Python.h>
#include <CQEVE_ALL.h>
#include <CQAPI_EX.h>