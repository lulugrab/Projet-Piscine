#include "Arrete.h"

Arrete::Arrete(int bout, int poids, int direction)
{
    m_bout=bout;
    m_poids=poids;
    m_direction=direction;
}

Arrete::~Arrete()
{
    //dtor
}

int Arrete::get_bout()
{
    return m_bout;
}

int Arrete::get_poids()
{
    return m_poids;
}

int Arrete::get_dir()
{
    return m_direction;
}
