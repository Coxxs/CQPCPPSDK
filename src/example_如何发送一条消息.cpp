#include <CQEVE_PrivateMsg.h>
#include <winSpeak.h>
#include <CQcode.h>

#include <string>
using namespace std;
using namespace CQ;

EVE_PrivateMsg_EX(SendMsg) {
	if (!eve.message.compare("CQ:msg1")) 
		eve.sendMsg("�յ���Ϣ��!");

	if (!eve.message.compare("CQ:msg2"))
		//һ��Ҫĩβ����<<send�Żᷢ�ͳ�ȥ
		eve.sendMsg()<< "�յ���Ϣ��!"<<send;

	if (!eve.message.compare("CQ:msg3"))
		//���������ɶ���������
		eve.sendMsg()
		<< "������Ϊ:" << eve.fromQQ
		<< ",��ϢΪ:" << eve.message
		<< send;

	if (!eve.message.compare("CQ:image"))
		//����һ��ͼƬ
		eve.sendMsg() << code::image("123.png") << send;

	if (!eve.message.compare("CQ:face"))
		//����һ������
		eve.sendMsg() << code::face(face::����) << send;

	if (!eve.message.compare("CQ:raw"))
		eve.sendMsg()
		//RAW ��ʾ�������Ϣ����ԭ������
		//�����ǽ�����CQ��,���������й���,���緢��ͼƬ
		<< RAW << code::at(eve.fromQQ)
		//CODE ��ʾ�������Ϣ��������ΪCQ��
		//Ĭ�Ͻ���
		<< CODE << code::face(face::����)
		<< send;

	if (!eve.message.compare("CQ:effect"))
		//����һ��ħ������,��CQ����뵥��һ����Ϣ
		eve.sendMsg(code::effect("art", 2003, "ħ����Ϣ"));

}