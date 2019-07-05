//
//Matthew Pham
//998804208
//phonebook.cpp
//

#include <iostream>
#include <sstream>
#include <fstream>
#include "Person.h"
#include <string>
#include <cassert>
#include <set>
#include <iomanip>

using namespace std;

void conditions(string &last, string &first, string &number){
	for(unsigned int i = 0; i<last.length(); i++){
		if(!isalpha(last[i])){ throw invalid_argument("invalid characters in last name");}
	}
	for(unsigned int i = 0; i<first.length(); i++){
		if(!isalpha(first[i])){ throw invalid_argument("invalid characters in first name");}
	}

	if(number[3]!='-' || number[7]!='-'){throw invalid_argument("invalid number format");}
	 
	string area, num1, num2;
	area = number.substr(0,3);
	num1 = number.substr(4,3);
	num2 = number.substr(8,4);

	for(unsigned int i=0;area[i]!=NULL;i++){
		if(!isdigit(area[i])){throw invalid_argument("invalid number format");}
	}
	for (unsigned int i=0;num1[i]!=NULL;i++){
	if(!isdigit(num1[i])){throw invalid_argument("invalid number format");}
	}
	for(unsigned int i=0;num2[i]!=NULL;i++){
		if(!isdigit(num2[i])){throw invalid_argument("invalid number format");}
	}
}




int main(int argc, char* argv[]){
	//argc = 2
	if (argc > 2){cout << "too many argument"; return -1;}
	if (argc < 2){cout << "file not found"; return -1;}

	//checks for 2 arguments, program & filename. else throws error	
	//assert (argc == 2);//) throw invalid_argument("file not found");
	//opens file into filestream using name from argv1 
	set<Person> Phonebook;	
	
	ifstream inFile(argv[1]);
	if (!inFile) throw invalid_argument("file not found");
	
try{
	while(!inFile.eof()){
		string line;
		getline(inFile,line); //line from infile is copied to line
		istringstream is(line);//operating on line
			//create vector to store tokens OR use getline to store tokens in string
			//pass tokens to person as argument
			//constructor to verify tokens
			//
		string last, first, number;
		is >> last >> first >> number;
		//cout << line << endl;
		//cout << last << ' '  << first << ' ' << number << endl; //print to check line
		if(number.length() == 0) continue;
		conditions(last,first,number);
		Person p1(last,first,number);
		Phonebook.insert(p1);	
	}


	for(set<Person>::iterator i = Phonebook.begin();i!=Phonebook.end();i++){
		cout <<setw(15) << left << i->lastname()
			  <<setw(15) << i->firstname()
			  << i->number() <<  endl;
	}
}
	catch (invalid_argument& e){
		cout << e.what() << endl;
  }	
}
