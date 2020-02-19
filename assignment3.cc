//******************************************************************//
//   PROGRAM:    CSCI 340 Assignment 3                              //
//   PROGRAMMER: Margaret Higginbotham                              //
//   LOGON ID:   z1793581                                           //
//   DUE DATE:   February 13, 2018                                  //
//                                                                  //
//   FUNCTION:   Finds and print all prime numbers within a range   //
//               using the Sieve of Eratosthenes algorithm          //
//******************************************************************//

#include <iostream>		//cout, cin, endl
#include <set>			//set
#include <iomanip>		//setw
#include <string>

const int NO_ITEMS = 6;		//Number of primes per line
const int ITEM_W = 4;		//Spaces allocated for each prime

using namespace std;

/***************************************************************
void sieve(set<int>& s, const int lower, const int upper)
Use: Applies the Sieve of Eratosthenes algorithm to remove
     all non prime numbers
Parameters: 1. set<int>& s- Integer set s
            2. const int lower- Smallest value in the set
            3. const int upper- Highest value in the set
Returns: Nothing
***************************************************************/
void sieve(set<int>& s, const int lower, const int upper){
  s.clear();					//Resets the set
  s.insert(2);					//lower and upper

  for(int i = 2; i <= upper; i++){		//Fills set
    s.insert(i);
  }

  set<int>::const_iterator it;
  set<int>::const_iterator it2;

  for(it = s.begin(); it != s.end(); it++){	//Loops through set

    //Condition 1: Checks if number is divisible by the other
    //Condition 2: Checks if number is the same as the other
    for(it2 = it; it2 != s.end(); it2++){
      if((*it2 % *it == 0) && (*it2 != *it)){
        s.erase(it2);				//If both are true
      }						//Then it's not a prime, remove it

    }

  }

  for(it = s.begin(); *it < lower;it ++){	//If the number is lower than
    s.erase(it);				//The smallest number in the
  }						//Range, remove it

}

/***************************************************************
void print_primes(const set<int>& s, const int lower, const int upper)
Use: Prints the elements in the integer set s
Parameters: 1. set<int>& s- Integer set s
            2. const int lower- Lowest value in the set
            3. const int upper- Highest value in the set
Returns: Nothing
***************************************************************/
void print_primes(const set<int>& s, const int lower, const int upper){
  int count = 0;
  set<int>::const_iterator it;			//Iterator

  cout << endl << "Number of prime numbers between " << lower << " and " << upper << " is " << s.size() << endl;

  for(it = s.begin(); it != s.end(); it++){
    if(count % NO_ITEMS == 0)			//Prints elements within
      cout << endl;				//The width

    cout << setw(ITEM_W) << *it;
    count++;
  }

  cout << endl << endl;
}

/***************************************************************
void run_game(set<int>& s)
Use: Maintains a loop to take inputs from the user
Parameters: 1. set<int>& s- Integer set s
Returns: Nothing
***************************************************************/
void run_game(set<int>& s){
  bool playAgain = true;

  while(playAgain){				//Starts the loop to play again
    cout << endl << "Enter the lower limit and upper limit with a space in between: ";
    int lower = 0;				//Input values
    int upper = 0;
    cin >> lower;
    cin >> upper;

    sieve(s, lower, upper);			//Calls the functions
    print_primes(s, lower, upper);

    cout << "Play again? Type yes or no: ";	//Prompts user to play again
    string input;
    cin >> input;

    if(input != "yes")				//If yes, loops program
      playAgain = false;			//Else, program ends
  }

}

int main() {
  set<int> s;
  run_game(s);

  return 0;
}
