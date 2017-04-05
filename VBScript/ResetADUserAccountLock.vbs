strPath = "LDAP://cn=hoge,cn=Users,dc=win2k3dom,dc=local"

Set objUser = GetObject(strPath)

objUser.IsAccountLocked = False
objUser.SetInfo 