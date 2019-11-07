
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


int
main(int argc, char *argv[])
{
    int pid;
    pid = fork();
    printf(1,"Children of process %d : %d \n", getpid(), get_children(getpid()));

    // if(pid == 0){

    //     if(!fork()){  
    //         printf(1,"Children of process %d : %d \n", getpid(), get_children(getpid()));
    //         fork();
    //         printf(1,"Children of process %d : %d \n", getpid(), get_children(getpid()));            
    //     }
    //     else
    //     {
    //         wait() ;   
    //         printf(1,"Children of process %d : %d \n", getpid(), get_children(getpid()));
    //     }  
    // }
    // else
    // {
    //     fork();
    //     printf(1,"Children of process %d : %d \n", getpid(), get_children(getpid()));
    // }
    // wait();

    // if(pid == 0){
    //     if(fork()){
    //         printf(1,"Children of process %d : %d \n", getpid(), get_children(getpid()));
    //     }
    //     else{
    //         printf(1,"Children of process %d : %d \n", getpid(), get_children(getpid()));
    //         wait();
    //     }
    // }
    // else{
    //     wait();
    // }
    // if(!fork()){
    //     printf(1,"Children of process %d : %d \n", getpid(), get_children(getpid()));
    //     wait();
    // }
    // else{
    //     printf(1,"Children of process %d : %d \n", getpid(), get_children(getpid()));
    // }

    int n, id, children;
    for( n = 0; n < 2 ; n++){
        pid = fork();
        id = getpid();
        children = get_children(id);
        printf(1,"Children of process %d : %d \n", id, children);
        if(pid < 0)
            break;
        if(pid == 0)
            exit();
    }

    for(; n > 0; n--){
        if(wait() < 0){
            printf(1, "wait stopped early\n");
            exit();
        }
    }  
    
    if(wait() != -1){
        printf(1, "wait got too many\n");
        exit();
    }

    
    return 0;
}
