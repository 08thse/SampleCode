Option Explicit
Dim objShell
Set objShell = CreateObject("WScript.Shell")
objShell.Run "notepad.exe", 1, 1

'Run ���\�b�h�̑������� 0 �łȂ��̂ŁA�������̏I����ҋ@���Ă���X�N���v�g�𑱍s

Call MsgBox("���������I�����܂����B")
Set objShell = Nothing