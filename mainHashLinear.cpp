#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <cstdlib>
#include "HashTableLinear.cpp"

using namespace std;
using namespace std::chrono; 

int main() {
  // initialization 
  ifstream file("emailsSetA.txt");
  const int n = 100;
  string email;
  string target;

  // Declare a hashtable of int named "ht", size is 10% smaller than the data set.
  HashTable<string> ht(n*1.5);

  cout << "Hash Table Using Linear Probing method.\n";
  // Insert email from textfile into ht.
  auto start = high_resolution_clock::now();
  while(getline(file,email)){
    ht.insert(email);
  }
  auto end =  high_resolution_clock::now();
  file.close();
  
  //display insertion time
  auto duration = duration_cast<milliseconds>(end - start);
  cout << endl;  
  cout << "Insert Duration: " << duration.count() << " milliseconds\n";
  
  ifstream searchfile("SetACanFound.txt");
  cout << "Search 10 emails that can be found :\n";
  start =  high_resolution_clock::now();
  while(getline(searchfile,target)){
    if(!ht.retrieve(target)){
      cout << "Not Found\n";
      //break;
    }
  }
  end = high_resolution_clock::now();
  int duration2 = duration_cast<milliseconds>(end - start).count();
  cout << "Duration: " << duration2 << " milliseconds\n";
  long int average = duration2/10;
  cout << "Average Time: " << average << " milliseconds\n";
  searchfile.close();

  ifstream searchfilenot("emailNotFound.txt");
  cout << "Search 10 emails that cannot be found :\n";
  start =  high_resolution_clock::now();
  while(getline(searchfilenot,email)){
    if(ht.retrieve(email)){
      cout << "Found\n";
      //break;
    }
  }
  end =  high_resolution_clock::now();
  int duration3 = duration_cast<milliseconds>(end - start).count();
  cout << "Duration: " << duration3 << " milliseconds\n";
  long int average2 = duration3/10;
  cout << "Average Time: " << average2 << " milliseconds\n";
  searchfilenot.close();
}
