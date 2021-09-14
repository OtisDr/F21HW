#include <stack>
#include <fstream>
#include <cctype>
#include <iostream>

using namespace std;

#define FILENAME "test_input.txt"

bool checkOrder (string, bool, stack<char> &);

int main() {

  ifstream f(FILENAME);
  stack<char> s;
  string tmp;
  bool failed = false;
  char item;
  int ct;

  //Make sure the file can be opened.
  if (!f.good()) {
    cout << "Invalid File." << endl;
    exit(-1);
  }

  //Outer Loop: for the entire file.
  while (true) {
    getline(f, tmp);
    int ct = stoi(tmp);
    
    for (int i = 0; i < ct; i++) {
      getline(f, tmp);
      checkOrder(tmp, failed, s);
      if (!s.empty()){
        failed = true;
      }
    }

    if (failed){
      cout << "invalid" << endl;
    }
    else{
      cout << "valid" << endl;
    }

    //we've hit EOF, done.ß
    if (f.eof())
      return 0;
  }
}

bool checkOrder(string order, bool failed, stack<char> &s) {

  char type = order[0];
  char place = order [2];
  
  if (type == 'P') {
    s.push(place);
  }
  else if (type == 'D') {
    if(place == s.top())
      s.pop();
    else {
      failed = true;
      return failed;
    }
  }
  else {    
    stack<char>().swap(s);
  }

  return failed;

}
