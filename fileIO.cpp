# include <iostream>
# include <fstream>
# include <string>

using namespace std;

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

    // define output file
    ofstream outfile;
    outfile.open("words_out.txt");

    // loop through array and wrire values
    for (int i = 0; i < line; i++) {
        outfile << array[i] << "\n";
    }

    // close output file
    outfile.close();

    return(0);
}