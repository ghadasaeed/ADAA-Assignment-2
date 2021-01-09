#include <vector>
#include "LinkedList.cpp"

template <typename T>
class HashTable {
  vector< LinkedList<T> > table;
  int hashfunction (int hashitem) { // hash function
    return hashitem % table.size() ;
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
    int location = hashfunction(AsciiValue(newItem));
    table[location].insertFront(newItem);

  }

  bool retrieve (T target) {
    int location = hashfunction(AsciiValue(target));
    if(table[location].find(target)){
      return true;
    }
    
    return false;
      
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
