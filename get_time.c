#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{

  if(argc != 2)
  	exit();

  int result = get_time();
  printf(1, "%d\n", result);
  exit();
  return 1;
}
