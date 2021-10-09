#include <iostream>
#include <fstream>
#include <string>


int main(){
  // Prompting and Entering the file name
  std::cout << "Enter your filename: ";
  std::string inputName;
  getline(std::cin, inputName);
  // testing to see if user entered a empty line
  while(inputName.empty()){
    std::cout << "Empty file name!\nPlease enter again: ";
    getline(std::cin, inputName);
  }
  //std::cout << name << std::endl;

  // Trying to find the file in the local directory
  std::fstream input, output;
  input.open(inputName, std::fstream::in);
  if(!input.good()){
    std::cout << "Cannot find file: " << inputName << '\n'
              << "Exiting with return value -1" << std::endl;
    return -1;
  }

  // Code to count all the non empty characters in the file
  std::string line;
  unsigned long int counter = 0;
  while(getline(input, line)){
    for(int i = 0; i < line.size(); ++i){
      //std::cout << line[i];
      //std::cout << line[0];
      if(line[i] != ' '){
	++counter;
      }
    }
  }
  std::cout << "Characters: " << counter << std::endl;
  return 0;
}
