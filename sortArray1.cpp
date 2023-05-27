# include <iostream>

using namespace std;

void sortArr (int *array, int size, int descending) {
    if(descending != 1){
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                int loindex = *(array + i);
                int hiindex = *(array + j);
                if (loindex > hiindex) {
                    *(array + i) = hiindex;
                    *(array + j) = loindex;
                }
            }
        }
    } else {
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                int loindex = *(array + i);
                int hiindex = *(array + j);
                if (loindex < hiindex) {
                    *(array + i) = hiindex;
                    *(array + j) = loindex;
                }
            }
        }
    }

    return;
}

int main () {
    // initialize the size variable
    int size;
    int descending;

    // get array size from user
    cout << "Enter the size of the array: ";
    cin >> size;

    // check if size is valid
    if (size < 1) {
        cerr << "You entered an incorrect value for the array size!" << endl;
        return(1);
    }
    int array[size];

    // get array numbers from user
    cout << "Enter the numbers in the array, separated by a space, and press enter: ";

    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    // ask if user wants it descending
    cout << "Sort in ascending (0) or descending (1) order? ";
    cin >> descending;

    // selection sort
    sortArr(array, size, descending);

    string quest;
    if (descending == 0) {
        quest = "ascending";
    } else {
        quest = "descending";
    }

    cout << "This is the sorted array in " << quest << " order:" << endl;
    for (int i = 0; i < size; i++) {
        if (i + 1 < size) {
            cout << array[i] << ", ";
        } else {
            cout << array[i] << endl;
        }
    }

    return(0);
}