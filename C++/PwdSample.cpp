// PwdSample.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
// Visual Studio 2017
// �u�}���`�o�C�g��������g�p����v�ɐݒ肵�Ă���
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
using namespace std;


int main()
{
	char buffer[MAX_PATH];
	DWORD len;

	len = GetCurrentDirectory(MAX_PATH, buffer);
	if (len == 0) {
		cout << "Error: " << GetLastError() << endl;
	}
	else {
		cout << "Current Directory: " << buffer << endl;
	}

    return 0;
}