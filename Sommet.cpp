#include "Sommet.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

Sommet::Sommet()
{
}

Sommet::Sommet(int id)
{
    m_id=id;
}

Sommet::~Sommet()
{
    //dtor
}

int Sommet::get_id()
{
    return m_id;
}

void Sommet::afficher_adj(int nb)
{
    if(nb==0)
    {
        for(size_t i=0; i<m_adj.size(); i++)
        {
            std::cout<< m_adj[i]->get_bout() << " ";
        }
    }
    if(nb==1)
    {
        for(size_t i=0; i<m_adj.size(); i++)
        {
            if(m_adj[i]->get_dir()==1)
            {
                std::cout<< m_adj[i]->get_bout() << " ";
            }
        }
    }
    std::cout << std::endl;
}

void Sommet::ajouter_adj(int id, int poids, int dir)
{
    m_adj.push_back(new Arrete(id, poids, dir));
}

std::vector<Arrete*> Sommet::get_adj()
{
    return m_adj;
}
