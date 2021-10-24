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

bool isaA(std::string &sentence, int pos){
  if(sentence[pos] == 'a' || sentence[pos] == 'A'){
    return true;
  }
  else{
    return false;
  }
}

void correctArticles(std::fstream &input, std::fstream &output){
  std::string line;
  int flag = 0;
  while(getline(input, line)){
    flag = 0;
    for(int i = 0; i < line.size(); i++){
      if(i > 3 && isVowel(line[i]) && line[i-1] == ' ' && isaA(line, i-2) && line[i-3] == ' '){
	  std::string lastPart = line.substr(i);
	  std::string beginningPart = line.substr(0, i);
	  beginningPart[beginningPart.size() - 1] = 'n';
	  beginningPart.push_back(' ');
	  //std::cout << '|' << beginningPart << '|' << std::endl;
	  //std::cout << '|' << lastPart << '|' << std::endl;
	  
	  std::string corrected = beginningPart + lastPart;
	  //std::cout << corrected << std::endl;
	  output << corrected << std::endl;
	  flag = 1; 
      }
      else if(i == 2 && isVowel(line[i]) && line[i-1] == ' ' && isaA(line, i-2)){
	  std::string lastPart = line.substr(i);
	  std::string beginningPart = line.substr(0, i);
	  beginningPart[beginningPart.size() - 1] = 'n';
	  beginningPart.push_back(' ');
	  //std::cout << '|' << beginningPart << '|' << std::endl;
	  //std::cout << '|' << lastPart << '|' << std::endl;

	  std::string corrected = beginningPart + lastPart;
	  //std::cout << corrected << std::endl;
	  output << corrected << std::endl;
	  flag = 1;
      }
    }
    if(flag == 0){
      output << line << std::endl;
    }
    line.erase(line.begin(), line.end());
  }
}

int main(){

  std::cout << "Enter the file name: " << std::endl;
  std::string name;
  std::cin >> name;
  std::fstream input, output;

  input.open(name, std::fstream::in);
  output.open("output.txt", std::fstream::out);

  correctArticles(input, output);
 
  input.close(), output.close();
}
