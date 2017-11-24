#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(){
	map<string,int> m_label;
	m_label.insert(pair<string,int>("apple",500));
	m_label.insert(pair<string,int>("banana",1200));

	map<string,int>::iterator it;
	for(it = m_label.begin(); it != m_label.end(); it++){
		cout << it->first << " , " << it->second << endl;
	}
	return 0;
}