#include <iostream>
#include <fstream>
#include <string>

int CharacterCounter(std::fstream &input, std::fstream &output){
  std::string line;
  unsigned long int counter = 0;
  while(getline(input, line)){
    for(int i = 0; i < line.size(); ++i){
      if(line[i] != ' '){
	++counter;
      }
    }
  }
  return counter;
}

void printCharacters(std::fstream &input, std::fstream &output){
  std::cout << "Characters: " << CharacterCounter(input, output) << std::endl;
}

int main(){
  //************************************************************//
  //**** Same start of main file for every utility function ****//
  //************************************************************//
  // propmts for input //
  std::cout << "Enter your file: ";
  std::string name;
  getline(std::cin, name);
  // tests to see if entered anything //
  while(name.empty()){
    std::cout << "You didn't type anything. Enter again: ";
    getline(std::cin, name);
  }

  // Starts opening files and writing to files //
  std::fstream input, output;
  input.open(name, std::fstream::in);
  output.open("output.txt", std::fstream::out);

  // Tests to see if input is readable //
  if(!input.good()){
    std::cout << "File cannot be found. Exiting with return code -1" << std::endl;
    return -1;
  }
  //************************************************************//
  printCharacters(input, output);
  return 0;
}
