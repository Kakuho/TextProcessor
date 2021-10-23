#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>



void printLine(int oswidth, std::string &line){
  // int maps to line number to be printed
  if(line.empty()){
      std::cout << '|';
      for(int k = 0; k < 2; k++) std::cout <<' ';
      for(int j = 0; j < oswidth; j++){
	 std::cout << ' ';
      }
      for(int k = 0; k < 2; k++) std::cout <<' ';
      std::cout << '|' << std::endl;
  }
  else{
  int i = 0;
    while(i < line.size()){
      std::cout << '|';
      for(int k = 0; k < 2; k++) std::cout <<' ';
      for(int j = 0; j < oswidth; j++){
	if(i + j > line.size()) std::cout << ' ';
	else if(line[i + j]) std::cout << line[i+j];
	else std::cout << ' ';
      }
      //if(line[i]) std::cout << line[i];
      //if(line[i+1]) std::cout << line[i+1];
      for(int k = 0; k < 2; k++) std::cout <<' ';
      std::cout << '|' << std::endl;
      i += oswidth;
    }
  }
}

void Displayer(std::fstream &input, std::fstream &output, int oswidth){
  std::string line;
  while(getline(input, line)){
    printLine(oswidth, line);
  }
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

  Displayer(input, output, 10);

}
