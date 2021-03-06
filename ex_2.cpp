#include <iostream>
using namespace std;
#include "DynamicArray.h"

int main() {
  cout << "[Hello DynamicArray!]" << endl;


  DynamicArray<int> da;
  
  for (int i = 2; i < 100; i++){
          da.push_back(i);
          }
        
  for (int i = 2; i < 100; i=i + 2){
          cout << da[i] << endl;
          }
}        
