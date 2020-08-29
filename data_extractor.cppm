/* Global Module Fragments */
#include "fstream"
/* #include "ctype.h" */
#include "iostream"

/* Module Preamble */
export module data_extractor;
import string_ops;

using namespace std;

export void read_file(string file_name)
{
    if(file_name.empty())
        return;
    ifstream file;
    string line;

    file.open(file_name);

    if (!file) {
        cout << "Unable to open file datafile.txt";
    }

    /* int i=0; */
    /* while (getline(file, line)) { */
    /*     if(isalpha(line[0])) */
    /*     cout << line[0] << '\n'; */
    /* } */

    file.close();
}
