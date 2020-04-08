#include <iostream>

using namespace std;

bool find(string str1, string str2)
{
    //returns true of str2 is contained in str1
    if(str1.size() < str2.size())
        return false;

    for(int x = 0; x <= str1.size()-str2.size(); x++)
    {
        bool wordFound = true;
        for(int y = x; y < str2.size(); y++)
        {
            if(str2[y-x] != str1[y])
            {
                wordFound = false;
                break;
            }
        }
        if(wordFound == true)
            return true;
    }


}


int main()
{
    string string1 = "";
    string string2 = "";
    bool found = false;

    cin >> string1;
    cin >> string2;

    for(int x = 0; x < string2.size(); x++)
    {
        if(find(string1,string2) == true)
        {
            found = true;
            break;
        }
        string newString = string2.substr(1,string2.size()-1) + string2[0];
        string2 = newString;
    }

    if(found == true)
        cout << "yes";
    else
        cout << "no";



    return 0;
}
