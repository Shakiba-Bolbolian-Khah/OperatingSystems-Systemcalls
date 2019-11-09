#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"  

int
main(int argc, char *argv[])
{
    if(argc <= 1){
        printf(1,"Count_digit: No number has been entered!\n");
        exit();
    }

    int num = atoi(argv[1]);

    get_subtree(num);

    exit();
    return 0;
}
