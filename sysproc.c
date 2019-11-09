#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int
sys_count_num_of_digits(void){
  int num =0;

  struct proc *curproc = myproc();
  struct trapframe *trp = curproc-> tf;
  num = trp -> esi;

  int digits = 0;
  while(num != 0){
    digits += 1;
    num = num / 10;
  }
  cprintf("Number of digits of entered number is: %d \n", digits);

  return 0;

}

int
sys_get_parent_id(void)
{
  return get_parent_id();
}

int
sys_get_children(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;

  return get_children(pid);
}

int
sys_get_time(void)
{
  struct rtcdate t;
  cmostime(&t);
  return (t.second + (t.minute * 60) + (t.hour * 3600));
}

int
sys_stop(void)
{
  int wait_time;
  uint first_ticks;
  if(argint(0, &wait_time) < 0)
    return -1;
  wait_time = wait_time * 100;
  acquire(&tickslock);
  first_ticks = ticks;
  release(&tickslock);
  while(ticks - first_ticks < wait_time){
    if(myproc()->killed) {
      return -1;
    }
  }
  return 0;
}

int
sys_get_subtree(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;

  return get_subtree(pid);
}