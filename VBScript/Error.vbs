'0 �ɂ�鏜�Z�ł̃T���v��
Option Explicit
On Error Resume Next
Dim sample
sample = 100 / 0
If Not (Err.Number = 0) Then
   Call MsgBox(Err.Description)
Else
   Call MsgBox(CStr(sample))
End If