#include <iostream>
using namespace std;
#include "DynamicArray.h"

int main() {
  cout << "[Hello DynamicArray!]" << endl;


  DynamicArray<int> da;
  int isize = da.capacity();
  cout <<isize << endl;
  
  for (int i = 0; i < 10; i++){
          da.push_back(i);
          }
        
  int size = da.capacity();
  cout << size << endl;
  da.reverse();
  cout << "TEST" << endl;
  int revcap = da.capacity();
  cout << "Reversed capacity is: " <<  revcap << endl;


  int revsize = da.size();
  //int revcap = da/capicity();

  cout << "New Size is"  << revsize << endl;

  for(int i = 0; i < revsize + 1; i++){
    cout << da[i] << endl;
  }

 cout << "TEST2" << endl;
  return 0;
}
