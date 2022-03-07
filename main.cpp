//
// Created by anasse.elboudir on 21/02/2022.
//
#include "GrapheMatrice/GrapheMatrice.h"
#include "GrapheListe/GrapheListe.h"

void matrice_continuite();
void liste_adjacence();

int main()
{
    matrice_continuite();
    liste_adjacence();

    return 0;
}

void matrice_continuite()
{
    GrapheMatrice g(11);
    g.ajouterArc('a', 'b');
    g.ajouterArc('a', 'c');
    g.ajouterArc('a', 'f');
    g.ajouterArc('a', 'g');
    g.ajouterArc('f', 'd');
    g.ajouterArc('f', 'e');
    g.ajouterArc('d', 'e');
    g.ajouterArc('e', 'g');
    g.ajouterArc('i', 'j');
    g.ajouterArc('i', 'k');
    g.ajouterArc('j', 'k');

    std::cout << "affichage de notre graphe : " << std::endl;
    g.afficherGraphe();

    std::cout << "parcour iteratif : " << std::endl;
    g.parcourProfondeurRecursif();

    std::cout << std::endl << "nombre de degre de a : " << g.degre('a') << std::endl;
    std::cout << std::boolalpha << "Le graphe est pondere : "  << g.estPondere() << std::noboolalpha << std::endl;
    std::cout << std::boolalpha << "Le graphe est orienter : "  << g.estOriente() << std::noboolalpha << std::endl;
    std::cout << std::boolalpha << "Le graphe est fortement connexe : "  << g.estFortementConnexe() << std::noboolalpha<< std::endl;
    std::cout << std::boolalpha << "Le graphe est connexe : "  << g.estConnexe() << std::noboolalpha << std::endl;
}

void liste_adjacence()
{

}