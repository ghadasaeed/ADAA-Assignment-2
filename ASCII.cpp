#include <iostream>
#include <string>
using namespace std;

void convertToASCII(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        cout << (int)s[i]<< endl;
    }
}

int main()
{
    string plainText;
    cout << "Enter text to convert to ASCII: ";
    getline(cin,plainText);
    convertToASCII(plainText);
    return 0;
}