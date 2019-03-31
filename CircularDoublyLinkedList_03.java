/*
Program	: Circular Doubly Linked List 03
Nama	: Muhammad Iqbal Alif Fadilla
NPM		: 140810180020
Tanggal	: 31 03 19
Desc	: Program ini berfungsi untuk menambah atau menghapus elemen dari linked list.
*/
import java.util.Scanner;
public class CircularDoublyLinkedList_03 {
    public static Scanner scan = new Scanner(System.in);
    static class CDLL{
        int data;
        CDLL next,prev;
    }
    public static void main(String[] args) {
        CDLL list; list=null;
        CDLL p = new CDLL();
	char pilihan; char loop;
        System.out.print("\ninput data: ");
        for(int i=0; i<5; i++){
            p=newElmt();
            list=insertFirst(list,p);
        }
	do{
            System.out.println("A. Insert First\tB.Delete First\n");
            do{
                pilihan=scan.next().charAt(0);scan.nextLine();
            }while(pilihan!='a' && pilihan!='A' && pilihan!='b' && pilihan!='B');
            switch(pilihan){
                case 'a': case 'A':
                    System.out.println("keadaan awal\n");
                    traversal(list);
                    System.out.println("insertFirst: ");
                    p=newElmt();
                    list=insertFirst(list,p);
                    System.out.println("keadaan akhir\n");
                    traversal(list);
                    break;
                case 'b': case 'B':
                    System.out.println("keadaan awal\n");
                    traversal(list);
                    list=deleteFirst(list,p);
                    System.out.println("keadaan akhir\n");
                    traversal(list);
                    break;
            }do{
                System.out.println("Kembali ke menu? (Y/N) ");
                loop=scan.next().charAt(0);
            }while(loop!='Y' && loop!='y' && loop!='N' && loop!='n');
        }while(loop=='Y' || loop=='y');
    }
    static CDLL newElmt(){
	CDLL newNode=new CDLL();
        newNode.data=scan.nextInt();
	scan.nextLine();newNode.next=null;
        return newNode;
    }
    public static CDLL insertFirst(CDLL First, CDLL newNode){
	CDLL last=First;
	if(First==null){
            First=newNode;
            First.next=First;
            First.prev=First;
	}else if(First.next==First){
            newNode.next=First;
            newNode.prev=First;
            First.next=newNode;
            First.prev=newNode;
            First=newNode;
	}else{
            newNode.next=First;
            First.prev=newNode;
            while(last.next!=First){
                last=last.next;
            }
            newNode.prev=last;
            last.next=newNode;
            First=newNode;
	}
        return First;
    }
    public static CDLL deleteFirst(CDLL First, CDLL delNode){
	delNode=First;
	if(First==null){
            System.out.println("tidak ada yang didelete\n");
	}else if(First.next==First){
            First=null;
            delNode.next=null;
            delNode.prev=null;
	}else{
            First=null;
            First=delNode.next;
            First.prev=delNode.prev;
            delNode.prev.next=First;
            delNode.next=null;
            delNode.prev=null;
	}
        return First;
    }
    public static void traversal(CDLL First){
	CDLL target=new CDLL();
	if(First==null){
            System.out.println("List Kosong");
	}else{
            target=First;
            int i=1;
            System.out.println("\ndata"+i+"->prev: "+target.prev.data+"\n");
            do{
                System.out.println("\ndata"+i+": "+target.data+"\n");
                target=target.next;
                i++;
            }while(target!=First);
            System.out.println("\ndata"+(i-1)+"->next1: "+target.data+"\n");
	}
    }
}