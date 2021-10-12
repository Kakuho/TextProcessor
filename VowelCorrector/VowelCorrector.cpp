#include <iostream>
#include <fstream>
#include <string>

bool isVowel(char c){
  switch(c){
    case 'a': case 'e':
    case 'i': case 'o': case 'u':
      return true;

    default:
      return false;
    }
}

int main(){

  std::cout << "Enter the file name: " << std::endl;
  std::string name;
  std::cin >> name;
  std::fstream input, output;

  input.open(name, std::fstream::in);
  output.open("output.txt", std::fstream::out);

  std::string line;
  while(getline(input, line)){
    for(int i = 0; i < line.size(); i++){
      if(i > 3){
	if(isVowel(line[i]) && line[i-1] == ' ' && (line[i-2] == 'a' || line[i-2] == 'A') && line[i-3] == ' ');
      }
      else if(i = 2){
	if(isVowel(line[i]) && line[i-1] == ' ' && (line[i-2] == 'a' || line[i-2] == 'A'));
      }
    }
    line.erase(line.begin(), line.end());
  }
}
