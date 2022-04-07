#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
COORD position = { 0, 0 };
void shifr_text();
void zamena();
void result();
bool alph(char ch);
int main()
{
	setlocale(LC_ALL, "rus");
	shifr_text();
return 0;
}
void shifr_text()
{
	ifstream Beginresult("Begintext.txt");
	ofstream Endresult("Endtext1.txt");
	if (!Beginresult.is_open()) {
		cout << "Ошибка открытия файла!" << endl;
	}
	else {
		char ch;
		while (Beginresult.get(ch)) {
			if (alph(ch)&&ch!=' ') {
				ch--;
				Endresult << ch;
			}
			else {
				Endresult << ch;
			}
		}
	}
	Beginresult.close();
	Endresult.close();
	zamena();
}
void zamena() {
	ifstream Beginresult("Endtext1.txt");
	ofstream Endresult("Endtext2.txt");
	int stroka = 1;
	if (!Beginresult.is_open()) {
		cout << "Ошибка открытия файла!" << endl;
	}
	else {
		char ch;
		while (Beginresult.get(ch)) {
			if (ch == '\n')
				stroka++;
			if (stroka % 2 == 0) {
				Endresult << ch;
				Beginresult.get(ch);
				do {
					if (ch == 's' || ch == 'S') {
						ch = '$';
						Endresult << ch;
					}
					else
						Endresult << ch;
					Beginresult.get(ch);
				} while (ch != '\n');
				Endresult << ch;
				stroka++;
			}
			else  
				Endresult << ch;
		}
	}
	Beginresult.close();
	Endresult.close();
	result();
}
void result()
{
	ifstream Beginresult("Begintext.txt");
	ifstream Endresult("Endtext1.txt");
	ifstream Endresult2("Endtext2.txt");
	short b = 0;
	char ch;
	cout << "Изначальный текст" << endl;
	while (Beginresult.get(ch)) {
		cout << ch;
	}
	position = { 24, b };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Расшифровка текста" << endl;
	b++;
	position = { 24, b };
	SetConsoleCursorPosition(hConsole, position);
	while (Endresult.get(ch)) {
		cout << ch;
		if (ch == '\n') {
			b++;
			position = { 24, b };
			SetConsoleCursorPosition(hConsole, position);
		}
	}
	b = 0;
	position = { 49, b };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Замена 's' на '$'" << endl;
	b++;
	position = { 49, b };
	SetConsoleCursorPosition(hConsole, position);
	while (Endresult2.get(ch)) {
		cout << ch;
		if (ch == '\n') {
			b++;
			position = { 49, b };
			SetConsoleCursorPosition(hConsole, position);
		}
	}
	Beginresult.close();
	Endresult.close();
	Endresult2.close();
}
bool alph(char ch)
{
	char test[130] = "A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,a, b,c ,d, e, f ,g, h, i, j, k, l, m ,n, o, p, q, r, s, t, u, v, w, x, y, z";
	for (int i = 0; i < sizeof(test); i++)
	{
		if (ch == test[i])
		{
			return true;
		}

	}
	return false;
}