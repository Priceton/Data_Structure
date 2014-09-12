

#include<iostream>

using namespace std;

class HashTable{
	public:
		HashTable(int length);
		~HashTable();

		int hash(int key);
		bool insertLinear(int key);
		bool searchLinear(int key, int &addr);
		bool insertRand(int key);
		bool searchRand(int key, int &addr);
	private:
		int *m_elem;
		int m_len;
};

HashTable::HashTable(int length){
	int m_len = length;
	m_elem = new int[m_len]();
	for(int i=0; i<m_len; ++i)
		m_elem[i] = INT_MAX;
}

HashTable::~HashTable(){
	m_len = 0;
	delete m_elem;
}

int HashTable::hash(int key){
	return key % m_len;
}

bool insertLinear(int key){
	int addr = hash(key);
	while(m_elem[addr] != INT_MAX){
		addr = (addr + 1) % m_len;
		if(addr == hash(key))    // have go with a loop.
			return false;
	}
	m_elem[addr] = key;
	return true;
}

bool HashTable::searchLinear(int key, int &addr){
	addr = hash(key);
	while(m_elem[addr] != key){
		addr = (addr + 1) % m_len;
		if(addr == hash(key) || m_elem[addr] == INT_MAX)
			return false;
	}
	return true;
}

bool HashTable::insertRand(int key){
	int addr = hash(key);
	while(m_elem[addr] != INT_MAX){
		addr = (addr + rand()) % m_len;
	}
	m_elem[addr] = key;
	return true;
}

bool HashTable::searchRand(int key, int &addr){
	addr = hash(key);
	while(m_elem[addr] != key){
		addr = (addr + rand()) % m_len;
		if(addr == hash(key) || elem[addr] = INT_MAX)
			return false;
	}
	return true;
}


