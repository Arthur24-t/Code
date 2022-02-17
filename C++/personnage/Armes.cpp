#include <iostream>
#include <fstream>
#include <string>
#include "Armes.h"
using namespace std;

Arme::Arme() : m_nom("epee rouillee"), m_degats(10)
{

}

Arme::Arme(string nom, int degats) : m_nom(nom), m_degats(degats)
{

}

void Arme::changer(std::string nom, int degats)
{
	m_nom = nom;
	m_degats = degats;

}

void Arme::afficher() const
{
	cout << "l'arme est " << m_nom << "et fait" << m_degats << "de degats " << endl;

}

int Arme::getDegats() const
{
	return m_degats;
}