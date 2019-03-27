#include <iostream>
#include <cstring>

using namespace std;

void f(char* str1, char* str2)
{
    int letters1[26] = {0};
    int letters2[26] = {0};
    for(int i = 0; i < strlen(str1); i++)
    {
        letters1[str1[i] - 'A']++;
        letters2[str2[i] - 'A']++;
    }

    bool equals = true;
    for(int i = 0; i < 26; i++)
    {
        letters1[i] = letters1[i] - letters2[i];
        if(letters1[i] != 0)
        {
            equals = false;
        }
    }
    if(equals)
    {
        cout << "0";
        return;
    }

    char* from = new char[strlen(str1)];
    char* to = new char[strlen(str1)];
    int j = 0;
    int k = 0;
    for(int i = 0; i < 26; i++)
    {
        if(letters1[i] > 0)
        {
            while(letters1[i] > 0)
            {
                from[j++] = char(i + 'A');
                letters1[i]--;
            }
        } else if (letters1[i] < 0)
        {
            while(letters1[i] < 0)
            {
                to[k++] = char(i + 'A');
                letters1[i]++;
            }
        }
    }

    int length = strlen(from);
    int price = 0;
    for(int i = 0; i < length; i++)
    {
        int minDist = 1000000000;
        int minChar;
        bool fuck = false;
        for(int j = 0; j < length; j++)
        {
            if(to[j] != '-')
            {
                fuck = true;
                if(from[i] > to[j])
                {
                    int tmp = 'z' - from[i] + to[j] - 'a' + 1;
                    if(tmp < minDist)
                    {
                        minDist = tmp;
                        minChar = j;
                    }
                } else
                {
                    int tmp = to[j] - from[i];
                    if(tmp < minDist)
                    {
                        minDist = tmp;
                        minChar = j;
                    }
                }
            }
        }
        if(fuck)
        {
            to[minChar] = '-';
            price+=minDist;
        }
    }
    cout << price << endl;
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        char str1[201];
        char str2[201];
        cin >> str1 >> str2;
        f(str1, str2);
        cout << endl;

    }
    return 0;
}
