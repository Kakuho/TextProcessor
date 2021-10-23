#include <iostream>
#include <fstream>
#include <string>

void printString(std::string s){
  for(int k = 0 ; k < s.size(); k++){
    std::cout << s[k];
  }
  std::cout << std::endl;
}

void Paragraphify(std::fstream &input, std::fstream &output){
  std::string str;
  std::string paragraph;
  int lineCount = 0;
    while(std::getline(input, str)){
      lineCount++;
      //std::cout << lineCount << ": " << str << std::endl;
      if(str.empty()){
	//std::cout << lineCount << ": Empty Line!" << std::endl;  // alerts if there's a empty line
	//std::cout << " paragraph: " << paragraph << std::endl;
	if(!paragraph.empty()){
	  output << paragraph << '\n' << std::endl;
	  paragraph.erase(paragraph.begin(), paragraph.end());
	}
      } 
	else {
	  for(int i = 0; i < str.size(); i++){
	  paragraph.push_back(str[i]);
	  //std::cout << i << ": " << paragraph << std::endl;
	  }
	paragraph.push_back(' ');
	//std::cout << paragraph << std::endl;
      }
    }
  // putting last paragraph in
  output << paragraph << '\n' << std::endl;
  paragraph.erase(paragraph.begin(), paragraph.end());

  input.close(); output.close();
}

int main(int argc, char** argv){
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

  Paragraphify(input, output);
}
