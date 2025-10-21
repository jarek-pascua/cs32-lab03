#include <string>
#include "studentRoll.h"
#include <sstream>

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
  Node *n = new Node; 
  n->s = new Student(s); 
  n -> next = NULL; 

  if(head == NULL) {
      head = n; 
      tail = n; 
  }
  else {
      tail->next = n; 
      tail = n; 
  }
}

std::string StudentRoll::toString() const {
    std::ostringstream oss;
    Node* curr = head; 
    bool beg = true; //beg = beginning of LL
    oss << "["; 
    while(curr != NULL) {
        if(!beg) {    //In order to get format right
            oss << ","; 
        }
        else {
            beg = false; 
        }
        oss << curr -> s -> toString();
        curr = curr -> next; 
    }
    oss << "]";
    return oss.str();
}

StudentRoll::StudentRoll(const StudentRoll &orig) {
  head = NULL;
  tail = NULL;
  Node* curr = orig.head; 
  while(curr != NULL) {
      insertAtTail(*(curr->s));
      curr = curr -> next;
  }
}

StudentRoll::~StudentRoll() {
  Node* curr = head; 
  while (curr != NULL) {
      Node* next = curr -> next; 
      delete curr -> s; 
      delete curr; 
      curr = next; 
  }
  head = NULL; 
  tail = NULL;
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...
  Node* curr = head; 
  while(curr != NULL){
      Node *next = curr -> next; 
      delete curr -> s; 
      delete curr; 
      curr = next; 
  }
  head = NULL;
  tail = NULL;
  curr = right.head; 
  while(curr != NULL) {
      insertAtTail(*(curr->s));
      curr = curr -> next;
  }


  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}





