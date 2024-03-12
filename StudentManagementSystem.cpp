/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include <cstring>

using namespace std;

const int MAX_STUDENTS = 100;

struct Student {
  int id;
  char name[50];
  float gpa;
};

int studentCount = 0;
Student students[MAX_STUDENTS];


void insertStudent();
void deleteStudent(int id);
void displayStudents();
void searchStudent(int id);

int main() {
  int choice;

  do {
    cout << "\n--- Student Database Management System ---\n";
    cout << "1. Insert Student\n";
    cout << "2. Delete Student\n";
    cout << "3. Display Students\n";
    cout << "4. Search Student\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        insertStudent();
        break;
      case 2:
        int idToDelete;
        cout << "Enter student ID to delete: ";
        cin >> idToDelete;
        deleteStudent(idToDelete);
        break;
      case 3:
        displayStudents();
        break;
      case 4:
        int idToSearch;
        cout << "Enter student ID to search: ";
        cin >> idToSearch;
        searchStudent(idToSearch);
        break;
      case 5:
        cout << "Exiting...\n";
        break;
      default:
        cout << "Invalid choice!\n";
    }
  } while (choice != 5);

  return 0;
}

void insertStudent() {
  if (studentCount == MAX_STUDENTS) {
    cout << "Error: Database is full!\n";
    return;
  }

  Student newStudent;

  cout << "Enter student ID: ";
  cin >> newStudent.id;

  cout << "Enter student name: ";
  cin.ignore(); 
  cin.getline(newStudent.name, 50);

  cout << "Enter student GPA: ";
  cin >> newStudent.gpa;

  students[studentCount] = newStudent;
  studentCount++;

  cout << "Student inserted successfully!\n";
}

void deleteStudent(int id) {
  bool found = false;
  for (int i = 0; i < studentCount; i++) {
    if (students[i].id == id) {
      found = true;
      for (int j = i; j < studentCount - 1; j++) {
        students[j] = students[j + 1];
      }
      studentCount--;
      break;
    }
  }

  if (found) {
    cout << "Student deleted successfully!\n";
  } else {
    cout << "Student with ID " << id << " not found!\n";
  }
}

void displayStudents() {
  if (studentCount == 0) {
    cout << "No students found in database!\n";
    return;
  }

  cout << "\n--- Student List ---\n";
  cout << "ID\tName\tGPA\n";
  for (int i = 0; i < studentCount; i++) {
    cout << students[i].id << "\t" << students[i].name << "\t" << students[i].gpa << endl;
  }
}

void searchStudent(int id) {
  bool found = false;
  for (int i = 0; i < studentCount; i++) {
    if (students[i].id == id) {
      found = true;
      cout << "\n--- Student Details ---\n";
      cout << "ID: " << students[i].id << endl;
      cout << "Name: " << students[i].name << endl;
      cout << "GPA: " << students[i].gpa << endl;
      break;
    }
  }

  if (!found) {
    cout << "Student with ID " << id << " not found!\n";
  }
}
