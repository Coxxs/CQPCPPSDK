#include "py_����.h"

#include <CQLogger.h>
#include <CQAPI_EX.h>
#include"PyTupleMinute.h"
#include"PyTupleGet.h"
#include"PyObjGet.h"

using namespace CQ;
using namespace std;

typedef PyObject* PYO;
static Logger logger("PyRunAPi");

//self - ���÷�
//args - ����
#define SPO(name) static PYO name (PYO self, PYO args)

#define �� PYO res = nullptr; Py_BEGIN_ALLOW_THREADS
#define �� PyTupleMinute r(args,
#define ˹ ); if (r) {
#define DE_ZA }else logger.Debug() << "��Py�����ͼ����API,���ǲ�������ȷ" << send;\
               Py_END_ALLOW_THREADS;return res;

#define ž PYO res = nullptr;Py_BEGIN_ALLOW_THREADS res = PyTupleGet(
#define �� ); Py_END_ALLOW_THREADS;return res;

#define �� PYO res = nullptr;Py_BEGIN_ALLOW_THREADS
#define ſ Py_END_ALLOW_THREADS;return res;

SPO(py_addLog) { �� ������ ���ȼ�; char* ����; char* ����; �� &���ȼ�, &����, &���� ˹ res = PyTupleGet(addLog(���ȼ�, ����, ����)); DE_ZA }
SPO(py_deleteMsg) { �� �������� MsgId; �� &MsgId ˹ res = PyTupleGet(deleteMsg(MsgId)); DE_ZA }
SPO(py_getAppDirectory) { ž getAppDirectory() �� }
SPO(py_getCookies) { ž getCookies() �� }
SPO(py_getCsrfToken) { ž getCsrfToken() �� }
SPO(py_getGroupList) { �� auto list = getGroupList(); PyObjGet obj; for (auto ls : list)obj.put(ls.first, ls.second); res = PyTupleGet(obj); ſ }
SPO(py_getGroupMemberInfo) {
	�� �������� Ⱥ��; �������� QQID; �߼��� ��ʹ�û���; �� &Ⱥ��, &QQID, &��ʹ�û��� ˹
		GroupMemberInfo info = getGroupMemberInfo(Ⱥ��, QQID, ��ʹ�û���);
	PyObjGet obj;
	obj.put("Group", info.Group);
	obj.put("QQID", info.QQID);
	obj.put("�ǳ�", info.�ǳ�);
	obj.put("��Ƭ", info.��Ƭ);
	obj.put("�Ա�", info.�Ա�);
	obj.put("����", info.����);
	obj.put("����", info.����);
	obj.put("��Ⱥʱ��", info.��Ⱥʱ��);
	obj.put("�����", info.�����);
	obj.put("�ȼ�_����", info.�ȼ�_����);
	obj.put("permissions", info.permissions);
	obj.put("ר��ͷ��", info.ר��ͷ��);
	obj.put("ר��ͷ�ι���ʱ��", info.ר��ͷ�ι���ʱ��);
	obj.put("������¼��Ա", info.������¼��Ա);
	obj.put("�����޸���Ƭ", info.�����޸���Ƭ);
	res = PyTupleGet(obj);
	DE_ZA
}
SPO(py_getLoginNick) { ž getLoginNick() �� }
SPO(py_getLoginQQ) { ž getLoginQQ() �� }
SPO(py_getRecord) { �� �ı��� file, outformat; �� &file, &outformat ˹ res = PyTupleGet(getRecord(file, outformat)); DE_ZA }
SPO(py_getStrangerInfo) {
	�� �������� QQID; �߼��� ��ʹ�û���; �� &QQID, &��ʹ�û��� ˹
	auto info = getStrangerInfo(QQID, ��ʹ�û���);
	
	res = PyTupleGet();
	DE_ZA
}
SPO(py_sendDiscussMsg) { �� �������� �������; �ı��� msg; �� &�������, &msg ˹ res = PyTupleGet(sendDiscussMsg(�������, msg)); DE_ZA }
SPO(py_sendGroupMsg) { �� �������� Ⱥ��; �ı��� msg; �� &Ⱥ��, &msg ˹ res = PyTupleGet(sendGroupMsg(Ⱥ��, msg)); DE_ZA }
SPO(py_sendLike) { �� �������� QQID; ������ times; �� &QQID, &times ˹ res = PyTupleGet(sendLike(QQID, times)); DE_ZA }
SPO(py_sendPrivateMsg) { �� �������� QQ; �ı��� msg; �� &QQ, &msg ˹ res = PyTupleGet(sendPrivateMsg(QQ, msg)); DE_ZA }
SPO(py_setDiscussLeave) { �� �������� ������� �� &������� ˹ res = PyTupleGet(setDiscussLeave(�������)); DE_ZA }
SPO(py_setFriendAddRequest) { �� �ı��� ��������ʶ;������ ��������;�ı��� ��ע; �� &������ʶ,&��������,&��ע ˹ res = PyTupleGet(setFriendAddRequest(��������ʶ,��������,��ע)); DE_ZA }
SPO(py_setGroupAddRequest) { �� �ı��� ��������ʶ;������ ��������,��������;�ı��� ��ע; �� &������ʶ,&��������,&��������,&��ע ˹ res = PyTupleGet(setGroupAddRequest(��������ʶ,��������,��������,��ע)); DE_ZA }
SPO(py_setGroupAdmin) { �� �������� Ⱥ��, QQID;�߼��� ��Ϊ����Ա; �� &Ⱥ��, &QQID, &��Ϊ����Ա ˹ res = PyTupleGet(setGroupAdmin(Ⱥ��, QQID, ��Ϊ����Ա)); DE_ZA }
SPO(py_setGroupAnonymous) { �� �������� Ⱥ��;�߼��� ��������; �� &Ⱥ��,&�������� ˹ res = PyTupleGet(setGroupAnonymous(Ⱥ��,��������)); DE_ZA }
SPO(py_setGroupAnonymousBan) { �� �������� Ⱥ��;�ı��� ����;�������� ����ʱ��; �� &Ⱥ��,&����,&����ʱ�� ˹ res = PyTupleGet(setGroupAnonymousBan(Ⱥ��,����,����ʱ��)); DE_ZA }
SPO(py_setGroupBan) { �� �������� Ⱥ��,QQID,����ʱ��; �� &Ⱥ��,&QQID,&����ʱ�� ˹ res = PyTupleGet(setGroupBan(Ⱥ��, QQID,����ʱ��)); DE_ZA }
SPO(py_setGroupCard) { �� �������� Ⱥ��,QQID;�ı��� ����Ƭ_�ǳ� �� &Ⱥ��,&QQID,&����Ƭ_�ǳ� ˹ res = PyTupleGet(setGroupCard(Ⱥ��,QQID,����Ƭ_�ǳ�)); DE_ZA }
SPO(py_setGroupKick) { �� �������� Ⱥ��,  QQID;�߼��� �ܾ��ټ�Ⱥ �� &Ⱥ��,&QQID,&�ܾ��ټ�Ⱥ ˹ res = PyTupleGet(setGroupKick(Ⱥ��,QQID,�ܾ��ټ�Ⱥ)); DE_ZA }
SPO(py_setGroupLeave) { �� �������� Ⱥ��;�߼��� �Ƿ��ɢ �� &Ⱥ��,&�Ƿ��ɢ ˹ res = PyTupleGet(setGroupLeave(Ⱥ��,�Ƿ��ɢ)); DE_ZA }
SPO(py_setGroupSpecialTitle) { �� �������� Ⱥ��,QQID �� Ⱥ��,QQID ˹ res = PyTupleGet(setGroupSpecialTitle(Ⱥ��,QQID)); DE_ZA }
SPO(py_setGroupWholeBan) { ��  ��  ˹ res = PyTupleGet(); DE_ZA }

