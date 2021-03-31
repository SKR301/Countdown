/*PLAY THE NUMEBR GAME OF COUNTDOWN*/

#include<windows.h>
#include "../logger/logger.h"

class number
{
private:
	std::vector<int>finalNumbers;
	int possible[13]={1,2,3,4,5,6,7,8,9,25,50,75,100};
	logger l;
public:
	void select(int,int);
	bool isValidInputs(int,int);
	void display();
	void genNumber();
	void timer(int);
};

void number::select(int big,int small){				//select the numbers as per required
	if(!isValidInputs(big,small)){
		// std::cout<<"Invalid numbers asked";
		l.log("Invalid numbers asked","red");
		l.log("\n\n");
		system("pause");
		system("exit");
	}

	// std::cout<<"\nGenerating "<<big<<" big and "<<small<<" small numbers";
	l.log("\nGenerating ","green");
	l.log(std::to_string(big),"yellow");
	l.log(" big and ","green");
	l.log(std::to_string(small),"yellow");
	l.log(" small numbers","green");
	Sleep(1000);

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

void number::genNumber(){					//generate final number
	srand(time(NULL));
	l.log("\n\nNumber to get: \t[");
	l.log(std::to_string(rand()%899+100),"blue");
	l.log("]");
	return ;
}

void number::timer(int time){				//start the timer in mili()
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

void number::display(){
	std::cout<<"\n\n";
	for(int a=0;a<6;a++){
		// std::cout<<finalNumbers[a]<<"\t";
		l.log("    "+std::to_string(finalNumbers[a])+"    ","red");
		Sleep(500);
	}
}