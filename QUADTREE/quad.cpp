#include <iostream>
#include <vector>
#include <string>
using namespace std;
int changeUpAndDown[4] = {2,3,0,1};
class node{
public:
 	node* children[4];
 	char val[4];
 	int val_count;
 	int children_count;
 	node(){
 		for(int i = 0 ; i < 4; i++)val[i]='#';
 		val_count = 0;
 		children_count = 0;
 	}
 	void push(char _val){
 		//cout << "update > " << _val << endl;
 		val[val_count] = _val;
 		children[children_count] = new node();
 		val_count++;
 		children_count++;
 	}

 	node* getChild(){
 		return children[children_count-1];
 	}
};

class QuadTree{
public:
	node* root;
	node* cur;
	QuadTree(string& data){
		root = new node;
		cur = root;
		initQuadTree(0,data,root);
		cur = root;
		print_nodes(root);
	}

	void print_nodes(node* current){
		//cout << "cur node's children_count : " << current->children_count << endl;
		//cout << "cur node's val_count : " << current->val_count << endl;
		for(int i = 0 ; i < 4 ; i++){
			if(current->val[changeUpAndDown[i]] != '#'){
				
				if(current->val[changeUpAndDown[i]] == 'x'){
					cout << current->val[changeUpAndDown[i]];
					print_nodes(current->children[changeUpAndDown[i]]);
				}else{
					cout << current->val[changeUpAndDown[i]];
				}
			}
		}
	}

	int initQuadTree(int start,string& data,node* current){

		if(start == data.size())return -1;

		int i = start;

		int idxCnt = 0;

		while((idxCnt < 4) && (i < data.size())){

			char c;

			if(data[i] == 'x'){

				c = data[i];

				//cout << "start : " << start << " , index : " << idxCnt << " , parts : " << c << endl;

				current->push(c);

				//cout << current->val[current->val_count-1] << endl;
				
				node* next_child = current->getChild();
				
				i = initQuadTree(i+1,data,next_child);
			
			}else{
			
				c = data[i];
				
				//cout << "start : " << start << " , index : " << idxCnt << " , parts : " << c << endl;

				current->push(c);

				//cout << current->val[current->val_count-1] << endl;
				
			}

			idxCnt++;
			
			i++;
		
		}

		return i-1;

	}

};


int main(){
	int N;
	cin >> N;
	for(int n = 0 ; n < N; n++){
		string data;
		QuadTree* qtree;
		cin >> data;
		//cout << data << endl;
		qtree = new QuadTree(data);	
		cout << endl;

	}
	return 0;
}