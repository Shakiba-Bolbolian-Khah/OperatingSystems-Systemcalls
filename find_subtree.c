#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"  

int
main(int argc, char *argv[])
{
    int pid, id, children, grandparent, parent = 0;
    int grandparent_id = getpid();

    for(int i = 0; i < 3; i++){
        pid = fork();
        if(!pid){
            id = getpid();
            grandparent = get_parent_id();
            printf(1,"Parernt of current process with pid %d is: %d \n", id, grandparent);
            if(i==0){
                parent = id;
                for(int i = 0; i < 3; i++){
                    pid = fork();
                    if(!pid){
                        id = getpid();
                        parent = get_parent_id();
                        printf(1,"Parernt of current process with pid %d is: %d \n", id, parent);
                    }
                    else{  
                        sleep(10); 
                    }
                }
            }
            break;
        }
        else{  
            sleep(10); 
        }
    }

    if(getpid() == grandparent_id){
        id = getpid();
        children = get_subtree(id);
        printf(1,"Children of current process with pid %d is: %d \n", id, children);
        for(int i = 0; i < 7; i++){
            wait();
        }  
    }
    if(getpid() == parent){
        id = getpid();
        children = get_subtree(id);
        printf(1,"Children of current process with pid %d is: %d \n", id, children);
        for(int i = 0; i < 3; i++){
            wait();
        } 
    }
    
    exit();
    return 0;
}
