#pragma once
#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace csv {
// template <typename... T>
class csv {
public:
  std::vector<std::string> colNames;
  std::vector<std::vector<std::string>> data;
  // std::vector<std::tuple<T...>> dataC;
  // bool
  // string
  // int
  // float
  csv(const std::vector<std::string> vals) {
    colNames.emplace_back(vals[0]);
    data.emplace_back(vals);
  }
  csv(const std::string &path) { loadCSV(path); }
  void loadCSV(const std::string &path) {
    std::ifstream csvFile;
    csvFile.open(path);
    if (!csvFile.is_open()) {
      std::cerr << "Error loading file" << std::endl;
      exit(1);
    }
    bool flag = false;
    std::vector<std::string> temp;
    while (!csvFile.eof()) {
      std::string dataRow;
      getline(csvFile, dataRow);
      std::stringstream stream(dataRow);
      std::string vals;
      while (getline(stream, vals, ',')) {
        temp.push_back(vals);
      }
      if (!flag) {
        colNames = temp;
        data.emplace_back(temp);
      } else {
        data.emplace_back(temp);
      }
      temp.clear();
      flag = true;
    }
    csvFile.close();
  }

  std::vector<std::string> getCols() const { return colNames; }
  std::vector<std::vector<std::string>> getData() const { return data; }
  template <typename... T> void printCols() const {
    for (const auto &name : colNames) {
      std::cout << name << "\t";
    }
    std::cout << std::endl;
  }
  void printData() const {
    for (const auto &x : data) {
      for (const auto &y : x) {
        std::cout << y << "\t\t";
      }
      std::cout << std::endl;
    }
  }
  void head() {
    for (int i = 0; i < std::min(data.size(), 5UL); i++) {
      for (int j = 0; j < data[i].size(); j++) {
        std::cout << data[i][j] << "\t";
      }
      std::cout << std::endl;
    }
  }
  int indexOf(const std::string &Colname) const {
    for (int i = 0; i < colNames.size(); i++) {
      if (Colname == colNames[i])
        return i;
    }
    return -1;
  }
  int dropColInplace(const std::string &Colname) {
    int index = indexOf(Colname);
    if (index != -1) {
      colNames.erase(colNames.begin() + index);
      for (auto &row : data) {
        row.erase(row.begin() + index);
      }
      return 0;
    }
    return -1;
  }
  csv dropCol(const std::string &Colname) const {
    csv copy = *this;
    copy.dropColInplace(Colname);
    return copy;
  }
  void addColInplace(const std::string &name,
                     const std::vector<std::string> &vals) {
    assert(vals.size() == data.size() - 1);
    colNames.push_back(name);
    data[0].push_back(name);
    for (int i = 1; i < data.size(); i++) {
      data[i].push_back(vals[i]);
    }
  }
  csv addCol(const std::string &name,
             const std::vector<std::string> &vals) const {
    csv copy = *this;
    copy.addColInplace(name, vals);
    return copy;
  }
  std::vector<std::string> extractCol(const std::string &Colname) const {
    std::vector<std::string> vals;
    int index = indexOf(Colname);
    if (index != -1) {
      for (int i = 1; i < data.size(); i++) {
        vals.push_back(data[i][index]);
      }
    }
    return vals;
  }
  bool save(const std::string &path) const {
    std::ofstream file;
    file.open(path);
    if (!file.is_open()) {
      return false;
    }
    bool flag = true;
    for (int i = 0; i < data.size(); i++) {
      file << data[i][0];
      for (int j = 1; j < data[i].size(); j++) {
        file << "," << data[i][j];
      }
      if (i == data.size() - 1) {
        flag = false;
      }
      if (flag) {
        file << "\n";
      }
    }
    file.close();
    return true;
  }
};
} // namespace csv
