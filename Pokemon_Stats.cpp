//working file
#include <string>
#include <vector>
#include <iostream>
#include <sstream>


std::vector<std::string> Process_Line(std::string & column_name) {
  std::getline(std::cin, column_name, ':');
  std::string rest_of_first_line;
  std::getline(std::cin, rest_of_first_line);
  std::istringstream first_line_iss(rest_of_first_line);
  std::string element;
  std::vector<std::string> column;
  while (std::getline(first_line_iss, element, ',')) {
    column.push_back(element);
  }
  return column;
}

void Output_Max(std::vector<std::string> const & first_column_elements, 
  std::vector<std::string> const & second_column_elements) {
  std::vector<int> second_column_elements_ints;
  for (std::string const & s : second_column_elements) {
    std::istringstream iss(s);
    int x;
    iss >> x;
    second_column_elements_ints.push_back(x);
  }
  std::string max_first_column;
  int max_second_column = 0;
  for (int i = 0; i < static_cast<int>(first_column_elements.size()); ++i) {
    if (second_column_elements_ints.at(i) > max_second_column) {
      max_second_column = second_column_elements_ints.at(i);
      max_first_column = first_column_elements.at(i);
    }
  }
  std::cout << "Max:" << std::endl << max_first_column << ',' << max_second_column << ',' << std::endl;
}

int main() {

  std::string first_column_name;
  std::vector<std::string> first_column_elements = Process_Line(first_column_name);
  std::string second_column_name;
  std::vector<std::string> second_column_elements = Process_Line(second_column_name);

  std::cout << first_column_name << ',' << second_column_name << ',' << std::endl;
  for (int i = 0; i < static_cast<int>(first_column_elements.size()); ++i) {
    std::cout << first_column_elements.at(i) << ',' << second_column_elements.at(i) << ',' << std::endl;
  }
  std::cout << std::endl;
  Output_Max(first_column_elements, second_column_elements);


  return 0;
}
