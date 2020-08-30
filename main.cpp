#include "bits/stdc++.h"
#include <iostream>
#include <string>
import scraper;
import geometry;
import tsp_algo;
import vector_ops;

using namespace std;

int main(int argc, char** argv)
{
    string filename;
    if (argc != 2) {
        cout << "You did not entered any filename!\nPlease enter the filename: ";
        getline(cin, filename);
    } else
        filename = argv[1];

    struct scraper::file_data filedata = scraper::extract_data(filename);

    int rows = filedata.dimension;
    int cols = scraper::get_cols(filedata);
    vector_ops::print_vector(filedata.point_data);
    cout << tsp_algo::linear_tsp(filedata.point_data, rows, cols);

    return 0;
}
