#ifndef _UTILS_HPP_
#define _UTILS_HPP_

#include "algo.hpp"
 
namespace graph::utils
{
    void GenerateRandomGraph(int n, int m, int edges[][2]);
    
    void DisplayEdgeMatrix(int m, int edges[][2]);
    
    void DisplayCompMatrix(int n, int comp[]);

    void DisplayComponentSizes(int n, int m, int comp[]);

    void ExportTreeInPSFormat(int n, graph::algo::Point2D points[], int tree[][2], char* name);

};

#endif //_UTILS_HPP_