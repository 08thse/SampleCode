Set objShell = CreateObject("WScript.Shell")
Set objExec = objShell.Exec("control inetcpl.cpl")
'�C���^�[�l�b�g�I�v�V�����̋N��
ret = False
Do While ret = False
  ret = objShell.AppActivate("�C���^�[�l�b�g�̃v���p�e�B")
  WScript.Sleep 100
Loop