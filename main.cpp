#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

int main()
{
    /*
    Ingredients: Lemons, Sugar, Cups, Ice Cubes

    Recipe: 1.75 Cups sugar, 1.5 cups of lemon juice, 8 cups or water, 20 ice cubes, 10 cups

    Costs: $0.44 lemon, 0.03 ice cube. 0.23 cup, 0.28/cup sugar

    10.56 + 0.49 + .60 + 2.30  it costs about 1.395 to make one cup.


    1 Lemon = 1 TBS Lemon Juice
    16 TBS = 1 Cup
    24 lemons per recipe
    */

    int lemons = 0, cups = 0, iceCubes = 0;
    double sugar = 0, money = 40;
    const double LEMONCOST = 0.44, ICECUBECOST = 0.03, CUPCOST = 0.23, SUGARCOST = 0.28, FREEZERCOST = 100, MRCHOWSTATUECOST = 100;
    int mainMenuChoice, storeChoice, quantity, customerMin = 0, customerMax = 20;
    double price = 2.0;
    int location = 1;
    bool freezer = false, mrChowStatue = false;
    int upgradeCount = 0;

    do
    {
        system("cls"); // This can only be used in WINDOWS - NO IOS
        cout << "\tLemonade Tycoon\n";
        cout << "================================" << endl;
        cout << "Lemons:\t\t" << lemons << endl;
        cout << "Sugar:\t\t" << setprecision(2) << fixed << sugar << endl;
        cout << "Cups:\t\t" << cups << endl;
        cout << "Ice Cubes:\t" << iceCubes << endl;
        cout << "Money: \t\t$" << setprecision(2) << fixed <<  money << endl << endl;

        cout << "Upgrades:" << endl;
        cout << "================================" << endl;
        if(upgradeCount == 0)
            cout << "None." << endl;
        if(mrChowStatue == true)
            cout << "Mr.Chow Statue" << endl;
        if(freezer == true)
            cout << "Freezer" << endl;

        cout << "\nCurrent Location: ";
                if(location == 1)
                    cout << "Mom's house." << endl;
                else if (location == 2)
                    cout << "The park" << endl;

        cout << endl;

        cout << "\tMain Menu\n";
        cout << "================================" << endl;
        cout << "0. Exit the game.\n";
        cout << "1. Go to the store.\n";
        cout << "2. Set the price of lemonade.\n";
        cout << "3. Buy upgrades.\n";
        cout << "4. Change locations \n";
        cout << "5. Start the day.\n";

        cout << "\nWhat would you like to do? ";
        cin >> mainMenuChoice;
        ///TODO: Error Trap

        if(mainMenuChoice == 1)//Go to the store
        {
            do
            {
                system("cls"); // This can only be used in WINDOWS - NO IOS
                cout << "\tLemonade Tycoon\n";
                cout << "================================" << endl;
                cout << "Lemons:\t\t" << lemons << endl;
                cout << "Sugar:\t\t" << setprecision(2) << fixed << sugar << endl;
                cout << "Cups:\t\t" << cups << endl;
                cout << "Ice Cubes:\t" << iceCubes << endl;
                cout << "Money: \t\t$" << setprecision(2) << fixed <<  money << endl << endl;

                cout << "Upgrades:" << endl;
                cout << "================================" << endl;
                if(upgradeCount == 0)
                    cout << "None." << endl;
                if(mrChowStatue == true)
                    cout << "Mr.Chow Statue" << endl;
                if(freezer == true)
                    cout << "Freezer" << endl;

                cout << "\nCurrent Location: ";
                if(location == 1)
                    cout << "Mom's house." << endl;
                else if (location == 2)
                    cout << "The park" << endl;

                cout << endl;
                cout << "\tLinus' Lemon Lab\n";
                cout << "================================" << endl;
                cout << "0. Exit the store.\n";
                cout << "1. Buy lemons: $" << LEMONCOST << endl;

                cout << "\nWhat would you like to do? ";
                cin >> storeChoice;

                if(storeChoice == 1)//Buy lemons
                {
                    do
                    {
                        cout << "How many would you like to buy?";
                        cin >> quantity;

                    }while(quantity < 0 || money < quantity*LEMONCOST);
                    //lemons = lemons+quantity; //This does the same as the line below
                    lemons += quantity;
                    money -= quantity * LEMONCOST;
                }

                ///TODO: Complete the rest of the purchasing


            }while(storeChoice != 0);
        }

        else if(mainMenuChoice == 2)
        {
            double newPrice = 0;

            do
            {
                cout << "The current price of lemonade is $" << price << endl;
                cout << "What will the new lemonade price per cup be? ";
                cin >> newPrice;
            }while (newPrice < 0);

            price = newPrice;
        }

        else if (mainMenuChoice == 3)
        {
            int upgradeChoice = 0;
            do
            {
                system("cls"); // This can only be used in WINDOWS - NO IOS
                cout << "\tLemonade Tycoon\n";
                cout << "================================" << endl;
                cout << "Lemons:\t\t" << lemons << endl;
                cout << "Sugar:\t\t" << setprecision(2) << fixed << sugar << endl;
                cout << "Cups:\t\t" << cups << endl;
                cout << "Ice Cubes:\t" << iceCubes << endl;
                cout << "Money: \t\t$" << setprecision(2) << fixed <<  money << endl << endl;

                cout << "Upgrades:" << endl;
                cout << "================================" << endl;
                if(upgradeCount == 0)
                    cout << "None." << endl;
                if(mrChowStatue == true)
                    cout << "Mr.Chow Statue" << endl;
                if(freezer == true)
                    cout << "Freezer" << endl;

                cout << "\nCurrent Location: ";
                if(location == 1)
                    cout << "Mom's house." << endl;
                else if (location == 2)
                    cout << "The park" << endl;

                cout << endl;
                cout << "\tUrsula's Upgrades\n";
                cout << "================================" << endl;
                cout << "0. Exit the store.\n";
                cout << "1. Buy a freezer: $" << FREEZERCOST << endl;
                cout << "2. Buy a Mr. Chow statue: $" << MRCHOWSTATUECOST << endl;

                cout << "\nWhat would you like to do? ";
                cin >> upgradeChoice;

                if(upgradeChoice == 1 && freezer == false)
                {
                    if(money >= FREEZERCOST)
                    {
                        money -= FREEZERCOST;
                        freezer = true;
                        upgradeCount++;
                    }
                    else
                    {
                        cout << "You cannot afford this upgrade." << endl;
                    }
                }
                else if(upgradeChoice == 2 && mrChowStatue == false)
                {
                    if(money >= MRCHOWSTATUECOST)
                    {
                        money -= MRCHOWSTATUECOST;
                        mrChowStatue = true;
                        upgradeCount++;
                    }
                    else
                    {
                        cout << "You cannot afford this upgrade." << endl;
                    }
                }
                else if(upgradeChoice <= 2 && upgradeChoice > 0)
                {
                    cout << "You already have this upgrade." << endl;
                    system("pause");
                }
            }while(upgradeChoice != 0);

        }

        else if(mainMenuChoice == 4)
        {

            int newLocation = 0;
            do
            {
                system ("cls");
                cout << "Current Location: ";
                if(location == 1)
                    cout << "Mom's house." << endl;
                else if (location == 2)
                    cout << "The park" << endl;

                cout << "1. Mom's house." << endl;
                cout << "2. The park." << endl;
                cout << "Where would you like to set up your shop? ";
                cin >> newLocation;
            }while(newLocation < 0 || newLocation > 2);

            location = newLocation;

        }


        else if(mainMenuChoice == 5)//start the day
        {
            int numberOfCustomers = rand()%(customerMax-customerMin+1)+customerMin;
            double goodPrice = (rand()%(300 - 140 + 1) + 140)/100.0;

            //PRICE EFFECT
            if(price < 1.395)//selling at less than cost
                numberOfCustomers = numberOfCustomers * 3;
            else if (price > 3.00)
                numberOfCustomers = 0;
            else if (price > goodPrice)
                numberOfCustomers = numberOfCustomers *0.5;
            //END PRICE EFFECT

            //MRCHOW EFFECT
            if(mrChowStatue == true)
                numberOfCustomers *= 1.5;
            //END MRCHOW EFFECT

            cout << "You had " << numberOfCustomers << " customers today!" << endl;

            int servings = 0, customersServed = 0;


            while(numberOfCustomers > 0 && sugar >= 1.75 && lemons >= 24)//checking to see if there are customers and we have ingredients to make lemonade
            {
                //If we don't have enough cups or ice cubes, we cannot serve anyone today.
                if(cups == 0 || iceCubes < 2)
                {
                    numberOfCustomers == 0;
                    break;
                }
                else
                {
                    //make a jug of lemonade
                    sugar -= 1.75;
                    lemons -= 24;
                    servings = 10;

                    while(numberOfCustomers > 0 && cups > 0 && iceCubes > 2 && servings > 0)//we have enough to assemble a cup
                    {
                        cups--; // take away a cup
                        iceCubes -= 2; // take away 2 ice cubes
                        servings--; // take one serving from the jug
                        numberOfCustomers--; //take one customer out of line
                        customersServed++;

                        money += price;
                    }
                }
            }


            cout << "You were able to serve " << customersServed << " customers." << endl;
            //cout << "Customers:" << numberOfCustomers << endl;
            system("pause");

            if(freezer == false)
                iceCubes = 0;
            else
                iceCubes += 30;
        }


        else if(mainMenuChoice == 12345)//CHEAT CODE
        {
            lemons += 100;
            sugar += 100;
            cups += 100;
            iceCubes += 100;
            money +=100;
        }









    }while(mainMenuChoice != 0);


    return 0;
}
