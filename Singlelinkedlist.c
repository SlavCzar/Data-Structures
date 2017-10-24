#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
 struct node
 { int data;
 struct node *next;
 };
struct node *start = NULL;
struct node *create_ll();
struct node *display();
struct node *insert_after();
struct node *delete_after();
int main()
{
     int ch,d;
    
     do
      {  printf("\n MENU");
	 printf("\n 1.  Create a list \n 2.  Insert after a node\n 3.Delete after a node\n 4.  Display");
	 printf("\n 5.  Exit");
	 printf("\nEnter your choice:\n");
	 scanf("%d",&d);
	 switch(d)
	   {case 1:create_ll();break;
	    case 2:insert_after();break;
	    case 3:delete_after();break;
	    case 4:display();break;
	    case 5:exit(0);
	    default:printf("Invalid choice");
	    }

      }while(ch!=2);
    return 1;

}
struct node *create_ll()
{ struct node *new_node, *ptr;
 int num;
 printf("\n Enter '-1'to end");
 printf("\n Enter the data : ");
 scanf("%d", &num);
 while(num!=-1)
 {new_node = (struct node*)malloc(sizeof(struct node));
  new_node -> data=num;
 if(start==NULL)
 {   new_node -> next = NULL;
  start = new_node;
 }
 else
{   ptr=start;
 while(ptr->next!=NULL)
   ptr=ptr->next;
   ptr->next = new_node;
   new_node->next=NULL;
  }
  printf("\n Enter the data:");
  scanf("%d",&num);
  }
return start;
 }
struct node *display()
{  struct node *ptr;
    ptr=start;
		  while(ptr!=NULL)
		  { printf("\t %d",ptr -> data);
		    ptr=ptr -> next;
		  } return start;
}
struct node *insert_after()
{ struct node *new_node, *ptr, *preptr;
int num, val;
printf("\n Enter the data : ");
scanf("%d",&num);
 printf("\n Enter the value after which the data has to be inserted : ");
scanf("%d", &val);
new_node = (struct node *)malloc(sizeof(struct node));
new_node -> data = num;
 ptr = start;
preptr = ptr;
 while(preptr -> data != val)
 {  preptr = ptr;
 ptr = ptr -> next;
}
preptr -> next=new_node;
new_node -> next = ptr;
return start;
 }
struct node *delete_after()
 { struct node *ptr, *preptr;
int val;
 printf("\n Enter the value after which the node has to deleted :");
scanf("%d", &val);
 ptr = start;
preptr = ptr;
 while(preptr -> data != val)
 {  preptr = ptr;
 ptr = ptr -> next;
}
preptr -> next=ptr -> next;
free(ptr);
 return start;
}

