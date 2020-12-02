#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
class Liczba_zad {	
	public:
	int num, sum, counter = 0;
		int sum_nums(int number1, int number2);
		int return_reversed_number(string numberStr);
		bool is_sum_palindrome(int sumNumber);
		string converse_number_into_string(int number);
		string reverse_number_str(string numberStr);
		
};

class Plik {	
	ifstream fileIn;
	ofstream fileOut;
	public:
		Plik();
		void fileLoop();
		~Plik();
	Liczba_zad liczba;
};



Plik::Plik(){
	fileIn.open("C:\\liczby.txt");
	fileOut.open("C:\\wynik.txt");
}



Plik::~Plik(){
	fileIn.close();
	fileOut.close();
}



string Liczba_zad::converse_number_into_string(int number){
	stringstream ss;
	string s;
	ss<<number;
	ss>>s;
	return s;
}

string Liczba_zad::reverse_number_str(string numberStr){
	string reversedNumber;
	for(int i = numberStr.length()-1; i>=0;i--){
		reversedNumber += numberStr[i];
	}
	return reversedNumber;
}

int Liczba_zad::return_reversed_number(string numberStr){
	int reversedNum;
	istringstream(numberStr) >> reversedNum;
	return reversedNum;	
}

int Liczba_zad::sum_nums(int number1, int number2){
	sum = number1 + number2;
	return sum;
}

bool Liczba_zad::is_sum_palindrome(int sumNumber){
	string stringSum = converse_number_into_string(sum);
	string reversedSum = reverse_number_str(stringSum);
	int back = reversedSum.length()-1;
	bool palindrome = true;
	for(int i = 0; i<reversedSum.length()/2 && palindrome; i++){
		if(reversedSum[i] == reversedSum[back--]){
			counter++;
			return true;
		} else {
			palindrome = false;
			return false;
		}
	}
}

void Plik::fileLoop(){
	int num = liczba.num;
	while(!fileIn.eof()){
		fileIn>>num;
		string convertedString = liczba.converse_number_into_string(num);
		
		string reversedString = liczba.reverse_number_str(convertedString);
		
		int convertedInt = liczba.return_reversed_number(reversedString);
		
		int numsSum = liczba.sum_nums(num, convertedInt);
		
		fileOut<<num<<" "<<convertedInt<<" "<<numsSum<<" "<<liczba.is_sum_palindrome(numsSum)<<endl;
		liczba.sum = 0;
		
	}
	fileOut<<"licznik: "<<liczba.counter;
		
}


int main(int argc, char** argv) {
	Plik p1;	
	p1.fileLoop();
	
	return 0;
}
