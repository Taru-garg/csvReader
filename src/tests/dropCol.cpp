#include <iostream>
#include "../../include/csv.h" // use actual path


int main() {
    csv::csv data("iris.csv");
    data.head();
    return 0;
}