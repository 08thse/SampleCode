// PwdSample.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
// Visual Studio 2017
// 「マルチバイト文字列を使用する」に設定しておく
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