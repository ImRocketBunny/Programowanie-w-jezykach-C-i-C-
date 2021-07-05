// punktowane.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <time.h>
#include <stdio.h>
using namespace std;
/*struct Node {
	int data;
	Node* next;
};*/

struct Student {
	string imie;
	string nazwisko;
	int nrIndexu;
	time_t data;
};
void menu(vector<Student> vec) {
	cout << "wybierz co zrobic" << endl;
	cout << "1 Dodaj" << endl;
	cout << "2 usun" << endl;
	cout << "3 nadpisz" << endl;
	cout << "4 odczytaj" << endl;
	cout << "5 wyjdz" << endl;
	int a;
	cin >> a;
	if (a == 1) {
		string i;
		string n;
		int es = 0;
		time_t data;
		cout << "podaj imie" << endl;
		cin >> i;
		cout << "podaj nazwisko" << endl;
		cin >> n;
		cout << "podaj date" << endl;
		cin >> data;
		Student id;
		id.imie = i;
		id.nazwisko = n;
		id.nrIndexu = es;
		id.data = data;
		vec.push_back(id);
		cout << "dodane" << endl;
		cout << sizeof(vec) / sizeof(vec[0]) << endl;
		menu(vec);
	}
	if (a == 2) {
		cout << "podaj numer do usuniecia" << endl;
		int nr;
		cin >> nr;
		if (nr <= sizeof(vec) / sizeof(vec[0])) {
			vec.erase(vec.begin() + nr);
			cout << "usunieto" << endl;
		}
		else {
			cout << "blad try again" << endl;
			menu(vec);
		}
	}
	if (a == 3) {
		int ind;
		cout << "podaj index do podmiany" << endl;
		cin >> ind;
		string i;
		string n;
		int es = 0;
		time_t data;
		cout << "podaj imie" << endl;
		cin >> ind;
		cout << "podaj nazwisko" << endl;
		cin >> n;
		cout << "podaj date" << endl;
		cin >> data;
		Student id;
		id.imie = i;
		id.nazwisko = n;
		id.nrIndexu = es;
		id.data = data;
		vec[ind] = id;
		cout << "podmienione" << endl;
		menu(vec);
	}
	if (a == 4) {
		//int a;
		menu(vec);
	}
	if (a == 5) {
		ofstream plik("Z:/c++/baza.txt");
		for (int i = 0; i < sizeof(vec)/sizeof(vec[0]); i++) {
			plik << &vec[i] << ";" << endl;

		}
		plik.close();
		
	}
	else {
		cout << "blad, wybierz 1-5" << endl;
		menu(vec);
	}
}
/*bool add(Node*& head, int data);
size_t size(const Node* head);
void clear(Node*& head);
void printList(Node* head);
bool add(Node*& head, int data) {
	Node* tmp = head;
	while (tmp != 0 && tmp->data != data) {
		tmp = tmp->next;
	}
	if (tmp != 0) {
		return false;
	}
	Node* h2 = new Node;
	h2->data = data;
	h2->next = head;
	head = h2;
	return true;

	/*int counter = 0;
	if (head->next != nullptr) {
		if (head->data == data) {
			//cout << "Not aded " << head->next << endl;
			counter++;
		}

	}
	if (counter == 0) {
		return true;
	}
	else{
		return false;
	}
}
size_t size(const Node* head) {
	size_t siz = 0;
	const Node* h2 = head;
	while (h2 != 0) {
		siz++;
		h2 = h2->next;
	}
	return siz;
}
void clear(Node*& head) {
	if (head->next != 0) {
		clear(head->next);
	}
	cout << "Del " << head->data << endl;
	delete head;
}
void printList(Node* head) {
	if (head != 0) {
		cout << head->data << endl;
		printList(head->next);
	}
	else {

	}

}*/

/*int main() {
	using std::cout; using std::endl;
	int tab[] = { 1,4,1,3,5 };
	Node* head = 0;
	for (size_t i = 0; i < 5; ++i) {
		bool b = add(head, tab[i]);
		cout << tab[i] << (b ? "     " : " NOT ")
			<< "added" << endl;
	}
	cout << "Size of the list: " << size(head) << endl;
	printList(head);
	clear(head);
}*/


int main()
{
	std::vector<Student> myList;
	
	ifstream mojStrumien("Z:/c++/baza.txt");
	if (mojStrumien) {
		string linia;
		//char a;
		string b = "";
		string im;
		string n;
		int es;
		time_t data;
		int id = 0;
		cout << "yo" << endl;
		while (getline(mojStrumien, linia)) {
			cout << linia << endl;
			int counter = -1;
			for (int i = 0; i < sizeof(linia)/sizeof(linia[0])+2; i++) {
				//cout << sizeof(linia) / sizeof(linia[0]) << endl;
				if (linia[i] != ' ' && linia[i] != ';') {
					b += linia[i];
					//cout << b << endl;
				}
				if (linia[i] == ' ') {
					counter++;
					//cout << counter << endl;
					if (counter == 0) {
						im = b;
						b = "";
						cout << im << endl;
						
					}
					if (counter == 1) {
						n = b;
						b = "";
						cout << n << endl;
						
					}
					if (counter == 2) {
						cout << "jestem" << endl;
						istringstream iss(b);
						iss >> es;
						b = "";
						cout << es << endl;
					}
					if (counter == 3) {
						//cout << "elo" << endl;
						counter=0;
						int y, m, d;
						string c;
						int counter2 = 0;
						for (int j = 0; j < sizeof(b) / sizeof(b[0]); j++) {
							if (b[j] != '-')
								c += b[j];
							if (b[j] == '-') {
								counter2++;
								if (counter2 == 1) {
									istringstream iss(b);
									iss >> y;
								}
								if (counter2 == 2) {
									istringstream iss(b);
									iss >> m;
								}
								if (counter2 == 3) {
									istringstream iss(b);
									iss >> d;
								}
							}
						}
						data = y-m-d;
						b = "";
						cout << data << endl;

					}
				}
				if (linia[i] == ';') {
					cout << "elo" << endl;
					counter = 0;
					id = id+1;
					Student id;
					cout << im << endl;
					id.imie = im;
					id.nazwisko = n;
					id.nrIndexu = es;
					id.data = data;
					im = "";
					n = "";
					es = 0;
					data = 0 - 0 - 0;
					myList.push_back(id);
				}
			}
		}
		cout << sizeof(myList) / sizeof(myList[0]) << endl;
		menu(myList);
	}
	else {
		cout << "nie mozna odczytac pliku" << endl;

	}
	return 0;


}

