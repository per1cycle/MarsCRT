```
We choose to go to the Moon in this decade and do the other things, not because they are easy, but because they are hard. By John F. Kennedy

Same as Mars. By per1cycle.
```

# HOW TO TASTE MARS CRT?

## PREREQUEST
Install vs 2022 and enable c/c++ support

## GET START

- launch visual studio developer command prompt terminal 
- locate to the project

runtime for pure c
```powershell
cl /GS- /c ./src/MarsEntry.c ./src/MarsIO.c ./src/MarsMalloc.c ./src/MarsPrintf.c ./src/MarsString.c
lib MarsEntry.obj MarsIO.obj MarsMalloc.obj MarsPrintf.obj MarsString.obj /OUT:Mars.lib

# run the test.c
cl /GS- /c ./tests/FinalTest.c
link ./FinalTest.obj ./Mars.lib kernel32.lib /NODEFAULTLIB /entry:MarsEntry

```

TODO: runtime for c++
```powershell
TODO
```