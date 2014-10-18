// simplify a string: 
// str[] = "    i am    a    student.   "
//---> str[] = "i am a student."

#include<iostream>
#include<string>
using namespace std;

void SimplifyString(char str[], int len){
	int iStart = -1;
	while(str[++iStart] == ' ');

	int index = 0;
	for(int i= iStart+1; i<len; ++i){
		if(str[i] != ' ' || str[i-1] != ' '){
			str[++index] = str[i];
		}
	}
	str[index] = '\0';
}

