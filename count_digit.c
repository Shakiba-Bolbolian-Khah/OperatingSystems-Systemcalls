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

  int num = 0 , j = 0, previous_esi;

  char s = (char) argv[1][0];
  if((strcmp(&s,"-"))== 0){
    j = 1;
  }

  for( int i = j; i < strlen(argv[1]); i++){
		num = num * 10 + ( argv[1][i] - '0' );
	}

  asm volatile( 
    "movl %%esi,%0;"
    :"=r"(previous_esi)
    :
    :"%esi"
  );

  asm volatile( 
    "movl %0,%%esi;"
    :
    :"r"(num)
    :"%esi"
  );

  int new = 0;
  asm volatile( 
    "movl %%esi,%0;"
    :"=r"(new)
    :
    :"%esi"
  );
  
  count_num_of_digits(num);

  asm volatile( 
    "movl %0,%%esi;"
    :
    :"r"(previous_esi)
    :"%esi"
  );

  exit();
}
