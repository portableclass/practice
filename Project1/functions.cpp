#include <ctime>
#include <Windows.h>
#include <iostream>

/// <summary>
/// ��� ������� ���������� ������.
/// </summary>
/// <param name="arr">������</param>
/// <param name="size">����������� �������</param>
void generateArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = 1 + rand() % 1000;
	}
}

/// <summary>
/// ��� ������� ��������� ��������������� ������ '�' � ������ 'b'.
/// </summary>
/// <param name="a">��������������� ������</param>
/// <param name="b">�������������� ������</param>
/// <param name="size">����������� �������</param>
void cloneArray(int* a, int* b, int size)
{
	for (int i = 0; i < size; i++)
	{
		b[i] = a[i];
	}
}

void sortingMax(int* arr, int size)
{
	// ��������� ���������� ��� ������ ��������� �������.
	int temporary;

	// ���������� �� ����������� � �����������.
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				// ������ �������� �������.
				temporary = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temporary;
			}
		}
	}
}

/// <summary>
/// ������ ������� ��������� �������������� ������ �� ����������� � ����������� ��������.
/// </summary>
/// <param name="arr">������</param>
/// <param name="size">����������� �������</param>
void sortingMin(int* arr, int size)
{
	int temporary;
	// ���������� �� ����������� � �����������.
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
