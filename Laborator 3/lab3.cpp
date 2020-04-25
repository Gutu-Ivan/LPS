#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#define NMAX 100

using namespace std;
int Citire(int n, int a[]);
int Afisare(int n, int a[], char sir[]);
int Minimum(int n, int a[]);
int Maximum(int n, int a[]);
float Media(int n, int a[]);
int RotireStangaOdata(int n, int a[]);
void RotireStanga(int n, int a[], int k);
int Ordonare(int n, int a[]);
int Cautare(int n, int a[], int val);
int Inserare(int &n, int a[], int k);
int Stergere(int &n, int a[], int k);
int Modificare(int n, int a[]);
int Generare(int n, int a[]);
int Caracteristica(int n, int a[]);
int main()
{
    int opt;
    int n = 10;
    int rotationNumber;
    int k;
    int note[NMAX] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    do
    {
        system("cls");
        cout << "1. Minumul si maximul" << endl;
        cout << "2. Media" << endl;
        cout << "3. Ordonarea notelor (crescator)" << endl;
        cout << "4. Rotirea" << endl;
        cout << "5. Adaugarea unui element" << endl;
        cout << "6. Stergerea unui element" << endl;
        cout << "7. Caracteristica" << endl;
        cout << "0. Exit" << endl;
        cout << "\nSelecteaza optiune:: ";
        cin >> opt;
        switch(opt)
        {
        case 1:
            Afisare(n, note, "initial");
            cout << "\nCea mai mica nota (min) este " << Minimum(n, note);
            cout << "\nCea mai mare mare (max) este " << Maximum(n, note);
            getch();
            break;
        case 2:
            cout << "\nMedia notelor este: " << Media(n, note);
            getch();
            break;
        case 3:
            Afisare(n, note, "initial");
            Ordonare(n, note);
            Afisare(n, note, "ordonat crescator");
            getch();
            break;
        case 4:
            cout << "De cate ori doriti sa rotiti vectorul " ;
            cin >> rotationNumber;
            Afisare(n, note, "initial");
            RotireStanga(n, note, rotationNumber);
            Afisare(n, note, "schimbat");
            getch();
            break;
        case 5:
            cout << "Dati valoarea care doriti sa o adaugati: ";
            cin >> k;
            Afisare(n, note, "initial");
            Inserare(n, note, k);
            Afisare(n, note, "cu elementul inserat");
            getch();
            break;
        case 6:
            cout << "Dati pozitia elementului care doriti sa-l stergeti: ";
            cin >> k;
            Afisare(n, note, "initial");
            Stergere(n, note, k);
            Afisare(n, note, "cu un element sters");
            getch();
            break;
        }
    } while (opt);

    return 0;
}
int Citire(int n, int a[])
{

}
int Afisare(int n, int a[], char sir[])
{
    cout << "\nTabelul " << sir << " de note\n";
    for(int i=0; i<n; i++)
        cout << setw(7) << a[i];
        cout << endl;
    return 1;
}
int Minimum(int n, int a[1])
{
    int aux = a[0];
    for(int i=1; i<n; i++)
        if (a[i] < aux)
            aux = a[i];
    return aux;
}
int Maximum(int n, int a[])
{
    int aux = a[0];
    for(int i=1; i<n; i++)
        if (a[i] > aux)
            aux = a[i];
    return aux;
}
float Media(int n, int a[])
{
    float media = 0;
    int i = 0;
    for (i; i < n; i++){
        media += a[i];
    }
    return media / n;
}
void RotireStanga(int n, int a[], int k){
    for (int i = 0; i < k; i++){
        RotireStangaOdata(n, a);
    }
}
int RotireStangaOdata(int n, int a[])
{
    int i, aux;
	if(n==0) return 0;
	aux = a[0];
	for(i=0; i<n-1; i++)
		a[i] = a[i+1];
	a[n-1] = aux;
	return 1;

}
int Ordonare(int n, int a[])
{
    int i, j=0, m, aux;
	do
	{
		m = 0; j++;
		for(i=0; i<n-j; i++)
			if(a[i] > a[i+1]) {
				aux = a[i]; a[i] = a[i+1]; a[i+1] = aux; m = 1;
			}
	} while(m);
	return 1;
}
int Inserare(int &n, int a[], int k)
{
    int i;
	if(n==0) return 0;
		n++;
	for(i=n-1; i>0; i--)
		a[i] = a[i-1];
	a[0] = k;
	return 1;

}
int Stergere(int &n, int a[], int k)
{
    n--;
    for (int i = k - 1; i < n; i++) {
        a[i] = a[i + 1];
    }
}


int Caracteristica(int n, int a[1]){

}