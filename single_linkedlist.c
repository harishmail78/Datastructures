#include <stdio.h>
#include <stdlib.h>
struct node
{
	int x;
	struct node *next;
};
struct node *phead;
void createnode(int val);
void displaynodes();
void removenodefromtail();
void addnodetohead(int val);
void removenodefromhead(); 
void insertnode(int val);
void deletenode(int val);
void main()
{
	//int c;
	int flag,n,val;
	//void createnode(int val);
 	//void displaynodes();	
	while(1)
	{	
	printf("\nenter your choice...............:");	
	 printf("\nif you want create nods press=1:");
	 printf("\ndisplay all the nodes   press=2:");
	 printf("\nRemove node from tail...press=3:");
	 printf("\nAdd node to head........press=4:");
	 printf("\nRemove node frome head..press=5:");
	 printf("\nInset node..............press=6:");
	 printf("\nDelete node.............press=7:");
	 printf("\npress any other key to exit:...:\n");
	 	
	scanf("%d",&flag);	
	switch(flag)
	{
 	case 1: createnode(1);
		break;
	case 2: displaynodes();
		break;
	case 3: removenodefromtail();
		break;
	case 4: printf("enter the new head value:");
		scanf("%d",&val);
		addnodetohead(val);
		break;
	case 5: removenodefromhead();
		break;
	case 6: printf("enter the insert node value:");
		scanf("%d",&val);
		insertnode(val);
		break;
	case 7: printf("enter the delete node value:");
		scanf("%d",&val); 
		deletenode(val);
		break;		
	default:exit(1);
	}
	}
}
 int c=0;
void createnode(int val)
{
	struct node *pnew,*ptrav;
	printf("enter the value:");
	scanf("%d",&val);
	pnew=malloc(sizeof(struct node));
	pnew->x=val;
	pnew->next=NULL;
	c++;
	if(phead==NULL)
	{
		phead=pnew;
		printf("node-%d:%d\n",c,pnew->x);		
		return;
	}
	ptrav=phead; 
	while(ptrav->next!=NULL)
	{
		ptrav=ptrav->next;
	}
	ptrav->next=pnew;
	printf("node-%d:%d\n",c,val);
	return;
	
}
 int d=0;
void displaynodes()
{
	int d=0;
	struct node *ptrav;
	if(phead==NULL)
	{
	 printf("LIST IS EMPTY....\n");
	 return;	
	}	
	ptrav=phead;
	while(ptrav!=NULL)
	{
	 d++;
	 printf("node-%d:%d\n",d,ptrav->x);
	 ptrav=ptrav->next;	
	}
}	
#if 0
//int p=0;
void removenodefromtail()
{
	struct node *ptrav,*ptemp;
	if(phead==NULL)
	{
	 printf("list is empty....");
	 return;
	}
	ptrav=phead;
	while(ptrav->next!=NULL)
	{
	 //p++;
	 //printf("node-%d:%d\n",p,ptrav->x);
	 ptemp=ptrav;
	 ptrav=ptrav->next;	
	}
	free(ptrav);
	ptrav=NULL;
	ptemp->next=NULL;
}
		 
#endif

#if 1 //by using single structure pointer
void removenodefromtail()
{
	struct node *ptrav;
	if(phead==NULL)
	{
	 printf("list is empty....");
	 return;
	}
	ptrav=phead;
	while(ptrav->next->next!=NULL)
	{
	    ptrav=ptrav->next;	
	}
	free(ptrav->next);
	ptrav->next=NULL;
}

#endif

void addnodetohead(int val)
{
	struct node *pnew;
	pnew=malloc(sizeof(struct node));
	pnew->x=val;
	//printf("add node to head...:%d",pnew->x=val);	
	pnew->next=NULL;
	pnew->next=phead;
	phead=pnew;
}
void removenodefromhead()
{
	struct node *ptemp;
	if(phead==NULL)
	{
	  printf("LIST IS EMPTY");
	  return;
	}
	ptemp=phead;
	phead=phead->next;
 	free(ptemp);
}
void insertnode(int val)
{
	struct node *ptrav,*pnew,*ptemp;
	pnew=malloc(sizeof(struct node));
	pnew->x=val;
	pnew->next=NULL;
	if(phead==NULL)
	{
	  printf("LIST IS EMPTY");
	  return;
	}
	ptrav=phead;
	while(ptrav->x<val)
	{
	 ptemp=ptrav;
	 ptrav=ptrav->next;
	}
	pnew->next=ptrav;
	ptemp->next=pnew;	
	//pnew->next=ptrav;
}
void deletenode(int val)
{
	struct node *ptrav,*ptemp;
	if(phead==NULL)
	{
	  printf("LIST IS EMPTY");
	  return;
	}
	ptrav=phead;
	while(ptrav->x!=val)
	{
	  ptemp=ptrav;
	  ptrav=ptrav->next;
	}
	ptemp->next=ptrav->next;
	free(ptrav);
}
/*	struct node *ptrav;
	if(phead==NULL)
	{
	  printf("LIST IS EMPTY");
	  return;
	}
	ptrav=phead;
	while(ptrav->next->next!=NULL)
	{

*/
	  








