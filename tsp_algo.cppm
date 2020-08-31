#include "bits/stdc++.h"
#include <iostream>
export module tsp_algo;
import geometry;
import vector_ops;
import rand_gen;

using namespace std;

namespace tsp_algo {
    export float linear_tsp(vector<vector<float>>& point_data, int rows, int cols)
    {
        float distance = 0;
        for (int i = 0; i < rows - 1; i++) {
            float x1 = point_data[i][1];
            float y1 = point_data[i][2];
            float x2 = point_data[i + 1][1];
            float y2 = point_data[i + 1][2];
            distance += geometry::get_distance(x1, y1, x2, y2);
        }
        return distance;
    }

    export int get_nearest_neighbour(float x1, float y1, vector<vector<float>>& point_data)
    {
        float min = 3.40282347e+37F;
        int nn = 0;
        int rows = vector_ops::get_rows(point_data);
        for (int i = 0; i < rows; i++) {
            float x2 = point_data[i][1];
            float y2 = point_data[i][2];
            float distance = pow(x1 - x2, 2) + pow(y1 - y2, 2);

            if (distance < min) {
                min = distance;
                nn = i;
            }
        }
        return nn;
    }

    export void nearest_neighbour_tsp(vector<vector<float>>& point_data, vector<vector<float>>& visited)
    {
        int nn;
        vector<float> current;
        int start_city = rand_gen::between(0,vector_ops::get_rows(point_data));
        visited.push_back(point_data[start_city]);
        vector_ops::remove(point_data, start_city);
        float total_distance = 0;
        int i = 0;

        while (vector_ops::get_rows(point_data) > 0) {
            vector<float> current = visited[i++];
            nn = tsp_algo::get_nearest_neighbour(current[1], current[2], point_data);
            float distance = geometry::get_distance(current[1], current[2], point_data[nn][1], point_data[nn][2]);
            total_distance += distance;
            visited.push_back(point_data[nn]);
            vector_ops::remove(point_data, nn);
        }
        cout << fixed << total_distance<<endl;
    }

}
