#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <algorithm>
#include <iomanip>

#define limit 100

using namespace std;

void showMatrix ( int matrix[limit][limit], int row, int column );
void Position ( int matrix, int row, int column, int value );
void manualMatrix ( int matrix[limit][limit], int row, int column );
void randomMatrix ( int matrix[limit][limit], int row, int column );
void searchMax ( int matrix[limit][limit], int row, int column );
void searchMin ( int matrix[limit][limit], int row, int column );
void changeRows ( int matrix[limit][limit], int row, int column );
void changeColumns ( int matrix[limit][limit], int row, int column );
void addColumn ( int matrix[limit][limit], int row, int &column );
void matrixSortColumn ( int matrix[limit][limit], int &row, int &column );
void generateMatrix ( int matrix[limit][limit], int row, int column );

int main() {
	
	setlocale(LC_ALL, "Russian");
	
	int row, column, value1, value2;
	int matrix[limit][limit];
	char key1, key2;
	string key3;
	
	do {
		
		cout << "\t\t Обработка данных в матрице \n\n" <<endl;
	    cout << "1.Найти наибольшее и наименьшее значения в матрице, и их позиции." << endl;
		cout << "2.Поменять местами строки или колонки." << endl;
		cout << "3.Добавить колонку, которая высчитывает среднее значение." << endl;
		cout << "4.Отсортировать матрицу по колонке." << endl;
		cout << "5.Сгенерировать матрицу.\n" << endl;
	    cout << "\t|2  4  6 |" <<endl;
	    cout << "\t|8  10 12|" <<endl;
	    cout << "\t|14 16 18|\n" <<endl;
	    cout << "0.Выход" <<endl;
	    key1 = getch();
	    
	    switch (key1) {
	    	
	    	case '1':
	    		
	    		do {
	    			
	    			system("CLS");
	    			cout << "\t\t Найти наибольшее и наименьшее значения в матрице, и их позиции \n\n";
            		cout << "1. Ввести матрицу вручную" << endl;
                	cout << "2. Сгенерировать матрицу" << endl;
                	cout << "0. Главное меню\n\n";
					key2 = getch();
					
					switch (key2) {
						
						case '1':
							
							system("CLS");
							cout << "Введите количетсво строк = ";
							cin >> row;
							cout << "Введите количество колонок = ";
							cin >> column;
							
							cout << " Матрица: \n\n";
							manualMatrix( matrix, row, column );
							searchMax( matrix, row, column );
							searchMin( matrix, row ,column );
							
							cout << endl;
							cout << "\t( 'Enter' - вернуться в меню )" << endl;
							getch();
							break;
							
						case '2':
							
							system("CLS");
							cout << "Введите количетсво строк = ";
							cin >> row;
							cout << "Введите количество колонок = ";
							cin >> column;
							
							cout << " Матрица: \n\n";
							randomMatrix( matrix, row, column );
							searchMax( matrix, row, column );
							searchMin( matrix, row ,column );
							
							cout << endl;
							cout << "\t( 'Enter' - вернуться в меню )" << endl;
							getch();
							break;
					}
					
				} while ( key2 != 0 );
        		break;
        		
        	case '2':
        		
	    		do {
	    			
	    			system("CLS");
	    			cout << "\t\t Найти наибольшее и наименьшее значения в матрице, и их позиции \n\n";
            		cout << "1. Ввести матрицу вручную" << endl;
                	cout << "2. Сгенерировать матрицу" << endl;
                	cout << "0. Главное меню\n\n";
					key2 = getch();
					
					switch (key2) {
						
						case '1':
							
							system("CLS");
							cout << "Введите количетсво строк = ";
							cin >> row;
							cout << "Введите количество колонок = ";
							cin >> column;
							
							cout << " Матрица: \n\n";
							manualMatrix( matrix, row, column );
							cout << "Введите 'column' чтобы поменять местами столбецы, 'row' - строки : ";
							cin >> key3;
							if ( key3 == "row" ) {
								changeRows( matrix, row, column );
							} else if ( key3 == "column" ) {
								changeColumns( matrix, row, column );
							}
							
							cout << endl;
							cout << "\t( 'Enter' - вернуться в меню )" << endl;
							getch();
							break;
							
						case '2':
							
							system("CLS");
							cout << "Введите количетсво строк = ";
							cin >> row;
							cout << "Введите количество колонок = ";
							cin >> column;
							
							cout << " Матрица: \n\n";
							randomMatrix( matrix, row, column );
							cout << "Введите 'column' чтобы поменять местами столбецы, 'row' - строки : ";
							cin >> key3;
							if ( key3 == "row" ) {
								changeRows( matrix, row, column );
							} else if ( key3 == "column" ) {
								changeColumns( matrix, row, column );
							}
							
							cout << endl;
							cout << "\t( 'Enter' - вернуться в меню )" << endl;
							getch();
							break;
					}
					
				} while ( key2 != 0 );
	    		getch();
        		break;
        	case '3':
        		
        		do {
	    			
	    			system("CLS");
	    			cout << "\t\t Добавить колонку, которая высчитывает среднее значение. \n\n";
            		cout << "1. Ввести матрицу вручную" << endl;
                	cout << "2. Сгенерировать матрицу" << endl;
                	cout << "0. Главное меню\n\n";
					key2 = getch();
					
					switch (key2) {
						
						case '1':
							
							system("CLS");
							cout << "Введите количетсво строк = ";
							cin >> row;
							cout << "Введите количество колонок = ";
							cin >> column;
							
							cout << " Матрица: \n\n";
							manualMatrix( matrix, row, column );
							addColumn( matrix, row, column );
							
							cout << endl;
							cout << "\t( 'Enter' - вернуться в меню )" << endl;
							getch();
							break;
							
						case '2':
							
							system("CLS");
							cout << "Введите количетсво строк = ";
							cin >> row;
							cout << "Введите количество колонок = ";
							cin >> column;
							
							cout << " Матрица: \n\n";
							randomMatrix( matrix, row, column );
							addColumn( matrix, row, column );
							
							cout << endl;
							cout << "\t( 'Enter' - вернуться в меню )" << endl;
							getch();
							break;
					}
					
				} while ( key2 != 0 );
        		
	    		getch();
        		break;
        		
        	case '4':
        		
        		do {
	    			
	    			system("CLS");
	    			cout << "\t\t Отсортировать матрицу по колонке \n\n";
            		cout << "1. Ввести матрицу вручную" << endl;
                	cout << "2. Сгенерировать матрицу" << endl;
                	cout << "0. Главное меню\n\n";
					key2 = getch();
					
					switch (key2) {
						
						case '1':
							
							system("CLS");
							cout << "Введите количетсво строк = ";
							cin >> row;
							cout << "Введите количество колонок = ";
							cin >> column;
							
							cout << " Матрица: \n\n";
							manualMatrix( matrix, row, column );
							addColumn( matrix, row, column );
							matrixSortColumn( matrix, row, column );
							
							cout << endl;
							cout << "\t( 'Enter' - вернуться в меню )" << endl;
							getch();
							break;
							
						case '2':
							
							system("CLS");
							cout << "Введите количетсво строк = ";
							cin >> row;
							cout << "Введите количество колонок = ";
							cin >> column;
							
							cout << " Матрица: \n\n";
							randomMatrix( matrix, row, column );
							addColumn( matrix, row, column );
							matrixSortColumn( matrix, row, column );
							
							cout << endl;
							cout << "\t( 'Enter' - вернуться в меню )" << endl;
							getch();
							break;
					}
					
				} while ( key2 != 0 );
				
	    		getch();
        		break;
        	case '5':
	    		system("CLS");
	    		cout << "Введите количетсво строк = ";
				cin >> row;
				cout << "Введите количество колонок = ";
				cin >> column;
	    		
	    		generateMatrix( matrix, row, column);
	    		getch();
        		break;
		}
	} while ( key1 != '0');
	
	return 1;
}

