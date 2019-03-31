/*
Program	: Doubly Linked List Pembalap
Nama	: Muhammad Iqbal Alif Fadilla
NPM		: 140810180020
Tanggal	: 31 03 19
Desc	: Program ini berfungsi untuk membuat bagan pembalap.
*/
#include <iostream>
#include <windows.h>
#include <iomanip>
using namespace std;

struct Pembalap
{
	char nama[20];
	char tim[20];
	int pos;
	int lap;
	int time;
	Pembalap* next;
	Pembalap* prev;
};
typedef Pembalap* pointer;
typedef pointer List;

void createList(List& First)
{
	First=NULL;
}

void createElmnt(pointer& pBaru)
{
	pBaru=new Pembalap;
	cout << "\n********************************************\n";
	cout << "Nama Pembalap\t: "; cin.ignore(); cin.getline(pBaru->nama,20);
	cout << "Nama Tim\t: ";  cin >> pBaru->tim;
	cout << "Posisi\t\t: "; cin >> pBaru->pos;
	cout << "Lap\t\t: "; cin >> pBaru->lap;
	cout << "Time/Gap\t: "; cin >> pBaru->time;
	pBaru->next=NULL;
	pBaru->prev=NULL;
}

void insertFirst(List& First, pointer pBaru)
{
	if (First==NULL) First=pBaru;
	else
	{
		pBaru->next=First;
		First->prev=pBaru;
		First=pBaru;
	}
}

void insertLast(List& First, pointer pBaru)
{
	pointer Last;
	if (First==NULL) First=pBaru;
	else
	{
		Last=First;
		while (Last->next!=NULL)
		{
			Last=Last->next;
		}
		pBaru->prev=Last;
		Last->next=pBaru;
	}
}

void linearSearch(List First, int key, int& found, pointer& pCari)
{
	found=0;
	pCari=First;
	while  (found==0 && pCari!=NULL)
	{
		if(pCari->pos==key)
		{
			found=1;
		} 
		else pCari=pCari->next;
	}
}

void insertAfter (List& First, pointer pBaru, pointer pCari)
{
	if (First==NULL) cout << "List kosong.";
	else if (pCari==NULL) cout << "Indeks search kosong.";
	else if (pCari->next==NULL) insertLast(First, pBaru);
	else
	{
		pBaru->next=pCari->next;
		pBaru->prev=pCari;
		pBaru->next->prev=pBaru;
		pCari->next=pBaru;
	}
}

void insertBefore (List& First, pointer pBaru, pointer pCari)
{
	if (First==NULL) cout << "List Kosong";
	else if (pCari==NULL) cout << "Indeks search kosong.";
	else if (pCari==First) insertFirst(First, pBaru);
	else
	{
		pBaru->next=pCari;
		pBaru->prev=pCari->prev;
		pCari->prev->next=pBaru;
		pCari->prev=pBaru;
	}
}

void deleteFirst(List& First, pointer pHapus)
{
	if(First==NULL)
	{
		pHapus=NULL;
		cout << "List kosong, tidak ada yang bisa dihapus." << endl;
	}
	else if (First->next==NULL)
	{
		pHapus=First; First=NULL;
	}
	else
	{
		pHapus=First;
		First=First->next;
		pHapus->next=NULL;
		First->prev=NULL;
	}
}

void deleteLast(List& First, pointer pHapus)
{
	pointer Last;
	if (First==NULL)
	{
		pHapus=NULL;
		cout << "List kosong, tidak ada yang bisa dihapus" << endl;
	}
	else if (First->next==NULL)
	{
		pHapus=First;
		First=NULL;
	}
	else
	{
		Last=First;
		while (Last->next != NULL)
		{
			Last=Last->next;
		}
		pHapus=Last;
		Last->prev->next=NULL;
		pHapus->prev=NULL;
	}
}

void deleteAfter(List& First, pointer pHapus, pointer pCari)
{
	if (First==NULL) cout << "List Kosong.";
	else if (pCari->next==NULL) cout << "Tidak ada yang bisa dihapus.";
	else if (pCari->next->next==NULL) deleteLast(First, pHapus);
	else
	{
		pHapus=pCari->next;
		pCari->next=pHapus->next;
		pHapus->next->prev=pCari;
		pHapus->next=NULL;
		pHapus->prev=NULL;
	}
}

void deleteBefore(List& First, pointer pHapus, pointer pCari)
{
	if (pCari->prev==NULL) cout << "Tidak ada yang bisa dihapus.";
	else if (pCari->prev==First) deleteFirst(First, pHapus);
	else
	{
		pHapus=pCari->prev;
		pHapus->prev->next=pCari;
		pCari->prev=pHapus->prev;
		pHapus->next=NULL;
		pHapus->prev=NULL;
	}
}

void deletepCari(List& First, pointer pHapus, pointer pCari)
{
	if (pCari==First) deleteFirst(First, pHapus);
	else if (pCari->next==NULL) deleteLast(First, pHapus);
	else
	{
		pHapus=pCari;
		pCari->prev->next=pCari->next;
		pCari->next->prev=pCari->prev;
		pCari->next=NULL;
		pCari->prev=NULL;
	}
}

