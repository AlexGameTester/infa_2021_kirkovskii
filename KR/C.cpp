#include <iostream>
using namespace std;

int main()
{
    string text;
    getline(cin, text);
    int index = 0;
    for (int i = 0; i < text.size(); i++)
    {
        if (text[i] == ' ')
        {
            cout << text[i];
            continue;
        }
        else
        {
            if (index % 2 == 0)
            {
                cout << (char)toupper(text[i]);
            }
            else
            {
                cout << (char)tolower(text[i]);
            }

            index++;
        }
    }
    return 0;
}