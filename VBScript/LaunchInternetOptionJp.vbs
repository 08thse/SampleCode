Set objShell = CreateObject("WScript.Shell")
Set objExec = objShell.Exec("control inetcpl.cpl")
'インターネットオプションの起動
ret = False
Do While ret = False
  ret = objShell.AppActivate("インターネットのプロパティ")
  WScript.Sleep 100
Loop