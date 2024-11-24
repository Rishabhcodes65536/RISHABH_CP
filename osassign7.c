#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFER_SIZE 16
int buffer[BUFFER_SIZE],spool[BUFFER_SIZE];
sem_t db,m,full,empty,mutex,ps;
int counter, readerCount, writercount;
pthread_t readerThread[50],writerThread[50],producerThread[50], 
consumerThread[50],fileThread[50];
void init()
{
sem_init(&m,0,1);
sem_init(&db,0,1);
counter=0;
readerCount=0;
writercount=0;
 sem_init(&mutex,0,1);
sem_init(&full,1,0);
sem_init(&empty,1,BUFFER_SIZE);
counter=0;
 sem_init(&ps,0,1);
}
void *spooler(void *param)
{
int data,regi;
sem_wait(&ps);
regi = counter;
data = counter;
spool[counter]=data;
regi++;
printf("Spooler State: ");
for(int i=0;i<regi;i++)
printf("File %d ",spool[i]);
printf("\n");
sleep(1);
counter=regi;
sem_post(&ps);
}
void printer_spooler()
{
int i,number_of_files;
init();
printf("Enter number of Files: ");
scanf("%d",&number_of_files);
for(i=0;i<number_of_files;i++)
{
pthread_create(&fileThread[i],NULL,spooler,NULL);
}
for(i=0;i<number_of_files;i++)
{
pthread_join(fileThread[i],NULL);
}
}
void *producer(void *param)
{
int item=rand(1)*10;
// item=rand();
sem_wait(&empty);
sem_wait(&mutex);
printf("Produced item: %d\n", item);
buffer[counter++]=item;
sleep(1);
sem_post(&mutex);
sem_post(&full);
}
void *consumer(void *param)
{
int item;
sem_wait(&full);
sem_wait(&mutex);
counter--;
item = buffer[counter];
printf("Consumed item: %d\n",item );
sleep(1);
sem_post(&mutex);
sem_post(&full);
}
void producer_consumer()
{
int i,number_of_producers,number_of_consumers;
init();
printf("Enter number of item to be produce: ");
scanf("%d",&number_of_producers);
printf("Enter number of item to be consumed: ");
scanf("%d",&number_of_consumers);
for(i=0;i<number_of_producers;i++)
{
pthread_create(&producerThread[i],NULL,producer,NULL);
}
for(i=0;i<number_of_consumers;i++)
{
pthread_create(&consumerThread[i],NULL,consumer,NULL);
}
for(i=0;i<number_of_producers;i++)
{
pthread_join(producerThread[i],NULL);
}
for(i=0;i<number_of_consumers;i++)
{
pthread_join(consumerThread[i],NULL);
}
}
void *writer(void *param)
{
sem_wait(&db);
writercount++;
printf("Writer %d start writing\n",writercount);
FILE *fptr;
fptr = fopen("data.txt","a+");
fprintf(fptr,"%d writer\n", writercount);
counter++;
 sleep(1);
printf("Writer %d stop writing\n",writercount);
 sem_post(&db);
}
void *reader(void *param)
{
sem_wait(&m);
readerCount++;
if(readerCount==1)
{
sem_wait(&db);
}
printf("Reader start reading\n");
printf("Reader count is %d\n",readerCount);
sem_post(&m);
char mystring[100];
FILE *fptr;
fptr = fopen("data.txt","r");
fgets(mystring,100,fptr);
counter--;
 sleep(1);
 sem_wait(&m);
 readerCount--;
printf("Reader stop reading\n");
printf("Reader count is %d\n",readerCount);
 if(readerCount==0)
 {
 sem_post(&db);
 }
 sem_post(&m);
}
void reader_writer()
{
int no_of_writers,no_of_readers;
init();
printf("Enter number of readers: ");
scanf("%d",&no_of_readers);
printf("Enter number of writers: ");
scanf("%d",&no_of_writers);
int i;
for(i=0;i<no_of_writers;i++)
{
pthread_create(&writerThread[i],NULL,writer,&i);
}
for(i=0;i<no_of_readers;i++)
{
pthread_create(&readerThread[i],NULL,reader, &i);
}
for(i=0;i<no_of_writers;i++)
{
pthread_join(writerThread[i],NULL);
}
for(i=0;i<no_of_readers;i++)
{
pthread_join(readerThread[i],NULL);
}
}
int main()
{
 int select;
 while(1)
 {
 printf("\t\t----0-Exit\t1-Printer Spooler\t2-Producer Consumer\t3-ReaderWriter-----\n");
 printf("Enter Number: ");
 scanf("%d",&select);
 switch(select)
 {
 case 1:
 printer_spooler();
 break;
 case 2:
 producer_consumer();
 break;
 case 3:
 reader_writer();
 break;
 case 0:
 exit(0);
 break;
 default:
 printf("Enter valid Number: ");
 }
 }
}
