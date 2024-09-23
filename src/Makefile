compile:
	cl /c /GS- MarsEntry.c MarsIO.c MarsMalloc.c MarsPrintf.c MarsString.c

lib:
	lib MarsEntry.obj MarsIO.obj MarsMalloc.obj MarsPrintf.obj MarsString.obj /OUT:Mars.lib
	del -Force *.obj

link:
	cl /c FinalTest.c
	link .\FinalTest.obj .\Mars.lib kernel32.lib /NODEFAULTLIB /entry:MarsEntry

test: compile lib
	cl /DEBUG /c FinalTest.c
	link .\FinalTest.obj .\Mars.lib kernel32.lib /NODEFAULTLIB /entry:MarsEntry
	echo "run test..."
	FinalTest.exe

clean:
	del -Force *.obj *.lib *.exe
