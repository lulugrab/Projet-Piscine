#ifndef SOMMET_H
#define SOMMET_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include "Arrete.h"

class Sommet
{
    public:
        Sommet();
        Sommet(int id);
        virtual ~Sommet();
        int get_id();
        void ajouter_adj(int id, int poids, int dir);
        void afficher_adj(int nb);
        std::vector<Arrete*> get_adj();

    protected:
        int m_id;
        std::vector<Arrete*> m_adj;

};

#endif // SOMMET_H
