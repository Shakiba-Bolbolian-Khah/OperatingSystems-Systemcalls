#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"  

int
main(int argc, char *argv[])
{
    int pid, id, children, parent, my_p = 0, subtree;
    int parent_id = getpid();

    for(int i = 0; i < 4; i++){
        pid = fork();
        if(!pid){
            id = getpid();
            parent = get_parent_id();
            printf(1,"Parent of current process with pid %d is: %d \n", id, parent);
            if (i == 3){
                if (!fork()){
                    id = getpid();
                    my_p = get_parent_id();
                    printf(1,"Parent of current process with pid %d is: %d \n", id, my_p);
                    break;
                }
                else{
                    stop(1);
                    children = get_children(getpid());
                    printf(1,"Children of current process with pid %d is: %d \n", getpid(), children);
                    wait();
                }
            } 
            break;
        }
        else{  
            sleep(10);
        }
    }
    
    if(getpid() == parent_id){
        subtree = get_subtree(parent_id);
        printf(1,"Subtree of current process with pid %d is: %d \n", parent_id, subtree);
        for(int i = 0; i < 5; i++){
            wait();
        }
    }
    
    
    exit();
    return 0;
}
