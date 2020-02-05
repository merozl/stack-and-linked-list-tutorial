// Programda kulland���m stack ve linked listte fonksiyonlarda gereksiz, kullanmam� gerektirmeyecek fonksiyonlar� ��kard�m.
// (Linked listin varsay�lan baz� �zellikleri gibi)
// B�ylelikle veriden tasaruf sa�lam�� oldum.
#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include <windows.h>
//Stack kodlar� ba�lang�c�
struct stack //Stack yap�s� olu�turdum. Karma��kl�k: O(1) Bellek: 6 veya 12
{
	int stackBoyut;
	int top;
	int *items;
};
struct stack* newStack(int kapasite) //Karma��kl�k: O(1)
{
	struct stack *pt = (struct stack*)malloc(sizeof(struct stack));
    pt->stackBoyut = kapasite;
	pt->top = -1;
	pt->items = (int*)malloc(sizeof(int) * kapasite);
    return pt;
}
int StackSize(struct stack *pt)// O(n)
{
	return pt->top + 1;
}
int stackBosMu(struct stack *pt)//O(n)
{
	return pt->top == -1;
}
int stackDoluMu(struct stack *pt)//O(n)
{
	return pt->top == pt->stackBoyut - 1;
}
void push(struct stack *pt, int x)//O(1)
{
	if (stackDoluMu(pt))
	{
		printf("Stack boyutu dolu oldu�u i�in veri al�m� yapam�yoruz. \n");
		exit(EXIT_FAILURE);
	}
    pt->items[++pt->top] = x;
}
int peek(struct stack *pt)//O(1)
{

	if (!stackBosMu(pt))
		return pt->items[pt->top];
	else
		exit(EXIT_FAILURE);
}
int pop(struct stack *pt)//O(1)
{
	if (stackBosMu(pt))
	{
		printf("Stakc dolu");
		exit(EXIT_FAILURE);
	}
	return pt->items[pt->top--];
}
//Stack kodlar� sonu

