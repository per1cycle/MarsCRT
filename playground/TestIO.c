#include <Windows.h>

#define EOF     (-1)
#define FILE    int
#define stdin   (FILE*)(GetStdHandle(STD_INPUT_HANDLE))
#define stdout  (FILE*)(GetStdHandle(STD_OUTPUT_HANDLE))
#define stderr  (FILE*)(GetStdHandle(STD_ERROR_HANDLE))

int fwrite(const void* Buffer, size_t Size, size_t Count, FILE* Stream)
{
    size_t Write = 0;
    if(!WriteFile((HANDLE)Stream, Buffer, Size * Count, &Write, NULL))
    {
        return 0;
    }
    return Write;
}

int fputc(int Char, FILE* Stream)
{
    if(fwrite(&Char, 1, 1, Stream) != 1)
    {
        return EOF;
    }
    return 0;
}

int vfprintf(FILE* Stream, const char*Format, va_list ArgList)
{
    fputc(1, Stream);
    return 1;
}

int printf(const char* Format, ...)
{
    va_list(ArgList);
    va_start(ArgList, Format);

    return vfprintf(stdout, Format, ArgList);
}

int main(int argc, char const *argv[])
{
    printf("Hello");
    return 0;
}
