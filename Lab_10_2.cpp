#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;


// Â²ÄÊĞÈÒÒß ÔÀÉËÓ
bool OpenFile(char* fname)
{
	fstream f(fname);
	if (!f.is_open())
	{
		cout << "Ôàéë íå â³äêğèòî!" << endl;
		return false;
	}
	f.close();
	return true;
}

// ÏÎØÓÊ ÍÀÉÁ²ËÜØÎ¯ Ê²ËÜÊÎÑÒ² ÏĞÎÁ²Ë²Â
int MaxSpacesCount(char* fname) {
	ifstream fin(fname);
	string s;
	int maxSpaces = 0;
	int currentSpaces = 0;

	while (getline(fin, s)) {
		for (unsigned i = 0; i < s.length(); i++) {
			if (s[i] == ' ') {
				currentSpaces++;
			}
			else {
				if (currentSpaces > maxSpaces) {
					maxSpaces = currentSpaces;
				}
				currentSpaces = 0;
			}
		}
	}

	if (currentSpaces > maxSpaces) {
		maxSpaces = currentSpaces;
	}

	return maxSpaces;
}

// ÂÈÂ²Ä ²ÍÔÎĞÌÀÖ²¯ ÔÀÉËÓ
void PrintInfo(char* fname) 
{
	ifstream fin(fname); 
	string s; 
	while (getline(fin, s)) 
	{
		cout << s << endl; 
	}
	cout << endl;
	cout << "Ìàêñèìàëüíà ê³ëüê³ñòü ïğîá³ë³â ïîñï³ëü: " << MaxSpacesCount(fname) << endl;
}




int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const int SIZE = 100;
	char fname[SIZE]; 
	char ch;
	
	do {
		cout << "Íàïèø³òü íàçâó ôàéëó: "; cin >> fname;
		OpenFile(fname);
		PrintInfo(fname);
		cout << "continue? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');

	
	return 0;
}