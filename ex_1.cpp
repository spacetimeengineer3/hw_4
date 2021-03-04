#include <iostream>
#include <unistd.h> // Gives us access to the sleep(int seconds) function
#include "Timer.h"
using namespace std;

int main() {

  Timer t;
  //test to make sure that getTime() is 0
  /*
  cout << t.getTime() << endl;



  t.start();                   // Start the clock
  sleep(2);                    // Sleep for 2 seconds
  cout << t.getTime() << endl; // Should print approximately 2.0

  sleep(1);                    // Sleep for 1 second
  t.stop();                    // Stop the clock
  cout << t.getTime() << endl; // Should print approximately 3.0 

  t.clear();                   // Reset the stopped clock
  cout << t.getTime() << endl;// Should print 0
  //test 0.1 seconds, then clear (GOOD) DELETEING NOW
  //test 0.1 seconds, get time, then another 0.1 seoncds.
  //GOOD, DELETEING NOW
  //Test wether start will reset the beginning time or no
  //t GOOD DELETING
  */
  //Test wether starting and stoping during the middle will acidentally clear it. GOOD DELETING
  //
  //test wether clear will clear things correctly
  //DEBUGGED DELETING
  //Bug fix led to a new bug, test 3 of stop start issue again
  t.start();
  sleep(3);
  t.stop();
  cout << t.getTime() << endl; //should return 3ish
  t.start();
  sleep(2);
  t.stop();
  cout << t.getTime() <<endl; //should return 5ish





  return 0;
}

