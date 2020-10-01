#include<stdio.h>
void main()
{
 int n,i,j,TEMP,TEMP1,TEMP2,TEMP3,TEMP4;
 float WTSUM=0,TATSUM=0;
 int bt[10],at[10],P[10],ct[10],tat[10],wt[10],pt[10];
 printf("ENTER NUMBER OF PROCESSES:");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
  printf("ENTER ARRIVAL TIME OF p%d:\t",i);
  scanf("%d",&at[i]);
  printf("ENTER BURST TIME p%d: \t",i);
  scanf("%d",&bt[i]);
  printf("ENTER THE PRIORITY:\t");
  scanf("%d",&pt[i]);
  P[i]=i;
  printf("\n");
 }
 ct[0]=0;
    if(bt[1]>=at[n])
    {
        ct[1]=bt[1]+at[1];
        tat[1]=ct[1]-at[1];
        wt[1]=tat[1]-bt[1];
  WTSUM=wt[1];
  TATSUM=tat[1];
        for(i=2;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                if(pt[j]>pt[i])
                {
                    TEMP4=pt[i];
                    pt[i]=pt[j];
                    pt[j]=TEMP4;
                    TEMP1=bt[i];
                    bt[i]=bt[j];
                    bt[j]=TEMP1;
                    TEMP2=at[i];
                    at[i]=at[j];
                    at[j]=TEMP2;
                    TEMP3=P[i];
                    P[i]=P[j];
                    P[j]=TEMP3;
                }
            }
                if(ct[i-1]<at[i])
                {
                    TEMP=at[i]-ct[i-1];
                    ct[i]=ct[i-1]+bt[i]+TEMP;
                    TEMP1=bt[i];
                }
                else
                {
                    ct[i]=ct[i-1]+bt[i];
                }
                tat[i]=ct[i]-at[i];
                wt[i]=tat[i]-bt[i];
                WTSUM=WTSUM+wt[i]+wt[1];
                TATSUM=TATSUM+tat[i]+tat[1];
       }
   }
            if(at[n]==0)
            {
            ct[0]=0;
            for(i=1;i<=n;i++)
                {
                    for(j=i+1;j<=n;j++)
                    {
                        if(pt[j]<pt[i])
                        {
                            TEMP4=pt[i];
                            pt[i]=pt[j];
                            pt[j]=TEMP4;
                          TEMP1=bt[i];
                          bt[i]=bt[j];
                          bt[j]=TEMP1;
                        TEMP2=at[i];
                        at[i]=at[j];
                        at[j]=TEMP2;
                        }
                    }
                if(ct[i-1]>at[i])
                {

                    TEMP=at[i]-ct[i-1];
                    ct[i]=ct[i-1]+bt[i]+TEMP;
                    TEMP1=bt[i];
                }
                else
                {
                    ct[i]=ct[i-1]+bt[i];
                }
            tat[i]=ct[i]-at[i];
            wt[i]=tat[i]-bt[i];
            WTSUM=WTSUM+wt[i];
           TATSUM=TATSUM+tat[i];
        }
    }
 printf("\n\n\n");
 printf(" PROCESS   ARRIVAL TIME    BURST TIME  PRIORITY    TURN AROUND TIME    WAITING TIME\n");
 for(i=1;i<=n;i++)
 {

 printf("  %d",P[i]);
 printf("           %d",at[i]);
    printf("              %d",bt[i]);
    printf("                %d",pt[i]);
    printf("                 %d",tat[i]);
    printf("                  %d",wt[i]);
    printf("\n");
 }
 printf("AVERAGE WAITING TIME = %f\n",WTSUM/n);
 printf("AVERAGE TURN AROUND TIME= %f\n",TATSUM/n);
 printf("\n\n");
 printf("GANT CHART\n");
 for(i=1;i<=n;i++)
 {
  printf("\tP%d\t",P[i]);

 }
 printf("\n");
 for(i=1;i<=n;i++)
 {
 printf("\t%d\t",ct[i]);
 }
}
