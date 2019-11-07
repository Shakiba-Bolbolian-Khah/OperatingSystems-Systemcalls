
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


int
main(int argc, char *argv[])
{
    int pid;
    pid = fork();
    // printf(1,"Parent of process with pid %d : %d \n", getpid(), get_parent_id());

    if(pid == 0){
        printf(1,"here\n");
        // if(fork() == 0){
        //     printf(1,"Parent of process with pid %d : %d \n", getpid(), get_parent_id());
        // }
        // else
        // {

        //     printf(1,"Parent of process with pid %d : %d \n", getpid(), get_parent_id());
        //     wait();
        //     if(!fork()){
        //         printf(1,"Parent of process with pid %d : %d \n", getpid(), get_parent_id());
        //     }
        //     else
        //     {
        //         printf(1,"Parent of process with pid %d : %d \n", getpid(), get_parent_id());
        //         wait();
        //     }
            
        // }  
    }
    else
    {
        wait();
    }
    exit();
    return 0;
}
