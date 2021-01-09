#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <cstdlib>
#include "HashTable.cpp"

using namespace std;
using namespace std::chrono; 
int main() {
// initialization 
  ifstream file("emailsSetA.txt");
  const int n = 100;
  string email;
  string target;

// Declare a hashtable of int named "ht", size is 10% smaller than the data set.
  HashTable<string> ht(n*0.9);


  cout << "Hash Table Using Chaining method.\n";
// Insert email from textfile into ht.
  auto start = high_resolution_clock::now();
  int num = 0; 
  while(getline(file,email)){
    ht.insert(email);
  }
  auto end =  high_resolution_clock::now();
  file.close();

//display insertion time
  auto duration = duration_cast<milliseconds>(end - start);
  cout << endl;  
  cout << "Insertion Duration: " << duration.count() << " milliseconds\n";

//Search for 10 email that can be found from the data set
  ifstream searchfile("SetACanFound.txt");
  cout << "Search 10 emails that can be found :\n";
  start =  high_resolution_clock::now();
  while(getline(searchfile,email)){
    if(!ht.retrieve(email)){
      cout << "NotFound" << "\n";
    }
  }
  end = high_resolution_clock::now();
  auto duration2 = duration_cast<milliseconds>(end - start);
  cout << "Duration: " << duration2.count() << " milliseconds\n";
  chrono::duration<double> average = duration2/10;
  cout << "Average Time: " << average.count() << " milliseconds\n";
  

//Search for 10 email that cannot be found from the data set
  ifstream notsearchfile("emailNotFound.txt");
  cout << "Search 10 emails that can not found :\n";
  start =  high_resolution_clock::now();
  while(getline(notsearchfile,email)){
    if(ht.retrieve(email)){
      cout << "Not Found\n";
    }
  }
  end =  high_resolution_clock::now();
  auto duration3 = duration_cast<milliseconds>(end - start);
  cout << "Duration: " << duration3.count() << " milliseconds\n";
  chrono::duration<double> average2 = duration3/10;
  cout << "Average Time: " << average2.count() << " milliseconds\n";
  notsearchfile.close();
  //cout << "First 10 index of the hash table: \n" ;
  //cout << ht ;
}
