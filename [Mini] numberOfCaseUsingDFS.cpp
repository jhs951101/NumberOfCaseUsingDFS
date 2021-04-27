#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

/*
	Made by: SharPing - Sharp Coder
	Date of Modification: 2020-10-24
*/

int str2int(const string &str) {
	stringstream ss(str);
	int num;
	
	if((ss >> num).fail())
	{ 
	  cout << "Error: Cannot convert" << endl;
	}
	
	return num;
}

string trim(const string& s) {
   if(s.length() == 0)
       return s;

   size_t beg = s.find_first_not_of(" \a\b\f\n\r\t\v");
   size_t end = s.find_last_not_of(" \a\b\f\n\r\t\v");
   if(beg == string::npos)
       return "";

   return string(s, beg, end - beg + 1);
}

string roots[500][2];
int numOfRoot;

int minRoot = 2147483647;
int maxRoot = 0;
int numOfCase = 0;

// DFS �˰����� ������ Ʈ�� Ž��
void findDes(const string src, const string des, const int cnt, string root){
	if(src == des){
		cout << root << endl;
		
		if(minRoot > cnt)
			minRoot = cnt;
		if(maxRoot < cnt)
			maxRoot = cnt;
			
		numOfCase++;
	}
	
	for(int i=0; i<numOfRoot; i++){
		if(roots[i][0] == src)
			findDes(roots[i][1], des, cnt+1, root + " - " + roots[i][1]);
	}
}

int main(){
	
	string src;
	string des;
	
	cout << "������� �Է��ϼ���: ";
	getline(cin, src);
	
	cout << "�������� �Է��ϼ���: "; 
	getline(cin, des);
	
	string str;
	
	cout << "Root�� ���� �Է��ϼ���: ";
	getline(cin, str);
	
	numOfRoot = str2int(str);
	
	cout << endl << "Root�� " << numOfRoot << "�� ��ŭ ��� �Է��ϼ���" << endl;
	
	for(int i=0; i<numOfRoot; i++){
		getline(cin, str);
		
		char split_char = ',';

		istringstream split(str);
		vector<string> tokens;
		
		for (string each; getline(split, each, split_char); tokens.push_back(each))
			;
			
		for(int j=0; j<tokens.size(); j++){
			tokens[j] = trim(tokens[j]);
		}
		
		roots[i][0] = tokens[0];
		roots[i][1] = tokens[1];
	}
	
	cout << endl;
	
	findDes(src, des, 0, src);
	
	if(numOfCase <= 0){
		cout << endl << "Error: �������� ���� �� �ִ� ��ΰ� �������� �ʽ��ϴ�." << endl;
	}
	else{
		cout << endl << "�� ����� ��: " << numOfCase << endl;
		cout << "���̰� ���� �� ��: " << maxRoot << endl;
		cout << "���̰� ���� ���� ��: " << minRoot << endl;
	}

	return 0;
}

