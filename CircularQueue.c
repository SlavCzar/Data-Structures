#include<stdio.h>
#include<conio.h>
#define Max 5
void insert(int);
void display();
void del();
int front=-1, rear=-1;
int cq[Max];
void main()
{
int element,ch;

 do
 {
  printf("\nChoose an operation to be preformed:\n");
  printf("\n1.)Insert\n2.)Delete\n3.)Display\n4.)Exit\n");
  scanf("%d",&ch);
  switch(ch)
  {
	case 1:
	{
		printf("\nEnter the element to be inserted:\n");
		scanf("%d",&element);
		insert(element);
		break;
	}
	case 2:
	{
		del();
		break;
	}
	case 3:
	{
		display();
		break;
	}
	case 4:
	{
		printf("\nExit\n");
		break;
	}
	default:
		printf("OOPS! Wrong Choice");
  }
 }while(ch!=4);
getch();
}
void insert(int element)
{
 if(rear==-1 && front==-1)
 {
	rear++;
	front++;
	cq[rear]=element;
 }
 else if(front==0 && rear==Max-1)
 {
	printf("\nStack Full\n");
 }
 else
 {      if(front!=0 && rear==Max-1)
	{
	rear=-1;
	}
	rear++;
	cq[rear]=element;
 }
}
void display()
{
int i;
	if((rear==-1 && front== -1 && rear==front) || front>rear)
	 printf("Stack Empty");
	else
	  {
	  printf("\nElements of the circular queue are:\n");
	  for(i=front; i<=rear; i++)
	   printf("%d\n",cq[i]);
	  }
}
void del()
{
int val;
	if(front==-1 && rear==-1)
	{
		printf("\nUnderflow");
	}
	val=cq[front];
	if(front== rear)
	{
		front=rear=-1;
	}
	else
	{
		if(front=Max-1)
		 front=1;
		else
		 front++;
	}
	printf("\nElement %d is deleted",val);
}




