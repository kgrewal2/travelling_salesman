#include "cstring"
#include "iostream"
export module str_ops;

using namespace std;

namespace str_ops {
int get_index_of(string substr, string str, int start_index = 0);
int to_int(string str);

/* Returns the index of the substr in str */
export int get_index_of(string substr, string str, int start_index)
{
    size_t found = str.find(substr, start_index);
    return found;
}

/* Converts string into integer */
export int to_int(string str)
{
    int i;
    try {
        i = stoi(str);
    } catch (invalid_argument const& e) {
        cout << "Bad input: invalid_argument thrown" << '\n';
    } catch (out_of_range const& e) {
        cout << "Integer overflow: out_of_range thrown" << '\n';
    }
    return i;
}

// Replace the occurence of term with replacement
export string replace_all(string str, const string& term, const string& replacement)
{
    size_t start_pos = 0;
    while ((start_pos = str.find(term, start_pos)) != string::npos) {
        str.replace(start_pos, term.length(), replacement);
        start_pos += replacement.length();
    }
    return str;
}
}
