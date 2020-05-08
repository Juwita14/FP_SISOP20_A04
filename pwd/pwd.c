#include <unistd.h>
#include <stdio.h>

int main() {
    char cwd[1036];
    chdir("/path/to/change/directory/to");
    getcwd(cwd, sizeof(cwd));
    printf("%s\n", cwd);
}
