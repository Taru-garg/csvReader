#include <iostream>
#include <vector>
#include <string>
#include "../../include/csv.h" // use actual path


int main() {
    csv::csv data("{filename}.csv");
    
    std::vector<std::string> extractedCol;

    // Extract Column Example
    // column only extracted to a string vector
    extractedCol = data.extractCol("{column name}");
    
    for(auto x : extractedCol) {
        std::cout << x << std::endl;
    }

    // Add Columm Example
    /* This sample uses the extracted column although any string vector can be added */
    data.printCols();

    // adding the column
    // column can be added Inplace or we can use addCol() to return a new csv object
    data.addColInplace("{new column name}", extractedCol);

    // printing modified csv
    data.printCols();

    return 0;
}
