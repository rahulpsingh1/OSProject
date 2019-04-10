#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<unistd.h>

int timeQuant;   //time quantum for round robin

struct req{
  int arriveTime, burstTime, PID;
  int completionTime;


  }fac[100], stu[100], mainLine[200], s[100];

  int num=0,facCount = 0,stuCount = 0;
  int mergeCount = 0;

void getData(){
int i=0, t=0, reqType=0,b=0;
  printf("Enter number of queries: ");
  scanf("%d", &num);

  printf("Enter TIME QUANTUM for the processes : ");
  scanf("%d",&timeQuant);

  if(num == 0)
  {printf("\n NO QUERIES");}
  else{

  for(i=0; i<num; i++)
  {

  	printf("\nEnter 1 for faculty and 2 for student ");
    p:

    scanf("%d",&reqType);

	switch(reqType){

        //for faculty
       case 1:
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
       {
	   fac[facCount].arriveTime = t - 1000;}
       printf("Burst Time : ");
       scanf("%d", &b);
       fac[facCount].burstTime=b;

       facCount += 1;
       break;
       }

    //for student
	 case 2:
	{

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
       scanf("%d", &b);
       stu[stuCount].burstTime=b;
       stuCount += 1;
       break;
       }

    default:
    {
		printf("wrong option, enter 1 for faculty and 2 for student ");
    	goto p;
    }
   }
    }
}
}

void ShowData(){
    int i;

	printf("\n\n\n Processing please wait");
	for(i=0; i<4; i++){
	Sleep(500);

	printf(".");
}
    printf("\n\n");

	for(i=0; i<120; i++){
		printf("-");
	}
	printf("\n");

	for(i=0; i<120; i++){
        printf(" ");
		if(i==57){
            printf("Result");
		}
	}
	printf("\n");
	for(i=0; i<120; i++){
		printf("-");
	}

	printf("\n    PID \t Arrival Time \t Burst Time \t Waiting Time \t Completion Time \t Turn Around Time\n\n");

	for(i=0; i<num; i++){
		printf("     %d\t\t    %d \t\t %d \t\t   %d \t\t  %d \t\t       %d     \n", mainLine[i].PID, (mainLine[i].arriveTime + 1000),
		          mainLine[i].burstTime, (mainLine[i].completionTime - mainLine[i].arriveTime) - mainLine[i].burstTime,
				  (mainLine[i].completionTime + 1000), (mainLine[i].completionTime - mainLine[i].arriveTime) );
				  Sleep(100);
	}
    for(i=0; i<num; i++){
        if((mainLine[i].completionTime - mainLine[i].arriveTime) - mainLine[i].burstTime<0){
            printf("   Sir with PID: %d, kindly come tomorrow. The given timeslot for today is over\n",mainLine[i].PID);
        }
    }
	printf("\n");
	for(i=0; i<120; i++){
		printf("-");
	}

}


//sorting the processes by their arrival time.
//if arrival time of student and faculrty is same. then faculty will be preferred.
//if arrival time of either of 2 faculty or 2 students is same. then FCFS is used.
void oneWorld(){
	int onefacCount=0;
	int onestuCount=0;

	if(facCount !=0 && stuCount!=0){
		while(onefacCount < facCount && onestuCount < stuCount){

			if(fac[onefacCount].arriveTime == stu[onestuCount].arriveTime){
				mainLine[mergeCount] = fac[onefacCount];
				mergeCount += 1;
				onefacCount += 1;

				mainLine[mergeCount] = stu[onestuCount];
				mergeCount += 1;
				onestuCount += 1;
			}

			else if(fac[onefacCount].arriveTime < stu[onestuCount].arriveTime){
				mainLine[mergeCount] = fac[onefacCount];
				mergeCount += 1;
				onefacCount += 1;
			}
			else if(fac[onefacCount].arriveTime > stu[onestuCount].arriveTime){
				mainLine[mergeCount] = stu[onestuCount];
				mergeCount += 1;
				onestuCount += 1;
			}



		}
		if(mergeCount != (facCount + stuCount)){
			if(onestuCount!=stuCount ){

				while(onestuCount != stuCount){
				mainLine[mergeCount] = stu[onestuCount];
				mergeCount += 1;
				onestuCount += 1;
			}
			}
			else if(onefacCount!=facCount){

				while(onefacCount != facCount){
				mainLine[mergeCount] = fac[onefacCount];
				mergeCount += 1;
				onefacCount += 1;
			}
		}
	}
	int i,j;
	for(i=0;i<mergeCount; i++){
            for(j=0; j<mergeCount-1; j++){
                if(mainLine[j].arriveTime>mainLine[j+1].arriveTime){
                    s[1] = mainLine[j];
                    mainLine[j]=mainLine[j+1];
                    mainLine[j+1] = s[1];
                }
            }
		}



	}
	//when no faculty entry is there.
	else if(facCount == 0){


int i=0, j=0;
		while(onestuCount < stuCount){

			mainLine[mergeCount] = stu[onestuCount];
			mergeCount += 1;
			onestuCount += 1;
		}
		for(i=0;i<stuCount; i++){
            for(j=0; j<stuCount-1; j++){
                if(mainLine[j].arriveTime>mainLine[j+1].arriveTime){
                    s[1] = mainLine[j];
                    mainLine[j]=mainLine[j+1];
                    mainLine[j+1] = s[1];
                }
            }
		}
	}
	//when no student entry is there.
	else if(stuCount ==0){
int i,j;

		while(onefacCount != facCount){
			mainLine[mergeCount] = fac[onefacCount];
			mergeCount += 1;
			onefacCount += 1;
		}
		for(i=0;i<facCount; i++){
            for(j=0; j<facCount-1; j++){
                if(mainLine[j].arriveTime>mainLine[j+1].arriveTime){
                    s[1] = mainLine[j];
                    mainLine[j]=mainLine[j+1];
                    mainLine[j+1] = s[1];
                }
            }
		}
	}
	//no entry
	else{
		printf("\n no job");
	}
}


void workTime(){
	int compl = 0;
	int time = mainLine[0].arriveTime;
	int i,flag=0, ini;
	int copyBurstTime[num];

	//taking a copy of Burst Time.
	for(i=0; i<num; i++){
		copyBurstTime[i] = mainLine[i].burstTime;
	}


	while(time!=120&&compl!=mergeCount)
	{
		for(i=0; i<=flag; i++){
			if(copyBurstTime[i] > timeQuant){
				time += timeQuant;
				copyBurstTime[i] -= timeQuant;
			}

			else if(copyBurstTime[i] <= timeQuant && copyBurstTime[i] !=0){
				time += copyBurstTime[i];
				copyBurstTime[i] = 0;
				mainLine[i].completionTime = time;
				compl += 1;
			}
		}

		ini = flag + 1;
		for(i = ini; i < mergeCount; i++){
			if(mainLine[i].arriveTime <= time){
				flag += 1;
			}
		}
	}
}



    int main(){
    getData();
    oneWorld();
    workTime();
    ShowData();

	return 0;
	}
