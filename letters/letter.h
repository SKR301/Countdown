/*PLAY THE LETTERS GAME OF COUNTDOWN*/
#include<windows.h>
#include<algorithm>
#include "../logger/logger.h"

class letter
{
private:
	std::vector<char> letterList;
	logger l;
public:
	void select(int,int);
	bool isValidInputs(int,int);
	void display();
	void timer(int);
	void shuffleLetterList();
};

void letter::select(int vowel,int consonant){				//select the letters as per required
	if(!isValidInputs(vowel,consonant)){
		// std::cout<<"Invalid letters asked";
		l.log("Invalid letters asked","red");
		l.log("\n\n");
		system("pause");
		system("exit");
	}

	// std::cout<<"\nGenerating "<<vowel<<" vowels and "<<consonant<<" consonants";
	l.log("\nGenerating ","green");
	l.log(std::to_string(vowel),"yellow");
	l.log(" vowels and ","green");
	l.log(std::to_string(consonant),"yellow");
	l.log(" consonants","green");

	Sleep(1000);

	srand(time(NULL));
	for(int a=0;a<vowel;a++){							//select vowel letters
		int random=rand()%5;
		switch(random){
			case 0:letterList.push_back('A');break;
			case 1:letterList.push_back('E');break;
			case 2:letterList.push_back('I');break;
			case 3:letterList.push_back('O');break;
			case 4:letterList.push_back('U');break;
		}
	}

	for(int a=0;a<consonant;a++){							//select consonant letters
		int random=rand()%26;
		if(random==0||random==4||random==8||random==14||random==20){
			a--;
			continue;
		}
		letterList.push_back(char(random+65));
	}					

	shuffleLetterList();
}

bool letter::isValidInputs(int vowel,int consonant){			//check if requested letters are valid
	if(vowel<3||consonant<3){
		return false;
	}
	if(vowel>6||consonant>6){
		return false;
	}
	if(vowel+consonant!=9){
		return false;
	}
	return true;		
}

void letter::timer(int time){				//start the timer in mili()
	// std::cout<<"\n\n\nYour got "<<time<<" secs!!! STARTS NOW:";
	l.log("\n\n\nYour got "+std::to_string(time)+" secs!!! STARTS NOW:","yellow");

	Sleep((time-5)*1000);
	l.log("\n\n5","yellow");
	Sleep(1000);
	l.log("\n\n4","yellow");
	Sleep(1000);
	l.log("\n\n3","yellow");
	Sleep(1000);
	l.log("\n\n2","yellow");
	Sleep(1000);
	l.log("\n\n1","yellow");
	Sleep(1000);
	l.log("\n\n-----------------STOP-----------------");
}

void letter::shuffleLetterList(){
	for(int a=0;a<9;a++){
		int b = a + rand() % (letterList.size() - a);
		iter_swap(letterList.begin() + a, letterList.begin() + b);
	}
}

void letter::display(){
	l.log("\n\n");
	for(int a=0;a<9;a++){
		std::string s(1,letterList[a]);
		l.log("    "+s+"    ","red");
		Sleep(500);
	}
}