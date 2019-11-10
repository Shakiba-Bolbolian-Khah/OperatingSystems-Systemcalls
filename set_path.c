#include "types.h"
#include "stat.h"
#include "user.h" 

int
main(int argc, char *argv[])
{
	if(argc < 2){
    	printf(1,"Set PATH: No PATH has been set!\n");
    	exit();
  	}

  	set_path(argv[1]);

	exit();
}