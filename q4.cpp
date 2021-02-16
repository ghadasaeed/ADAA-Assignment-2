#include <bits/stdc++.h> 
#include<string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <cstdlib>
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
			cout << "\tPlanet " << n-1 << " with Weight = " << W[n - 1] << " and Profit = " << V[n - 1] << endl;
			
			M = M - W[n-1];
		}
		
		n--;
	}
}

int main()
{
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

    int capacity = 80;
    int n =  sizeof(item_profit)/sizeof(*item_profit);
    
    knapsackDyProg(item_weight,item_profit,capacity,n);
    return 0; 
}