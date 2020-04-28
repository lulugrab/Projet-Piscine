#include "Arrete.h"

Arrete::Arrete(int bout, int poids, int direction, int ida)
{
    m_bout=bout;
    m_poids=poids;
    m_direction=direction;
    m_ida=ida;
}

Arrete::~Arrete()
{
    //dtor
}

int Arrete::get_ida()
{
    return m_ida;
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
