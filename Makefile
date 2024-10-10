compile:
	cl /c /GS- ./src/MarsEntry.c ./src/MarsIO.c ./src/MallocV1/MarsMalloc.c ./src/MarsPrintf.c ./src/MarsString.c

debug:
	cl /DDEBUG /c /GS- ./src/MarsEntry.c ./src/MarsIO.c ./src/MallocV1/MarsMalloc.c ./src/MarsPrintf.c ./src/MarsString.c

lib: compile
	lib MarsEntry.obj MarsIO.obj MarsMalloc.obj MarsPrintf.obj MarsString.obj /OUT:Mars.lib

link:
	cl /GS- /c ./tests/FinalTest.c
	link ./FinalTest.obj ./Mars.lib kernel32.lib /NODEFAULTLIB /entry:MarsEntry

finaltest: compile lib
	cl /GS- /c ./tests/FinalTest.c
	link ./FinalTest.obj ./Mars.lib kernel32.lib /NODEFAULTLIB /entry:MarsEntry
	echo "run test..."
	FinalTest.exe 1 2 3

teststr: 
	cl /GS- /c ./tests/TestString.c
	link ./FinalTest.obj ./Mars.lib kernel32.lib /NODEFAULTLIB /entry:MarsEntry

testprintf: compile lib
	cl /GS- /c ./tests/TestPrintf.c
	link ./TestPrintf.obj ./Mars.lib kernel32.lib /NODEFAULTLIB /entry:MarsEntry
	echo "run test..."
	TestPrintf.exe 

testmem: debug lib
	cl /DDEBUG /GS- /c ./tests/TestMemory.c
	link ./TestMemory.obj ./Mars.lib kernel32.lib /NODEFAULTLIB /entry:MarsEntry
	echo "run test..."
	TestMemory.exe 

clean:
	rm -rf *.obj *.lib *.exe
