#include <iostream>
#include <fstream>
#include <string>

int main(){
  // propmts for input
  std::cout << "Enter your file: ";
  std::string name;
  getline(std::cin, name);
  // tests to see if entered anything
  while(name.empty()){
    std::cout << "You didn't type anything. Enter again: ";
    getline(std::cin, name);
  }

  std::fstream input, output;
  input.open(name, std::fstream::in);
  output.open("output.txt", std::fstream::out);

  if(!input.good()){
    std::cout << "File cannot be found. Exiting with return code -1" << std::endl;
    return -1;
  }
  
  // this is where code starts
  std::string line;
  while(getline(input, line)){
    if(line.empty()){
      output << std::endl;
    }

    // program to clear all subsequent lines of empty texts
    while(line.empty()){
      line.erase(0, line.size());
      getline(input, line);
    }
    output << line << std::endl;
    line.erase(0, line.size());
  }
  input.close(); output.close();
}
