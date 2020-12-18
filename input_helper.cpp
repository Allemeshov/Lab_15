#include "input_helper.h"

using namespace std;

void welcome()
{
    cout << "Hello! this is lab 15 of Alexander Lemeshov.\n\n";
}

int selectInputType()
{
    int result = -1;
    while (result < 0 || 3 < result)
    {
        cout << "Please, choose among 4 types of input:\n";
        cout << "\t1 - Console type\n";
        cout << "\t2 - Random type\n";
        cout << "\t3 - From file type\n";
        cout << "\t0 - Quit application\n";
        cout << "Type: ";
        cin >> result;
    }
    return result;
}

int selectOutputType()
{
    int result = -1;
    while (result < 1 || 2 < result)
    {
        cout << "Please, choose among 2 types of output:\n";
        cout << "\t1 - Console type\n";
        cout << "\t2 - Into file type\n";
        cout << "Type: ";
        cin >> result;
    }
    return result;
}
int inputNumberOfPassengers()
{
    int res = 0;
    while (res < 0 || 20 < res)
    {
        cout << "\nPlease, enter number of passengers: ";
        cin >> res;
    }
    return res;
}