#include <iostream>
#include <fstream>
#include <string>
#include "Magie.h"
using namespace std;

Magie::Magie() : m_Sort("Boule de feu"), m_degatsMagique(50), m_coutmana(30), m_mana(100)
{

}

Magie::Magie(string nom, int degats, int coutmana) : m_Sort(nom), m_degatsMagique(degats), m_coutmana(coutmana), m_mana(100)
{

}

void Magie::changerDesort(std::string nom, int degats, int coutmana)
{
	m_Sort = nom;
	m_degatsMagique = degats;
	m_coutmana = coutmana;
}

void Magie::afficher() const
{
	cout << "le sort est " << m_Sort << "et fait" << m_degatsMagique << "de degats " <<"et a consommé :" << m_coutmana <<"de mana" <<endl;

}

int Magie::getDegats() const
{
	return m_degatsMagique;
}