//#include "stack.h"
#include <string.h>
#include <fstream>
#include <iostream>
using namespace std;

int const n = 100;
int main() 
{
 // stack_pile st_pile;
 // queue qu_deck;

 /*load questions and answers from questions.txt and save cards in queue*/
 
  char tmp[n];
  char tmp1[n];
  char *ques;
  char *ans;
  ifstream file_in;
  file_in.open("questions.txt");
  if (file_in) 
  {
    file_in.get(tmp, n, '?');
    while (!file_in.eof()) 
    {
      file_in.ignore(n, '?');
      file_in.get(tmp1, n, '\n');
      file_in.ignore(n, '\n');
      ques = new char[strlen(tmp) + 1];
      strcpy(ques, tmp);
      ans = new char[strlen(tmp1) + 1];
      strcpy(ans, tmp1);
     // card a_card;
      //a_card.create_card(ques, ans);
      //qu_deck.enqueue(a_card);
      delete[] ques;
      delete[] ans;
      file_in.get(tmp, n, '?');
    }
    file_in.close();
  }

    cout<<"\n\t\t\t\t\t**********************************************************";
    cout<<"\n\t\t\t\t\t*                                                        *";
    cout<<"\n\t\t\t\t\t*                       W E L C O M E                    *";
    cout<<"\n\t\t\t\t\t*                                                        *";
    cout<<"\n\t\t\t\t\t*                           T O                          *";
    cout<<"\n\t\t\t\t\t*                                                        *";
    cout<<"\n\t\t\t\t\t*                   D E C K N N A I R E                  *";
    cout<<"\n\t\t\t\t\t*                                                        *";
    cout<<"\n\t\t\t\t\t**********************************************************"<<endl<<endl<<endl;


  // game starts
  int marks = 0;
 // card container;
  char user_response[n];
  char choice;
  int i=0;
  while (marks < 5 && (i<10)) 
  {

    /* display the top card in the stack and ask the user whether to answer this question. if not, dissplay the question in pile*/

    /*if (st_pile.peek() == 0) 
    {
      qu_deck.display_question();
      qu_deck.dequeue(container);
    } 
    else 
    {
      cout << "Want to try this question again (Y/N) ? ";
      cin >> choice;
      cout<<endl;
      cin.ignore(n, '\n');
      if (toupper(choice) == 'N') 
      {
 
        qu_deck.display_question();
        qu_deck.dequeue(container);
      } 
      else 
        st_pile.pop_top_question(container);
    }*/
    
    cout << "Enter your answer : ";
    cin.get(user_response, n, '\n');
    cin.ignore(n, '\n');
    //score++,place card at bottom of deck if right answer,else move the card to the top of the pile.
    /*if (container.check_answer(user_response) == 1) 
    {
      ++marks;
      cout << "\n___________" << endl;
      cout << "Wohoo, you're a pro!!" << endl;
      cout << "Your score is: " << marks << endl<<endl;
      qu_deck.enqueue(container);
    } 
    else 
    {
      cout << "\n___________" << endl;
      cout << "Oops!! Wrong answer!\nContinue."<<endl;
      cout << "\n___________" << endl;
      st_pile.push_question(container);
    }
    i++;
  }*/
  if (marks == 5)
    cout << "Congrats !! You win! Game over!" << endl;
  else
    cout << "Sorry !! You lose! Game over!" << endl;
  return 0;
}
