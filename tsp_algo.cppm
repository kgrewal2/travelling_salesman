#include "bits/stdc++.h"
#include <iostream>
export module tsp_algo;
import geometry;
import vector_ops;

using namespace std;

namespace tsp_algo{
export int linear_tsp(vector<vector<float>>& point_data, int rows, int cols)
{
    int distance = 0;
    for (int i = 0; i < rows - 1; i++) {
        distance += geometry::get_distance(point_data[i][1], point_data[i][2], point_data[i + 1][1], point_data[i + 1][2]);
    }
    return distance;
}
}
