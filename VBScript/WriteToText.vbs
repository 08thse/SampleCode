Option Explicit
Dim objFso
Set objFso = CreateObject("Scripting.FileSystemObject")
Dim objFile
Set objFile = objFso.OpenTextFile("sample.txt", 8)
objFile.WriteLine "Sample message."
Set objFile = Nothing
Set objFso = Nothing