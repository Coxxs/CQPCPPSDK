#include "string"

//#include "CQSDK/CQconstant.h"
//#include "CQSDK/CQAPI_EX.h"
//#include "CQSDK/CQEVE_GroupMsg.h"
//#include "CQSDK/CQEVE_PrivateMsg.h"
//#include "CQSDK/CQLogger.h"

#include <CQAPI_EX.h>
#include <CQEVE_GroupMsg.h>
#include <CQEVE_PrivateMsg.h>
#include <CQLogger.h>

#include "APPINFO.h"

using namespace std;
using namespace CQ;


EVE_PrivateMsg_EX(privateMsgEx)
{
	static logger log("˽���¼�");
	try
	{
		log.Info()
			<< "{����: " << eve.font.����
			<< ", �ֺ�:" << eve.font.�ֺ�
			<< ", ��ɫ:" << eve.font.��ɫ
			<< ", ��ʽ:" << eve.font.��ʽ
			<< ", ����:" << eve.font.����
			<< "}" << send;
	}
	catch (...)
    {
        log.Info("˽�ĳ����쳣");
	}
}

EVE_Disable(Disable)
{
	return 0;
}

EVE_Enable(Enable)
{
	return 0;
}

EVE_Menu(menu1)
{
	addLog(Log_Info, "�˵��¼�", "�˵�1�����");

	return 0;
}

EVE_Menu(menu2)
{
	addLog(Log_Info, "�˵��¼�", "�˵�2�����");

	return 0;
}

MUST_AppInfo_RETURN(CQAPPID)

