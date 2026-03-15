#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void bubbleSort(int arr[], int start, int end)
{
    for (int a = start + 1; a < end; a++)
    {
        for (int b = end - 1; b >= a; b--)
        {
            if (arr[b - 1] > arr[b])
            {
                int temp = arr[b - 1];
                arr[b - 1] = arr[b];
                arr[b] = temp;
            }
        }
    }
}

void printArray(int arr[], int n, const char* msg)
{
    cout << msg;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void fillRandom(int arr[], int n, int min, int max)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = min + rand() % (max - min + 1);
    }
}

int main()
{
    setlocale(LC_ALL, "");
    srand(time(0));

    try {
        int N, K;
        cout << "Введите размер массива N: ";
        cin >> N;

        int* arr = new int[N];

        fillRandom(arr, N, 10, 99);
        printArray(arr, N, "Исходный массив: ");

        cout << "Введите количество блоков K (K <= N): ";
        cin >> K;

        int blockSize = N / K;
        int remainder = N % K;

        cout << "\nРазмер блока: " << blockSize;
        if (remainder > 0) {
            cout << " (первые " << remainder << " блоков больше на 1 элемент)";
        }
        cout << endl;

        int start = 0;
        for (int i = 0; i < K; i++) {
            int end = start + blockSize;
            if (i < remainder) {
                end++;
            }

            cout << "Блок " << i + 1 << ": ";
            for (int j = start; j < end; j++) {
                cout << arr[j] << " ";
            }
            cout << " -> ";

            bubbleSort(arr, start, end);

            for (int j = start; j < end; j++) {
                cout << arr[j] << " ";
            }
            cout << endl;

            start = end;
        }

        cout << "\nРезультат:\n";
        printArray(arr, N, "Отсортированный массив: ");

        delete[] arr;
    }
    catch (const string& e) {
        cerr << e << endl;
        return 1;
    }
    catch (const bad_alloc& e) {
        cerr << "Ошибка выделения памяти" << endl;
        return 1;
    }
    return 0;
}