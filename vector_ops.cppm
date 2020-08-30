#include "bits/stdc++.h"
export module vector_ops;
using namespace std;

namespace vector_ops {
    export void resize_vector(vector<vector<float>>& vect, int rows, int cols)
    {
        vect.resize(rows);
        for (int i = 0; i < rows; i++) {
            vect[i].resize(cols);
        }
    }

    export void print_vector(vector<vector<float>>& vect)
    {
        for (int i = 0; i < vect.size(); i++) {
            for (int j = 0; j < vect[i].size(); j++)
                cout << vect[i][j] << "\t";
            cout << endl;
        }
    }

    export int get_cols(vector<vector<float>>& vect)
    {
        return vect[0].size();
    }
    export int get_rows(vector<vector<float>>& vect)
    {
        return vect.size();
    }
}
