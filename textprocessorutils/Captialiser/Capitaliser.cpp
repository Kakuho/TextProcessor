#include <iostream>
#include <fstream>
#include <string>

void Capitalise(char& c){
  if(c >= 97 || c <= 122){
    c -= 32;
  }
}

void Capitaliser(std::fstream &input, std::fstream &output){
  std::string line;
  while(getline(input, line)){
    if(line.empty()){
      output << '\n' << '\n';
    } else {
      for(int i = 0; i < line.size(); ++i){
	if(i == 0){
	  Capitalise(line[i]);
	} else if(i > 2 && line[i-2] == '.' && line[i-1] == ' '){
	  Capitalise(line[i]);
	}
	output << line[i];
      }
    }
  }
  input.close(); output.close();
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

  Capitaliser(input, output);
}
