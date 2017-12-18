// C: 直下のファイル名の変更を検知する関数のサンプル

#include "stdafx.h"
#include <windows.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	HANDLE changeHandle;
	changeHandle = FindFirstChangeNotification("C:\\",
		FALSE, FILE_NOTIFY_CHANGE_FILE_NAME);

	cout << "ファイル名の変更を待機中 ..." << endl;

	WaitForSingleObject(changeHandle, INFINITE);
	cout << "ファイル名が変更されました。" << endl;

	FindNextChangeNotification(changeHandle);
	cout << "次のファイル名の変更を待機中 ..." << endl;

	WaitForSingleObject(changeHandle, INFINITE);
	cout << "ファイル名が変更されました。" << endl;

	FindCloseChangeNotification(changeHandle);
	return 0;
}

