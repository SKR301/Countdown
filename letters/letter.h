/*PLAY THE LETTERS GAME OF COUNTDOWN*/


class letter
{
private:
	std::vector<char> letterList;
public:
	void select(int,int);
	bool isValidInputs(int,int);
	void display();
	void timer(int);
	void shuffleLetterList();
};

void letter::select(int vowel,int consonant){				//select the letters as per required
	if(!isValidInputs(vowel,consonant)){
		std::cout<<"Invalid letters asked";
		std::cout<<"\n\n";
		system("pause");
		system("exit");
	}

	std::cout<<"\nGenerating "<<vowel<<" vowels and "<<consonant<<" consonants";
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
	std::cout<<"\n\n\nYour got "<<time<<" secs!!! STARTS NOW:";

	Sleep((time-5)*1000);
	std::cout<<"\n\n5";
	Sleep(1000);
	std::cout<<"\n4";
	Sleep(1000);
	std::cout<<"\n3";
	Sleep(1000);
	std::cout<<"\n2";
	Sleep(1000);
	std::cout<<"\n1";
	Sleep(1000);
	std::cout<<"\n\n!!!!!!!!STOP!!!!!!!!";
}

void letter::shuffleLetterList(){
	for(int a=0;a<9;a++){
		int b = a + rand() % (letterList.size() - a);
      	// swap(letterList[a], letterList[b]);

		iter_swap(letterList.begin() + a, letterList.begin() + b);
	}
}

void letter::display(){
	std::cout<<"\n\n";
	for(int a=0;a<9;a++){
		std::cout<<letterList[a]<<"\t";
		Sleep(500);
	}
}