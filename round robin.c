#include<stdio.h>

int main()
{
       int i,j,n,time,remain,flag=0,tq;

       float avgwt=0,avgtat=0;

       printf("ENTER THE NO OF PROCESSES : ");
       scanf("%d",&n);
       remain=n;
       int at[n],bt[n],p[n],rnt[n],tat[n],wtt[n];
       for(i=0;i<n;i++)
       {
              printf("ENTER THE ARRIVAL TIME  TIME FOR PROCESS P%d : ",i+1);
              scanf("%d",&at[i]);
              printf("ENTER THE BURST TIME FOR THE PROCESS P%d : ",i+1);
              scanf("%d",&bt[i]);
              p[i] = i+1;
              rnt[i] = bt[i];
       }
       sortat(at,bt,n);
       printf("Enter TIME QUANTUM : ");
       scanf("%d",&tq);

       printf("GANTT CHART\n");
       printf("0");
       for(time=0,i=0;remain!=0;)
       {
              if(rnt[i]<=tq && rnt[i]>0)
              {
                     time = time + rnt[i];
                     printf("[P%d]%d",p[i],time);

                     rnt[i]=0;
                     flag=1;
              }
              else if(rnt[i] > 0)
              {
                     rnt[i] = rnt[i] - tq;
                     time = time + tq;
                     printf("[P%d]%d",p[i],time);
              }
              if(rnt[i]==0 && flag==1)
              {
                     remain--;
                     tat[i] = time-at[i];
                     wtt[i] = time-at[i]-bt[i];
                     avgwt = avgwt + time-at[i]-bt[i];
                     avgtat = avgtat + time-at[i];
                     flag=0;
              }
              if(i==n-1)
                     i=0;
              else if(at[i+1] <= time)
                     i++;
              else
                     i=0;
       }
       printf("\n\n");
       printf("\n");
       printf("PROCESS\tARRIVAL TIME\tBURST TIME\tTURN AROUND TIME\tWAITING TIME\n");
       printf("\n");
       for(i=0;i<n;i++)
       {
              printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i],at[i],bt[i],tat[i],wtt[i]);
       }
       printf("\n");
       avgwt = avgwt/n;
       avgtat = avgtat/n;
       printf("Average Waiting Time : %.2f\n",avgwt);
       printf("Average Turnaround Time : %.2f\n",avgtat);
       return 0;
}
void sortat(int at[],int bt[],int n)
{
       int i,j,temp;

       for(i=0;i<n;i++)
       {
              for(j=i+1;j<n;j++)
              {
                     if(at[i] > at[j])
                     {
                           temp = at[i];
                           at[i] = bt[j];
                           bt[j] = temp;
                     }
              }
       }

}

