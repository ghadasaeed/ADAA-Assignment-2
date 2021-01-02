#include <cstdlib>
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
//char array to make the data
static const char pool[] =
"ABCDEFGHIJKLMNOPQRSTUVWYZ"
"abcdefghijklmnopqrstuvwxyz"
"0123456789";

static const char pool3[] =
"ABCDEFGHIJKLMNOPQRSTUVWYZ"
"abcdefghijklmnopqrstuvwxyz"
"0123456789";

static const char pool2[] =
"ABCDEFGHIJKLMNOPQRSTUVWYZ"
"abcdefghijklmnopqrstuvwxyz";

static const string pool4[3] = {"com" ,"net" ,"org"};

//the size of the array
int poolSize = sizeof(pool)-1;
int pool2Size = sizeof(pool2)-1;
int pool3Size = sizeof(pool3)-1;
int pool4Size = 3;
//random index from the array
char getRandomChar(const char *pool0 , int poolSize0)
{
    return pool0[rand() % poolSize0];
}
string getRandomChar4()
{
    return pool4[rand() % pool4Size];
}

int main(int argc, char *argv[])
{
    ofstream file ("email.txt");
    int numberOfEmails;

    int passLength = 5;
    
    srand (time(0));  // Init random number generator.
    string pass;
    string pass2;
    string pass3;
    string pass4;
    
    cout << "How many Emails you want ? ";
    cin >> numberOfEmails;
    if(!file.is_open()){
        cout << "File not found.";
    } else {
        auto start = chrono::system_clock::now();

        for (int j = 0; j<numberOfEmails;j++)
        {
            for (int i = 0; i< passLength; i++)
            {
                pass += getRandomChar(pool , poolSize);
                pass2 += getRandomChar(pool2 , pool2Size);
                pass3 += getRandomChar(pool3 , pool3Size);
            }
            pass4 += getRandomChar4();
            file << pass + "." + pass3 + "@" + pass2 + "." +pass4 << endl;
            
            pass = "";// to empty for the next one
            pass2 = "";
            pass3 = "";
            pass4 = "";
        }
        auto end = chrono::system_clock::now();
        chrono::duration<double> duration = end - start;
        cout << "Duration: " << duration.count() << "s\n";
        file.close();
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}