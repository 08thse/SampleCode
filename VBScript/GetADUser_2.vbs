' 接続するユーザを指定する。以下の例はドメインの Administrator で接続。

Const ADS_SECURE_AUTHENTICATION = 1
Const ADS_USE_ENCRYPTION = 2

strPath = "LDAP://cn=hoge,cn=Users,dc=win2k3dom,dc=local"
strUser = "win2k3dom\Administrator"
strPassword = "hogehoge"

Set objDSO = GetObject("LDAP:")
Set objUser = objDSO.OpenDSObject(strPath, strUser, strPassword, _
ADS_USE_ENCRYPTION AND ADS_SECURE_AUTHENTICATION)

WScript.Echo "First Name: " & objUser.givenName
WScript.Echo "Last Name: " & objUser.sn 