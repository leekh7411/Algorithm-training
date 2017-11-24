#include <iostream>
using namespace std;
class node{
public:
	node* next;
	int val;
	node(){
		val = 0;
		next = NULL;
	}
};

class linkedList{
private:
	node* head;
	node* end;
	int size;
public:
	linkedList(){
		head = new node();
		size = 0;
		end = head;
	}
	void push_back(int _val){
		if(size == 0){
			head->val = _val;
			size++;
		}
		else{
			end->next = new node();
			end->next->val = _val;
			end = end->next;
			size++;
		}
	}
	void print_list(){
		cout << "SIZE : " << size << endl;
		node* cur = head;
		while(size >= 0){
			if(cur == NULL)break;
			cout << cur->val << " ";
			cur = cur->next;
			size--;
		}
		cout << endl;
	}
};

int main(){

	linkedList lList;
	for(int i = 0 ; i < 100 ; i++){
		lList.push_back(i);
	}
	lList.print_list();

	return 0;
}