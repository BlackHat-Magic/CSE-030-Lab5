# include <iostream>
# include <fstream>
# include <string>

using namespace std;

int checkArraySort(string *array, int array_size){
    int result = 0;

    // loop through array
    for (int i = 0; i < array_size - 1; i++) {
        // if current element and next element are in ascending order,
        // increment result by 1. Otherwise decrement result by 1.
        // this will result in result being equal to array_size-1
        // if the array is ascending.
        // result will be -1*array_size+1 if the array is descending
        // result will be in between if the array is neither.
        if(*(array + i) < *(array + i + 1)) {
            result ++;
        } else {
            result --;
        }
    }

    if (result == array_size - 1) {
        return(1);
    } else if (result == -1 * array_size + 1) {
        return(-1);
    } else {
        return(0);
    }

}

int main () {
    // open file
    ifstream infile;
    infile.open("words_in.txt");

    // dummy variable to read data and test if we're at the end of a file
    string dummy;

    // loop through file lines to find the end
    int line = 0;

    infile >> dummy;

    while (!infile.eof()) {
        infile >> dummy;
        line ++;
    }
    infile.close();

    // define array of size equal to number of lines in output file
    string array[line];

    // write values from file to array
    infile.open("words_in.txt");
    for (int i = 0; i < line; i++) {
        infile >> array[i];
    }
    infile.close();

    int result = checkArraySort(array, line);

    if(result == -1) {
        cout << "The array is sorted in descending order!" << endl;
    } else if (result == 0) {
        cout << "The array is not sorted!" << endl;
    } else {
        cout << "The array is sorted in ascending order!" << endl;
    }

    return(0);
}