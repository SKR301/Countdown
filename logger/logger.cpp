#include <bits/stdc++.h>
#include "logger.h"

int main(){
	logger l;

	l.log("Your name\n","blue","black");			
	l.log(std::to_string(1111)+"\n","red","yellow");
	l.log(std::to_string(111.11111));
	l.log("\n\n");

	system("pause");
}
