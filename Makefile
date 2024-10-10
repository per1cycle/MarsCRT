Compile:
	cl /c /GS- ./src/MarsEntry.c ./src/MarsIO.c ./src/MallocV1/MarsMalloc.c ./src/MarsPrintf.c ./src/MarsString.c

Lib:
	lib MarsEntry.obj MarsIO.obj MarsMalloc.obj MarsPrintf.obj MarsString.obj /OUT:Mars.lib

Link:
	cl /GS- /c ./tests/FinalTest.c
	link ./FinalTest.obj ./Mars.lib kernel32.lib /NODEFAULTLIB /entry:MarsEntry

FinalTest: Compile MakeLib
	cl /GS- /c ./tests/FinalTest.c
	link ./FinalTest.obj ./Mars.lib kernel32.lib /NODEFAULTLIB /entry:MarsEntry
	echo "run test..."
	FinalTest.exe 1 2 3

TestString: 
	cl /GS- /c ./tests/TestString.c
	link ./FinalTest.obj ./Mars.lib kernel32.lib /NODEFAULTLIB /entry:MarsEntry

TestPrintf: 
	cl /GS- /c ./tests/TestPrintf.c
	link ./TestPrintf.obj ./Mars.lib kernel32.lib /NODEFAULTLIB /entry:MarsEntry
	echo "run test..."
	TestPrintf.exe 
	dir

Clean:
	del -Force *.obj *.lib *.exe
