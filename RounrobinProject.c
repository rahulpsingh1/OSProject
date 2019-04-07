#include<stdio.h>

int timeQuant;

struct req{
  int arriveTime, burstTime, PID;
  
  
  }fac[100], stu[100], mainLine[200];
  int num,facCount=0,stuCount=0;
  
void getData(){
int num, i, t, reqType,b;
  printf("Enter number of queries: ");
  scanf("%d", &num);
  
  printf("Enter TIME QUANTUM for the processes : ");
  scanf("%d",&timeQuant);
  
  if(num == 0)
  {printf("\n NO QUERIES");}
  else{
 
  for(i=0; i<num; i++)
  { printf("\nEnter 1 for faculty and 2 for student");
    scanf("%d",&reqType);
    if(reqType != 1 && reqType != 2)
    {while(reqType != 1 && reqType != 2)
    {printf("wrong option, enter 1 for faculty and 2 for student ");
     scanf("%d",&reqType);}
     }
    if(reqType == 1)              //for faculty
    {  printf("Pid : ");
       scanf("%d",&fac[facCount].PID);
       printf("enter time as a number, for ex: 10:00 as 1000\n");
       printf("Arrival Time : ");
       scanf("%d", &t);
       if(t<1000 || t>1200){
        while(t<1000 || t>1200){
        printf("wrong time, enter arrival time again : ");
        scanf("%d", &t);}
       }
       else
       {fac[facCount].arriveTime = t - 1000;}
       printf("Burst Time : ");
       scanf("%d", &b);
       fac[facCount].burstTime=b;
       
       facCount += 1;
       }
       
    else{
      printf("Pid : ");
       scanf("%d",&stu[stuCount].PID);
       printf("enter time as a number, for ex: 10:00 as 1000\n");
       printf("Arrival Time : ");
       scanf("%d", &t);
       if(t<1000 || t>1200){
        while(t<1000 || t>1200){
        printf("wrong time, enter arrival time again : ");
        scanf("%d", &t);}
       }
       else
       {stu[stuCount].arriveTime = t - 1000;}
       printf("Burst Time : ");
       scanf("%d", &stu[stuCount].burstTime);
       stuCount += 1;
       }
    
    }
    }
    }
    
    
    main(){
    getData();
    
    
    }
  
  
