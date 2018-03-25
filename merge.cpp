#include<iostream>

using namespace std;

struct node
{
   int data;
   struct node *next;  
};

class list
{
   struct node *start;
   public:
      void create(); 
      void show();   
      void merge(list,list); 
};

int main()
{
   list l1,l2,l3;
   cout<<"Enter the First List in ascending order: ";
   l1.create(); 
   cout<<"Enter the Second List in ascending order: ";
   l2.create(); 
   l3.merge(l1,l2);
   l3.show();
   return (0);
}

void list::create()
{
   struct node *nxt_node,*pre_node;
   int value,no,i;
   start=nxt_node=pre_node=NULL;

   for(i=1;i<=3;i++)
   {
      cin>>value;
      nxt_node=new node;
      nxt_node->data=value;
      nxt_node->next=NULL;
      if(start==NULL)
	 start=nxt_node;
      else
	 pre_node->next=nxt_node;
      pre_node=nxt_node;
   }
}

void list::show()
{
   struct node *ptr=start;
   cout<<"The List is ";
   while(ptr!=NULL)
   {
      cout<<ptr->data<<" -> ";
      ptr=ptr->next;
   }
   cout<<"   ";
}

void list::merge(list l1,list l2)
{
   struct node *nxt_node,*pre_node,*pptr,*qptr;
   int dat;
   pptr=l1.start;
   qptr=l2.start;
   start=nxt_node=pre_node=NULL;
   while(pptr!=NULL && qptr!=NULL)
   {
      if(pptr->data<=qptr->data)
      {
	 dat=pptr->data;
	 pptr=pptr->next;
      }
      else
      {
	 dat=qptr->data;
	 qptr=qptr->next;
      }
      nxt_node=new node;
      nxt_node->data=dat;
      nxt_node->next=NULL;
      if(start==NULL)
	 start=nxt_node;
      else
	 pre_node->next=nxt_node;
      pre_node=nxt_node;
   }
   if(pptr==NULL)
   {
      while(qptr!=NULL)
      {
	 nxt_node=new node;
	 nxt_node->data=qptr->data;
	 nxt_node->next=NULL;
	 if(start==NULL)
	    start=nxt_node;
	 else
	    pre_node->next=nxt_node;
	 pre_node=nxt_node;
	 qptr=qptr->next;
      }
   }
   else if(qptr==NULL)
   {
      while(pptr!=NULL)
      {
	 nxt_node=new node;
	 nxt_node->data=pptr->data;
	 nxt_node->next=NULL;
	 if(start==NULL)
	    start=nxt_node;
	 else
	    pre_node->next=nxt_node;
	 pre_node=nxt_node;
	 pptr=pptr->next;
      }
   }
   return;
}


