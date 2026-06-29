#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <cstdlib>

using namespace std;

int main()
{
   pid_t pid = fork();

   if (pid < 0)
   {
       cout << "Fork Failed\n";
       return 1;
   }

   if (pid > 0)
   {
       cout << "Parent Exiting\n";
       exit(0);
   }

   // Child becomes a session leader
   if (setsid() < 0)
   {
       return 1;
   }

   // Change working directory
   chdir("/");

   // Reset file creation mask
   umask(0);

   // Close terminal file descriptors
   close(STDIN_FILENO);
   close(STDOUT_FILENO);
   close(STDERR_FILENO);

   while (true)
   {
       ofstream log("/tmp/daemon.log", ios::app);

       log << "Daemon Running PID : "
           << getpid()
           << endl;

       log.close();

       sleep(5);
   }

   return 0;
}
