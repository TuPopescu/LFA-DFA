#include <iostream>
#include <fstream>
#include <cstring>
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
    fin >> D;
    cout << D;
    fin.close();

    char cuvant[lung_cuvant];
    ifstream cuv("Cuvant 1.txt");
    ofstream fout("Check.txt");
    if (!cuv.is_open())
    {
        cout << "Nu am reusit sa deschid fisierul\n";
        return 0;
    }
    while (true)
    {
        if (cuv.eof() != 0) {
            cout << "Am ajuns la capatul fisierului.";
            break;
        }
        cuv.getline(cuvant,lung_cuvant);
        cuvant[strlen(cuvant)-1]='\0';
        fout << cuvant;
        if (D.check_word(cuvant)) {
            fout << " apartine DFA-ului dat.\n";
        } else {
            fout << " nu apartine DFA-ului dat.\n";
        }
    }
    cuv.close();
    fout.close();

    return 0;
}