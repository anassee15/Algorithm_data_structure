//
// Created by anasse.elboudir on 28/02/2022.
//

#include "GrapheListe.h"

GrapheListe::GrapheListe(int nb_sommets) {
    this->nb_sommets = nb_sommets;
    this->links = new list<Link>[nb_sommets];
    this->visited = new bool[nb_sommets];
    this->stacked = new bool[nb_sommets];
}

GrapheListe::GrapheListe(const string &path, bool ponderer) {

    ifstream file(path, ios::in);  // on ouvre le fichier en lecture, path doit etre le chemin absolu vers le fichier

    if (file) {
        // creation du graph / sommets
        string taille;
        getline(file, taille);
        this->nb_sommets = stoi(taille);

        this->links = new list<Link>[nb_sommets];
        this->visited = new bool[nb_sommets];
        this->stacked = new bool[nb_sommets];

        string line;

        // ajout des arcs
        do {
            char s1, s2;
            if (ponderer) {
                int p;
                file >> s1 >> s2 >> p;
                ajouterArcOriente(s1, s2, p);
            } else {
                file >> s1 >> s2;
                ajouterArcOriente(s1, s2);
            }
        } while (getline(file, line));

        file.close();
    } else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
}

GrapheListe::~GrapheListe() {
    delete[] links;
    links = nullptr;
}

void GrapheListe::ajouterArc(char s1, char s2, int p) {
    Link link;
    link.label = s1;
    link.ponderation = p;

    this->links[Conversion::charToInt(s2)].push_back(link);

    link.label = s2;
    link.ponderation = p;
    this->links[Conversion::charToInt(s1)].push_back(link);
}

void GrapheListe::ajouterArcOriente(char s1, char s2, int p) {

    Link link;
    link.label = s2;
    link.ponderation = p;
    this->links[Conversion::charToInt(s1)].push_back(link);
}

void GrapheListe::display() {
    for (int i = 0; i < this->nb_sommets; i++) {
        cout << Conversion::intToChar(i);
        for (auto const &link: this->links[i]) {
            cout << " --> (" << link.label << ", " << link.ponderation << ")";
        }
        cout << endl;
    }
}

bool GrapheListe::estFortementConnexe() {
    int nb_arc = 0;

    for (int i = 0; i < this->nb_sommets; i++) {
        for (auto &link: this->links[i]) {
            nb_arc++;
        }
    }
    return nb_arc > (this->nb_sommets * log2(this->nb_sommets));
}

bool GrapheListe::estOriente() {

    bool Oriente;

    for (int i = 0; i < this->nb_sommets; i++) {
        for (auto &link: this->links[i]) {
            Oriente = true;
            int oppose = Conversion::charToInt(link.label);
            char actuel = Conversion::intToChar(i);

            for (auto &link2: this->links[oppose]) {
                if (link2.label == actuel) {
                    Oriente = false;
                    break;
                }
            }
            if (Oriente) {
                return true;
            }
        }
    }
    return false;
}

bool GrapheListe::estPondere() {
    for (int i = 0; i < this->nb_sommets; i++) {
        for (auto &link: this->links[i]) {
            if (link.ponderation != 1) {
                return true;
            }
        }
    }
    return false;
}

bool GrapheListe::estConnexe() {
    initVisited();
    visiteSommetProfondeurR(0, false);

    for (int i = 0; i < this->nb_sommets; i++) {
        if (!this->visited[i]) {
            return false;
        }
    }
    return true;
}

int GrapheListe::degre(char sommet) {
    int degre = 0;
    int indice_sommet = Conversion::charToInt(sommet);

    for (auto &link: this->links[indice_sommet]) {
        degre++;
    }
    return degre;
}

void GrapheListe::initVisited() {
    for (int i = 0; i < this->nb_sommets; i++) {
        this->visited[i] = false;
    }
}

void GrapheListe::initStacked() {
    for (int i = 0; i < this->nb_sommets; i++) {
        this->stacked[i] = false;
    }
}

