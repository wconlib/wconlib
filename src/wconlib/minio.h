#ifndef MINIO_HEADER
#define MINIO_HEADER

#ifdef _WIN32 || WIN32
#define __WINDOWS__
#endif

#ifdef __linux__
#define __LINUX__
#endif

//Windows functions:
#ifdef __WINDOWS__

#include <Windows.h>
#include <wchar.h>

HANDLE win_get_input_handle()
{
    return GetStdHandle(STD_INPUT_HANDLE);
}

HANDLE win_get_output_handle()
{
    return GetStdHandle(STD_OUTPUT_HANDLE);
}

BOOL win_read_console(HANDLE consoleInput, wchar_t* buffer, DWORD bufferSize)
{
    DWORD read;
    BOOL ret = ReadConsole(consoleInput, buffer, bufferSize, &read, NULL);
    if (read >= 2)
    {
        buffer[read - 2] = 0;
    }
    return ret;
}

BOOL win_write_console(HANDLE consoleOutput, const wchar_t* buffer)
{
    size_t len = wcslen(buffer);
    DWORD written;
    BOOL ret = WriteConsole(consoleOutput, buffer, len, &written, NULL);
    return ret;
}

#endif

//Linux functions:
#ifdef __LINUX__

#include <unistd.h>
#include <wchar.h>

int lin_get_input_handle()
{
    return STDIN_FILENO;
}

int lin_get_output_handle()
{
    return STDOUT_FILENO;
}

BOOL lin_read_console(int consoleInput, char* buffer, size_t bufferSize)
{
    size_t ret = read(consoleInput, buffer, bufferSize);
    return ret != -1;
}

BOOL lin_write_console(int consoleOutput, const char* buffer)
{
    size_t len = wcslen(buffer);
    size_t ret = write(consoleOutput, buffer, len);
    return ret != -1;
}

#endif

#endif