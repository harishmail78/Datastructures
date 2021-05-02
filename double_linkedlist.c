#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *prv;
	int val;
	struct node *nxt;
};
struct node *phead;
void addnodetotail(int x);
void displaynodes();
void removenodefromtail();
void addnodetohead(int x);
void removenodefromhead();
void insertnode(int x);
void deletenode(int x);
void reverse_double_linledlist(struct node **head_ref);
void main()
{
	int flag,n,val,x;
	while(1)
	{	
	 printf("\nenter your choice...............:");	
	 printf("\nif you want create nods ..press=1:");
	 printf("\ndisplay all the nodes   ..press=2:");
	 printf("\nRemove node from tail.....press=3:");
	 printf("\nAdd node to head..........press=4:");
	 printf("\nRemove node frome head....press=5:");
	 printf("\nInset node................press=6:");
	 printf("\nDelete node...............press=7:");
	 printf("\nReverse doublelinkedlist "press=8:");
	 printf("\npress any other key to exit:...:\n");
	
	scanf("%d",&flag);	
	switch(flag)
	{
 	case 1: addnodetotail(1);
		break;
	case 2: displaynodes();
		break;
	case 3: removenodefromtail();
		break;
	case 4: printf("enter the new head value:");
		scanf("%d",&x);
		addnodetohead(x);
		break;
	case 5: removenodefromhead();
		break;
	case 6: printf("enter the insert node value:");
		scanf("%d",&x);
		insertnode(x);
		break;
	case 7: printf("enter the delete node value:");
		scanf("%d",&x); 
		deletenode(x);
		break;
	casne 8: reverse_double_linledlist(&head);	
	default:exit(1);	
	}
	}
}
int c=0;
void addnodetotail(int x)
{
	struct node *pnew,*ptrav;
	printf("enter the value:");
	scanf("%d",&x);
	pnew=malloc(sizeof(struct node));
	pnew->val=x;
	pnew->prv=NULL;
	pnew->nxt=NULL;
	c++;
	if(phead==NULL)
	{
	 phead=pnew;
	 printf("node-%d:%d\n",c,pnew->val);
	 return;
	}
	ptrav=phead;
	while(ptrav->nxt)
	{
	 ptrav=ptrav->nxt;
	}
	ptrav->nxt=pnew;
	printf("node-%d:%d\n",c,x);
	pnew->prv=ptrav;
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
	 printf("node-%d:%d\n",d,ptrav->val);
	 ptrav=ptrav->nxt;	
	}
}
void removenodefromtail()
{
	struct node *ptrav;
	if(phead==NULL)
	{
	 printf("list is empty\n");
	 return;
	}
	ptrav=phead;
	while(ptrav->nxt)
	{
	 ptrav=ptrav->nxt;
	}
	ptrav->prv->nxt=NULL;
	free(ptrav);
}
void addnodetohead(int x)
{
	struct node *pnew;
	pnew=malloc(sizeof(struct node));
	pnew->val=x;
	pnew->nxt=NULL;
	pnew->prv=NULL;
	if(phead==NULL)
	{
	 printf("LIST IS EMPTY");
	  return;
	}
	pnew->nxt=phead;
	phead->prv=pnew;	
	phead=pnew;
}
#if 0
void removenodefromhead()
{
	struct node *ptemp;
	if(phead==NULL)
	{
	  printf("LIST IS EMPTY");
	  return;
	}
	ptemp=phead;
	phead=phead->nxt;
	phead->prv=NULL; 	
	free(ptemp);
}
#endif

#if 1
void removenodefromhead()
{
	if(phead==NULL)
	{
	  printf("LIST IS EMPTY");
	  return;
	}
	phead=phead->nxt;
	free(phead->prv);
	phead->prv=NULL;
}
#endif
void insertnode(int x)
{
	struct node *ptrav,*ptemp,*pnew;
	pnew=malloc(sizeof(struct node));
	pnew->val=x;
	pnew->prv=NULL;
	pnew->nxt=NULL;
	if(phead==NULL)
	{
	  printf("list is empty:");
	  return;
	}
	ptrav=phead;
	while(ptrav->val<x)
	{	
	  ptrav=ptrav->nxt;
	}
	ptrav->prv->nxt=pnew;
	pnew->prv=ptrav->prv;
	pnew->nxt=ptrav;
	ptrav->prv=pnew;
}
void deletenode(int x)
{
	struct node *ptrav,*ptemp;
	if(phead==NULL)
	{
	  printf("LIST IS EMPTY");
	  return;
	}
	ptrav=phead;
	while(ptrav->val!=x)
	{
	  ptemp=ptrav;
	  ptrav=ptrav->nxt;
	}
	ptemp->nxt=ptrav->nxt;
	ptrav->nxt->prv=ptemp;
	free(ptrav);
}
void reverse_double_linledlist(struct node **head_ref)
{
	struct node *temp=NULL;
	struct node *current=**head_ref;
	//swap next and prev for all nodes od double linked list
	while(current!=NULL)
	{
		temp = current->prv;
		current->prv=current->next;
		current-next=temp;
		current=current->prv;
	}	
	if(temp!=NULL)
	 *head_ref = temp->prv;
		
}	


















