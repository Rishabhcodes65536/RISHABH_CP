// Memory Management Scheme - Best Fit
#include <bits/stdc++.h>

using namespace std;

void best_fit()
{
    int fragment[20], b[20], p[20], i, j, nb, np, temp, lowest = 9999;
    static int barray[20], parray[20];
    printf("\n\t\t\tMemory Management Scheme - Best Fit");
    printf("\nEnter the number of blocks:");
    scanf("%d", &nb);
    printf("Enter the number of processes:");
    scanf("%d", &np);
    printf("\nEnter the size of the blocks:-\n");
    for (i = 1; i <= nb; i++)
    {
        printf("Block no.%d:", i);
        scanf("%d", &b[i]);
    }
    printf("\nEnter the size of the processes :-\n");
    for (i = 1; i <= np; i++)
    {
        printf("Process no.%d:", i);
        scanf("%d", &p[i]);
    }
    for (i = 1; i <= np; i++)
    {
        for (j = 1; j <= nb; j++)
        {
            if (barray[j] != 1)
            {
                temp = b[j] - p[i];
                if (temp >= 0)
                    if (lowest > temp)
                    {
                        parray[i] = j;
                        lowest = temp;
                    }
            }
        }
        fragment[i] = lowest;
        barray[parray[i]] = 1;
        lowest = 10000;
    }
    printf("\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tFragment");
    for (i = 1; i <= np && parray[i] != 0; i++)
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, p[i], parray[i], b[parray[i]], fragment[i]);
}



// WorstFit


// #include <stdio.h>

void worst_fit()
{
    int blockSize[10],processSize[10],blocks,processes;
    printf("Enter the number of blocks: ");
    scanf("%d",&blocks);
     printf("Enter the number of processes: ");
    scanf("%d",&processes);
    for(int i=0;i<blocks;i++){
        printf("Enter the block size: ");
        scanf("%d",&blockSize[i]);

    }
    for(int i=0;i<processes;i++){
        printf("Enter the process size: ");
        scanf("%d",&processSize[i]);
    }
    int allocation[processes];
    int occupied[blocks];
    
  for(int i = 0; i < processes; i++){
        allocation[i] = -1;
    }
    
    for(int i = 0; i < blocks; i++){
        occupied[i] = 0;
    }

    for (int i=0; i < processes; i++)
    {
	int indexPlaced = -1;
	for(int j = 0; j < blocks; j++)
	{

	    if(blockSize[j] >= processSize[i] && !occupied[j])
            {
                
                if (indexPlaced == -1)
                    indexPlaced = j;
                    
                else if (blockSize[indexPlaced] < blockSize[j])
                    indexPlaced = j;
            }
        }
 
        if (indexPlaced != -1)
        {
            allocation[i] = indexPlaced;
            occupied[indexPlaced] = 1;
            blockSize[indexPlaced] -= processSize[i];
        }
    }
 
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < processes; i++)
    {
        printf("%d \t\t\t %d \t\t\t", i+1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n",allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}


void first_fit()
{
int bsize[10], psize[10], bno, pno, flags[10], allocation[10], i, j;
for(i = 0; i < 10; i++)
{
flags[i] = 0;
allocation[i] = -1;
}
printf("Enter no. of blocks: ");
scanf("%d", &bno);
printf("\nEnter size of each block: ");
for(i = 0; i < bno; i++)
scanf("%d", &bsize[i]);
printf("\nEnter no. of processes: ");
scanf("%d", &pno);
printf("\nEnter size of each process: ");
for(i = 0; i < pno; i++)
scanf("%d", &psize[i]);
for(i = 0; i < pno; i++) //allocation as per first fit
for(j = 0; j < bno; j++)
if(flags[j] == 0 && bsize[j] >= psize[i])
{
allocation[j] = i;
flags[j] = 1;
break;
}
//display allocation details
printf("\nBlock no.\tsize\t\tprocess no.\t\tsize");
for(i = 0; i < bno; i++)
{
printf("\n%d\t\t%d\t\t", i+1, bsize[i]);
if(flags[i] == 1)
printf("%d\t\t\t%d",allocation[i]+1,psize[allocation[i]]);
else
printf("Not allocated");
}
}

int main(){
int k;
cout<<"Enter the vale of option 1.Best fit 2.First fit 3.Worst fit";
cin>>k;
switch(k){
    case 1:
    best_fit();
    break;

    case 2:
    first_fit();
    break;

    case 3:
    worst_fit();
    break;

    default:
     break;
}
}