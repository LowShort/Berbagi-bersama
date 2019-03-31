/*
Program	: Circular Doubly Linked List-02
Nama	: Muhammad Iqbal Alif Fadilla
NPM		: 140810180020
Tanggal	: 31 03 19
Desc	: Program ini berfungsi untuk menambah atau menghapus elemen dari linked list.
*/
import java.util.Scanner;
public class CircularDoublyLinkedList_02 {
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
            list=insertLast(list,p);
        }
	do{
            System.out.println("A. Insert Last\tB.Delete Last\n");
            do{
                pilihan=scan.next().charAt(0);scan.nextLine();
            }while(pilihan!='a' && pilihan!='A' && pilihan!='b' && pilihan!='B');
            switch(pilihan){
                case 'a': case 'A':
                    System.out.println("keadaan awal\n");
                    traversal(list);
                    System.out.println("insertLast: ");
                    p=newElmt();
                    list=insertLast(list,p);
                    System.out.println("keadaan akhir\n");
                    traversal(list);
                    break;
                case 'b': case 'B':
                    System.out.println("keadaan awal\n");
                    traversal(list);
                    list=deleteLast(list,p);
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
    public static CDLL insertLast(CDLL First, CDLL newNode){
	CDLL target=First;
	if(First==null){
            First=newNode;
            First.next=First;
            First.prev=First;
	}else if(First.next==First){
            First.next=newNode;
            First.prev=newNode;
            newNode.prev=First;
            newNode.next=First;
	}else{
            while(target.next!=First){
                target=target.next;
            }
            target.next=newNode;
            First.prev=newNode;
            newNode.prev=target;
            newNode.next=First;
	}
        return First;
    }
    public static CDLL deleteLast(CDLL First, CDLL delNode){
	delNode=First;
	if(First==null){
            System.out.println("tidak ada yang didelete\n");
	}else if(First.next==First){
            delNode=First;
            First=null;
            delNode.next=null;
            delNode.prev=null;
	}else{
            while(delNode.next!=First){
                delNode=delNode.next;
            }
            delNode.prev.next=First;
            First.prev=delNode.prev;
            delNode.next=null;
            delNode.prev=null;
            delNode=null;
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