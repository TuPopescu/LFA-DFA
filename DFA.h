<<<<<<< HEAD
#ifndef DFA_h
#define DFA_h
#include <iostream>
using namespace std;
#define lung_cuvant 100

class DFA
{
private:
    int nr_stari;
    int dim_alfabet;
    int nr_tranzitii;
    int **tranzitii;
    bool *finale;
    char *alfabet;

public:
    DFA(int x, int y);
    ~DFA();
    friend istream &operator>>(istream& in, DFA &d);
    friend ostream &operator<<(ostream &out, DFA &d);
    bool check_word(char c[]);
};
=======
#ifndef DFA_h
#define DFA_h
#include <iostream>
using namespace std;
#define lung_cuvant 100

class DFA
{
private:
    int nr_stari;
    int dim_alfabet;
    int nr_tranzitii;
    int **tranzitii;
    bool *finale;
    char *alfabet;

public:
    DFA(int x, int y);
    ~DFA();
    friend istream &operator>>(istream& in, DFA &d);
    friend ostream &operator<<(ostream &out, DFA &d);
    bool check_word(char c[]);
};
>>>>>>> b18393c69a58bfdd88fe8448f21058f1e75d64b9
#endif // !DFA.h