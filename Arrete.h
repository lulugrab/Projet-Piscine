#ifndef ARRETE_H
#define ARRETE_H


class Arrete
{
    public:
        Arrete(int bout, int poids, int direction, int ida);
        ~Arrete();
        int get_bout();
        int get_poids();
        int get_dir(); //1 si l'arrete pars du sommet, 0 si elle va vers le sommet
        int get_ida();


    protected:
        int m_bout;
        int m_poids;
        int m_direction;
     //   Sommet* m_sommet1;
      //  Sommet* m_sommet2;
        int m_ida;

};

#endif // ARRETE_H
