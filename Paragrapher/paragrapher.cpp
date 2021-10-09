#include <iostream>
#include <fstream>
#include <string>

void printString(std::string s){
  for(int k = 0 ; k < s.size(); k++){
    std::cout << s[k];
  }
  std::cout << std::endl;
}

int main(int argc, char** argv){
  if(argc > 2){
    std::cout << "There is more than one file!" << std::endl;
    return -1;
  } else if(argc == 1){
    std::cout << "You did not enter a file!" << std::endl;
    return 1;
  } else { 
    //std::cout << argv[1] << std::endl; // this line of code shows the input file.
    std::fstream inputFile, outputFile;
    // name fromatter
    std::string inputFileName = argv[1];
    std::string outputFileName = "P_" + inputFileName;
    //std::cout << outputFileName; // check to see if file name works

    // opening files
    inputFile.open(inputFileName, std::fstream::in | std::fstream::out | std::fstream::app);
    outputFile.open(outputFileName, std::fstream::in | std::fstream::out | std::fstream::app);

    std::string str;
    std::string paragraph;
    int lineCount = 0;
    while(std::getline(inputFile, str)){
      lineCount++;
      //std::cout << lineCount << ": " << str << std::endl;
      if(str.empty()){
	//std::cout << lineCount << ": Empty Line!" << std::endl;  // alerts if there's a empty line
	//std::cout << " paragraph: " << paragraph << std::endl;
	if(!paragraph.empty()){
	  outputFile << paragraph << '\n' << std::endl;
	  paragraph.erase(paragraph.begin(), paragraph.end());
	}
      } 
      else {
	for(int i = 0; i < str.size(); i++){
	  paragraph.push_back(str[i]);
          //std::cout << i << ": " << paragraph << std::endl;
	}
	paragraph.push_back(' ');
	std::cout << paragraph << std::endl;
      }
    }
    // putting last paragraph in
    outputFile << paragraph << '\n' << std::endl;
    paragraph.erase(paragraph.begin(), paragraph.end());

    inputFile.close(); outputFile.close();
  }
}
