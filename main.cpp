#include <iostream>
#include <fstream>
using namespace std;
#include "DFA.h"
#define lung_cuvant 100

int main()
{
    DFA D(3, 2);
    ifstream fin("DFA 1.txt");
    if (!fin.is_open())
    {
        cout << "Nu am reusit sa deschid fisierul\n";
        return 0;
    }
    fin >> D;////
    cout << D;
    fin.close();

    char cuvant[lung_cuvant];
    ifstream cuv("Cuvant 1.txt");
    if (!cuv.is_open())
    {
        cout << "Nu am reusit sa deschid fisierul\n";
        return 0;
    }
    while (!cuv.eof())
    {
        cuv.getline(cuvant,lung_cuvant);
        cout << cuvant;
        if (D.check_word(cuvant))
        {
            cout << " apartine DFA-ului dat.\n";
        }
        else
        {
            cout << " nu apartine DFA-ului dat.\n";
        }
    }
    cuv.close();

    return 0;
}