strPath = "LDAP://cn=Users,dc=win2k3dom,dc=local"

Set objPath = GetObject(strPath)
Set newUser = objPath.create("User","cn=hoge hoge")
newUser.Put "sAMAccountName","hoge"

newUser.SetInfo

newUser.Put "givenName","Hoge"
newUser.Put "sn","hoge"
newUser.SetInfo 