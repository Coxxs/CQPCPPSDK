#include "stdafx.h"
#include "init.h"
#include <CQLogger.h>
#include <iostream>

using namespace std;
using namespace CQ;

bool init = false; PyObject *runtime;
void load_runtime() {
	logger log("��ʼ��");
	if (init) {
		return;
	}

	auto lib = LoadLibrary(L"\\bin\\python36.dll");
	if (!lib) {
		log.Warning("�޷�����\\bin\\python36.dll,����!");
		return;
	}

	Py_Initialize();
	if (!Py_IsInitialized())
	{
		log.Warning("py������ʼ��ʧ��");
		return;
	}

	PyRun_SimpleString("import sys;");
	PyRun_SimpleString("sys.path.append(\"pyapp\");");

	runtime = PyImport_ImportModule("PluginManager");
	if (!runtime) {
		err = true;
		log.Warning("py�ļ�����ʧ��");
		Py_Finalize();
		return ;
	}
}