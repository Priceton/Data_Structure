//
//

#include<iostream>
#include<string>

using namespace std;

char* strcpy(char *to, char *from){
	if(to == NULL || from == NULL)
		return NULL;
	char *p = to;
	while(*p++ = *from++ != '\0');
	return to;
}

char* strcat(char *dst, const char *src){
	if(dst == NULL || src == NULL)
		return dst;
	char *p = dst;
	while(*p != '\0') p++;
	while(*p++ = *str++ != '\0');
	return dst;
}

char* strcmp(const char *str1, const char *str2){
	while(*str1 == *str2){
		if(*str1 = '\0') return 0;
		++str1;
		++str2;
	}
	return *str1 - *str2;
}

void reverse(char *str, int s, int e){
	if(str == NULL) return;
	while(s < e){
		swap(str[s++], str[e--]);
	}
}

size_t strlen(const char *str){
	const char *s = str;
	while(*s != '\0') ++s;
	return (s-str);
}

//*****************************************

char* strStr(const char *test, const char *pattern){
	if(test == NULL || pattern == NULL)
		return NULL;
	int t_len = strlen(test);
	int p_len = strlen(pattern);

	int i,j;
	for(i=0; i<t_len-p_len; ++i){
		for(j=i; j<p_len; ++j){
			if(test[i+j] != pattern[j])
				break;
		}
		if(j == p_len) return test+i;	//find the pattern.
	}
	return NULL;
}

//The lenth is len, but the index from 0 -> len-1, be careful.
char* leftRotation(char *str, int k){
	if(str == NULL) return;
	int len = strlen(str);
	k = k%len;
	reverse(str, 0, k-1);
	reverse(str, k, len-1);
	reverse(str, 0, len-1);
	return str;
}

//********* Implentation of String Operation ******************//
class String{
	friend istream& operator>> (istream &, string &);
	friend ostream& operator<< (istream &, string &);
	
public:
	String(const char *str = NULL);
	String(const String &other);
	~String(){ delete []m_data;}

	String& operator=(const String &other);
	String operator+(const String &other) const; //return value cannot be a reference of itself.
	bool operator==(cosnt String &other);
	char& operator[](unsigned int);

	size_t size(){ return strlen(m_data); }

private:
	char *m_data;

}

inline String::String(const char *str){
	if(str == NULL) m_data = NULL;
	else{
		m_data = new char[strlen(str)+1];
		strcpy(m_data, str);
	}
}

inline String::String(const String &other){
	if(other.m_data == NULL){
		m_data = NULL;
	}
	else{
		m_data = new char[strlen(other.m_data)+1];
		strcpy(m_data, other.m_data);
	}
}

inline String& String::operator=(const String &other){
	if(&other != this){
		delete []m_data;
		if(other.m_data == NULL){
			m_data = NULL;
		}
		else{
			m_data = new char[strlen(other.m_data)+1];
			strcpy(m_data, other.m_data);
		}
	}
	return *this;
}

inline String String::operator+(const String &other) const {
	String newString;
	if(other.m_data == NULL){
		newString = *this;
	}
	else if(m_data == NULL){
		newString = other;
	}
	else{
		newString.m_data = new char[strlen(m_data)+strlen(other.m_data) + 1];
		strcpy(newString.m_data, m_data);
		strcat(newString.m_data, other.m_data);
	}
	return newString;
}

inline bool String::operator==(const String &other){
	if(strlen(m_data) != strlen(other.m_data))
		return false;
	else
		return (strcmp(m_data, other.m_data) == 0) ? true : false;
}

inline char& String::operator[](unsigned int e){
	if(e >= 0 && e<= strlen(m_data)){
		return m_data[e];
	}
}

ostream& operator<<(iostream &os, String &str){
	os<<str.m_data;
	return os;
}

istream& operator>>(istream &is, String &str){
	char tmp[255];
	is>>setw(255)>>tmp;
	str = tmp;
	return is;
}

