#include <ctime>
#include <Windows.h>
#include <iostream>

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
	int temporary;
	// Сортировка от наибольшего к наименьшему.
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				temporary = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temporary;
			}
		}
	}
}
