#include <iostream>

using namespace std;

int main()
{
    int* num = new int(10);
    cout << "Hello World!" << endl
         << "Created new int: " << *num << endl;
    return 0;
}

