#include <CQEVE_PrivateMsg.h>
#include <CQcode.h>
#include <CQLogger.h>

#include <string>
using namespace std;
using namespace CQ;

//�����static,��ʾ���loggerֻ�б�cpp��Ч
static Logger logger("SendMsg");

EVE_PrivateMsg_EX(SendMsg) {
	logger.Debug() << DEBUGINFO << eve.message;
	auto msg = eve.sendMsg();
	auto message = eve.message;

	if (!message.compare("CQ:msg1"))
		eve.sendMsg("�յ���Ϣ��!");

	if (!message.compare("CQ:msg2"))
		//һ��Ҫĩβ����<<send�Żᷢ�ͳ�ȥ
		msg << "�յ���Ϣ��!" << send;

	if (!message.compare("CQ:msg3"))
		//���������ɶ���������
		msg
		<< "������Ϊ:" << eve.fromQQ
		<< ",��ϢΪ:" << eve.message
		<< send;

	if (!message.compare("CQ:image")) {
		logger.Debug() << "rawģʽ:" << msg.isRAW() << send;
		//����һ��ͼƬ
		msg << code::image("123.png") << send;
	}

	if (!message.compare("CQ:face"))
		//����һ������
		msg << code::face(face::����) << send;

	if (!message.compare("CQ:raw"))
		msg
		//RAW ��ʾ�������Ϣ����ԭ������
		//�����ǽ�����CQ��,���������й���,���緢��ͼƬ
		<< RAW << code::at(eve.fromQQ)
		//CODE ��ʾ�������Ϣ��������ΪCQ��
		//Ĭ�Ͻ���
		<< CODE << code::face(face::����)
		<< send;

	if (!message.compare("CQ:effect"))
		//����һ��ħ������,��CQ����뵥��һ����Ϣ
		eve.sendMsg(code::effect("art", 2003, "ħ����Ϣ"));
}