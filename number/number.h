/*PLAY THE NUMEBR GAME OF COUNTDOWN*/


class number
{
private:
	std::vector<int>finalNumbers;
	int possible[13]={1,2,3,4,5,6,7,8,9,25,50,75,100};
public:
	void select(int,int);
	bool isValidInputs(int,int);
	void display();
	int genNumber();
	void timer(int);
};

void number::select(int big,int small){				//select the numbers as per required
	if(!isValidInputs(big,small)){
		std::cout<<"Invalid numbers asked";
	}

	std::cout<<"\nGenerating "<<big<<" big and "<<small<<" small numbers";
	srand(time(NULL));
	for(int a=0;a<big;a++){							//select big numbers
		int random=rand()%4+9;
		finalNumbers.push_back(possible[random]);
	}

	for(int a=0;a<small;a++){							//select small numbers
		int random=rand()%9;
		finalNumbers.push_back(possible[random]);
	}					
}

bool number::isValidInputs(int big,int small){			//check if requested numbers are valid
	if(big<0||small<1){
		return false;
	}
	if(big>4||small>6){
		return false;
	}
	if(big+small!=6){
		return false;
	}
	return true;		
}

int number::genNumber(){					//generate final number
	srand(time(NULL));
	return (rand()%899+100);
}

void number::timer(int time){				//start the timer in mili()
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

void number::display(){
	std::cout<<"\n\n";
	for(int a=0;a<6;a++){
		std::cout<<finalNumbers[a]<<"\t";
	}
}