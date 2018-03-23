#include "DFA.h"
#include <cstring>

DFA::DFA(int x, int y)
{
    nr_stari = x;
    dim_alfabet = y;
    nr_tranzitii = 0;
    tranzitii = new int*[x];
    finale = new bool[x];
    for (int i = 0; i < x; i++)
    {
        finale[i] = false;
        tranzitii[i] = new int[y];
        for (int j = 0; j < y; j++)
        {
            tranzitii[i][j] = -1;
        }
    }
    alfabet = new char[y + 1];
    alfabet[0] = '\0';
}

DFA::~DFA()
{
    delete[] alfabet;
    delete[] finale;
    for (int i = 0; i < nr_stari; i++)
    {
        delete[] tranzitii[i];
    }
    delete[] tranzitii;
}

istream &operator>>(istream &in, DFA &d)
{
    in >> d.nr_tranzitii;
    in >> d.alfabet;
    for (int i = 0; i < d.nr_stari; i++)
    {
        in >> d.finale[i];
    }
    int x, y, poz;
    char c, *p;
    for (int i = 0; i < d.nr_tranzitii; i++)
    {
        in >> x >> c >> y;
        p = strchr(d.alfabet, c);
        poz = p - d.alfabet;
        d.tranzitii[x][poz] = y;
    }
    return in;
}

ostream &operator<<(ostream &out, DFA &d)
{
    out << "Nr. stari: " << d.nr_stari;
    out << "\nDim. alfabet: " << d.dim_alfabet << "\nAlfabet: " << d.alfabet;
    out	<< "\nNr. tranzitii: " << d.nr_tranzitii << "\nStarile finale: ";
    for (int i = 0; i < d.nr_stari; i++)
    {
        out << d.finale[i] << " ";
    }
    out << "Matricea de tranzitie:\n";
    for (int i = 0; i < d.nr_stari; i++)
    {
        for (int j = 0; j < d.dim_alfabet; j++)
        {
            out << d.tranzitii[i][j] << " ";
        }
        out << endl;
    }
    return out;
}

bool DFA::check_word(char c[])
{
    int n = strlen(c),poz;
    int stare = 0;
    char *p;
    for (int i = 0; i < n; i++)
    {
        p = strchr(alfabet, c[i]);
        if (p == NULL)
        {
            if (finale[stare] == true)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        poz = p - alfabet;
        if (tranzitii[stare][poz] != -1)
        {
            stare = tranzitii[stare][poz];
        }
        else
        {
            return false;
        }

    }
    if (finale[stare] == true)
        return true;
    return false;
}