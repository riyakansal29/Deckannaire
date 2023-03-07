
#include "card.h"  
#include <cctype>
#include <cstring>

struct node 
{
  card cards;
  node *next;
};

class queue 
{
  private:
  node *rear;

  public:
queue() 
{ 
  rear=NULL; 
}

~queue() 
{
  if (rear!=NULL) 
  {
    node *head=rear->next;
    rear->next=NULL;
    node *temp=head->next;
    while(head!=NULL) 
    {
      delete head;
      head=head->next;
    }
  }
}

int enqueue(card &to_add) 
{
  if (rear==NULL) 
  {
    rear=new node;
    rear->cards.copy_card(to_add);
    rear->next=rear;
    return 1;
  }
  node *temp=new node;
  temp->cards.copy_card(to_add);
  temp->next=rear->next;
  rear->next=temp;
  rear=temp;
  return 1;
}

int dequeue(card &to_delete) 
{
  if (rear!=NULL) 
  {
    if(rear->next==rear) 
    {
      rear->cards.get_card(to_delete);
      delete rear;
      rear=NULL;
      return 1;
      
    }
    node *temp=rear->next;
    temp->cards.get_card(to_delete);
    rear->next=temp->next;
    delete temp;
    return 1;
  }
  return 0;
}

int displayall() 
{
  if (rear == NULL)
      return 0;
  else if (rear->next==rear) 
  {
    rear->cards.display_question();
    rear->cards.display_answer();
    return 1;
  }
  node *temp=rear->next;
  while (temp!=rear) 
  {
    temp->cards.display_question();
    temp->cards.display_answer();
    temp=temp->next;
  }
  rear->cards.display_question();
  rear->cards.display_answer();
  return 1;
}

int display_question() 
{
  if(rear!=NULL) 
  {  
    rear->next->cards.display_question();
    return 1;
  }
  return 0;
}

int deck_empty(){
    if(rear==NULL)
      return 1;
    return 0;
}

};


