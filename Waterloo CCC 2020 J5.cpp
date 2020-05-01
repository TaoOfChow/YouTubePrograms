#include <iostream>
#include <cstdio>

using namespace std;

int main()
{

    ios_base::sync_with_stdio (false);

    //setting up for data entry=============
    int rows, columns;
    cin >> rows;
    cin >> columns;

    int array[rows+1][columns+1];
    int size = rows*columns;

    for(int x = 1; x <= rows; x++)
        for(int y = 1; y <= columns; y++)
            cin >> array[x][y];

     //end data entry==================

    //setting up for exploration===========

    int pathways[size];
    int emptySpot = 0;
    int currentExploration = 0;
    int target = rows*columns;
    bool numberInList[1000001];
    int arrayXY;

    //clearing the pathways array============
    for(int x = 0; x < rows*columns; x++)
        pathways[x] = -1;

    pathways[emptySpot++] = array[1][1];
    //emptySpot++;

    if(pathways[currentExploration] == target)//solution found
    {
        cout << "yes";
        return 0;
    }

    do
    {

        for(int x = 1; x <= rows; x++)
        {
            if(pathways[currentExploration]%x == 0)
                for(int y = 1; y <= columns ; y++)
                {
                    //if( y > pathways[currentExploration]/x)
                       // break;
                    //add more pathways to the list
                    if(x*y == pathways[currentExploration])
                    {
                        arrayXY = array[x][y];
                        if(arrayXY == target)
                        {
                            cout << "yes";
                            return 0;
                        }

                        if(numberInList[ arrayXY ] == false)
                        {
                            pathways[emptySpot++] = array[x][y];
                            numberInList[ arrayXY ] = true;
                           // emptySpot++;
                        }

                        if( (y+1) > pathways[currentExploration]/x)
                            break;

                    }
                }

        }
        currentExploration++;
    }while(pathways[currentExploration] != -1);

        cout << "no";

    return 0;
}
