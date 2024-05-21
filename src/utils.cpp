#include "utils.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

namespace graph::utils
{
    void GenerateRandomGraph(int n, int m, int edges[][2])
    {
        std::srand(std::time(nullptr));
        for(int i = 0; i < m; i++)
        {
            edges[i][0] = rand() % n;
            edges[i][1] = rand() % n;
        }
    }

    void DisplayEdgeMatrix(int m, int edges[][2])
    {
        for(int i = 0; i < m; i++)
        {
            std::cout << "[" << edges[i][0] << "," << edges[i][1] << "]";
        }
        
        std::cout << std::endl;
    }

    void DisplayCompMatrix(int n, int comp[])
    {
        for(int i = 0; i < n; i++)
        {
            std::cout << i << "->" << comp[i] << std::endl;
        }
    }

    void DisplayComponentSizes(int n, int m, int comp[])
    {
        int compOccurences[n]; //Worst case : n components
        int compSizes[n+1]; // Worst case : 1 component with size equals n 

        //Array initialization
        for(int i = 0; i < n; i++)
        {
            compOccurences[i] = 0;
            compSizes[i] = 0; 
        }

        compSizes[n] = 0;

        //Compute components occurence
        for(int i = 0; i < n; i++)
        {
            compOccurences[comp[i]]++;
        }
        
        //Compute each component size
        for(int i = 0; i < n; i++)
        {
            if(compOccurences[i] > 0)
            {
                compSizes[compOccurences[i]]++;
            }
        }

        for(int i = 1; i < n + 1; i++)
        {
            if(compSizes[i] != 0)
            {
                if(i == 1)
                {
                    std::cout << "There's " << compSizes[i] << " isolated vertice(s)." << std::endl;
                }
                else
                {
                    std::cout << "There's " << compSizes[i] << " component of size." << std::endl;
                }
            }
        }
    }

    void ExportTreeInPSFormat(int n, graph::algo::Point2D points[], int tree[][2], char* name)
    {       
        // Cree le fichier Exemple.ps qui affiche
        // les points et l'arbre de Kruskal.

        std::ofstream output;                           
        output.open(name,std::ios::out);
        output << "%!PS-Adobe-3.0" << std::endl;
        output << "%%BoundingBox: 0 0 612 792" << std::endl;
        output << std::endl;  
        for(int i=0;i<n;i++){
            output << points[i].abs << " " << points[i].ord << " 3 0 360 arc" << std::endl;
            output << "0 setgray" << std::endl;
            output << "fill" << std::endl;
            output << "stroke"<< std::endl;
            output << std::endl;
        }
        output << std::endl;
        for(int i = 0; i < n - 1; ++i){
            output << points[tree[i][0]].abs << " " << points[tree[i][0]].ord 
        << " moveto" << std::endl;
            output << points[tree[i][1]].abs << " " << points[tree[i][1]].ord
        << " lineto" << std::endl;
            output << "stroke" << std::endl;
            output << std::endl;
        }
        output << "showpage";
        output << std::endl;
    }
}