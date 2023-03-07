#include <iostream>
#include <string.h>

using namespace std;

class card {

private:
  char *question;
  char *answer;

public:
  card() {
    question = NULL;
    answer = NULL;
  }

  ~card() {
    delete[] question;
    delete[] answer;
  }

  int create_card(char *ques, char *ans) {
    if (ques) {
      question = new char[strlen(ques) + 1];
      strcpy(question, ques);
    }
    if (ans) {
      answer = new char[strlen(ans) + 1];
      strcpy(answer, ans);
    }
   return 1;
  }

  int copy_card(card &copy_from) {
    if (copy_from.question) {
     question = new char[strlen(copy_from.question) + 1];
      strcpy(question, copy_from.question);
    }
    if (copy_from.answer) {
      answer = new char[strlen(copy_from.answer) + 1];
      strcpy(answer, copy_from.answer);
    }
    return 1;
  }

  int get_card(card &current_card) {
    current_card.question = new char[strlen(question) + 1];
    strcpy(current_card.question, question);
    current_card.answer = new char[strlen(answer) + 1];
    strcpy(current_card.answer, answer);
    return 1;
  }

  int display_card() {
    if (display_question() == 1 && display_answer() == 1)
      return 1;
    return 0;
  }

  int display_question() {
    if (question != NULL) {
      cout << "Q : " << question << endl;
      return 1;
    }
    return 0;
  }

  int display_answer() {
    if (answer != NULL) {
     cout << "A : " << answer << endl;
      return 1;
    }
    return 0;
  }

  int check_answer(char *user_answer) {
    if (answer != NULL) {
      if (strcmp(answer, user_answer) == 0)
        return 1;
      else
        return 0;
    } 
    else
      return 0;
  }

};