#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    // Step 1: Create child process
    pid_t pid = fork();

    if (pid < 0)
    {
        exit(EXIT_FAILURE);
    }

    // Parent exits
    if (pid > 0)
    {
        cout << "Daemon Started Successfully" << endl;
        cout << "Parent Process Exiting..." << endl;
        exit(EXIT_SUCCESS);
    }

    // Step 2: Become session leader
    if (setsid() < 0)
    {
        exit(EXIT_FAILURE);
    }

    // Step 3: Change working directory
    chdir("/");

    // Step 4: Reset file creation mask
    umask(0);

    // Step 5: Close terminal descriptors
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    srand(time(NULL));

    while (true)
    {
        ofstream logfile("/tmp/bank_server.log", ios::app);

        time_t now = time(0);

        char *dt = ctime(&now);

        int account = rand() % 9000 + 1000;

        int amount = rand() % 5000 + 100;

        logfile << "-------------------------------------\n";
        logfile << "Time        : " << dt;
        logfile << "Account No  : " << account << endl;
        logfile << "Transaction : Deposit" << endl;
        logfile << "Amount      : Rs." << amount << endl;
        logfile << "Status      : SUCCESS\n";
        logfile << "-------------------------------------\n\n";

        logfile.close();

        sleep(5);
    }

    return 0;
}