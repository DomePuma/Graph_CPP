#include <iostream>
#include <cstdlib>

#include "utils.hpp"
#include "algo.hpp"

namespace GraphUtils = graph::utils;
namespace GraphAlgo = graph::algo;

int main()
{
    std::cout << "Practical exercices: connected components" << std::endl;

    int n, m; //Nombre de sommets (n) et d'arêtes (m)

    std::cout << "Entre le nombre de sommets: ";
    std::cin >> n;
    std::cout << "Entrer le nombre d'arrêtes: ";
    std::cin >> m;

    /*
        Soit G un graphe composé de l'ensemble des sommets {0,1,2,3} ayant pour arêtes {01, 02, 03, 12, 23}, 
        le tableau d'arêtes est codé par le tableau edges[5][2] = {{0,1}, {0,2}, {0,3}, {1,2}, {2,3}}
    */ 

    int edges[m][2];
    int comp[n];


    GraphUtils::GenerateRandomGraph(n, m, edges);
    GraphAlgo::ComputeRelatedComponents(n, m, edges, comp);
    
    GraphUtils::DisplayEdgeMatrix(m, edges);
    GraphUtils::DisplayCompMatrix(n, comp);

    GraphUtils::DisplayComponentSizes(n, m, comp);

    //Kruskal
    std::cout << "Entrez le nombre de sommets pour Kruskal : ";
    std::cin >> n;

    m = n * (n - 1) / 2;

    GraphAlgo::Point2D points[n];
    int edgesForKurskal[m][3];
    int tree[n - 1][2];

    GraphAlgo::CreateRandomPoints(n, points);
    GraphAlgo::ComputeEdges(n, m, points, edgesForKurskal);
    GraphAlgo::Kruskal(n, m, edgesForKurskal, tree);

    GraphUtils::ExportTreeInPSFormat(n, points, tree, "Kruskal.ps");

    return 0;
}