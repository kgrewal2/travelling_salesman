/* Global Module Fragments */
#include "bits/stdc++.h"
#include "cstring"
#include "fstream"
#include "iostream"

/* Module Preamble */
export module scraper;
import str_ops;
import vector_ops;

using namespace std;

namespace scraper {
export struct file_data {
    bool is_symmetric = true;
    int dimension;
    vector<vector<float>> point_data;
    bool* visited;
};
ifstream read_file(string file_name);
string get_dimension(string data);
string get_tsp_data(string data);
void string_to_array(string data, vector<vector<float>>& array, int rows, int cols);
export int get_cols(file_data data);

export file_data extract_data(string file_name)
{
    struct file_data final_data;
    /* OPENING FILE */
    ifstream file;
    file = read_file(file_name);

    /* FILE TO STRING */
    string tsp_data;
    getline(file, tsp_data, (char)file.eof());

    final_data.dimension = str_ops::to_int(get_dimension(tsp_data));
    if (str_ops::get_index_of("ATSP", tsp_data, 0) != -1)
        final_data.is_symmetric = false;

    /* GET TSP DATA */
    tsp_data = get_tsp_data(tsp_data);
    int rows = final_data.dimension;
    int cols = get_cols(final_data);
    if (final_data.is_symmetric) {
        cols = 3;
    }

    vector_ops::resize_vector(final_data.point_data, rows, cols);
    string_to_array(tsp_data, final_data.point_data, rows, cols);

    return final_data;
}

export int get_cols(file_data data)
{
    if (data.is_symmetric) {
        return 3;
    }
    return data.dimension;
}

void string_to_array(string data, vector<vector<float>>& array, int rows, int cols)
{
    data = str_ops::replace_all(data, string("\n"), string(" "));
    int temp_r = 0;
    int temp_c = 0;
    for (int i = 0; i < data.length(); i++) {
        if (data[i] != ' ') {
            string temp = "";
            while (data[i] != ' ') {
                temp = temp + data[i];
                i++;
            }
            array[temp_r][temp_c] = stof(temp);
            temp_c++;
            if (temp_c == cols) {
                temp_c = 0;
                temp_r++;
            }
        }
    }
}

string get_tsp_data(string data)
{
    int end_index = str_ops::get_index_of("EOF", data, 0);
    int start_index = str_ops::get_index_of("EDGE_WEIGHT_SECTION", data, 0);
    if (start_index == -1)
        start_index = str_ops::get_index_of("NODE_COORD_SECTION", data, 0);
    start_index = str_ops::get_index_of("\n", data, start_index) + 1;
    string tsp_data = data.substr(start_index, end_index - start_index);
    return tsp_data;
}

string get_dimension(string data)
{
    string term = "DIMENSION:";
    int string_index = str_ops::get_index_of(term, data, 0);
    int end_index = str_ops::get_index_of("\n", data, string_index);
    string value = data.substr(string_index + term.length(), end_index - string_index - term.length());
    return value;
}

ifstream read_file(string file_name)
{
    ifstream file;
    file.open(file_name);
    if (!file) {
        cout << "Unable to open the file";
        exit(1);
    }
    return file;
}
}
