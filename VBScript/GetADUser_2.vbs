' �ڑ����郆�[�U���w�肷��B�ȉ��̗�̓h���C���� Administrator �Őڑ��B

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