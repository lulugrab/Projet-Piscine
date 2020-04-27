#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Graphe.h"



int main()
{
    int choice, origine;
    int exit=0;
    std::vector<Sommet*> prec;
    std::vector<std::vector<int>> CC;
    std::vector<int> ChCyEuler;
    Sommet* white;
    Graphe G("Fichier.txt");
    std::cout << "      Bonjour" << std::endl;

    while(exit!=1)
    {
        std::cout << "Faites votre choix :" << std::endl;
        std::cout << "1/ Presentation generale du graphe" << std::endl;
        std::cout << "2/ Recherche BFS" << std::endl;
        std::cout << "3/ Recherche DFS" << std::endl;
        std::cout << "4/ Afficher composantes connexes" << std::endl;
        std::cout << "5/ Afficher chaine/cycle eulerien" << std::endl;
        std::cout << "6/ Quitter" << std::endl;
        std::cin >> choice;
        std::cout << std::endl;
        switch(choice)
        {
            case 1 :
                G.afficher();
                std::cout << std::endl;
                break;
            case 2 :
                std::cout << "Entrez le numero du sommet depuis lequel doit se faire la recherche : ";
                std::cin >> origine;
                std::cout << std::endl;
                prec=G.BFS(origine, white);
                std::cout << "Parcours BFS a partir du sommet " << origine << " :" << std::endl;
                for(size_t i=0; i< prec.size(); i++)
                {
                    if(prec[i]!=white)
                    {
                        std::cout << i;
                        G.retrace(prec, i, origine);
                        std::cout << std::endl;
                    }
                }
                std::cout << std::endl;
                break;
            case 3 :
                std::cout << "Entrez le numero du sommet depuis lequel doit se faire la recherche : ";
                std::cin >> origine;
                std::cout << std::endl;
                prec=G.DFS_pile(origine, white);
                //prec=G.init_white(white);
                //G.DFS_rec(prec, origine, origine, 0, white);
                std::cout << "Parcours DFS a partir du sommet " << origine << " :" << std::endl;
                for(size_t i=0; i< prec.size(); i++)
                {
                    if(prec[i]!=white)
                    {
                        std::cout << i;
                        G.retrace(prec, i, origine);
                        std::cout << std::endl;
                    }
                }
                std::cout << std::endl;
                break;

            case 4 :
                if(G.get_orientation()==0)
                {
                    CC=G.find_cc(white);
                    for(size_t i=0; i<CC.size(); i++)
                    {
                        if(CC[i][0]!=-1)
                        {
                            std::cout << "Composante connexe n" << i << " : ";
                            for(size_t j=0; j<CC[i].size(); j++)
                            {
                                std::cout << CC[i][j] << " ";
                            }
                        }
                        std::cout << std::endl;
                    }
                    std::cout << std::endl;
                }
                else
                {
                    std::cout <<  "Graphe oriente : action impossible..." << std::endl << std::endl;
                }

                break;
            case 5 :
                CC=G.find_cc(white);
                ChCyEuler=G.search_euler(CC, white);
                break;

            case 6 :
                exit=1;
                std::cout << "Bonne journee !" << std::endl;
                break;
        }

    }
    return 0;
}