void GrapheListe::clearStack() {
    while (!this->pile.empty()) {
        this->pile.pop();
    }
}

void GrapheListe::clearQueue() {
    while (!this->queue.empty()) {
        this->queue.pop();
    }
}

void GrapheListe::parcourProfondeurRecursif() {
    initVisited();

    for (int i = 0; i < this->nb_sommets; i++) {
        this->visiteSommetProfondeurR(i);
    }
}

void GrapheListe::visiteSommetProfondeurR(int index, bool traiter_sommet) {
    // si le sommet est deja visiter on ne continue pas
    if (this->visited[index]) {
        return;
    }

    // on traite le sommet (ici on affiche)
    if (traiter_sommet) {
        cout << Conversion::intToChar(index) << endl;
    }

    // on marque le sommet comme visité
    this->visited[index] = true;

    // pour chaque sommet voisin du sommet actuel on le visite en profondeur
    for (auto &link: this->links[index]) {
        visiteSommetProfondeurR(Conversion::charToInt(link.label), traiter_sommet);
    }
}

void GrapheListe::parcourProfondeurIteratifPile() {

    initVisited();
    initStacked();
    clearStack();

    for (int i = 0; i < this->nb_sommets; i++) {
        this->visiteSommetProfondeurI(i);
    }
}

void GrapheListe::visiteSommetProfondeurI(int index) {
    // si le sommet n'est pas visite on l'ajoute a la pile
    if (!this->visited[index]) {
        this->pile.push(index);
        this->stacked[index] = true;
    }

    // tant que la pile n'est pas vide
    while (!this->pile.empty()) {

        // on recupere le sommet
        int indice = this->pile.top();
        // on traite le sommet (ici on affiche)
        cout << Conversion::intToChar(indice) << endl;
        // on le supprime de la pile
        this->pile.pop();

        // on le marque comme visite
        this->visited[indice] = true;

        for (auto &link: this->links[indice]) {
            int position = Conversion::charToInt(link.label);

            if (!this->stacked[position] && !this->visited[position]) {
                this->pile.push(position);
                this->stacked[position] = true;
            }
        }
    }
}

void GrapheListe::parcourLargeurIteratifQueue() {

    initVisited();
    initStacked();
    clearQueue();

    for (int i = 0; i < this->nb_sommets; i++) {
        this->visiteSommetLargeurI(i);
    }
}

void GrapheListe::visiteSommetLargeurI(int index) {
    // si le sommet n'est pas visite on l'ajoute a la queue
    if (!this->visited[index]) {
        this->queue.push(index);
        this->stacked[index] = true;
    }

    //tant que la queue n'est pas vide
    while (!this->queue.empty()) {
        // on recupere le sommet
        int indice = this->queue.front();

        // on traite le sommet
        cout << Conversion::intToChar(indice) << endl;

        // on supprime le sommet de la queue
        this->queue.pop();
        this->visited[indice] = true;

        for (auto &link: this->links[indice]) {
            int position = Conversion::charToInt(link.label);

            if (!this->stacked[position] && !this->visited[position]) {
                this->stacked[position] = true;
                this->queue.push(position);
            }
        }
    }
}

void GrapheListe::parcourGeneralise(Mode mode) {

    initVisited();
    initStacked();

    for (int i = 0; i < this->nb_sommets; i++) {
        this->visiteSommetGeneraliseI(i, mode);
    }
}

void GrapheListe::visiteSommetGeneraliseI(int index, Mode mode, int verbose) {

    if (!this->visited[index]) {
        int priority = 0;
        char label = Conversion::intToChar(index);

        this->find_priority(mode, &priority, index);
        this->priorityQueue.insert(label, (float) priority);
        this->stacked[index] = true;

        while (!this->priorityQueue.isEmpty()) {

            if (verbose == 1) {
                priorityQueue.display();
            }

            Vertex sommet = this->priorityQueue.extraireMin();

            int vertex_i = Conversion::charToInt(sommet.label);
            this->visited[vertex_i] = true;

            // on traite le sommet
            cout << sommet.label << " : " << sommet.priority << endl;

            for (auto &link: this->links[Conversion::charToInt(sommet.label)]) {
                vertex_i = Conversion::charToInt(link.label);

                if (!this->visited[vertex_i] && !this->stacked[vertex_i]) {
                    this->visited[vertex_i] = true;
                    this->find_priority(mode, &priority, vertex_i);
                    this->priorityQueue.insert(link.label, (float) priority);
                }
            }
        }
    }
}

