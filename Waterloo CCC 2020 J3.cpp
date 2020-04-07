#include <iostream>

using namespace std;

int main()
{
    string input = "";
    int numberOfInputs = 0, smallestX = 100, largestX = 0, smallestY = 100, largestY = 0;
    cin >> numberOfInputs;

    for(int y = 0; y < numberOfInputs; y++)
    {
        cin >> input;
        int stringLength = input.size();

        int commaIndex = 0;
        for(int x = 0; x < stringLength; x++)
        {
            if(input[x] == 44)
            {
                commaIndex = x;
                break;
            }
        }

        int firstNumber = 0;
        if(commaIndex == 1)
            firstNumber = input[0]-48;
        else
            firstNumber = ((input[0]-48)*10) + (input[1]-48);

        int secondNumber = 0;
        if(stringLength - 1 - commaIndex == 2)
            secondNumber = ((input[commaIndex+1]-48)*10) + (input[commaIndex+2]-48);
        else
            secondNumber = input[commaIndex+1]-48;
        //cout << firstNumber << endl;
        //cout << secondNumber << endl;

        if(firstNumber < smallestX)
            smallestX = firstNumber;
        if(firstNumber > largestX)
            largestX = firstNumber;
        if(secondNumber < smallestY)
            smallestY = secondNumber;
        if(secondNumber > largestY)
            largestY = secondNumber;
    }
        cout << smallestX-1 << "," << smallestY-1 << endl;
        cout << largestX+1 << "," << largestY+1 << endl;


    return 0;
}
