//
// Created by anasse.elboudir on 21/02/2022.
//
#include "GrapheMatrice/GrapheMatrice.h"
#include "GrapheListe/GrapheListe.h"
#include "File_priorite/PriorityQueue.h"

void matrice_contiguite();
void liste_adjacence();
void file_priorite();

int main()
{
    matrice_contiguite();
    liste_adjacence();
    file_priorite();

    return 0;
}

void matrice_contiguite()
{
    cout << "======= MATRICE CONTIGUITE =======\n" << endl;
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

    std::cout << "parcours recursif : " << std::endl;
    g.parcourProfondeurRecursif();

    std::cout << std::endl << "nombre de degre de a : " << g.degre('a') << std::endl;
    std::cout << std::boolalpha << "Le graphe est pondere : "  << g.estPondere() << std::noboolalpha << std::endl;
    std::cout << std::boolalpha << "Le graphe est orienter : "  << g.estOriente() << std::noboolalpha << std::endl;
    std::cout << std::boolalpha << "Le graphe est fortement connexe : "  << g.estFortementConnexe() << std::noboolalpha<< std::endl;
    std::cout << std::boolalpha << "Le graphe est connexe : "  << g.estConnexe() << std::noboolalpha << "\n" << std::endl;

    g.supprimerGraphe();
}

void liste_adjacence()
{
    cout << "======= LISTE ADJACENCE =======\n" << endl;

    GrapheListe g1(11);
    g1.ajouterArc('A', 'B');
    g1.ajouterArc('A', 'C');
    g1.ajouterArc('A', 'F');
    g1.ajouterArc('C', 'F');
    g1.ajouterArc('A', 'G');
    g1.ajouterArc('D', 'E');
    g1.ajouterArc('F', 'D');
    g1.ajouterArc('F', 'E');
    g1.ajouterArc('E', 'G');
    g1.ajouterArc('I', 'J');
    g1.ajouterArc('I', 'K');
    g1.ajouterArc('J', 'K');

    std::cout << "affichage de notre graphe : " << std::endl;
    g1.display();

    std::cout << std::endl;

    std::cout << "parcours recursif : " << std::endl;
    g1.parcourProfondeurRecursif();

    std::cout << std::endl;
    std::cout << "parcours iteratif (pile) : " << std::endl;
    g1.parcourProfondeurIteratifPile();

    std::cout << std::endl;
    std::cout << "parcours iteratif (queue) : " << std::endl;
    g1.parcourLargeurIteratifQueue();
}

void file_priorite()
{
    cout << "======= FILE DE PRIORITE =======\n" << endl;

    PriorityQueue priorityQueue;

    priorityQueue.insert('A', 3);
    priorityQueue.insert('B', -2);
    priorityQueue.insert('C', 1);

    priorityQueue.display();

}
