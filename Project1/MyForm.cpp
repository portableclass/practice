#include "MyForm.h"
#include <Windows.h>
#include <iostream>
#include <ctime>
#include <time.h>

using namespace std;
using namespace Project1; // Название проекта
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}

/*int division (int x, int y)
{
	return y == 0 ? throw overflow_error("Error") : (x / y);
}*/

/// <summary>
/// Эта функция генерирует массив.
/// </summary>
/// <param name="arr">Массив</param>
/// <param name="size">Размерность массива</param>
void generateArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = 1 + rand() % 1000;
	}
}

/// <summary>
/// Эта функция клонирует сгенерированный массив 'а' в массив 'b'.
/// </summary>
/// <param name="a">Сгенерированный массив</param>
/// <param name="b">Клоннированный массив</param>
/// <param name="size">Размерность массива</param>
void cloneArray(int* a, int* b, int size)
{
	for (int i = 0; i < size; i++)
	{
		b[i] = a[i];
	}
}

/// <summary>
/// Данная функция сортирует сгенерированный массив от наименьшего к наибольшему элементу.
/// </summary>
/// <param name="arr">Массив</param>
/// <param name="size">Размерность массива</param>
void sortingMax(int* arr, int size)
{
	// Временная переменная для обмена элементов местами.
	int temporary;

	// Сортировка от наименьшего к наибольшему.
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				// Меняем элементы местами.
				temporary = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temporary;
			}
		}
	}
}

/// <summary>
/// Данная функция сортирует клоннированный массив от наибольшего к наименьшему элементу.
/// </summary>
/// <param name="arr">Массив</param>
/// <param name="size">Размерность массива</param>
void sortingMin(int* arr, int size)
{
	// Сортировка от наибольшего к наименьшему.
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				// Меняем элементы местами.
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

System::Void MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	srand(time(NULL));

	/*try {
		cout << division(1, 0) << '\n';
	}
	catch (const overflow_error& e) {
		cout << e.what() << '\n';
	}*/
	const int size = 20001;
	int* a = new int[size];
	int* b = new int[size];

	textBox3->Text = System::Convert::ToString(size);

	generateArray(a, size);
	cloneArray(a, b, size);
	sortingMax(a, size);
	sortingMin(b, size);

	textBox1->Text = System::Convert::ToString(a[size - 1]);
	textBox2->Text = System::Convert::ToString(b[size - 1]);

	delete[] a;
	delete[] b;
}
