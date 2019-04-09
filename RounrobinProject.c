#include<stdio.h>

int timeQuant;      //time quantum of roundRobin algorithm

struct req{
  int arriveTime, burstTime, PID;
  /*here arriveTime is arrival time, burstTime denotes burst time,
  PID gives pid of a process*/
  
}fac[100], stu[100], mainLine[200];
  int num;               //total number of queries by people.
  int facCount=0;       //number of faculty is facCount
  int stuCount=0;      //number of studenta is stuCount
  
void getData(){
int i, t, reqType,b;
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
  

void oneWorld(){
	int onefacCount=0;          //for traversing the facultycount
	int onestuCount=0;          //for traversing the studentcount
	
	if(facCount !=0 && stuCount!=0){
		while(onefacCount < facCount && onestuCount < stuCount){
			if(fac[onefacCount].arriveTime < stu[onestuCount].arriveTime){
				mainLine[mergeCount] = fac[onefacCount];
				mergeCount += 1;
				onefacCount += 1;
			}
			else if(fac[onefacCount].arriveTime > stu[onestuCount].arriveTime){
				mainLine[mergeCount] = stu[onestuCount];
				mergeCount += 1;
				onestuCount += 1;
			}
			else{
				mainLine[mergeCount] = fac[onefacCount];
				mergeCount += 1;
				onefacCount += 1;
				
				mainLine[mergeCount] = stu[onestuCount];
				mergeCount += 1;
				onestuCount += 1;
			}
		}
		if(mergeCount != (facCount + stuCount)){
			if(stuCount != onestuCount){
				
				while(onestuCount != stuCount){
				mainLine[mergeCount] = stu[onestuCount];
				mergeCount += 1;
				onestuCount += 1;
			}
			}
			else if(facCount != onefacCount){
				
				while(onefacCount != facCount){
				mainLine[mergeCount] = fac[onefacCount];
				mergeCount += 1;
				onefacCount += 1;
			}
		}
	}
	else if(facCount == 0){
		while(onestuCount != stuCount){
			mainLine[mergeCount] = stu[onestuCount];
			mergeCount += 1;
			onestuCount += 1;
		}
	}
	else if(stuCount ==0){
		while(onefacCount != facCount){
			mainLine[mergeCount] = fac[onefacCount];
			mergeCount += 1;
			onefacCount += 1;
		}
	}
	else{
		printf("\n no job");
	}
}
}
//just for testing
void testShow(){
	int i;
	//printf("\n%d",num);
	for(i=0;i<num; i++){
		//printf("%d",i);
		printf("%d\n%d\n%d\n%d\n%d\n", num, facCount, stuCount, mainLine[i].arriveTime, mainLine[i].burstTime);
	}
}



    int main(){
    getData();
    oneWorld();
    testShow();
    return 0;
    }
  
  
