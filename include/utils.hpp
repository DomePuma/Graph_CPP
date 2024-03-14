#ifndef _UTILS_HPP_
#define _UTILS_HPP_

namespace graph::utils
{
    void GenerateRandomGraph(int n, int m, int edges[][2]);
    void DisplayEdgeMatrix(int m, int edges[][2]);
    void DisplayCompMatrix(int n, int comp[]);
};

#endif //_UTILS_HPP_