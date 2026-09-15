#include <unistd.h>

int main()
{
    int n;
    n = write(1, "Hello world!\n", sizeof("Hello world\n"));

    return 0;
}
