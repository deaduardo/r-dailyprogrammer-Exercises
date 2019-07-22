/* Perfectly Balanced 

Examine if number of all occuring chars in a string is equal, return true if equal, false if unequal

Normal: only detect x's and y's
Bonus: detect all characters in a string
Link: https://www.reddit.com/r/dailyprogrammer/comments/afxxca/20190114_challenge_372_easy_perfectly_balanced/ 

CONCEPTS: map - similar to dictionary in Python
              - is an array of pair value
see more: https://thispointer.com/stdmap-tutorial-part-1-usage-detail-with-examples/

*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

bool PerfectlyBalanced(string input) {
  int xCount = 0;
  int yCount = 0;

  for (int i = 0; i < input.length(); i++) {
    if (input[i] == 'x' || input[i] == 'X') 
      xCount++;
    else if (input[i] == 'y' || input[i] == 'Y')
      yCount++;
  }
    if (xCount == yCount)
      return true;
    return false;
}

bool PerfectlyBalancedBonus(string input) {
  // initialize map 
  map<char,int> myMap;
  
  // for every character in string 
  for (int i = 0; i < input.length(); i++) {
    // if char not in map 
    if (myMap.find(input[i])==myMap.end()) {
      // make a new char:int combo
      myMap.insert(make_pair(input[i], 1));
    }
    else { // if char is in map
    // increment int value for that char
      myMap[input[i]] += 1;
    }
  }
  int temp = 0;
  map<char,int>::iterator it = myMap.begin();
  while (it != myMap.end()) {
    // set value for 1st pointer
    int n1 = it->second;
    //cout << it->first << ": n1 is " << n1 << endl;
    // increment 1st pointer to 2nd position
    it++;
    // set value for 2nd position pointer 
    int n2 = it->second;
    //cout << it->first << ": n2 is " << n2 << endl << endl;

    // if 1st value != 2nd value - return false
    if (n1 != n2 && n2 != 0) 
      return false;
  }
  return true;
}
int main() {
  //cout << PerfectlyBalanced("xyy");

  cout << PerfectlyBalancedBonus("abccdabcd");
  /*map<string,int> mapp;
  mapp["a"] = 12;
  mapp["b"] = 34;

  map<string,int>::iterator it2 = mapp.begin();
  int nuu = it2->second;
  it2++;
  //it2--;
  int nu = it2->second;
  cout << nuu << endl;
  cout << nu << endl;*/
}
