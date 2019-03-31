/*
Program	: Circular Doubly Linked List
Nama	: Muhammad Iqbal Alif Fadilla
NPM		: 140810180020
Tanggal	: 31 03 19
Desc	: Program ini berfungsi untuk menambah atau menghapus elemen terakhir dari linked list.
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

void insertLast(CDLL* &First, CDLL* newNode) {
	CDLL* pBantu = First;
	if (First == NULL) {
		First = newNode;
		First->next = First;
		First->prev = First;
	}
	else if (First->next == First) {
		First->next = newNode;
		First->prev = newNode;
		newNode->prev = First;
		newNode->next = First;
	}
	else {
		while (pBantu->next != First) {
			pBantu = pBantu->next;
		}
		pBantu->next = newNode;
		First->prev = newNode;
		newNode->prev = pBantu;
		newNode->next = First;
	}
}
void deleteLast(CDLL* &First, CDLL* &delNode) {
	delNode = First;
	if (First == NULL) {
		cout << "Tidak ada yang di delete" << endl;
	}
	else if (First->next == First) {
		delNode = First;
		First = NULL;
		delNode->next = NULL;
		delNode->prev = NULL;
	}
	else {
		while (delNode->next != First) {
			delNode = delNode->next;
		}
		delNode->prev->next = First;
		First->prev = delNode->prev;
		delNode->next = NULL;
		delNode->prev = NULL;
		delNode = NULL;
	}
}
void traversal(CDLL *First) {
	CDLL* target = First;
	if (First == NULL) {
		cout << endl << "List kosong" << endl;
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
	cout << "input data:" << endl;
	for (int i = 0; i < 5; i++) {
		createElement(p);
		insertLast(list, p);
	}
	do {
		system("CLS");
		cout << "A. Insert Last\nB.Delete Last\n";
		do {
			cin >> pilihan;
		} while (pilihan != 'a' && pilihan != 'A' && pilihan != 'b' && pilihan != 'B');
		switch (pilihan) {
		case 'a':
			cout << endl << "Keadaan awal" << endl;
			traversal(list);
			cout << endl << "InsertLast: ";
			createElement(p);
			insertLast(list, p);
			cout << endl << "Keadaan akhir" << endl;
			traversal(list);
			break;
		case 'b':
			cout << endl << "keadaan awal" << endl;
			traversal(list);
			deleteLast(list, p);
			cout << endl << "keadaan akhir" << endl;
			traversal(list);
			break;
		}do {
			cout << endl << "Kembali ke menu? (Y/N) "; cin >> loop;
		} while (loop != 'Y' && loop != 'y' && loop != 'N' && loop != 'n');
	} while (loop == 'Y' || loop == 'y');

	return 0;
}