//linked list ba�lang�c�
struct node { //Karma��kl�k O(1)
  int data;
  struct node *next;
};
//Kullanaca��m fonksiyonlar� tan�mlad�m.
struct node *start = NULL;
void baslangicEkle(int);
void sonaEkle(int);
void yazdir();
void bastanSil();
int count = 0;//2 byte veya 4 byte
int rastgeleMuzik();
int rastgelePatates();
int bastanelemaniGetir();
int linkedListKazanan();
int linkedListEleman();
void linkedlistTemizle();
void baslangicEkle(int x) { //linked list ba��na ekleme fonksiyonu O(1)
  struct node *t;
  t = (struct node*)malloc(sizeof(struct node));
  t->data = x;
  count++;
  if (start == NULL) {
    start = t;
    start->next = NULL;
    return;
  }
  t->next = start;
  start = t;
}
void linkedlistTemizle()//linked list i�indeki elemanlar� temizlemeye yarayan fonksiyon. Karma��kl�k: O(n)
{
	struct node* t = start;
	struct node* next;
	while(t != NULL)
	{
		next = t->next;
		free(t);
		t = next;
	}

    start = NULL;
}
void sonaEkle(int x) {//linked list sonuna eleman ekleme fonksiyonu. Karma��kl�k: O(1)
  struct node *t, *temp;
t = (struct node*)malloc(sizeof(struct node));
  t->data = x;
  count++;
  if (start == NULL) {
    start = t;
    start->next = NULL;
    return;
  }
  temp = start;
  while (temp->next != NULL)
  temp = temp->next;
  temp->next = t;
  t->next   = NULL;
}
int linkedListKazanan() // Karma��kl�k: O(1)
{
	struct node *t;
    t = start;
	int x;//2 byte veya 4 byte
	if(count==1)//e�er linked list i�inde 1 eleman varsa onu geri d�nd�r.
	{
		x = t->data;
		return x;
	}
}
int linkedListEleman()//linked list bo� mu de�il mi sorgulama fonksiyonu. Karma��kl�k: O(1)
{
	struct node *t;
    t = start;
	int x;//2 byte veya 4 byte
	if(count==1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void yazdir() {//linked list i�indeki elemanlar� yazd�rma. Karma��kl�k: O(n)
  struct node *t;
  t = start;
  if (t == NULL) {
    printf("Kuyruk bo�.\n");
    return;
  }
   printf("\n********************\n");
  while (t->next != NULL) {
    printf("%d   ", t->data);
    t = t->next;
  }
  printf("%d   ", t->data);
}
void bastanSil() {//linked list ba��ndan eleman silme. Karma��kl�k: O(1)
  struct node *t;
  int n;//2 byte veya 4 byte
  if (start == NULL) {
    printf("Kuyruk bo�.\n");
    return;
  }
  n = start->data;
  t = start->next;
  free(start);
  start = t;
  count--;
  }
int rastgeleMuzik()// Karma��kl�k: O(1)
{
	int muzik;//2 byte veya 4 byte
	muzik = rand()%15;
   	muzik += 10;
    return muzik;
}
int rastgelePatates()// Karma��kl�k: O(1)
{
	int patates;//2 byte veya 4 byte
	patates = rand()%3;
    patates += 1;
    return patates;
}
int bastanelemaniGetir()//linked list ba��ndan eleman� getirme fonksiyonu. Karma��kl�k: O(1)
{
   struct node *t;
   int n;//2 byte veya 4 byte
   if (start == NULL) {
   printf("Kuyruk bo�.\n");
   }
   n = start->data;
   return n;
}
//linked list sonu
void EklemeSiralama() // Karma��kl�k: O(1)
{
	baslangicEkle(1);
    sonaEkle(2);
    sonaEkle(3);
    sonaEkle(4);
    sonaEkle(5);
    sonaEkle(6);
    sonaEkle(7);
    sonaEkle(8);
    sonaEkle(9);
    sonaEkle(10);
    sonaEkle(11);
    sonaEkle(12);
    sonaEkle(13);
    sonaEkle(14);
    sonaEkle(15);
    sonaEkle(16);
    sonaEkle(17);
    sonaEkle(18);
    sonaEkle(19);
    sonaEkle(20);
}
void EklemeHotPatato() // Karma��kl�k: O(1)
{
	baslangicEkle(1);
    sonaEkle(2);
    sonaEkle(3);
    sonaEkle(4);
    sonaEkle(5);
    sonaEkle(6);
    sonaEkle(7);
    sonaEkle(8);
    sonaEkle(9);
    sonaEkle(10);
    sonaEkle(11);
    sonaEkle(12);
    sonaEkle(13);
    sonaEkle(14);
    sonaEkle(15);
}

void siralama() // Karma��kl�k: O(n)
{
	int derinlik,sayac,geciciDerinlik,cukuraGiren;//8 byte veya 16 byte
	sayac = 100;
	FILE *dosya;
	linkedlistTemizle();//s�rekli se�im yapt���m�z i�in linked list i�indeki elemanlar art�yor. Bu fonksiyon sayesinde her s�ralama i�leminde s�f�rlan�yor.
	EklemeSiralama();
	dosya = fopen("cukur.txt","r");
    while(!feof (dosya))
	{
	    fscanf(dosya,"%d",&derinlik);
	    geciciDerinlik = derinlik;
	    struct stack *s = newStack(derinlik);//Bellek: 6 veya 12
	{
	while(derinlik>0)
	{
		int cukuraGiren;//2 byte veya 4 byte
		cukuraGiren = bastanelemaniGetir();
		push(s,cukuraGiren);
	    bastanSil();
		derinlik = derinlik - 1;
	}
	while(geciciDerinlik>0)
	{
		int a;//2 byte veya 4 byte
		a = peek(s);
		pop(s);
		sonaEkle(a);
		geciciDerinlik = geciciDerinlik - 1;
	}
	if(sayac==100)
	{
		yazdir();
		sayac = 0;
	}
	else
	{
		sayac = sayac + 1;
	}
	}
	}
}

void hotpatato() // Karma��kl�k: O(n)
{
	linkedlistTemizle();
	EklemeHotPatato();
    int muzikSayac = 0;//2 byte veya 4 byte
    int patatesSayac = 0;//2 byte veya 4 byte
    int rastgele,muzik,sorgu,patates,yerDegistirme,patatesKalanSure,muzikKalanSure,kazanan,sorgulama;//18 byte veya 36 byte
    muzik=rastgeleMuzik();
    sorgulama = linkedListEleman();
	patates = rastgelePatates();
	int silinen;//2 byte veya 4 byte
	while(sorgulama==0)
	{
		sorgulama = linkedListEleman();
		Sleep(1000);
		yerDegistirme = bastanelemaniGetir();
		kazanan = linkedListKazanan();
		if(muzik==muzikSayac)
		{
			if(sorgulama==1)
    		{
    			break;
			}
    		bastanSil();
    		silinen = bastanelemaniGetir();
    		muzikSayac = 0;
    		muzik = rastgeleMuzik();
    		printf("\n M�zi�in �alma s�resi %d , Elenen oyuncu: %d",muzik,silinen);
    		yazdir();
		}
		if(patates==patatesSayac)
    	{
    		yerDegistirme = bastanelemaniGetir();
    		patatesSayac = 0;
    		bastanSil();
    		sonaEkle(yerDegistirme);
    		patates = rastgelePatates();
		}
		patatesKalanSure = patates - patatesSayac;
		muzikKalanSure = muzik - muzikSayac;
		printf("\n M�zik kalan s�re: %d, Patates Kalan S�re: %d",muzikKalanSure,patatesKalanSure);
		printf("\n Patatesin oldu�u oyuncu : %d ",yerDegistirme);
		muzikSayac += 1;
    	patatesSayac += 1;
    }
    printf("********* \n KAZANAN OYUNCU: %d",kazanan);
}

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Turkish");
	int secim;//2 byte veya 4 byte
	while(1)// Karma��kl�k: O(n)
	{
	printf(" \n 1- S�ralama \n 2- Hot Patato \n 3- ��k�� \n Secim yap�n�z:");
	scanf("%d",&secim);
	if(secim==1)
	{
	siralama();
	}
	else if(secim==2)
	{
	hotpatato();
	}
	else if(secim==3)
	{
	exit(0);
	}
	else
	{
	printf("L�tfen d�zg�n bir se�im yap�n�z:! ");
	}
	}
	return 0;
}
