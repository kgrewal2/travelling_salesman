import data_extractor;
import geometry;

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
    string filename;
    if (argc != 2) {
        cout << "You did not entered any filename!\nPlease enter the filename: ";
        getline(cin, filename);
    } else
        filename = argv[1];
    struct file_data array = extract_data(filename);
    int rows = array.dimension;
    int cols = get_cols(array);
    int distance = 0;
    for (int i = 0; i < rows - 1; i++) {
        cout << int(array.data[i * cols])<<" ";
        distance += get_distance(array.data[i * cols + 1], array.data[i * cols + 2], array.data[(i + 1) * cols + 1], array.data[(i + 1) * cols + 2]);
    }
    cout<<distance;
    delete[] array.data;
    return 0;
}
