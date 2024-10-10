Compile:
	cl /c /GS- ./src/MarsEntry.c ./src/MarsIO.c ./src/NewMalloc/MarsMalloc.c ./src/MarsPrintf.c ./src/MarsString.c

MakeLib:
	lib MarsEntry.obj MarsIO.obj MarsMalloc.obj MarsPrintf.obj MarsString.obj /OUT:Mars.lib

Link:
	cl /GS- /c ./tests/FinalTest.c
	link ./FinalTest.obj ./Mars.lib kernel32.lib /NODEFAULTLIB /entry:MarsEntry

FinalTest: Compile MakeLib
	cl /GS- /c ./tests/FinalTest.c
	link ./FinalTest.obj ./Mars.lib kernel32.lib /NODEFAULTLIB /entry:MarsEntry
	echo "run test..."
	FinalTest.exe 1 2 3

TestString: compile lib
	cl /GS- /c ./tests/TestString.c
	link ./FinalTest.obj ./Mars.lib kernel32.lib /NODEFAULTLIB /entry:MarsEntry

TestPrintf: Compile MakeLib
	cl /GS- /c ./tests/TestPrintf.c
	link ./TestPrintf.obj ./Mars.lib kernel32.lib /NODEFAULTLIB /entry:MarsEntry
	echo "run test..."
	TestPrintf.exe 
	dir

Clean:
	del -Force *.obj *.lib *.exe
