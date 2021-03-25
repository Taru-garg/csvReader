#include <iostream>
#include "../../include/csv.h" // use actual path


int main() {
    csv::csv data("{filename}.csv"); // loading using constructor
    data.head();
    return 0;
}