#ifndef GRAPHE_H
#define GRAPHE_H
#include "Sommet.h"
#include "Arrete.h"


class Graphe
{
    public:
        Graphe(std::string name_f);
        ~Graphe();
        int get_orientation();
        void set_sommets(std::vector<Sommet*> S);
        void afficher() const;
        std::vector<Sommet*> BFS(int nb, Sommet* white);
        std::vector<Sommet*> DFS_pile(int nb, Sommet* white);
        void retrace(std::vector<Sommet*> prec, int cible, int origine);
        Sommet* search_sommet(int nb);
        std::vector<std::vector<int>> find_cc(Sommet* white);
        std::vector<int> search_euler(std::vector<std::vector<int>> CC, Sommet* white);

        std::vector<Sommet*> dijkstra(Sommet* origine, Sommet* white);
        void retracePoids(std::vector<Sommet*> prec, int cible, int origine, int bascule, int sum);


    protected:
        int m_orientation;
        int m_ordre;
        int m_taille;
        std::vector<Sommet*> m_sommets;
};

#endif // GRAPHE_H
