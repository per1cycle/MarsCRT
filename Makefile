compile:
	cl /GS- /c ./src/MarsEntry.c ./src/MarsIO.c ./src/MarsMalloc.c ./src/MarsPrintf.c ./src/MarsString.c

lib:
	lib MarsEntry.obj MarsIO.obj MarsMalloc.obj MarsPrintf.obj MarsString.obj /OUT:Mars.lib
	del -Force *.obj

link:
	cl /GS- /c ./tests/FinalTest.c
	link ./FinalTest.obj ./Mars.lib kernel32.lib /NODEFAULTLIB /entry:MarsEntry

test: compile lib
	cl /GS- /c ./tests/FinalTest.c
	link ./FinalTest.obj ./Mars.lib kernel32.lib /NODEFAULTLIB /entry:MarsEntry
	echo "run test..."
	FinalTest.exe

clean:
	del -Force *.obj *.lib *.exe
