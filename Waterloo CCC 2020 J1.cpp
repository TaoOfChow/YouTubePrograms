#include <iostream>

using namespace std;

int main()
{
    int small=0, medium=0, large=0;

    cin >> small;
    cin >> medium;
    cin >> large;

    if ( 1*small + 2*medium + 3*large >= 10)
        cout << "happy";
    else
        cout << "sad";

    return 0;
}
