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

  int num = 0 , previous_edi;

//~~~~~~~~~~~~~~~~~~Provide negative numbers~~~~~~~~~~~~~~~~~~~~~~~~~~//
  // char s = (char) argv[1][0];
  // if((strcmp(&s,"-"))== 0){
  //   j = 1;
  // }

  // for( int i = j; i < strlen(argv[1]); i++){
	// 	num = num * 10 + ( argv[1][i] - '0' );
	// }
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

  num = atoi(argv[1]);

//~~~~~~~Checking~~~~~~//
  // printf(1,"Num entered: %d \n", num);
//~~~~~~~~~~~~~~~~~~~~~//
  
  asm ( 
    "movl %%edi,%0;"
    :"=r"(previous_edi)
    :
    :"%edi"
  );
//~~~~~~~Checking~~~~~~//
  // printf(1,"Previous one: %d \n", previous_edi);
//~~~~~~~~~~~~~~~~~~~~~//

  asm ( 
    "movl %0,%%edi;"
    :
    :"r"(num)
    :"%edi"
  );

//~~~~~~~Checking~~~~~~//
  int new;
  asm ( 
    "movl %%edi,%0;"
    :"=r"(new)
    :
    :"%edi"
  );
  // printf(1,"Num in register: %d \n", new); 
//~~~~~~~~~~~~~~~~~~~~//

  count_num_of_digits(num);

  asm ( 
    "movl %0,%%edi;"
    :
    :"r"(previous_edi)
    :"%edi"
  );

  exit();
}
