#include <stdio.h>
#include <Windows.h>


int main()
{
    int Result = 0;
    // detect "\"" or "'" or " "
    int Interpret = 0;
    int Argc = 0;
    char* Argv[8];
    char *Command = GetCommandLineA();

    printf("Init command char: %s\n", Command);
    Argv[0] = Command;
    Argc ++;
    while(*Command) 
    {
        if(*Command == '\"')
        {
            if(Interpret)
            {
                Interpret = 0;
            }
            else 
            {
                Interpret = 1;
            }
        }
        else if ((*Command) == ' ' && Interpret == 0)
        {
            if (*(Command + 1))
            {
                Argv[Argc] = Command + 1;
                Argc ++;
            }
            *Command = 0;
        }
        
        Command ++;
    }

    int i = 0;
    for(i = 0; i < Argc; i ++)
    {
        printf("Command[%d]: %s\n", i, Argv[i]);
    }
    
    return 0;
}