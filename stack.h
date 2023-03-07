#include "queue.h"
#include <iostream>
#include <ctype.h>
#include <string.h>

int const maximum = 5;

struct s_node
{
  card *card;
  s_node *next;
};

class stack_pile
{
private:
  s_node *head;
  int index_at_top;


public:

stack_pile()
{
  index_at_top = 0;
  head = NULL;
}

~stack_pile() 
{
  s_node *temp;
  while (head != NULL) {
    temp = head->next;
    delete[] head->card;
    delete head;
    head = temp;
  }
}


int push_question(card &to_add) 
{
  if (head == NULL) {
    index_at_top = 0;
    head = new s_node;
    head->card = new card[maximum];
    head->next = NULL;
    head->card[index_at_top].copy_card(to_add);
    ++index_at_top;
    return 1;
  } else if (index_at_top < 5) {
    head->card[index_at_top].copy_card(to_add);
    ++index_at_top;
    return 1;
  } else {
    index_at_top = 0;
    s_node *temp = new s_node;
    temp->card = new card[maximum];
    temp->card[index_at_top].copy_card(to_add);
    ++index_at_top;
    temp->next = head;
    head = temp;
    return 1;
  }
  return 0;
}


int pop_top_question(card &to_pop) 
{
  if (head == NULL) {
    return 0;
  } else if (index_at_top > 0) {
    --index_at_top;
    head->card[index_at_top].get_card(to_pop);
    return 1;
  } else if (index_at_top == 0) {

    s_node *temp = head->next;
    temp->card[4].get_card(to_pop);
    delete[] head->card;
    delete head;
    head = temp;
    index_at_top = 5;
    return 1;
  }
  return 0;
}


int peek() {
  if (!head)
    return 0;
  else if (index_at_top > 0) {
    head->card[index_at_top - 1].display_question();
    return 1;
  }
  s_node *temp = head->next;
  if (temp != NULL) {
    temp->card[4].display_question();
    return 1;
  }
  return 0;
}

int displayall() 
{
  int current = index_at_top;

  for (s_node *temp = head; temp != NULL; temp = temp->next)
   {
    for (int i = current; i > 0; --i)
     {
      temp->card[i - 1].display_question();
      temp->card[i - 1].display_answer();
    }
    current = 5;
  }
  return 1;
}
};


