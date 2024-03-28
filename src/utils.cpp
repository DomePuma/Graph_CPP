#include "utils.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

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
}