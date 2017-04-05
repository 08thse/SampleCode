Option Explicit

Dim Locator
Dim Service
Dim PrcSet
Dim NetProto

Set Locator = WScript.CreateObject("WbemScripting.SWbemLocator")
Set Service = Locator.ConnectServer

Set PrcSet = Service.ExecQuery("SELECT * FROM Win32_NetworkProtocol")

For Each NetProto In PrcSet
	MsgBox NetProto.Name & ":" & NetProto.SupportsQualityofService
Next

Set NetProto = Nothing
Set PrcSet = Nothing
Set Service = Nothing
Set Locator = Nothing