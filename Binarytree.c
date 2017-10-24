#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
int data;
struct node *left;
struct node*right;
};
struct node *tree;
void createtree(struct node *tree)
{
tree= NULL;
}
struct node *insertelement(struct node *tree, int val)
{
struct node *ptr, *nodeptr, *parentptr;
ptr=(struct node*)malloc(sizeof(struct node));
ptr->data=val;
ptr->left=NULL;
ptr->right=NULL;
if(tree==NULL)
{
tree=ptr;
tree->left=NULL;
tree->right=NULL;
}
else
{
parentptr=NULL;
nodeptr=tree;
while(nodeptr!=NULL)
{
parentptr=nodeptr;
if(val<nodeptr->data)
nodeptr=nodeptr->left;
else
nodeptr=nodeptr->right;
}
if(val<parentptr->data)
parentptr->left=ptr;
else
parentptr->right=ptr;
}
return tree;
}
void preorder(struct node *tree)
{
if(tree!=NULL)
{
printf("%d\n",tree->data);
preorder(tree->left);
preorder(tree->right);
}
}
void inorder(struct node *tree)
{
if(tree!=NULL)
{
inorder(tree->left);
printf("%d\n",tree->data);
inorder(tree->right);
}
}
void postorder(struct node *tree)
{
if(tree!=NULL)
{
postorder(tree->left);
postorder(tree->right);
printf("%d\n",tree->data);
}
}
int main()
{
int option,val;
struct node *ptr;

do
{
printf("Main Menu\n");
printf("1.Insert element\n2.Preorder traversal\n3.Inorder traversal\n4.Postorder traversal\n5.Exit\n");
printf("Enter your choice\n");
scanf("%d",&option);
switch(option)
{
case 1:printf("Enter the value of node\n");
       scanf("%d",&val);
       tree=insertelement(tree,val);
       break;
case 2:printf("Preorder traversal\n");
       preorder(tree);
       break;
case 3:printf("Inorder traversal\n");
       inorder(tree);
       break;
case 4:printf("Postorder traversal\n");
       postorder(tree);
       break;
case 5:exit(0);
       break;
default:printf("Enter correct choice\n");
	break;
}
}
while(option!=5);
return 1;
}

