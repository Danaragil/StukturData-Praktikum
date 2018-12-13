#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

struct Node{
    char name[50],position[50];
    int num;
    Node *next;
}*head=NULL,*tail=NULL,*temp=NULL;

class Queue{
public:
    void tambah(int num,char name[],char position[]);
    void hapus();
    void tampilQueue();
};
void Queue::tambah(int num, char name[], char position[]){
    temp = new Node;
    temp->num = num;
    strcpy(temp->name,name);
    strcpy(temp->position,position);
    temp->next = NULL;
    if(head == NULL){
        head = temp;
        tail = temp;
    } else{
        tail->next = temp;
        tail =temp;
    }
}

void Queue::hapus() {
    if (head==NULL){
        cout<<"Queue Empty"<<endl;
    } else{
        temp = head;
        head=head->next;
        delete temp;
    }
}
void Queue::tampilQueue() {
    if(head==NULL){
        cout<<"Queue Empty"<<endl;
        return;
    }
    for (temp = head; temp !=NULL ; temp=temp->next){
    	cout<<"---------------"<<endl;
        cout<<temp->num<<"<"<<temp->name<<">"<<temp->position<<endl;
        cout<<"---------------"<<endl;
    }
}
int main() {
    Queue queue;
    int in;
    while (true){
        cout<<"^^^^^^^^^^^^^^^^^^^"<<endl;
        cout<<"|Linked List Queue|"<<endl;
        cout<<"-------------------"<<endl;
        cout<<"1. Tambah Antrian"<<endl;
        cout<<"2. Hapus Antrian"<<endl;
        cout<<"3. Tampilkan Antrian"<<endl;
        cout<<"4. Keluar"<<endl;
        cout<<"Masukkan Pilihan : ";cin>>in;
        cout<<endl;
        switch (in){
            case 1: {
                Node node;
                cout<<endl;
                cout << "Data Pemain Sepak Bola"<< endl;
                cout << "----------------------" << endl;
                cout << "Masukkan Nomor Punggung : ";
                cin>>node.num;
                cout << "Masukkan Nama Pemain    : ";
                cin.ignore(1);
                cin.getline(node.name,100);
                cout << "Masukkan Posisi Pemain  : ";
                cin.getline(node.position,20);
                queue.tambah(node.num, node.name, node.position);
                break;
            }
            case 2:
                queue.hapus();
                break;
            case 3:
                queue.tampilQueue();
                break;
            case 4:
                exit(0);
            default:
                cout<<"Pilihan Salah";
        }
    }
}
