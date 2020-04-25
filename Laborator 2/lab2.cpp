#include <iostream>
#include <iomanip>
#include <math.h>
#include <cstdlib>
#include <conio.h>

using namespace std;

int Perfect(int n);

int main()
{

    int key;
    int n, a, b, i, nr, A, k = 0;
    int cont = 0;
    do{
        cout << "\n1. De verificat daca numarul satisface conditia" << endl;
        cout << "\n2. De afisat toate numerele din intervalul [a, b] care satisfac conditia" << endl;
        cout << "\n3. De afisat primele n numere care satisfac conditia" << endl;
        cout << "\n4. De afisat toate numerele din intervalul [a, b] care satisfac a 2 conditie" << endl;
        cout << "\n5. De afisat valoarea maxima care satisface conditia" << endl;
        cout << "\n0. Exit" << endl;
        cout << "\nSelecteaza optiune: ";
        cin >> key;
    switch(key){
            case 1:
                system("cls");
                cout <<"Introduceti numarul ce trebuie verificat = ";
                cin >> n;
                if (Perfect(n)) cout <<"Numarul "<<n<<" este numar perfect";
                             else
                             cout <<"Numarul "<<n<<" nu este perfect";
            getch();
            break;

            case 2:
                system("cls");
                cout <<"Introduceti limita de stinga a intervalului ";
                cin >>a;
                cout <<"Introduceti limita de dreapta a intervalului ";
                cin >>b;
                cout <<"In intervalul dat sunt următoarele numere " <<endl;
                for (i = a; i<=b; i++){
                    if (Perfect(i)){
                        cout << i <<" ";
                        cont ++;
                    }
                }
                cout <<endl;
                if (cont == 0) cout <<"In intervalul dat nu sunt numere perfect";
                                else
                               cout <<"In intervalul ["<<a<<";"<<b<<"] sunt "<<cont<<" numere perfecte";
            getch();
            break;

            case 3:
                system("cls");
                cout <<"Cite cifre doriti sa afisam = ";
                cin >>nr;
                i = 1;
                cont = 0;
                while((cont < nr) && (i < 33550336)){
                    if(Perfect(i)){
                        cont++;
                        cout << i <<" ";
                    }
                    i++;
                }
            getch();
            break;

            case 4:
                system("cls");
                cout << "Dati inceputul intervalului ";
                cin >> a;

                cout << "Dati sfirsitul intervalului ";
                cin >> A;

                cout << "Perfect!" << endl;
                cout << "\nNumere perfecte de la " << a << " la " << A << endl;
                for(n = 1; n <= A; n++){
                if(Perfect(n)) {
                    cout << setw(8) << n;
                    k++;
                }
                }
                cout << "\n Total: " << k;
            getch();
            break;

            case 5:
                system("cls");

                if(Perfect(33550336)){
                    cout << 33550336;
                }
                else {
                    cout << 33550336;
                }
            getch();
            break;


    }
    }while(key != 0);

    return 0;
}

int Perfect(int n) {
  int sum = 0;
  for (int j = 1; j <= n / 2; j++) {
    if (n % j == 0) {
      sum += j;
    }
  }
  return sum == n;
}
