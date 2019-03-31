/*
Program	: Circular Doubly Linked List
Nama	: Muhammad Iqbal Alif Fadilla
NPM		: 140810180020
Tanggal	: 31 03 19
Desc	: Program ini berfungsi untuk menambah atau menghapus elemen pertama dari linked list.
*/
#include<iostream>
using namespace std;

struct CDLL {
	int data;
	CDLL *next; 
	CDLL *prev;
};
void createElement(CDLL* &newNode) {
	newNode = new CDLL;
	cin >> newNode->data;
	newNode->next = NULL;
	newNode->prev = NULL;
}
void insertFirst(CDLL* &First, CDLL* newNode) {
	CDLL* last = First;
	if (First == NULL) {
		First = newNode;
		First->next = First;
		First->prev = First;
	}
	else if (First->next == First) {
		newNode->next = First;
		newNode->prev = First;
		First->next = newNode;
		First->prev = newNode;
		First = newNode;
	}
	else {
		newNode->next = First;
		First->prev = newNode;
		while (last->next != First) {
			last = last->next;
		}
		newNode->prev = last;
		last->next = newNode;
		First = newNode;
	}
}
void deleteFirst(CDLL* &First, CDLL* &delNode) {
	delNode = First;
	if (First == NULL) {
		cout << endl << "Tidak ada yang di delete" << endl;
	}
	else if (First->next == First) {
		First = NULL;
		delNode->next = NULL;
		delNode->prev = NULL;
	}
	else {
		First = NULL;
		First = delNode->next;
		First->prev = delNode->prev;
		delNode->prev->next = First;
		delNode->next = NULL;
		delNode->prev = NULL;
	}
}
void traversal(CDLL *First) {
	CDLL* target = First;
	if (First == NULL) {
		cout << "List kosong" << endl;
	}
	else {
		int i = 1;
		cout << "data" << i << " -> prev: " << target->prev->data << endl;
		do {
			cout << "data" << i << " : " << target->data << endl;
			target = target->next;
			i++;
		} while (target != First);
		cout << "data" << i - 1 << " -> next: " << target->data << endl;
	}
}

int main() {
	CDLL *list = NULL, *p;
	char pilihan, loop;
	cout << "Input data :" << endl;
	for (int i = 0; i < 5; i++) {
		createElement(p);
		insertFirst(list, p);
	}
	do {
		system("CLS");
		cout << "A. Insert First\nB.Delete First\n";
		do {
			cin >> pilihan;
		} while (pilihan != 'a' && pilihan != 'A' && pilihan != 'b' && pilihan != 'B');
		switch (pilihan) {
		case 'a':
			cout << endl << "Keadaan awal" << endl;
			traversal(list);
			cout << endl << "InsertFirst: ";
			createElement(p);
			insertFirst(list, p);
			cout << endl << "Keadaan akhir" << endl;
			traversal(list);
			break;
		case 'b':
			cout << endl << "Keadaan awal" << endl;
			traversal(list);
			deleteFirst(list, p);
			cout << endl << "Keadaan akhir" << endl;
			traversal(list);
			break;
		}do {
			cout << "Kembali ke menu? (Y/N) "; cin >> loop;
		} while (loop != 'Y' && loop != 'y' && loop != 'N' && loop != 'n');
	} while (loop == 'Y' || loop == 'y');

	return 0;
}
