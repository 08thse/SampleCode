' �h���C���R���g���[���������̓h���C�����̃R���s���[�^�ɂāA�����ł���A�J�E���g�Ń��O�I�����Ď��s

Option Explicit
Dim strComputer, strUsername, objWMI, colUsers, objUser

strComputer = "."
Set objWMI = GetObject("winmgmts:\\" & strComputer & "\root\directory\LDAP")

strUsername = InputBox("Please type the user name")
Set colUsers = objWMI.ExecQuery("SELECT * FROM ds_user where ds_sAMAccountName = '" & strUsername & "'")

If colUsers.Count > 0 Then

 For Each objUser in colUsers
     WScript.Echo "First Name: " & objUser.ds_givenName
     WScript.Echo "Last Name: " & objUser.ds_sn
  Next

Else

 WScript.Echo "No users found!"

End If 