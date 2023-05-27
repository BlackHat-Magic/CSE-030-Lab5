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


int forwardBinary(string *array, int array_size, string key) {
    int small_size_one = array_size / 2;
    int small_size_two = array_size / 2 + array_size % 2;
    
    // check if the key is exactly in the middle
    if (*(array + small_size_one) == key) {
        return(small_size_one);

    // check if array is too small
    } else if (array_size < 2) {
        int result = -1;
        return(result);

    // if the middle is after the item, search the first half of the array
    } else if (*(array + small_size_one) > key) {
        string newarray[small_size_two];
        for (int i = 0; i < small_size_two; i++) {
            newarray[i] = *(array + i);
        }
        return(forwardBinary(newarray, small_size_two, key));

    // if the middle is before the item, search the second half of the array
    } else {
        string newarray[small_size_two];
        for (int i = small_size_one, j = 0; i < array_size; i++, j++) {
            newarray[j] = *(array + i);
        }
        int result = forwardBinary(newarray, small_size_two, key);
        if (result == -1) {
            return(result);
        } else {
            return(small_size_one + result);
        }
    }
}
int reverseBinary(string *array, int array_size, string key) {
    int small_size_one = array_size / 2;
    int small_size_two = array_size / 2 + array_size % 2;
    
    // check if the key is exactly in the middle
    if (*(array + small_size_one) == key) {
        return(small_size_one);

    // check if array is too small
    } else if (array_size < 2) {
        int result = -1;
        return(result);

    // if the middle is after the item, search the first half of the array
    } else if (*(array + small_size_one) < key) {
        string newarray[small_size_two];
        for (int i = 0; i < small_size_two; i++) {
            newarray[i] = *(array + i);
        }
        return(reverseBinary(newarray, small_size_two, key));

    // if the middle is before the item, search the second half of the array
    } else {
        string newarray[small_size_two];
        for (int i = small_size_one, j = 0; i < array_size; i++, j++) {
            newarray[j] = *(array + i);
        }
        int result = reverseBinary(newarray, small_size_two, key);
        if (result == -1) {
            return(result);
        } else {
            return(small_size_one + result);
        }
    }
}
int binarySearch(string *array, int array_size, string key) {
    if (*array < *(array + 1)) {
        return(forwardBinary(array, array_size, key));
    } else {
        return(reverseBinary(array, array_size, key));
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