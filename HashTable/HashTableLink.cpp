

#include<iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x=0) : val(x), next(NULL){}
};

class HashTable{
	public:
		HashTable(int len);
		~HashTable();

		int hash(int key);
		void insert(int key);
		bool search(int key, int &addr);

	private:
		ListNode* (*m_elem);
		int m_len;
};

HashTable::HashTable(int len){
	m_len = len;
	m_elem = new ListNode*[m_len];
	for(int i=0; i<m_len; ++i){
		m_elem[i] = new ListNode();
	}
}

HashTable::~HashTable(){
	for(int i=0; i<m_len; ++i){
		ListNode *h = m_elem[i];
		while(h != NULL){
			ListNode *t = h;
			h = h->next;
			delete t;
		}
	}
}

HashTable::hash(int key){
	return key%m_len;
}

void HashTable::insert(int key){
	int addr = hash(key);
	ListNode *newNode = new ListNode(key);
	newNode->next = m_elem[addr]->next;
	m_elem[addr]->next = newNode;
	return true;
}

bool HashTable::search(int key, int &addr){
	addr = hash(key);
	ListNode *p = m_elem[addr]->next;
	while(p != NULL){
		if(p->val = key) return true;
		p = p->next;
	}
	return false;
}

