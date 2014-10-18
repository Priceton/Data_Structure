// Reverse the string by part.
// Given a string str[] = "An Interview for 360"
// Output : "360 for Interview An"

#include<iostream>
#include<string>
using namespace std;

void reverse(char str[], int start, int end){
	while(start < end){
		swap(str[start++], str[end--]);
	}
}

void ReverseByPart(char str[]){
	if(str == NULL) return;
	int len = strlen(str);
	int iStart = 0, iEnd = len-1;
	reverse(str, iStart, iEnd);
	iEnd = 0;
	while(iEnd < len){
		if(A[iEnd] == ' '|| str[iEnd] == '\0'){
			reverse(str, iStart, iEnd-1);
			iEnd++;
			iStart = iEnd;
		}
		else
			++iEnd;
	}
}


