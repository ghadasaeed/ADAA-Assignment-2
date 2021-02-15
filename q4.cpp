#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main()
{
    int table[100][100] ;
    int value, n, max_wt;
    max_wt = 80;
    n = 10;
	int wt[] = {0,
		10,
		9,
		20,
		5,
		19,
		9,
		20,
		19,
		18};
	
	
	int val[] = {0,
		190,
		190,
		80,
		190,
		60,
		130,
		90,
		70,
		120};

    // Initialization
    /*
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= max_wt; j++)
            table[i][j] = 0;
    */
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= max_wt; j++)
            table[i][j] = -1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= max_wt; j++)
        {
            if (j < wt[i])
                table[i][j] = table[i - 1][j];
            else
                table[i][j] = max(table[i - 1][j], val[i] + table[i - 1][j - wt[i]]);
        }
    }

    cout << " Optimum value : " << table[n][max_wt] << endl;

    cout << " \n Table : \n";
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= max_wt; j++)
            if (table[i][j] == -1)
                cout << setw(5) << "-";
            else
                cout << setw(5) << table[i][j];
        cout << endl;
    }

    system("PAUSE");
	return EXIT_SUCCESS;
}