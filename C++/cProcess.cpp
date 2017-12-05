// cProcess.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>
using namespace std;


int main(void)
{
	CHAR cmdStr[100];
	STARTUPINFO startUpInfo;
	PROCESS_INFORMATION procInfo;
	BOOL success;

	cout << "Type command name.";
	cin.getline(cmdStr, 100);

	GetStartupInfo(&startUpInfo);

	success = CreateProcess(
		0,
		cmdStr,
		0,
		0,
		FALSE,
		CREATE_NEW_CONSOLE,
		0,
		0,
		&startUpInfo,
		&procInfo
	);
	if (!success) {
		cout << "Create Process Error : "
			<< GetLastError() << endl;

		WaitForSingleObject(procInfo.hProcess, INFINITE);
	}

    return 0;
}

