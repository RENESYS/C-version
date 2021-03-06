#include<string>
#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char* argv[]){
	ifstream inFile;
	ofstream outFile;
	string start, end;
	inFile.open("script.txt");
	getline(inFile, start);
	getline(inFile, end);
	inFile.close();

	inFile.open("originSrc.txt");
	string before;
	getline(inFile, before);
	outFile.open("modSrc.txt");

	outFile << "void partStart(){}" << endl;
	outFile << "void partEnd(){}" << endl;
	while (!inFile.eof()){
		string cur;
		getline(inFile, cur);
		for (int i = 0; i < cur.length(); i++){
			if (cur[i] == '\t')
				cur.erase(cur.begin());
		}
		
		if (cur == start){
			cout << "string found" << endl;
			outFile << "partStart();" << endl;
			outFile << cur << endl;
		}
		else if (cur == end){
			cout << "string end" << endl;

			outFile << cur << endl;
			outFile << "partEnd();" << endl;
		}
		else{
			outFile << cur << endl;
			before = cur;
		}
	}
	inFile.close();
	outFile.close();
	return 0;
}