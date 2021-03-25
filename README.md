# csvReader
A C++ class to perform basic operations on CSV


## Usage 
The usage is pretty simple. Just include the file ```csv.h``` in your project and it is done.
This library runs well for smaller csv files but might give some error when handling larger csv files (mostly while printing).
Currently it supports the following functionalities :-
- Load and Save
 - ```.loadCSV()``` this function loads the csv given a path to the file.
  - ```.save()``` this function saves the modified csv given a path to save to.
- Modification Functions
 - ```.addCol()``` this function adds a new column towards the end of csv object given a column name and a vector<string> and returns a new csv object.
 - ```.addColInplace()``` this function adds a new column towards the end of csv object given a column name and a vector<string> to the same csv.
 - ```.dropCol()``` this function drops a column given a column name and returns a new csv object.
 - ```.dropColInplace()``` this function drops a column from the csv object given a column name.
- Printing Functions
 - ```.printCols()``` prints a list of all the column names.
 - ```.printData()``` prints the complete csv file.
 - ```.head()``` prints the first 5 rows and the column names in a tabular format.
- Fetching Functions
 - ```.extractCol()``` returns a vector<string> contaning data of that column given a column name.
 - ```.getCols()``` returns a vector<string> containing all the column names.
 - ```.indexOf()``` returns the index of a column in the CSV given a column name.
