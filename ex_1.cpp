#include <iostream>
using namespace std;
#include "DynamicArray.h"

int main() {
  cout << "[Hello DynamicArray!]" << endl;


  DynamicArray<int> da;
  int isize = da.capacity();
  cout <<isize << endl;
  da.push_back(1);
  da.push_back(2);
  da.push_back(3);
  da.push_back(4);
  da.push_back(5);
  da.push_back(6);
  da.push_back(7);
  da.push_back(8);
  da.push_back(9);
  da.push_back(10);
  int size = da.capacity();
  cout << size << endl;
  da.reverse();
  int revcap = da.capacity();
  cout << "Reversed size is: " <<  revcap << endl;


  int revsize = da.size();
  for(int i; i <= revsize; i++){
    cout << da[i] << endl;
  }

  return 0;
}
