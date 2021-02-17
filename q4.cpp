#include <bits/stdc++.h> 
#include<string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <cstdlib>
#include <sstream>
#include <vector>

using namespace std;


void knapsackDyProg(int W[], int V[], int M, int n) {

    int B[n + 1][M + 1]; 

    for (int i=0; i<=n; i++)
		for (int j=0; j<=M; j++) {
			B[i][j] = 0;
		}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= M; j++) {
			B[i][j] = B[i - 1][j];
			
			if ((j >= W[i-1]) && (B[i][j] < B[i - 1][j - W[i - 1]] + V[i - 1])) {
				B[i][j] = B[i - 1][j - W[i - 1]] + V[i - 1]; 
			}
			
			cout << setw(5) << B[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << "Max Value:\t" << B[n][M] << endl;
	
	cout << "Selected Planets: " << endl;
	
	while (n != 0) {
		if (B[n][M] != B[n - 1][M]) {
			cout << "\tPlanet " << char(65+(n-1)) << " with Weight = " << W[n - 1] << " and Profit = " << V[n - 1] << endl;
			
			M = M - W[n-1];
		}
		
		n--;
	}
}

int main()
{
/*
    int item_profit[] = { 0,
190,
190,
80,
190,
60,
130,
90,
70,
120};
	int item_weight[] = {0,
10,
9,
20,
5,
19,
9,
20,
19,
18}; 
*/

	
   fstream  infile;
    infile.open("A2planets.txt",ios::in);
    string planets[10];
    int x[10];
    int y[10];
    int z[10];
    int item_weight[10];
    int item_profit[10];
    string oneline;
    int counter= 0;
   
    int values[10];

   //read data from file
    while (getline(infile,oneline)){
        istringstream iss (oneline);
        if(iss >> planets[counter] >> x[counter] >> y[counter] >> z[counter] >> item_weight[counter] >> item_profit[counter]){
            counter++; 
        }
    };

    int capacity = 80;
    int n =  sizeof(item_profit)/sizeof(*item_profit);
    
    knapsackDyProg(item_weight,item_profit,capacity,n);
    return 0; 
}