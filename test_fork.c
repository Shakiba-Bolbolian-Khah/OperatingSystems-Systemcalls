
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


int
main(int argc, char *argv[])
{
    int pid, id, children, parent;
    int parent_id = getpid();

    for(int i = 0; i < 4; i++){
        pid = fork();
        if(!pid){
            id = getpid();
            parent = get_parent_id();
            printf(1,"Parernt of current process with pid %d is: %d \n", id, parent);
            break;
        }
        else{  
            sleep(10); 
        }
    }

    if(getpid() == parent_id){
        id = getpid();
        children = get_children(id);
        printf(1,"Children of current process with pid %d is: %d \n", id, children);
        for(int i = 0; i < 4; i++){
        wait();
        }  
    }
    
    exit();
    return 0;
}
