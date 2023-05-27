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

int binarySearch(string *array, int array_size, string key) {
    //initialize min and max
    int min = 0;
    int max = array_size - 1;

    // search loop
    while (min <= max) {
        int middle = min + (max - min) / 2;
        // if key is in middle, hooray
        if (array[middle] == key) {
            return(middle);

        // if key is before middle, restrict search to first half for next loop iteration
        } else if (array[middle] > key) {
            max = middle - 1;
        
        // if key is after middle, restrict search to second half
        } else {
            min = middle + 1;
        }
    }

    // if/when min > max, that means the key is not in the array.
    // return -1 if that is the case.
    return(-1);
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

    int checkresult = checkArraySort(array, line);

    if (checkresult == 0) {
        return(0);
    }

    // initialize search key
    string key;

    // get  key input from user
    cout << "Input the key you want to search for: ";
    cin >> key;

    // binary search
    int result = binarySearch(array, line, key);

    if (result == -1) {
        cout << "The key " << key << " was not found in the array!" << endl;
        return(0);
    }

    cout << "Found key " << key << " at index " << binarySearch(array, line, key) << "!" << endl;

    return(0);
}