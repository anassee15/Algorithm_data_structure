//
// Created by anasse.elboudir on 21/02/2022.
//
#include "GrapheMatrice/GrapheMatrice.h"
#include "GrapheListe/GrapheListe.h"

void matrice_continuite();
void liste_adjacence();

int main()
{
    //matrice_continuite();
    liste_adjacence();
    return 0;
}

void matrice_continuite()
{
    GrapheMatrice g(11);
    g.ajouterArc('A', 'B');
    g.ajouterArc('A', 'C');
    g.ajouterArc('C', 'F');
    g.ajouterArc('A', 'G');
    g.ajouterArc('F', 'D');
    g.ajouterArc('F', 'E');
    g.ajouterArc('D', 'E');
    g.ajouterArc('E', 'G');
    g.ajouterArc('I', 'J');
    g.ajouterArc('I', 'K');
    g.ajouterArc('J', 'K');

    std::cout << "affichage de notre graphe : " << std::endl;
    g.afficherGraphe();

    std::cout << "parcour iteratif : " << std::endl;
    g.parcourProfondeurRecursif();

    std::cout << std::endl << "nombre de degre de a : " << g.degre('a') << std::endl;
    std::cout << std::boolalpha << "Le graphe est pondere : "  << g.estPondere() << std::noboolalpha << std::endl;
    std::cout << std::boolalpha << "Le graphe est orienter : "  << g.estOriente() << std::noboolalpha << std::endl;
    std::cout << std::boolalpha << "Le graphe est fortement connexe : "  << g.estFortementConnexe() << std::noboolalpha<< std::endl;
    std::cout << std::boolalpha << "Le graphe est connexe : "  << g.estConnexe() << std::noboolalpha << "\n" << std::endl;
}

void liste_adjacence()
{
    GrapheListe g(11);
    g.ajouterArc('A', 'B');
    g.ajouterArc('A', 'C');
    g.ajouterArc('C', 'F');
    g.ajouterArc('A', 'G');
    g.ajouterArc('D', 'E');
    g.ajouterArc('F', 'D');
    g.ajouterArc('F', 'E');
    g.ajouterArc('E', 'G');
    g.ajouterArc('I', 'J');
    g.ajouterArc('I', 'K');
    g.ajouterArc('J', 'K');

    std::cout << "affichage de notre graphe : " << std::endl;
    g.display();

    std::cout << std::endl;
    std::cout << "parcour iteratif : " << std::endl;
    g.parcourProfondeurRecursif();
}