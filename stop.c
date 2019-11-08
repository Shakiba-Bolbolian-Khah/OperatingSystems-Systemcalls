#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{

  if(argc != 2)
  	exit();

  int wait_time = atoi(argv[1]);

  int first = get_time();

  stop(wait_time);
  
  int second = get_time();

  int difference = second - first; 

  printf(1, "%d\n", difference);

  exit();
}