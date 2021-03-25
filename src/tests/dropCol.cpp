#include <iostream>
#include "../../include/csv.h" // use actual path


int main() {
    csv::csv data("{filename}.csv"); // loading the csv
    
    // printing the columns before modification
    data.printCols();

    // dropping the column inplace
    // column can be dropped inplace or can use dropCol() to return a new csv object
    data.dropColInplace("{colimn name}");

    // printing modified csv
    data.printCols();

    return 0;
}