void GrapheListe::prim(char startPoint, int verbose) {

    initVisited();
    initStacked();

    // on commence par le start point
    this->visiteSommetPrim(Conversion::charToInt(startPoint), verbose);

    // ensuite on traite tout les sommets du graph, si le graphe est connexe normalement tous les points sont deja visité.
    for (int i = 0; i < this->nb_sommets; i++) {
        this->visiteSommetPrim(i, verbose);
    }
}

void GrapheListe::visiteSommetPrim(int index, int verbose, Mode mode) {
    if (!this->visited[index]) {

        int priority = 0;
        find_priority(mode, &priority, index, index);

        char label = Conversion::intToChar(index);
        this->priorityQueue.insert(label, (float) priority);
        this->stacked[index] = true;

        while (!this->priorityQueue.isEmpty()) {
            if (verbose == 1) {
                priorityQueue.display();
            }

            Vertex vertex = this->priorityQueue.extraireMin();
            int i = Conversion::charToInt(vertex.label);
            this->visited[i] = true;

            // on traite le sommet
            cout << vertex.label << " : " << vertex.priority << endl;

            for (auto &link: this->links[i]) {
                int indice = Conversion::charToInt(link.label);

                if (!this->visited[indice]) {
                    find_priority(mode, &priority, indice, i);

                    if (!this->stacked[indice]) {
                        this->priorityQueue.insert(link.label, (float) priority);
                    } else {
                        this->priorityQueue.diminuerClef(link.label, (float) priority);
                    }
                }
            }
        }
    }
}

void GrapheListe::dijkstra(char startPoint, int verbose) {
    initVisited();
    initStacked();

    visiteSommetDijkstra(Conversion::charToInt(startPoint), verbose);
}

void GrapheListe::visiteSommetDijkstra(int index, int verbose) {
    if (!this->visited[index]) {
        this->priorityQueue.insert(Conversion::intToChar(index), 0);
        this->stacked[index] = true;

        while (!this->priorityQueue.isEmpty()) {
            if (verbose == 1) {
                priorityQueue.display();
            }

            Vertex vertex = this->priorityQueue.extraireMin();
            int vertex_i = Conversion::charToInt(vertex.label);

            // on traite le sommet
            cout << vertex.label << " : " << vertex.priority << endl;

            this->visited[vertex_i] = true;

            for (auto &link: this->links[vertex_i]) {
                int indice = Conversion::charToInt(link.label);

                if (!this->visited[indice]) {
                    float priority_dijkstra = vertex.priority + (float) link.ponderation;
                    if (!this->stacked[indice]) {
                        this->priorityQueue.insert(link.label, priority_dijkstra);
                    } else {
                        this->priorityQueue.diminuerClef(link.label, priority_dijkstra);
                    }
                }
            }
        }
    }
}

void GrapheListe::find_priority(Mode mode, int *priority, int index_current, int index_older) {
    switch (mode) {
        // profondeur -> pile
        case PROFONDEUR:
            (*priority)--;
            break;

            // largeur -> file
        case LARGEUR:
            (*priority)++;
            break;

        case PRIM:
            for (auto &link: this->links[index_older]) {
                // on cherche la ponderation du lien entre le sommet de depart(index_older) et le sommet d'arriver(index_current)
                if (link.label == Conversion::intToChar(index_current)) {
                    *priority = link.ponderation;
                    break;
                }
            }
            break;
        default:
            break;
    }
}