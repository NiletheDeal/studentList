#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

struct student{
  char first_name[20];
  char last_name[20];
  int studentID;
  float gpa;
};

void DELETE(int id, vector<student*>* studentList);
void PRINT(vector<student*>* studentList);
student* ADD() {
  student* ns = new student();
  cout << "Enter first name: " << endl;
  cin >> ns -> first_name;
  cout << "Enter last name: " << endl;
  cin >> ns -> last_name;
  cout << "Enter ID number: " << endl;
  cin >> ns -> studentID;
  cout << "Enter GPA: " << endl;
  cin >> ns -> gpa;
  return ns;
}
void PRINT(vector<student*>* studentList) {
  vector<student*>::iterator print;
  for (print = studentList->begin(); print != studentList->end(); print++) {
    cout << (*print)->first_name << ", ";
    cout << (*print)->last_name << ", ";
    cout << (*print)->studentID << ", ";
    cout << fixed << setprecision(2) << (*print) ->gpa << endl;//Rounds GPA to 2 decimal places and prints(3.40 vs 3.4)
    cout << endl;
  }
}
void DELETE(int id, vector<student*>* studentList) {
  vector<student*> :: iterator del;
  for (del = studentList->begin(); del != studentList->end(); del++) {
    if ((*del)->studentID == id) {
      cout << "Deleted student ID #: " << id << endl;
      delete* del;
      studentList->erase(del);
      return;
    }
  }
  //If the ID doesn't exist
  cout << "Invalid ID." << endl;
}

int main() {
  char command[6];
  bool running = true;
  vector<student*>* studentList = new vector<student*>();//a pointer to a vector(array) of student pointers.
  //All to make sure you can edit both each student and the whole list
  cout << "Welcome to Student List." << endl;
  while (running == true) {
    cout << "ADD, PRINT, DELETE, QUIT" << endl;
    cin >> command;
    if (command[0] == 'A' && command[1] == 'D' && command[2] == 'D') {
      cout << "Adding a new student: " << endl;
      studentList->push_back(ADD());
    }
    else if (command[0] == 'P' && command[1] == 'R' && command[2] == 'I' && command[3] == 'N' && command[4] == 'T') {
      cout << "Printing the Student List: " << endl;
      PRINT(studentList);
    }
    else if (command[0] == 'D' && command[1] == 'E' && command[2] == 'L' && command[3] == 'E' && command[4] == 'T' && command[5] == 'E') {
      char delCheck;
      cout << "You are about to delete a student. Are you sure? (y/n)";
      cin >> delCheck;
      bool deleteChecking = true;
      while (deleteChecking == true) {
	if (delCheck == 'y' || delCheck == 'Y') {
	  cout << "Deleting Student." <<endl;
	  deleteChecking = false;
	  cout <<"Enter the student ID you want to delete: " << endl;
	  int IDdel;
	  cin >> IDdel;
	  DELETE(IDdel, studentList);
	}
	else if (delCheck == 'n' || delCheck == 'N') {
	  cout << "Back to main menu " << endl;
	  deleteChecking = false;
	}
	else{
	  cout << "Invalid input. Please input a 'y' or 'n'" << endl;
	}
      }
    }
    else if (command[0] == 'Q' && command[1] == 'U' && command[2] == 'I' && command[3] == 'T') {
      cout << "Quitting program" << endl;
      running = false;
    }
    else {
      cout << "Invalid Input. Type a valid Command in Capitals." << endl;
    }

    
  
  }
}
