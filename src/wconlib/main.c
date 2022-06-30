#include "minio.h"

int main()
{

#ifdef __WINDOWS__
    HANDLE input = win_get_input_handle();
    HANDLE output = win_get_output_handle();

    wchar_t buffer[1024];
    win_read_console(input, buffer, 1024);

    win_write_console(output, buffer);

    system("pause");
#endif

#ifdef __LINUX__

#endif

    return 0;
}