#include <iostream>
#include <chrono>
#include <fstream>
#include <math.h>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
#include <map> 
#include <vector> 

using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
 

    int L[n1], R[n2];
 

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    // Merge the temp arrays back into arr[l..r]

    // Initial index of first subarray
    int i = 0;
 
    // Initial index of second subarray
    int j = 0;
 
    // Initial index of merged subarray
    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void dmerge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
 

    int L[n1], R[n2];
 

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    // Merge the temp arrays back into arr[l..r]

    // Initial index of first subarray
    int i = 0;
 
    // Initial index of second subarray
    int j = 0;
 
    // Initial index of merged subarray
    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = R[j];
            j++;
        }
        else {
            arr[k] = L[i];
            i++;
        }
        k++;
    }
 
    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int arr[],int l,int r){
    if(l>=r){
        return;//returns recursively
    }
    int m =l+ (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}

void dmergeSort(int arr[],int l,int r){
    if(l>=r){
        return;//returns recursively
    }
    int m =l+ (r-l)/2;
    dmergeSort(arr,l,m);
    dmergeSort(arr,m+1,r);
    dmerge(arr,l,m,r);
}


int main(){

    fstream  infile;
    infile.open("A2planets.txt",ios::in);
    string planets[10];
    int x[10];
    int y[10];
    int z[10];
    int weight[10];
    int profit[10];
    string oneline;
    int counter= 0;
   
    int values[10];

   //read data from file
    while (getline(infile,oneline)){
        istringstream iss (oneline);
        if(iss >> planets[counter] >> x[counter] >> y[counter] >> z[counter] >> weight[counter] >> profit[counter]){
            counter++; 
        }
    };

    
    int edges[18];
    string enames[18] = {"AD","AJ","AH","AF","DJ","HJ","FH","BD","GJ","HI","CF","BG","GI","CI","BE","EG","EI","CE"};

    //calculate edge weight/distance 
    edges[0] = round(sqrt(pow(x[3]-x[0],2)+pow(y[3]-y[0],2)+pow(z[3]-z[0],2)));
    edges[1] = round(sqrt(pow(x[9]-x[0],2)+pow(y[9]-y[0],2)+pow(z[9]-z[0],2)));
    edges[2] = round(sqrt(pow(x[7]-x[0],2)+pow(y[7]-y[0],2)+pow(z[7]-z[0],2)));
    edges[3] = round(sqrt(pow(x[5]-x[0],2)+pow(y[5]-y[0],2)+pow(z[5]-z[0],2)));
    edges[4] = round(sqrt(pow(x[9]-x[3],2)+pow(y[9]-y[3],2)+pow(z[9]-z[3],2)));
    edges[5] = round(sqrt(pow(x[7]-x[9],2)+pow(y[7]-y[9],2)+pow(z[7]-z[9],2)));
    edges[6] = round(sqrt(pow(x[5]-x[7],2)+pow(y[5]-y[7],2)+pow(z[5]-z[7],2)));
    edges[7] = round(sqrt(pow(x[1]-x[3],2)+pow(y[1]-y[3],2)+pow(z[1]-z[3],2)));
    edges[8] = round(sqrt(pow(x[6]-x[9],2)+pow(y[6]-y[9],2)+pow(z[6]-z[9],2)));
    edges[9] = round(sqrt(pow(x[8]-x[7],2)+pow(y[8]-y[7],2)+pow(z[8]-z[7],2)));
    edges[10] = round(sqrt(pow(x[2]-x[5],2)+pow(y[2]-y[5],2)+pow(z[2]-z[5],2)));
    edges[11] = round(sqrt(pow(x[6]-x[1],2)+pow(y[6]-y[1],2)+pow(z[6]-z[1],2)));
    edges[12] = round(sqrt(pow(x[8]-x[6],2)+pow(y[8]-y[6],2)+pow(z[8]-z[6],2)));
    edges[13] = round(sqrt(pow(x[2]-x[8],2)+pow(y[2]-y[8],2)+pow(z[2]-z[8],2)));
    edges[14] = round(sqrt(pow(x[4]-x[1],2)+pow(y[4]-y[1],2)+pow(z[4]-z[1],2)));
    edges[15] = round(sqrt(pow(x[4]-x[6],2)+pow(y[4]-y[6],2)+pow(z[4]-z[6],2)));
    edges[16] = round(sqrt(pow(x[4]-x[8],2)+pow(y[4]-y[8],2)+pow(z[4]-z[8],2)));
    edges[17] = round(sqrt(pow(x[4]-x[2],2)+pow(y[4]-y[2],2)+pow(z[4]-z[2],2)));


    //adjacency matrix
    int matrix[10][10] = {0};
    //insert values
    matrix[0][3] = edges[0];    
    matrix[3][0] = edges[0];    
    matrix[0][9] = edges[1];    
    matrix[9][0] = edges[1];    
    matrix[7][0] = edges[2];    
    matrix[0][7] = edges[2];    
    matrix[0][5] = edges[3];    
    matrix[5][0] = edges[3];    
    matrix[3][9] = edges[4];    
    matrix[9][3] = edges[4];    
    matrix[9][7] = edges[5];    
    matrix[7][9] = edges[5];    
    matrix[7][5] = edges[6];    
    matrix[5][7] = edges[6];    
    matrix[1][3] = edges[7];    
    matrix[3][1] = edges[7];    
    matrix[9][6] = edges[8];    
    matrix[6][9] = edges[8];    
    matrix[8][7] = edges[9];    
    matrix[7][8] = edges[9];    
    matrix[5][2] = edges[10];    
    matrix[2][5] = edges[10];
    matrix[6][1] = edges[11];
    matrix[1][6] = edges[11];
    matrix[6][8] = edges[12];
    matrix[8][6] = edges[12];
    matrix[2][8] = edges[13];
    matrix[8][2] = edges[13];
    matrix[1][4] = edges[14];
    matrix[4][1] = edges[14];
    matrix[4][6] = edges[15];
    matrix[6][4] = edges[15];
    matrix[8][4] = edges[16];
    matrix[4][8] = edges[16];
    matrix[4][2] = edges[17];
    matrix[2][4] = edges[17];

    //display matrix
    cout << "\nAdjacency Matrix:\n";
    for(int h = 0 ; h < 10 ; h++ )
        cout << setw(6) << char(65 + h) ;
    cout << "\n";
    for(int i = 0 ; i < 10 ; i++){
        cout << char(65+i);
        for(int j = 0 ; j < 10 ; j++){
            cout << setw(6) << matrix[i][j] ;
        }
        cout << "\n";
    }    

    vector<char> list[10];
    for(int i = 0; i <10 ; i++){
        for(int j = i; j < 10; j++){
            if(matrix[i][j] != 0)
                list[i].push_back(65+j);
        }
    }


    int size;
    //display adjacency list
    cout << "\nAdjacency List:\n";

    for(int i = 0 ; i < 10 ; i++){
        cout << char (65 + i)<< " --> ";
        size = sizeof(list[i]) / sizeof(list[i][0]);
        for (auto it = list[i].begin();it != list[i].end(); it++) { 
            cout << *it << ' '; 
        } 

        cout << "\n";
    }    

    //map for egdes name and distance
    map<int, string> edgemap;
    for(int num = 0 ; num < 18 ; num++){
        edgemap.insert(pair<int,string>(edges[num],enames[num]));
    }
    //iterator for map
    map< int,string>::iterator ite;
    
    //merge sort for List of edges in ascending order of distance
    cout << "\nList of edges in ascending order of distance:\n";
    int arr_size = sizeof(edges) / sizeof(edges[0]);
    mergeSort(edges,0,arr_size-1);
        cout << '\t' << "Edge"
             << '\t' << "Distance"<< '\n';
    for(int i = 0; i < arr_size ; i++){
        ite = edgemap.find(edges[i]);
        cout << '\t' << ite->second 
             << '\t' << ite->first<< '\n';
    }

    //merge sort for List of planets in descending order of value
    cout << "\nList of planets in descending order of value:\n";


    arr_size = sizeof(profit) / sizeof(profit[0]);

    int pvalue[10];
    for(int u = 0; u < arr_size;u++){
        if(weight[u] != 0)
            values[u] =  round(profit[u]/weight[u]);
        else
            values[u] = 0; 

        pvalue[u] = values[u];
    }

    arr_size = sizeof(values) / sizeof(values[0]);
    dmergeSort(values,0,arr_size-1);
    cout << '\t' << "Planet  "
        << '\t' << "Value"<< '\n';
    int countp;
    int visited[10] = {0};
    for(int i = 0; i < arr_size ; ++i){
        countp = 0;
        for(int v = 0; v <  arr_size  ; v++){
            if(values[i] == pvalue[v] && visited[v] == 0){
                countp = v;
                visited[v] = 1;
                break;
            }
        }
        cout << '\t' << planets[countp]
             << '\t' << values[i] << '\n';
    }


};

