#ifndef DEF_MAGIE
#define DEF_MAGIE

#include <iostream>
#include <string>

class Magie
{
public:

    Magie();
    Magie(std::string nom, int degats, int coutmana);
    void afficher() const;
    int getDegats() const;
    void changerDesort(std::string nom, int degats, int coutmana);

private:

    std::string m_Sort;
    int m_degatsMagique;
    int m_mana;
    int m_coutmana;
};

#endif