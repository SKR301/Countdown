#include<bits/stdc++.h>
#include "number.h"

int main(){
	int big;

	std::cout<<"Enter how many big numbers:";
	std::cin>>big;

	number N;
	
	N.select(big,6-big);
	
	N.display();

	N.genNumber();

	N.timer(30);		//given time in secs (cannot be less than 5)

	std::cout<<"\n\n";
	system("pause");
}