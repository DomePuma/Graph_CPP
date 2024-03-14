#include "algo.hpp"

namespace graph::algo
{
    void ComputeRelatedComponents(int n, int m, int edges[][2], int comp[])
    {
        for(int i = 0; i < n; i++)
        {
            comp[i] = edges[i][0];
        }
        for(int j = 0; j < m; j++)
        {
            if(comp[edges[j][0]] != comp[edges[j][1]])
            {
                int aux = comp[edges[j][0]];
                for(int k; k < n; k++)
                {
                    if(comp[k] == aux)
                    {
                        comp[k] = comp[edges[j][1]];
                    }
                }
            }
        }
    }
}