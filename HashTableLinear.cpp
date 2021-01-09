#include <vector>
#include "LinkedListLinear.cpp" // available at MMLS.

template <typename T>
class HashTable {
  vector< LinkedList<T> > table;
  int hashfunction (int hashitem) { // hash function
    return hashitem % (table.size() + 1);
  }
 public:
  HashTable (int size) {
    table.resize (size); // resize vector to support size elements.
  }
  ~HashTable() {
    for (int i = 0; i < table.size(); i++)
      table[i].makeEmpty();
  }

  int size() {
    return table.size();
  }
 
  void insert (T newItem) {
    int collision = 0;
    int initLocation = hashfunction(AsciiValue(newItem));
    int targetlocation = initLocation;
    bool repeat = false;
    if(!table[targetlocation].find(newItem)){
      while(!table[targetlocation].isEmpty()){
        collision += 1;
        
        if(targetlocation >= table.size()){ 
          targetlocation = 0;     
        } 
        targetlocation++;
        if(targetlocation == initLocation)
          break;
      }
      table[targetlocation].insertFront(newItem,collision);
    } else {
        table[targetlocation].insertFront(newItem,collision);
    }
  }

  bool retrieve (T target) {
    bool found = false;
    int initLocation = hashfunction(AsciiValue(target));
    int searchLocation = initLocation;
    bool repeat = false;
    while(!found){
      if(table[searchLocation].find(target)){
        return true;
      }
      else 
        searchLocation++;  
      if(searchLocation >= table.size()){ 
        searchLocation = 0;   
        repeat = true;   
      }
      if(repeat == true && searchLocation == initLocation)
        break;
    }
     return found;
  }

  int AsciiValue(T newItem){
    int sum;
    for(int i = 0; i<newItem.length();i++){
      sum = sum + (int)newItem[i];
    }
    return sum * 987654;
  }

  friend ostream& operator<< (ostream& os, HashTable<T>& ht) {
    for (int i = 0; i < 10; i++)
      os << i << " = " << ht.table[i] << endl;
    return os;
  }
};
