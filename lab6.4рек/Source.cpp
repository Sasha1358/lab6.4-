#include <iostream>
#include <iomanip>
#include <Windows.h> 
using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i)
{
	cout << setw(4) << a[i];
	if (i < size - 1)
		Print(a, size, i + 1);
}

int FindMinAbs(int* a, const int size, int currentIndex)
{
    // Базовий випадок: якщо поточний індекс більший або рівний розміру масиву, повернути 0.
    if (currentIndex >= size) {
        return 0;
    }

    int absValue = abs(a[currentIndex]);

    // Рекурсивно викликаємо функцію для інших елементів масиву і порівнюємо їх з поточним мінімумом.
    int minAbsInRest = FindMinAbs(a, size, currentIndex + 1);

    // Порівнюємо поточне значення з мінімальним значенням у решті масиву.
    if (absValue < minAbsInRest) {
        return absValue;
    }
    else {
        return minAbsInRest;
    }
}

int FindMinAbs(int* a, const int size)
{
    if (size == 0) {
        return 0;
    }

    // Починаємо рекурсію з першого елемента масиву.
    return FindMinAbs(a, size, 0);
}

int SumAbsAfterFirstZero(int* a, const int size, int currentIndex, bool foundFirstZero)
{
    // Базовий випадок: якщо поточний індекс більший або рівний розміру масиву, повернути 0.
    if (currentIndex >= size) {
        return 0;
    }

    if (foundFirstZero) {
        return abs(a[currentIndex]) + SumAbsAfterFirstZero(a, size, currentIndex + 1, true);
    }

    if (a[currentIndex] == 0) {
        // Якщо знайдено перший нуль, переключити флаг та почати обчислення суми.
        return SumAbsAfterFirstZero(a, size, currentIndex + 1, true);
    }
    else {
        // Продовжуємо пошук першого нуля.
        return SumAbsAfterFirstZero(a, size, currentIndex + 1, false);
    }
}

int SumAbsAfterFirstZero(int* a, const int size)
{
    if (size == 0) {
        return 0;
    }

    // Починаємо рекурсію з першого елемента масиву та флагом, який позначає знайдений перший нуль.
    return SumAbsAfterFirstZero(a, size, 0, false);
}

void TransformArray(int* a, int* result, const int size, int currentIndex, int evenIndex, int oddIndex)
{
    if (currentIndex >= size) {
        for (int i = 0; i < size; i++) {
            a[i] = result[i];
        }
        return;
    }
    if (currentIndex % 2 == 0) {
        result[evenIndex] = a[currentIndex];
        evenIndex++;
    }
    else {
        result[oddIndex] = a[currentIndex];
        oddIndex++;
    }

    TransformArray(a, result, size, currentIndex + 1, evenIndex, oddIndex);
}

void TransformArray(int* a, const int size)
{
    int* result = new int[size];
    TransformArray(a, result, size, 0, 0, size / 2);
    delete[] result;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand((unsigned)time(NULL));
	int n;
	cout << "n = ";cin >> n;


	int* a = new int[n];
	int Low = -10;
	int High = 10;

	Create(a, n, Low, High, 0);
	cout << "Початковий масив  = [";  Print(a, n, 0);cout << "  ]" << endl;
    int minAbs = FindMinAbs(a, n, 0);
    cout << "Мінімальний за модулем елемент масиву: " << minAbs << endl;

    int sumAfterFirstZero = SumAbsAfterFirstZero(a, n, 0, 0);
    cout << "Сума модулів елементів після першого нульового елемента: " << sumAfterFirstZero << endl;

    TransformArray(a, n);

    cout << "Масив після перетворення = [";Print(a, n, 0);cout << "  ]" << endl;

    delete[] a; // Звільнити виділену пам'ять для масиву.

    return 0;
}

