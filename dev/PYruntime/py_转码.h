#pragma once

#include <memory>

//gbkתUTF-8
//�ش���char*��������
std::shared_ptr<char*> U(const char* strGbk);//�����strGbk��GBK����
//UTF-8תgbk
//�ش���char*��������
std::shared_ptr<char*> G(const char* strUtf8);//�����strUtf8��UTF-8����

//gbkתUTF-8
//�ش���char*��������
char* _U(const char* strGbk);//�����strGbk��GBK����
//UTF-8תgbk
//�ش���char*��������
char* _G(const char* strUtf8);//�����strUtf8��UTF-8����