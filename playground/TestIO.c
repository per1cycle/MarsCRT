#include <Windows.h>

#define EOF     (-1)
#define FILE    int
#define stdin   (FILE*)(GetStdHandle(STD_INPUT_HANDLE))
#define stdout  (FILE*)(GetStdHandle(STD_OUTPUT_HANDLE))
#define stderr  (FILE*)(GetStdHandle(STD_ERROR_HANDLE))

int MarsFwrite(const void* Buffer, size_t Size, size_t Count, FILE* Stream)
{
    size_t Write = 0;
    if(!WriteFile((HANDLE)Stream, Buffer, Size * Count, &Write, 0))
    {
        return 0;
    }
    return Write;
}

int MarsFputc(int Char, FILE* Stream)
{
    if(MarsFwrite(&Char, 1, 1, Stream) != 1)
    {
        return EOF;
    }
    return 0;
}

int MarsVfprintf(FILE* Stream, const char*Format, va_list ArgList)
{
    MarsFputc('1', Stream);
    return 1;
}

int MarsPrintf(const char* Format, ...)
{
    va_list(ArgList);
    va_start(ArgList, Format);

    return MarsVfprintf(stdout, Format, ArgList);
}

int main(int argc, char const *argv[])
{
    MarsPrintf("Hello");
    return 0;
}
