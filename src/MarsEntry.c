// The MIT License (MIT)

// Copyright (c) 2024 per1cycle

//  Permission is hereby granted, free of charge, to any person obtaining a
//  copy of this software and associated documentation files (the "Software"),
//  to deal in the Software without restriction, including without limitation
//  the rights to use, copy, modify, merge, publish, distribute, sublicense,
//  and/or sell copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
//  DEALINGS IN THE SOFTWARE.

#include <Windows.h>
#include "MarsCRT.h"

extern int main(int argc, char* argv[]);
void Exit(int ExitCode);

void MarsEntry()
{
    int Result = 0;
    // detect "\"" or "'" or " "
    int Interpret = 0;
    int Argc = 0;
    char* Argv[64];
    char* Command = (char*)GetCommandLineA();

    Argv[0] = Command;
    Argc ++;

    while(*Command != '\0')
    {
        puts(Command);
        if(*Command = '\'' || *Command == '\"')
        {
            if(Interpret)
            {
                Interpret = 0;
            }
            else Interpret = 1;
        }
        else if(*Command == ' ' && Interpret == 0)
        {
            if(*(Command + 1) != '\0')
            {    
                Argv[Argc] = Command + 1;
                Argc ++;
            }
            *Command = "\0";
        }
        Command ++;
        puts("\n");
    }

    // if(!MarsHeapInit())
    // {
    //     Exit(1);
    // }
    
    if(!MarsIOInit())
    {
        Exit(1);
    }
    
    Exit(main(Argc, Argv));
}

void Exit(int ExitCode) 
{
    ExitProcess(ExitCode);
}