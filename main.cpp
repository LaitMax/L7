#include <windows.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int x;
    cin >> x;
    int sym = 0, n = 0, slov = 0;
    const char* input = ("input.txt");
    const char* output = ("output.txt");
    ifstream file_in(input);
    ofstream file_out(output);
    while (!file_in.eof())
    {
        char str[256];
        char* p = str;
        file_in.getline(str, 255);
        while (*p++)
        {
            if (!isalpha(*p) && isalpha(*(p - 1)))
            {
                slov++;
            }
            if (*p == 33 || *p == 46 || *p == 59 || *p == 63)
            {
                if (slov == x)
                {
                    n++;
                    file_out << n << '.' << '\n';
                }
                slov = 0;
            }
        }
    }
}