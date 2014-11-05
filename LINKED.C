NAME:SONY REDDY,PASUNOORI
STUDENT ID:109080055
COURSE:CSCI 250
INSTRUCTOR:BRENT AUERNHEIMER

Q) Write a program to calculate the mean and standard deviation of a set of n real 
   numbers.


PROGRAM:

#include <stdio.h>
#include <MATH.h>
#include <stdlib.h>
#include<conio.h>
typedef struct node{
int data;
struct node *next;
}
NODE;

NODE *createNode(int item)
{
NODE *newNode=NULL;
newNode=(NODE*)malloc(sizeof(NODE));
newNode->next=NULL;
newNode->data=item;
return newNode;
}
NODE *insertNodeHead(NODE *head,int item)
{
NODE *newNode=NULL;
newNode=createNode(item);
if(head!=NULL)
newNode->next=head;
return newNode;
}
float calMean(NODE *head)
{
NODE *runNode=head;
float sum=0,count=0;
float ret=0;
while (runNode!=NULL)
{
sum=sum+runNode->data;
count++;
runNode=runNode->next;
}
ret=(float)sum/count;
return ret;
}
float calStandardDeviation(NODE *head,float ret)
{
NODE *runNode=head;
float mean=ret;
int count=0;
float B=0.0;
while(runNode!=NULL)
{
B=B+(pow(runNode->data-mean,2));
count++;
runNode=runNode->next;
}
B=sqrt(B/(count-1));
return B;
}
void main(void)
{
int a;
float mean=0,SD=0;
NODE *head=NULL;
clrscr();
printf("Enter 0 for exit\n");
while(a!=999)
{
printf("Enter the numbers:");
scanf("%d",&a);
if(a!=999)
head =insertNodeHead(head,a);
}

if(head!=NULL)
mean=calMean(head);
SD=calStandardDeviation(head,mean);
printf("mean=%f\n",mean);
printf("standard deviation=%f\n",SD);
getch();
}