static PyMethodDef API��������[] = {
 { "addLog"              ,py_addLog, METH_VARARGS , ""},
 //{ "deleteMsg"           ,py_deleteMsg, METH_VARARGS , ""},
 //{ "getAppDirectory"     ,py_getAppDirectory, METH_VARARGS , ""},
 //{ "getCookies"          ,py_getCookies, METH_VARARGS , ""},
 //{ "getCsrfToken"        ,py_getCsrfToken, METH_VARARGS ,"" },
 //{ "getGroupList"        ,py_getGroupList, METH_VARARGS , ""},
 //{ "getGroupMemberInfo"  ,py_getGroupMemberInfo, METH_VARARGS ,"" },
 //{ "getLoginNick"        ,py_getLoginNick, METH_VARARGS , ""},
 //{ "getLoginQQ"          ,py_getLoginQQ, METH_VARARGS ,"" },
 //{ "getRecord"           ,py_getRecord, METH_VARARGS , ""},
 //{ "getStrangerInfo"     ,py_getStrangerInfo, METH_VARARGS ,"" },
 //{ "sendDiscussMsg"      ,py_sendDiscussMsg, METH_VARARGS , ""},
 //{ "sendGroupMsg"        ,py_sendGroupMsg, METH_VARARGS , ""},
 //{ "sendLike"            ,py_sendLike, METH_VARARGS ,"" },
 //{ "sendPrivateMsg"      ,py_sendPrivateMsg, METH_VARARGS , ""},
 //{ "setDiscussLeave"     ,py_setDiscussLeave, METH_VARARGS , ""},
 //{ "setFriendAddRequest" ,py_setFriendAddRequest, METH_VARARGS ,"" },
 //{ "setGroupAddRequest"  ,py_setGroupAddRequest, METH_VARARGS , ""},
 //{ "setGroupAdmin"       ,py_setGroupAdmin, METH_VARARGS ,"" },
 //{ "setGroupAnonymous"   ,py_setGroupAnonymous, METH_VARARGS ,"" },
 //{ "setGroupAnonymousBan",py_setGroupAnonymousBan, METH_VARARGS , ""},
 //{ "setGroupBan"         ,py_setGroupBan, METH_VARARGS ,"" },
 //{ "setGroupCard"        ,py_setGroupCard, METH_VARARGS , ""},
 //{ "setGroupKick"        ,py_setGroupKick, METH_VARARGS , ""},
 //{ "setGroupLeave"       ,py_setGroupLeave, METH_VARARGS ,"" },
 //{ "setGroupSpecialTitle",py_setGroupSpecialTitle, METH_VARARGS , ""},
 //{ "setGroupWholeBan"    ,py_setGroupWholeBan, METH_VARARGS ,"" },

 { NULL                  , NULL,0,NULL },
};

static struct PyModuleDef API���� = {
 PyModuleDef_HEAD_INIT,
 "CQ",   /* name of module */
 NULL, /* module documentation, may be NULL */
 -1,       /* size of per-interpreter state of the module,
	 or -1 if the module keeps state in global variables. */
 API��������
};
PYO getCQAPI() {
	return PyModule_Create(&API����);
}