void showMatrix ( int matrix[limit][limit], int row, int column ) {
	int i, j;
	for ( i = 0; i < row; i++ ) {
		for ( j =0; j < column; j++ ) {
			cout << setw(4) << matrix[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void Position ( int matrix[limit][limit], int row, int column, int value ) {
	int i, j;
	for ( i = 0; i < row; i++ ) {
		for ( j = 0; j < column; j++ ) {
			if ( matrix[i][j] == value ) {
				cout << " [" << i << ";" << j << " ] ";
			}
		}
	}
}

void manualMatrix ( int matrix[limit][limit], int row, int column ) {
	int i, j;
	cout << "Введите значения матрицы: " << endl;
	for ( i = 0; i < row; i++ ) {
		for ( j = 0; j < column; j++) {
			cout << "[ "<< i + 1 << ";" << j + 1 << " ] = ";
			cin >> matrix[i][j];
		}
		cout << endl;
	}
	showMatrix( matrix, row, column );
}

void randomMatrix ( int matrix[limit][limit], int row, int column ) {
	int i, j;
	for ( i = 0; i < row; i++ ) {
		for ( j =0; j < column; j++ ) {
			matrix[i][j] = rand() % 100;
		}
	}
	showMatrix( matrix, row, column );
}

void searchMax ( int matrix[limit][limit], int row, int column ) {
	int i, j, max;
	max = matrix[0][0];
	for ( i = 0; i < row; i++ ) {
		for ( j = 0; j < column; j++ ) {
			if ( matrix[i][j] > max ) {
				max = matrix[i][j];
			}
		}
	}
	cout << "Наибольшее значение в матрице = " << max << " в позиции ";
	Position ( matrix, row, column, max );
	cout << endl;
}

void searchMin ( int matrix[limit][limit], int row, int column ) {
	int i, j, min;
	min = matrix[0][0];
	for ( i = 0; i < row; i++ ) {
		for ( j = 0; j < column; j++ ) {
			if ( matrix[i][j] < min ) {
				min = matrix[i][j];
			}
		}
	}
	cout << "Наименьшее значение в матрице = " << min << " в позиции ";
	Position ( matrix, row, column, min );
	cout << endl;
}

void changeRows ( int matrix[limit][limit], int row, int column ) {
	int j, tmp, value1, value2;
	cout << endl;
	cout << "Строки которые нужно поменять местами: ";
	cin >> value1;
	cout << " и ";
	cin >> value2;
	for ( j = 0; j < row; j++ ) {
		tmp = matrix[value1 - 1][j];
		matrix[value1 - 1][j] = matrix[value2 - 1][j];
		matrix[value2 - 1][j] = tmp;
	}
	cout << "\n\nМатрица после замены строк:\n\n" << endl;
	showMatrix( matrix, row, column );
}

void changeColumns ( int matrix[limit][limit], int row, int column ) {
	int i, tmp, value1, value2;
	cout << endl;
	cout << "Колонки которые нужно поменять местами: ";
	cin >> value1;
	cout << " и ";
	cin >> value2;
	for ( i = 0; i < column; i++ ) {
		tmp = matrix[i][value1 - 1];
		matrix[i][value1 - 1] = matrix[i][value2 - 1];
		matrix[i][value2 - 1] = tmp;
	}
	cout << "\n\nМатрица после замены столбцов:\n\n" << endl;
	showMatrix( matrix, row, column );
}

	/*

 void addRow ( int matrix[limit][limit], int row, int column ) {
	int i, j, value, value1;
	cout << "Введите сколько нужно добавить строк = ";
	cin >> value1;
	for ( i = row; i < row + value1; i++ ) {
		for ( j = 0; j < column; j++ ) {
			cout << "Введите значение элемента [" << i + 1 << ";" << j + 1 << "] = ";
			cin >> value;
			matrix[i][j] = value;
		}
	}
	row = i;
	cout << endl;
	cout << "Матрица после добавления строки:\n\n";
	showMatrix( matrix, row, column );
}

void addColumn ( int matrix[limit][limit], int row, int column ) {
	int i, j, value, value1;
	cout << "Введите сколько нужно добавить столбцов = ";
	cin >> value1;
	for ( i = 0; i < row ; i++ ) {
		for ( j = column; j < column + value1; j++ ) {
			cout << "Введите значение элемента [" << i + 1 << ";" << j + 1 << "] = ";
			cin >> value;
			matrix[i][j] = value;
		}
	}
	column = j;
	cout << endl;
	cout << "Матрица после добавления столбца:\n\n";
	showMatrix( matrix, row, column );
}

void addAll ( int matrix[limit][limit], int row, int column ) {
	
}

	*/

void addColumn ( int matrix[limit][limit], int row, int &column ) {
	int num, i, j, tmp;
	for ( i = 0; i < row; i++) {
		num = 0;
		for ( j = 0; j < column - 1; j++) {
			if ( matrix[i][j] > matrix[i + 1][j]) {
				tmp = matrix[i][j] - matrix[i + 1][j];
			} else {
				tmp = matrix[i + 1][j] - matrix[i][j];
			}
			if ( tmp < 50 ) {
				num++;	
			}	
			matrix[i][column] = num;
		}
	}
	column ++;
	cout << "\n\nМатрица после добавления столбца:\n\n" << endl;
	showMatrix( matrix, row, column );
}

void matrixSortColumn (int matrix[limit][limit], int &row, int &column ) {
	int temp, k;
	bool change;
	k = 0;
	do{
		k ++;
		change = 0;
		for( int i = 0; i < row - k; i++){
			if(matrix[i][column - 1] > matrix[i + 1][column - 1]){
				for(int  j = 0; j < column; j ++){
					temp = matrix[i][j];
					matrix[i][j] = matrix[i+1][j];
					matrix[i+1][j] = temp;
				}
				change = 1;
			}
		}
	}while(change);
	cout << "\n\nМатрица после сортировки по столбцам:\n\n" << endl;
	showMatrix( matrix, row, column);
	
}

void generateMatrix ( int matrix[limit][limit], int row, int column ) {
	int value = 0;
	for ( int i = 0; i < row; i++ ) {
		for ( int j = 0; j < column; j++ ) {
			value += 2;
			matrix[i][j] = value;
		}
	}
	cout << "\n\n\tМатрица:\n" << endl;
	showMatrix( matrix, row, column );
}
