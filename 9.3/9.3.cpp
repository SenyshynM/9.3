#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

struct route
{
	string start;
	string end;
	int nomer;
};

void Create(route* n, const int N);
void Print(route* n, const int N);

void Menu(route* n, const int N);
void Sort(route* n, const int N);
int Search(route* n, const int N, const int nomer);


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "Введіть кількість маршрутів: "; cin >> N;
	route* n = new route[N];

	Create(n, N);
	Print(n, N);
	Menu(n, N);
}

void Create(route* n, const int N) 
{
	for (int i = 0; i < N; i++)
	{
		cout << "Маршрут № " << i + 1 << ":" << endl;

		cout << " Номер маршруту: "; cin >> n[i].nomer;
		cin.get();
		cin.sync();
		cout << " Початок: "; getline(cin, n[i].start);
		cout << " Кінець: "; getline(cin, n[i].end);
		cout << endl;
	}
}
void Print(route* n, const int N)
{
	cout << "====================================="
		<< endl;
	cout << "| № | Початок | Кінець | Номер " << setw(6) << "|"
		<< endl;
	cout << "-------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++) 
	{
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(7) << left << n[i].start << " "
			<< "| " << setw(6) << right << n[i].end << " "
			<< "| " << setw(10) << left << n[i].nomer << " |" << endl;
	}
	cout << "=====================================" << endl << endl;
}

void Menu(route* n, const int N) {
	int choice;

	do {
		cout << "--------------------------\n";
		cout << "Меню\n";
		cout << "[1] - Сортування\n";
		cout << "[2] - Пошук\n";
		cout << "[3] - Вихід\n";
		cout << "--------------------------\n";
		cout << "Виберіть: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Відсортовано:\n";
			Sort(n, N);
			Print(n, N);
			break;
		case 2:
		{
			cout << "Пошук:\n";
			int number, found;
			cout << "Введіть номер маршруту: ";
			cin >> number;
			found = Search(n, N, number);
			if (found != -1)
			{
				cout << "Початок: " << n[found].start << endl;
				cout << "Кінець:  " << n[found].end << endl;
			}
			else
				cout << "Маршруту з таким номером не знайдено." << endl;
		}

		case 3:
			break;

		default:
			cout << "--------------------------\n";
			cout << "Меню\n";
			cout << "[1] - Сортування\n";
			cout << "[2] - Пошук\n";
			cout << "[3] - Вихід\n";
			cout << "--------------------------\n";
			cout << "Виберіть:";
			cin >> choice;
		}
	} while (choice != 3);
}

void Sort(route* n, const int N) {
	route tmp;

	for (int i0 = 0; i0 < N - 1; i0++) {
		for (int i1 = 0; i1 < N - i0 - 1; i1++) {
			if (n[i1].nomer > n[i1 + 1].nomer)
			{
				tmp = n[i1];
				n[i1] = n[i1 + 1];
				n[i1 + 1] = tmp;
			}
		}
	}
}

int Search(route* n, const int N, const int nomer){
	for (int i = 0; i < N; i++)
		if (n[i].nomer == nomer) 
			return i;

	return -1;
}