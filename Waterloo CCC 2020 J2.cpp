#include <iostream>

using namespace std;

int main()
{
    int spreaders = 0, nonSpreaders = 0, rateOfSpread = 0, targetPopulation = 0, day = 0;


    cin >> targetPopulation;
    cin >> spreaders;
    cin >> rateOfSpread;

    while(spreaders+nonSpreaders <= targetPopulation)
    {
        day++;
        nonSpreaders += spreaders;
        spreaders *= rateOfSpread;
        //cout << "day: " << day << endl;
        //cout << "total: " << spreaders + nonSpreaders << endl;
    }

    cout << day;

    return 0;
}
