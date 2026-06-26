#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstdlib>
 using namespace std;
int main()
{
    pid_t pid = fork();
    if (pid < 0)
    {
        cout << "Fork failed\n";
        return 1;
    }
    // Parent exits
    if (pid > 0)
    {
        cout << "Parent exiting...\n";
        exit(0);
    }
    // Child becomes session leader
    if (setsid() < 0)
    {
        return 1;
    }
    // Second fork
    pid = fork();
    if (pid < 0)
    {
        return 1;
    }
    if (pid > 0)
    {
        exit(0);
    }
    // Reset file mask
    umask(0);
    // Change working directory
    chdir("/");
    // Close standard file descriptors
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    // Daemon loop
    while (true)
    {
        sleep(5);
        // Background work goes here
    }
    return 0;
}
