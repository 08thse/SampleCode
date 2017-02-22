Option Explicit
Dim objShell
Set objShell = CreateObject("WScript.Shell")
objShell.Run "notepad.exe", 1, 1

'Run メソッドの第二引数が 0 でないので、メモ帳の終了を待機してからスクリプトを続行

Call MsgBox("メモ帳を終了しました。")
Set objShell = Nothing