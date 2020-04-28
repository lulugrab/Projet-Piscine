#include "Graphe.h"

bool appartenanceV(std::vector<int> visited, int i)
{
    int valid=0;
    for(size_t j=0; j<visited.size(); j++)
    {
        if(visited[j]==i)
        {
            valid=1;
            return true;
        }
    }
    if(valid==0)
    {
        return false;
    }
}

Graphe::Graphe(std::string name_f)
{
    std::string const Fichier(name_f);
    std::ifstream Flux(Fichier.c_str());

    int id1, id2, poids, coordx, coordy, ida, s1, s2;
    int TempSommetID;
    Sommet* mem1;
    Sommet* mem2;
std::string nom;


    if(Flux)
    {
        Flux >> m_orientation;
        Flux >> m_ordre;
        for(int i = 0; i < m_ordre; i++)
        {
            Flux >> TempSommetID;
            Flux >> nom;
            Flux >> coordx;
            Flux >> coordy;
            m_sommets.push_back(new Sommet(TempSommetID, nom, coordx, coordy));
        }

        Flux >> m_taille;
        for(int i = 0; i < m_taille; i++)
        {
            Flux >> ida;
            Flux >> id1;
            Flux >> id2;

/*for(size_t k=0; k < m_sommets.size(); k++)
            {

            }*/


            for(size_t k=0; k < m_sommets.size(); k++)
            {
                if(m_sommets[k]->get_id()==id1)
                {
                    mem1=m_sommets[k];
                }
            }
            for(size_t k=0; k < m_sommets.size(); k++)
            {
                if(m_sommets[k]->get_id()==id2)
                {
                    mem2=m_sommets[k];
                }
            }
            if(m_orientation==0)
            {
                mem1->ajouter_adj(id2, poids, 1, ida);  //Chacun des 2 sommets a une arrete qui pointe vers l'autre
                mem2->ajouter_adj(id1, poids, 1, ida);
            }
            else
            {
                mem1->ajouter_adj(id2, poids, 1, ida); //Le sommet 1 a une arrete qui pointe vers le sommet 2
                mem2->ajouter_adj(id1, poids, 0, ida); //Le sommet 2 a une arrete qui pars du sommet 1 et qui pointe vers lui
            }

        }
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}

Graphe::~Graphe()
{
    //dtor
}

int Graphe::get_orientation()
{
    return m_orientation;
}

void Graphe::retrace(std::vector<Sommet*> prec, int cible, int origine)
{
    if(prec[cible]!=prec[origine])
    {
        std::cout << " <== " << prec[cible]->get_id();
        retrace(prec, prec[cible]->get_id(), origine);
    }

}

void Graphe::set_sommets(std::vector<Sommet*> S)
{
    m_sommets=S;
}

void Graphe::afficher() const
{
    if(m_orientation==1)
    {
        std::cout << "Graphe oriente" << std::endl;
    }
    else
    {
        std::cout << "Graphe non oriente" << std::endl;
    }
    std::cout << "  Ordre : " << m_ordre << std::endl;
    std::cout << "  Listes d'adjacence : " << std::endl;

    for(int i = 0; i < m_sommets.size(); i++)
        {
            std::cout<< "     Sommet " <<m_sommets[i]->get_nom() << " : ";
            m_sommets[i]->afficher_adj(m_orientation);
           // std::cout<< " ses coordonnees " << m_sommets[i]->get_coordx << " " << m_sommets[i]->get_coordy;
        }
        for(int i = 0; i < m_sommets.size(); i++)
        {
            std::cout<< " coordonnees du sommet " <<m_sommets[i]->get_nom() << " sont : ";
            std::cout << m_sommets[i]->get_coordx() << " , " << m_sommets[i]->get_coordy()<< std::endl;
        }

}

std::vector<Sommet*> Graphe::BFS(int nb, Sommet* white)
{
    std::queue<int> Q;
    std::vector<int> visited;
    std::vector<Sommet*> prec;
    std::vector<Arrete*> temp = m_sommets[nb]->get_adj();

    int ctrAdjacentsINIT=0;
    for(size_t i=0; i< m_sommets.size(); i++)
    {
        visited.push_back(0);
        prec.push_back(white);
    }
    visited[m_sommets[nb]->get_id()] = 1;
    for(size_t i=0; i< temp.size(); i++)
    {
        if(temp[i]->get_dir()==1)
        {
            Q.push(temp[i]->get_bout());
            prec[temp[i]->get_bout()]=m_sommets[nb];
            visited[temp[i]->get_bout()]=1;
            ctrAdjacentsINIT+=1;
        }
    }
    while(Q.empty()!=true)
    {
        temp=m_sommets[Q.front()]->get_adj();
        visited[Q.front()] = 1;
        for(size_t i=0; i<temp.size(); i++)
        {
            //for(size_t j=0; j<visited.size(); j++)
            //{
                if((temp[i]->get_dir()==1)&&(visited[temp[i]->get_bout()]==0))
                {
                    Q.push(temp[i]->get_bout());
                    prec[temp[i]->get_bout()]=m_sommets[Q.front()];
                }
            //}
        }
        Q.pop();
    }
    return prec;
}

std::vector<Sommet*> Graphe::DFS_pile(int nb, Sommet* white)
{
    std::stack<int> St;
    std::vector<int> visited;
    int mem;
    std::vector<Sommet*> prec;
    std::vector<Arrete*> temp = m_sommets[nb]->get_adj();
    for(size_t i=0; i< m_sommets.size(); i++)
    {
        visited.push_back(0);
        prec.push_back(white);
    }
    for(size_t i=0; i< temp.size(); i++)
    {
        if(temp[i]->get_dir()==1)
        {
            St.push(temp[i]->get_bout());
            prec[temp[i]->get_bout()]=m_sommets[nb];
            visited[temp[i]->get_bout()]=1;
        }
    }
    visited[m_sommets[nb]->get_id()] = 1;
    while(St.empty()!=true)
    {
        temp=m_sommets[St.top()]->get_adj();
        visited[St.top()] = 1;
        mem=St.top();
        St.pop();
        for(size_t i=0; i<temp.size(); i++)
        {
            //for(size_t j=0; j<visited.size(); j++)
            //{
                if((temp[i]->get_dir()==1)&&(visited[temp[i]->get_bout()]==0))
                {
                    prec[temp[i]->get_bout()]=m_sommets[mem];
                    St.push(temp[i]->get_bout());
                }
            //}
        }
    }
    return prec;
}

Sommet* Graphe::search_sommet(int nb)
{
    for(size_t i=0; i<m_sommets.size(); i++)
    {
        if(m_sommets[i]->get_id()==nb)
        {
            return m_sommets[i];
        }
    }
}

std::vector<std::vector<int>> Graphe::find_cc(Sommet* white) //Utilisable uniquement sur graphe non-oriente
{
    std::vector<std::vector<int>> CC;
    std::vector<Sommet*> temp;
    std::vector<int> remaining;
    std::vector<int> valid;
    std::vector<int> visited;
    int nb=0;

    int ctrPass=0;
    std::vector<int> passage;
    passage.push_back(-1);

    remaining.push_back(nb);
    visited.clear();

    while(remaining.empty()!=1)
    {
        temp=BFS(remaining[0], white);
        remaining.clear();
        for(size_t i=0; i<temp.size();i++)
        {
            if(((temp[i]==white)&&(i!=remaining[0]))&&(appartenanceV(visited, i)==false))
            {
                remaining.push_back(i);
            }
            else
            {

                if(appartenanceV(visited, i)==false)
                {
                    valid.push_back(i);
                    visited.push_back(i);
                }
            }
        }
        CC.push_back(valid);
        valid.clear();
        ctrPass+=1;
    }
    if(ctrPass==1)
    {
            CC.push_back(passage);
    }
    return CC;
}

std::vector<int> Graphe::search_euler(std::vector<std::vector<int>> CC, Sommet* white) //A corriger / ameliorer si on l'utilise
{
    int ctrImp=0;
    Sommet* extremite_1;
    Sommet* extremite_2;
    int bascule=0;
    std::vector<Sommet*> prec;
    if(CC[1][0]!=-1)
    {
        std::cout << "Il existe plusieurs composantes connexes : pas de chaine/cycle eulerien" << std::endl << std::endl;
    }
    else
    {
        for(size_t i=0; i<m_sommets.size(); i++)
        {
            std::vector<Arrete*> temp;
            temp=m_sommets[i]->get_adj();
            if(temp.size()%2==1)
            {
                ctrImp+=1;
                if(bascule==0)
                {
                    extremite_1=m_sommets[i];
                    bascule=1;
                }
                else
                {
                    extremite_2=m_sommets[i];
                    bascule=0;
                }
            }
        }
        if(ctrImp==0)
        {
            std::cout << "Il existe un cycle eulerien" << std::endl;

            ///Nous n'avons pas reussi a coder cette fonction

        }
        else if(ctrImp==2)
        {
            std::cout << "Il existe une chaine eulerienne" << std::endl;
            prec=BFS(extremite_1->get_id(), white);
            std::cout << extremite_2->get_id();
            retrace(prec, extremite_2->get_id(), extremite_1->get_id());
            std::cout << std::endl;
        }
        else
        {
            std::cout << "Il n'existe pas de cycle/chaine eulerien(nne)" << std::endl;
        }
        std::cout << std::endl;
    }
}

std::vector<Sommet*> Graphe::dijkstra(Sommet* origine, Sommet* white) //Surement a modifier
{
    std::vector<int> distance;
    std::vector<Sommet*> prec;
    std::vector<int> visited;
    Sommet* SEL;
    std::vector<Arrete*> temp;
    std::queue<int> Q;

    Q.push(origine->get_id());

    ///INIT
    for(size_t  i=0; i<m_sommets.size(); i++)
    {
        if(i!=origine->get_id())
        {
            distance.push_back(-1);                //-1=infini
        }
        else
        {
            distance.push_back(0);
        }
        prec.push_back(white);
        visited.push_back(0);
    }
    ///BOUCLE
    while(Q.empty()!=1)
    {
        SEL=search_sommet(Q.front());
        Q.pop();
        temp = SEL->get_adj();
        visited[SEL->get_id()]=1;

        for(size_t  i=0; i<temp.size(); i++)
        {
            if(visited[temp[i]->get_bout()]!=1)
            {
                distance[temp[i]->get_bout()] = temp[i]->get_poids() + distance[SEL->get_id()]; //Distance[sommet i adj de SEL] = poids de SEL a i + distance de origine a SEL
                prec[temp[i]->get_bout()]=SEL;                                                  //Prec[sommet i adj de SEL] = SEL
                Q.push(temp[i]->get_bout());
            }
            if((visited[temp[i]->get_bout()]==1)&&((temp[i]->get_poids() + distance[SEL->get_id()]) <= distance[temp[i]->get_bout()]))
            {
                distance[temp[i]->get_bout()] = temp[i]->get_poids() + distance[SEL->get_id()]; //Distance[sommet i adj de SEL] = poids de SEL a i + distance de origine a SEL
                prec[temp[i]->get_bout()]=SEL;                                                  //Prec[sommet i adj de SEL] = SEL
            }
        }
    }
    return prec;
}

void Graphe::retracePoids(std::vector<Sommet*> prec, int cible, int origine, int bascule, int sum)
{
    int SavedI;

    if(prec[cible]!=prec[origine])
    {
        std::vector<Arrete*> temp=prec[cible]->get_adj();
        for(size_t i=0; i<temp.size(); i++)
        {
            if(temp[i]->get_bout()==cible)
            {
                SavedI=i;
            }
        }
        if(bascule==1)
        {
            bascule=0;
        }
        else
        {
            std::cout << "+";
        }
        std::cout << temp[SavedI]->get_poids();
        sum+=temp[SavedI]->get_poids();
        if(prec[cible]->get_id()==origine)
        {
            std::cout << "=" << sum;
        }
        retracePoids(prec, prec[cible]->get_id(), origine, bascule, sum);
    }
}
