#include <iostream>
using namespace std;

typedef struct node
{
      long data;
      node* next;
      node* prev;
};

node* head;
node* tail;
node* print;
node* del;
node* entry;

void inisialisasi()
{
      head = NULL;
      tail = NULL;
}

int isEmpty()
{
      if(head == NULL)
            return 1;
      else
            return 0;
}

void input(int *dta)
{
      entry = new node;
      entry->data = *dta;
      entry->next = NULL;
      entry->prev = NULL;
      if(isEmpty()==1)
      {
            head = entry;
            head->next = NULL;
            head->prev = NULL;
            tail=head;
      }
      else
      {
            tail->next = entry;
            entry->prev = tail;
            tail = entry;
      }
}

void hapus()
{
      int simpan;
      if(head!=NULL) 
      {
            if(head->next != NULL)
            {
            del=head;
            simpan = head->data;
            cout<<"\n"<<simpan<<"dihapus"<<endl;
            head = head->next;
            head->prev = NULL;
            delete del;
            }
            else
            {
                  simpan = head->data;
                  cout<<"\n"<<simpan<<"dihapus"<<endl;
                  head = NULL;
            }

      }
      else
            cout<<"\nTidak dapat menghapus karena link list kosong"<<endl;
}

void cetak()
{
      print = head;
      if(head!=NULL)
      {
            while(print!=NULL)
            {
                  cout<<"\n\t"<<print->data;
                  print = print->next;
            }
      }
      else
            cout<<"\nLink list tidak memiliki data"<<endl;

}
void menu()
{
      char pilih, ulang;
      int data;
      do
      {
            system("CLS");
menu :
      cout<<"PROGRAM DOUBLE LINK LIST"<<endl;
      cout<<"-------------------------------"<<endl;
      cout<<"Menu: \n";
      cout<<"1. Masukan ata\n";
      cout<<"2. Hapus Data\n";
      cout<<"3. Cetak Data\n";
      cout<<"4. Keluar\n";
      cout<<"Masukan pilihan : \n";
      cin>>pilih;

      switch(pilih)
      {
      case '1' :
            cout<<"\nMasukan Data  : ";
            cin>>data;

            input(&data);
            cout<<"\n"<<data<<" ditambahkan"<<endl;
            break;
      case '2' :
            hapus();
            break;
      case '3'  :
            cetak();
            break;
      case '4' :
            cout<<"\nTerima kasih "<<endl;
            exit;
            break;
      default :
            cout<<"\nPilih Kembali"<<endl;
            goto menu;
      }
      cout<<"\nKembali menuju menu? (y/n)";
      cin>>ulang;
      }while(ulang=='y' || ulang =='Y');
}

int main()
{
      inisialisasi();
      menu();
      return 0 ;
}

