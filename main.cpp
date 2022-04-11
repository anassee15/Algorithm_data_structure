//
// Created by anasse.elboudir on 21/02/2022.
//
#include "GrapheMatrice/GrapheMatrice.h"
#include "GrapheListe/GrapheListe.h"

using namespace std;

void matrice_contiguite();
void liste_adjacence();
void file_priorite();
void parcours();
void test();

int main() {
//    matrice_contiguite();
//    liste_adjacence();
//    file_priorite();
//    parcours();
    test();

    return 0;
}

void matrice_contiguite() {
    cout << "======= MATRICE CONTIGUITE =======\n"
         << endl;
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

    cout << "affichage de notre graphe : " << endl;
    g.display();

    cout << "nombre de degre du sommet A : " << g.degre('A') << endl;
    cout << boolalpha << "Le graphe est pondere : " << g.estPondere() << noboolalpha << endl;
    cout << boolalpha << "Le graphe est orienter : " << g.estOriente() << noboolalpha << endl;
    cout << boolalpha << "Le graphe est fortement connexe : " << g.estFortementConnexe() << noboolalpha << endl;
    cout << boolalpha << "Le graphe est connexe : " << g.estConnexe() << noboolalpha << "\n"
         << endl;

    cout << "parcours recursif : " << endl;
    g.parcoursProfondeurRecursif();
}

void liste_adjacence() {
    cout << "======= LISTE ADJACENCE =======\n"
         << endl;

    GrapheListe g(11);
    g.ajouterArc('A', 'B', 1);
    g.ajouterArc('A', 'F', 4);
    g.ajouterArc('A', 'G', 2);
    g.ajouterArc('A', 'C', 2);
    g.ajouterArc('C', 'J', 1);
    g.ajouterArc('D', 'E', 1);
    g.ajouterArc('F', 'D', 1);
    g.ajouterArc('F', 'E', 3);
    g.ajouterArc('G', 'C', 1);
    g.ajouterArc('G', 'E', 1);
    g.ajouterArc('H', 'C', 3);
    g.ajouterArc('H', 'K', 1);
    g.ajouterArc('I', 'J', 3);
    g.ajouterArc('I', 'K', 1);
    g.ajouterArc('J', 'K', 1);

    cout << "affichage de notre graphe : " << endl;
    g.display();

    cout << "\nnombre de degre du sommet A : " << g.degre('A') << endl;
    cout << boolalpha << "Le graphe est pondere : " << g.estPondere() << noboolalpha << endl;
    cout << boolalpha << "Le graphe est orienter : " << g.estOriente() << noboolalpha << endl;
    cout << boolalpha << "Le graphe est fortement connexe : " << g.estFortementConnexe() << noboolalpha << endl;
    cout << boolalpha << "Le graphe est connexe : " << g.estConnexe() << noboolalpha << "\n"
         << endl;
}

void file_priorite() {
    cout << "======= FILE DE PRIORITE =======\n"
         << endl;

    PriorityQueue priorityQueue;

    cout << "vide ? " << boolalpha << priorityQueue.isEmpty() << noboolalpha << '\n'
         << endl;

    priorityQueue.insert('A', 3);
    priorityQueue.insert('B', 1);
    priorityQueue.insert('C', 2);

    cout << "affichage de notre liste priorite : " << endl;
    priorityQueue.display();

    Vertex tmp = priorityQueue.extraireMin();

    cout << "\nextraire min : (" << tmp.label << ", " << tmp.priority << ")\n"
         << endl;

    cout << "affichage de notre liste priorite apres extraireMin() : " << endl;
    priorityQueue.display();

    cout << "\nvide ? " << boolalpha << priorityQueue.isEmpty() << noboolalpha << '\n'
         << endl;
}

void parcours() {
    string path = R"(C:\Users\anasse.elboudir\Desktop\CODE\algorithme_structure_donnee\create_graph.txt)";
    GrapheListe g(path, true);

    g.display();

    cout << "======= PARCOURS SIMPLE =======" << endl;

    cout << "parcours recursif : " << endl;
    g.parcourProfondeurRecursif();

    cout << "\nparcours profondeur iteratif (pile) : " << endl;
    g.parcourProfondeurIteratifPile();

    cout << "\nparcours largeur iteratif (queue) : " << endl;
    g.parcourLargeurIteratifQueue();

    cout << "\n======= PARCOURS GENERALISE =======" << endl;

    cout << "\nparcours generalise (priority_queue) en mode profondeur : " << endl;
    g.parcourGeneralise(PROFONDEUR);

    cout << "\nparcours generalise (priority_queue) en mode largeur : " << endl;
    g.parcourGeneralise(LARGEUR);

    cout << "======= PRIM / DIJKSTRA =======" << endl;

    cout << "\nAlgo PRIM : " << endl;
    g.prim('G');

    cout << "\nAlgo DIJKSTRA : " << endl;
    g.dijkstra('A');
}

void test() {
    string path = R"(..\create_graph.txt)";
    GrapheListe g(path, true);
    g.display();

    cout << "\nnombre de degre du sommet A : " << g.degre('A') << endl;
    cout << boolalpha << "Le graphe est pondere : " << g.estPondere() << noboolalpha << endl;
    cout << boolalpha << "Le graphe est orienter : " << g.estOriente() << noboolalpha << endl;
    cout << boolalpha << "Le graphe est fortement connexe : " << g.estFortementConnexe() << noboolalpha << endl;
    cout << boolalpha << "Le graphe est connexe : " << g.estConnexe() << noboolalpha << "\n"
         << endl;

    cout << "======= PARCOURS SIMPLE =======" << endl;

    cout << "parcours recursif : " << endl;
    g.parcourProfondeurRecursif();

    cout << "\nparcours profondeur iteratif (pile) : " << endl;
    g.parcourProfondeurIteratifPile();

    cout << "\nparcours largeur iteratif (queue) : " << endl;
    g.parcourLargeurIteratifQueue();

    cout << "\n======= PARCOURS GENERALISE =======" << endl;

    cout << "\nparcours generalise (priority_queue) en mode profondeur : " << endl;
    g.parcourGeneralise(PROFONDEUR);

    cout << "\nparcours generalise (priority_queue) en mode largeur : " << endl;
    g.parcourGeneralise(LARGEUR);

    cout << "======= PRIM / DIJKSTRA =======" << endl;

    cout << "\nAlgo PRIM : " << endl;
    g.prim('A');

    cout << "\nAlgo DIJKSTRA : " << endl;
    g.dijkstra('A');
}
