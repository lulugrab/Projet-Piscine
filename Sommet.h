#ifndef SOMMET_H
#define SOMMET_H
#include <iostream>
#include <fstream>
#include <set>
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

constexpr char defcol[] = "black";

struct sphere
{
    double x;
    double y;
    double rayon;
    std::string couleur;
};

class Svgfile
{
    private:
        std::string m_filename;
        std::ofstream m_ostrm;
        int m_width;
        int m_height;

        // Pour éviter les ouverture multiples
        static std::set<std::string> s_openfiles;

    public:

        Svgfile(std::string _filename = "output.svg", int _width=1000, int _height=800);
        ~Svgfile();

        void addDisk(double x, double y, double r, std::string color=defcol);
        void addLine(double x1, double y1, double x2, double y2, std::string color=defcol);
        void addCross(double x, double y, double span, std::string color=defcol);

        void addText(double x, double y, std::string text, std::string color=defcol);
        void addText(double x, double y, double val, std::string color=defcol);

        void addGrid(double span=50.0, bool numbering=true, std::string color="lightgrey");
        void svgSphere(sphere& nouv);
};

std::string makeRGB(int r, int g, int b);

std::string fillBallColor(std::string col);


#endif // SOMMET_H
