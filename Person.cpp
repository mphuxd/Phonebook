//Matthew Pham
//998804208
//HW4
//Person.cpp

#include <iostream>
#include "Person.h"
#include <string>
using namespace std;

Person::Person(string last,string first, string num): lastname_(last), firstname_(first), number_(num){
}

string Person::lastname(void)const{return lastname_;}
string Person::firstname(void)const{return firstname_;}
string Person::number(void)const{return number_;}
	
std::ostream& operator<<(ostream& os, const Person& p){
	return os << p.lastname()<<" "  << p.firstname()<< " " << p.number() << endl;
}

bool Person::operator<(const Person& p) const{
	if(&p==this){
		return false;
	} //checks if L==R; if yes, return.. 
	if(this->lastname_.compare(p.lastname_)<0){
		//cout <<this->lastname_ << endl;
		//cout <<p.lastname_<<endl;
		return true;}
	if(this->lastname_ == p.lastname_){ if(this->firstname_.compare(p.firstname_)<0){
		//cout<<this->lastname_<< " " << p.lastname_ << " " <<this->firstname_ << " " << p.firstname() <<endl;
		return true;
	}
	return false;	
	}
return false;
}

	

	