void traversal(List& First)
{
	pointer pBantu;
	if (First==NULL) cout << "List Kosong.";
	else
	{
		pBantu=First;
		do
		{
			cout << setw(6) << pBantu->pos << setw(20) << pBantu->nama << setw(20) << pBantu->tim << setw(8) << pBantu->lap << setw(15) << pBantu->time << endl;
			pBantu=pBantu->next;
		}
		while (pBantu!=NULL);
	}
	cout << endl;	
}

void update(List First, pointer& pCari)
{
	cout << "Nama Pembalap\t: "; cin.ignore(); cin.getline(pCari->nama,20);
	cout << "Nama Tim\t: ";  cin >> pCari->tim;
	cout << "Lap\t\t: "; cin >> pCari->lap;
	cout << "Time/Gap\t: "; cin >> pCari->time;
}

int main() {
	List x;
	pointer p, pCari, pHapus;
	int key;
	char pil1;
	int found;
	int pil;
	
	createList(x);
	do
	{
		system("cls");
		cout << "=====================Menu====================\n"
			 << "1. Insert First\t\t"
			 << "2. Insert Last\n"
			 << "3. Insert After\t\t"
			 << "4. Insert Before\n"
			 << "5. Delete First\t\t"
			 << "6. Delete Last\n"
			 << "7. Delete After\t\t"
			 << "8. Delete Before\n"
			 << "9. Delete Posisi\t"
			 << "10. Update\n"
			 << "11. Tampilkan List\n"
			 << "\nPilihan: "; cin >> pil;
		switch(pil)
		{
			case 1:
				createElmnt(p);
				linearSearch(x, key, found, pCari);
				if (found) cout << "Posisi sudah ada." << endl;
				else
				{
					insertFirst(x,p);
				}
				break;
			case 2:
				createElmnt(p);
				linearSearch(x, key, found, pCari);
				if (found) cout << "Posisi sudah ada." << endl;
				else
				{
				insertLast(x,p);
				}
				break;			
			case 3:
				cout << "Masukkan posisi yang akan ditambahkan setelahnya: "; cin >> key;
				linearSearch(x, key, found, pCari);
				if (found)
				{
					cout << "Ditemukan yang dicari." << endl;
					createElmnt(p);
					insertAfter(x, p, pCari);
				}
				else cout << "Tidak ditemukan yang dicari." << endl;
				break;
			case 4:
				cout << "Masukkan posisi yang akan ditambahkan sebelumnya: "; cin >> key;
				linearSearch(x, key, found, pCari);
				if (found)
				{
					cout << "Ditemukan yang dicari." << endl;
					createElmnt(p);
					insertBefore(x, p, pCari);
				}
				else cout << "Tidak ditemukan yang dicari." << endl;
				break;
			case 5:
				deleteFirst(x, pHapus);
				break;
			case 6:
				deleteLast(x, pHapus);
				break;
			case 7: 
				cout << "Masukkan posisi yang akan dihapus setelahnya: "; cin >> key;
				linearSearch(x, key, found, pCari);
				if (found)
				{
					cout << "Ditemukan yang dicari." << endl;
					deleteAfter(x, pHapus, pCari);
				}
				else cout << "Tidak ditemukan yang dicari." << endl;
				break;
			case 8:
				cout << "Masukkan posisi yang akan dihapus sebelumnya: "; cin >> key;
				linearSearch(x, key, found, pCari);
				if (found)
				{
					cout << "Ditemukan yang dicari." << endl;
					deleteBefore(x, pHapus, pCari);
				}
				else cout << "Tidak ditemukan yang dicari." << endl;
				break;
			case 9:
				cout << "Masukkan posisi yang akan dihapus: "; cin >> key;
				linearSearch(x, key, found, pCari);
				if (found)
				{
					cout << "Ditemukan yang dicari." << endl;
					deletepCari(x, pHapus, pCari);
					cout << "Delete pCari: " << endl;
					traversal(x);
				}
				else cout << "Tidak ditemukan yang dicari." << endl;
				break;
			case 10:
				cout << "Masukkan posisi yang akan diupdate: "; cin >> key;
				linearSearch(x, key, found, pCari);
				if (found)
				{
					cout << "Ditemukan yang dicari." << endl;
					update(x, pCari);
				}
				else cout << "Tidak ditemukan yang dicari." << endl;
				break;
			case 11:
				cout<<"\n============================== Papan Informasi Pole Position F1 2019 =============================="<<endl;
				cout<<"\n---------------------------------------------------------------------------------------------------"<<endl;
				cout << setw(6) << "Posisi" << setw(20) << "Pembalap" << setw(20) << "Tim" << setw(8) << "Lap" << setw(15) << "Waktu/Gap(ms)" << endl;
				cout<<"---------------------------------------------------------------------------------------------------"<<endl;
				traversal(x);
				cout<<"---------------------------------------------------------------------------------------------------"<<endl;
				break;
			default: 
				cout << "Pilihan anda tidak ada.";
				break;
		}
		cout << "Back to Menu (Y) "; cin >> pil1;
	}	while (pil1=='Y' || pil1=='y');
}


