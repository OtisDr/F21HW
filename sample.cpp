#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int SIZE = 100,
          TOTAL = 52,
          FIRST = 10,
          MIDDLE = 10,
          LAST = 20,
          ID = 9,
          AGE = 3; 
 
struct Student {
  
  char first[FIRST+1];
  char middle;
  char last;
  char studentID;
  int age;

};

int main() {
  
  ifstream f;
  f.open("/Users/jhsun/COMSC200/a2data.input", ios::in );
  
  if (!f.is_open()) {                 //Test stream
    cout << "Invalid file." << endl;
    exit (1);
  }

  cout << "1.we open the file.\n";

  Student info;
  
  //f.read(reinterpret_cast< char *>(&info), sizeof(TOTAL));

  
  char *firstPtr[FIRST+1] = new char;
  
  f.read(reinterpret_cast<char *>(&firstPtr), sizeof(FIRST));
  for (int i = 0; i < FIRST; i++){
    cout << firstPtr[i] << endl<< endl;


  }
  firstPtr[10] = '\0';
  
  string temp;
  temp = firstPtr;
  cout << firstPtr << "******" << temp << endl;
  temp = info.first;
  delete firstPtr;

  /*
  char * middlePtr = nullptr;
  middlePtr = new char[MIDDLE+1];

  for (int i = FIRST ; i < FIRST + MIDDLE; i++){
    middlePtr[i];
  }

  middlePtr[0] = info.middle;
  cout << middlePtr[0] << "+++MIDDLE+++" << info.middle << endl;

  delete middlePtr;
  
  char * lastPtr = nullptr;
  lastPtr = new char[MIDDLE+1];

  for (int i = FIRST + MIDDLE; i < FIRST + MIDDLE + LAST; i++){
    lastPtr[i];
  }
  
  lastPtr[LAST] = '\0';
  
  string tempp;
  temp = lastPtr;
  cout << lastPtr << "++++LastName+++" << tempp << endl;
  temp = info.last;
  delete lastPtr;
  */  

  

  //while(!f.eof()){

    //dynamically allocate space for a newstudent variable
    //populate the student variable from the input
    //read the next input record

  
  
  //}
  f.close();
  //displayList ;
  //ageCalc;
  //display the average age and the name of the oldest student

  

  
  /*
  delete[] stPtr; //avoids a memory leak
  stPtr = nullptr; //avoids a dangling pointer
  */
  
  return 0;

  

  
}

