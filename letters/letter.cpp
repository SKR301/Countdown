#include<bits/stdc++.h>
#include<windows.h>
#include<algorithm>
#include "letter.h"

int main(){
	int vowels;
	
	std::cout<<"Enter how many vowels:";
	std::cin>>vowels;

	letter L;
	
	L.select(vowels,9-vowels);
	
	L.display();

	L.timer(60);		//given time in secs (cannot be less than 5)

	std::cout<<"\n\n";
	system("pause");
}