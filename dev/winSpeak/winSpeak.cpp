#include "..\..\inculde\winSpeak.h"

#include "sapi.h"
#include "sphelper.h"
#pragma comment(lib, "sapi.lib")

#include <iostream>

using namespace std;

wchar_t*TW(string file) {
	USES_CONVERSION;
	wchar_t*t = A2W(file.c_str());
	wchar_t*w = new wchar_t[wcslen(t) + 1];
	wcscpy(w, t);
	return w;
}

ISpVoice *pISpVoice;//�����˽ӿ�

bool Speak_init() {
	if (!pISpVoice)
	{
		// ��ҪCOM�ӿ�
		::CoInitialize(NULL);

		// ��ȡISpVoice�ӿ�
		CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_INPROC_SERVER, IID_ISpVoice, (void**)&pISpVoice);

		return pISpVoice;
	}
	return true;
}

bool Speak_to_wav_file(string file, string wantSay) {
	bool res = false;

	auto _file = TW(file);
	auto _wantSay = TW(wantSay);

	CSpStreamFormat OriginalFmt;//����һ����������󶨵�wav�ļ�
	CComPtr<ISpStream> cpWavStream;//wav��Ƶ��
	CComPtr<ISpStreamFormat> cpOldStream;//�ɵ���

	HRESULT hr = pISpVoice->GetOutputStream(&cpOldStream);
	if (hr == S_OK)
	{
		hr = OriginalFmt.AssignFormat(cpOldStream);

		if (SUCCEEDED(hr))
		{
			// ʹ��sphelper.h���ṩ�ĺ������� wav �ļ�
			hr = SPBindToFile(_file, SPFM_CREATE_ALWAYS, &cpWavStream, &OriginalFmt.FormatId(), OriginalFmt.WaveFormatExPtr());

			if (SUCCEEDED(hr))
			{
				//��������������� wav �ļ��������� speakers
				pISpVoice->SetOutput(cpWavStream, TRUE);

				//��ʼ�ʶ�
				pISpVoice->Speak(_wantSay, SPF_IS_NOT_XML, 0);

				//�������û�ȥ
				pISpVoice->SetOutput(cpOldStream, FALSE);

				cpWavStream.Release();

				res = true;
			}
			else {
				cout << "SPBindToFile" << endl;
			}
		}
		else {
			cout << "OriginalFmt.AssignFormat(cpOldStream)" << endl;
		}
	}
	else {
		cout << "GetOutputStream" << endl;
	}

	return res;
}