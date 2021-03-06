#include <iostream>
using namespace std;
#include <vector>

int main() {
  cout << "[Hello DynamicArray!]" << endl;


  vector<int> numbers;
  vector<int> primes;
  //DynamicArray<int> da2;

  int t = 100000;

  for( int i= 0; i < t + 1; i++){
      numbers.push_back(i);
  }
  //cout << numbers.size() << endl;

  for(int i = numbers.size(); i > 1; i--) {
     int arrValue = numbers[i];
     int b = arrValue;
     //cout << arrValue << endl;
     //int n;
     int tick = 0;
     int remainder;
     //cout << arrValue << endl;
     for( b; b > 0; b--) {
         remainder = arrValue % b;
         //cout << "Remainder is " << remainder << endl;
         if (remainder == 0){
             tick ++;
         }
     //cout << "Tick is " << tick << endl;    
     }
     if( tick == 2){
         primes.push_back(arrValue);
         //cout << arrValue << "Is a prime!" << endl;
     }
     
     }
      

  for (int i = 0; i < primes.size(); i ++){
      cout << primes[i] << endl;
  }
      

}
