// C: �����̃t�@�C�����̕ύX�����m����֐��̃T���v��

#include "stdafx.h"
#include <windows.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	HANDLE changeHandle;
	changeHandle = FindFirstChangeNotification("C:\\",
		FALSE, FILE_NOTIFY_CHANGE_FILE_NAME);

	cout << "�t�@�C�����̕ύX��ҋ@�� ..." << endl;

	WaitForSingleObject(changeHandle, INFINITE);
	cout << "�t�@�C�������ύX����܂����B" << endl;

	FindNextChangeNotification(changeHandle);
	cout << "���̃t�@�C�����̕ύX��ҋ@�� ..." << endl;

	WaitForSingleObject(changeHandle, INFINITE);
	cout << "�t�@�C�������ύX����܂����B" << endl;

	FindCloseChangeNotification(changeHandle);
	return 0;
}

