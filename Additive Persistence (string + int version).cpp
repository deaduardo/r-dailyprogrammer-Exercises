/**********************************************
 * Additive Persistence
 * See how many times we need to add all the digits of a number
 * together until the total sum is single digit
 * CONCEPTS: stoi , to_string , pow(10,i) , round(...)
 * recursive 
 * Link: https://www.reddit.com/r/dailyprogrammer/comments/akv6z4/20190128_challenge_374_easy_additive_persistence/ 
 **********************************************/

#include <iostream>
#include <cmath>
#include <string>
using namespace std;


int AdditivePersistenceStringVer(int num) {
  int sum = 11; // to set up the white condition below - make it true as first
  int limit = 9; // to check the new sum has 2 digits or not - whether to iterate again or not
  int count = 0;
  while (sum > limit) {
    // Change num to string to dissect
    string numstring = to_string(num);

    // Initialize sum 
    sum = 0;

    // loop to add into sum
    for (int i = 0; i < numstring.length() ; i++) {
      // isolate each digit in the string version
      char digit = numstring[i];
      // char -> int
      int newdig = digit - '0';
      // add into sum
      sum += newdig; 
    }
    // set sum to num to repeat the loop again
    num = sum;
    // number of loop iterations - return this
    count++;
  }
  return count;
}

int AdditivePersistenceIntVer(int num) {
  int sum = 11;
  int limit = 9;
  int count = 0;

  // to find numLen
  int numLen = 0;
  int numTemp = num;
  while (numTemp >= 1) {
    numTemp /= 10;
    numLen++;
  }

  while (sum > limit) {
    sum = 0;

    for (int i = 0; i < numLen; i++) {
      sum += ( num % int(round(pow(10,i+1))) ) / round(pow(10,i));
      /* Unblock this to see details 
      cout << "sum += ( " << num << " % " << int(round(pow(10,i+1))) << " ) / " << round(pow(10,i)) << endl;
      */
    }
    count++;
    num = sum;
  }
  return count;
}

int main() {
  cout << "Number of times for 199: " << AdditivePersistenceIntVer(199);
}
