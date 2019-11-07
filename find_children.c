
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


int
main(int argc, char *argv[])
{
    int pid, id, children;
    pid = fork();
    if(pid == 0){
        id = getpid();
        children = get_children(id);
        printf(1,"Children of process %d : %d \n", id, children);

        if(!fork()){  
            id = getpid();
            children = get_children(id);
            printf(1,"Children of process %d : %d \n", id, children);
        }
        else
        {
            wait();   
            id = getpid();
            children = get_children(id);
            printf(1,"Children of process %d : %d \n", id, children);
            
            pid = fork();

            if(!pid) {
                wait();
                id = getpid();
                children = get_children(id);
                printf(1,"Children of process %d : %d \n", id, children);
                pid = fork();
                if(!pid){
                    wait();
                    id = getpid();
                    children = get_children(id);
                    printf(1,"Children of process %d : %d \n", id, children);
                }
                else{
                    id = getpid();
                    children = get_children(id);
                    printf(1,"Children of process %d : %d \n", id, children);
                }
            }
            else{
                id = getpid();
                children = get_children(id);
                printf(1,"Children of process %d : %d \n", id, children);
            }
        }
    }
    else
    {
        wait();
        id = getpid();
        children = get_children(id);
        printf(1,"Children of process %d : %d \n", id, children);
    }

    exit();
    return 0;
}
