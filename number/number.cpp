#include<bits/stdc++.h>
#include<windows.h>
#include "number.h"

int main(){
	int big;
	
	std::cout<<"Enter how many big numbers:";
	std::cin>>big;

	number N;
	
	N.select(big,6-big);
	
	N.display();

	std::cout<<"\n\nNumber to get: \t["<<N.genNumber()<<"]";

	N.timer(10);		//given time in secs (cannot be less than 5)

	std::cout<<"\n\n";
	system("pause");
}