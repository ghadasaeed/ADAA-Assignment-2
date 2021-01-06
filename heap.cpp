#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <cstdlib>
using namespace std;

string A[500000] = {};

template <typename T>
void printArray (T A[], int n) {
  for (int i = 0; i < 10; i++)
    cout << A[i] << " ";
  cout << endl;
}

template <typename T>
class PriorityQueue {
  vector<T> A;

  void heapify_enqueue (int index) {   // used in enqueue.
    if (index == 0)                    // if already at root.
      return;
    
    int parent_index = (index-1)/2;
	if(A[index].compare(A[parent_index])>0)
		swap(A[index], A[parent_index]);
		heapify_enqueue(parent_index);

  }
    
  void heapify_dequeue (int index) {   // used in dequeue.
    int max;                           // max index
    int left = 2*index+1;
    int right = 2*index+2;
    if(left < A.size() && A[left].compare(A[index])>0)
      max = left;
    else
      max = index;

    if(right < A.size() && A[right].compare(A[max])>0)
      max = right;

    if (max != index) {
      swap (A[index], A[max]);
      heapify_dequeue (max);
    }
  }
  
 public:
  void enqueue (T element) {
    A.push_back (element);
    heapify_enqueue (A.size()-1);  // start at last element.
  }
  
  T dequeue() {
    T removed_element = A[0];
    A[0] = A[A.size()-1];          // copy last element to root.
    A.pop_back();                  // remove last element.
    heapify_dequeue (0);           // start at root.
    return removed_element;
  }
  
  int size() {
    return A.size();
  }

  void print() {
    for (int i = 0; i < A.size(); i++)
      cout << A[i] << " ";
    cout << endl;
  }  
};

int main () {
  ifstream file("email.txt");
  if(!file.is_open()){
        cout << "File not found.";
  } 
  int i = 0;
  string email;
  while(getline(file,email)){
    A[i] = email;
	i++;
  }
  file.close();
  int n = sizeof(A)/sizeof(A[0]);
  cout << "Array = " << n << "\n";
  //printArray (A, 7);
  
  cout << "\nEnqueue\t: PriorityQueue\n";
  PriorityQueue<string> pq;
  auto start = chrono::system_clock::now();
  for (int i = 0; i < 500000; i++) {
    //cout << A[i] << "\t: ";
    pq.enqueue (A[i]);
    //pq.print();
  }
  auto end = chrono::system_clock::now();
  chrono::duration<double> duration = end - start;
  cout << "Time to enqueue: " << duration.count() << "s\n";
  
  cout << "\nDequeue\t: PriorityQueue\n";
  auto start2 = chrono::system_clock::now();
  for (int i = 0; i < (n*0.9); i++) {   
    pq.dequeue(); 
    //cout << pq.dequeue() << "\t: ";
    //pq.print();
  }
  auto end2 = chrono::system_clock::now();
  chrono::duration<double> duration2 = end2 - start2;
  cout << "Time to dequeue 10% of the data: " << duration2.count() << "s\n";
}
