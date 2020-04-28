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
        Sommet(int id, std::string nom, int coordx, int coordy);
        virtual ~Sommet();
        int get_id();
        int get_coordx();
        int get_coordy();
        std::string get_nom();
        void ajouter_adj(int id, int poids, int dir, int ida);
        void afficher_adj(int nb);
        std::vector<Arrete*> get_adj();

    protected:
        int m_id;
        int m_coordx;
        int m_coordy;
        std::string m_nom;
        std::vector<Arrete*> m_adj;

};

#endif // SOMMET_H
