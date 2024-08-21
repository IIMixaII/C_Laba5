#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>
using namespace std;

// Функция для генерации случайных чисел в заданном диапазоне
int getRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Функция для выполнения линейного поиска в массиве
int linearSearch(const std::vector<int>& arr, int target, int& comparisons) {

    for (int i = 0; i < arr.size(); ++i) {
        comparisons++;
        if (arr[i] == target) {
            return i; // Возвращаем индекс, если элемент найден
        }
    }
    return -1; // Если элемент не найден
}
int BarierlinearSearch( std::vector<int>& arr, int target, int& comparisons) {
    int last = arr[arr.size() - 1];
    arr[arr.size() - 1] = target; // Устанавливаем барьер
    int i = 0;
    while (arr[i] != target) {
        ++i;
        comparisons++;
    }
    arr[arr.size() - 1] = last; // Восстанавливаем последний элемент
    if (i < arr.size() - 1 || arr[arr.size() - 1] == target) {
        return i; // Возвращаем индекс, если элемент найден
    }
    return -1; // Возвращаем -1, если элемент не найден
}
int linearSearch1(const std::vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i; // Возвращаем индекс, если элемент найден
        }
    }
    return -1; // Если элемент не найден
}
int binarySearch(const std::vector<int>& arr, int target, int& comparisons) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        comparisons++;
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}


vector<int> generateArray(int size, string order) {
    vector<int> arr(size);
    if (order == "Отсортированный") {
        for (int i = 0; i < size; i++) {
            arr[i] = i;
        }
    }
    else if (order == "Обратная сортировка") {
        for (int i = 0; i < size; i++) {
            arr[i] = size - i - 1;
        }
    }
    else if (order == "Отсортрованный на 25%") {
        for (int i = 0; i < size; i++) {
            if (i < size * 0.25) {
                arr[i] = i;
            }
            else {
                arr[i] = rand() % size;
            }
        }
    }
    else if (order == "Отсортированный на 50%") {
        for (int i = 0; i < size; i++) {
            if (i < size * 0.5) {
                arr[i] = i;
            }
            else {
                arr[i] = rand() % size;
            }
        }
    }
    else if (order == "Отсортированный на 75%") {
        for (int i = 0; i < size; i++) {
            if (i < size * 0.75) {
                arr[i] = i;
            }
            else {
                arr[i] = rand() % size;
            }
        }
    }
    else {
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % size;
        }
    }
    return arr;
}
int main() {
    srand(time(0));
    setlocale(LC_ALL, "rus");
    // Создаем массивы разной длины
    std::vector<int> arraySizes = { 20, 500, 1000, 3000, 5000, 10000 };
   // std::vector<int> comparisons; // Здесь будем хранить количество сравнений для каждого размера массива

    for (int size : arraySizes) {
        std::vector<int> arr(size);

        // Заполняем массив случайными числами
        for (int i = 0; i < size; ++i) {
            arr[i] = getRandomNumber(1, 10000);
        }

        int target = getRandomNumber(1, 10000); // Искомое значение

        int comparisonCount = 0;
        //clock_t start = clock();
        auto start = chrono::high_resolution_clock::now();
        int index = linearSearch(arr, target, comparisonCount);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        //clock_t end = clock();
        //double elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

       // comparisons.push_back(comparisonCount);

        std::cout << "Размер массива: " << size << std::endl;
        std::cout << "Время выполнения поиска: " << duration.count() << " милесекунд" << std::endl;
        std::cout << "Количество сравнений: " << comparisonCount << std::endl;
        std::cout << "-----------------------------------" << std::endl;
    }
    cout << "///////////////////5.2" << endl;
    // Вывод зависимости времени поиска и числа сравнений от числа элементов в массиве
    vector<int> array_sizes1 = { 20, 500, 1000, 3000, 5000, 10000 };
    string serch_method[] = { "Линейные поиск", "Бинарный поиск" };
    string orders[] = { "Отсортированный", "Обратная сортировка", "Отсортированный на 25%", "Отсортированный на 50%", "Отсортированный на 75%", "Случайный" };
    for (int size : array_sizes1) {
        cout << "Размер массива: " << size << endl;
        cout << "-----------------------------------" << endl;
        for (string order : orders){
            cout << "Сортировка: " << order << endl;
            vector<int> arr1 = generateArray(size, order);
                int target1 = getRandomNumber(1, 10000);
                vector<int> copy_arr = arr1;
                clock_t start1, end1;
                //cout <<  order << " Размер массива: " << size << sort_method <<  endl;
                auto start = chrono::high_resolution_clock::now();
                //start1 = clock();
                int index1 = linearSearch1(arr1, target1);
                //end1 = clock();
                //double time_taken1 = double(end1 - start1) / double(CLOCKS_PER_SEC);
                auto end = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                cout <<" Время выполнения" << ":\t" << duration.count() << " милесекунд." << endl;
                //cout << "Метод поиска: " << search_method << " Размер массива: " << arr.size() << " Отсортированность: " << order << " Потраченное время: " << duration.count() << " microseconds" << endl;
                // Перед следующей сортировкой, скопируйте исходный массив arr обратно в copy_arr
                copy_arr = arr1;
            
            cout << "--------------------------" << endl;
        }

        
    }
    vector<int> array_sizes2 = { 10000 };
    string order1 = "Отсортированный";
    vector<int> arr2 = generateArray(10000, order1);
    int target2 = getRandomNumber(1, 10000);
    vector<int> copy_arr = arr2;
    int linearCount = 0;
    int binaryCount = 0;
    auto linearstart = chrono::high_resolution_clock::now();
    int linearResult = linearSearch(arr2, target2, linearCount);
    auto linearend = chrono::high_resolution_clock::now();
    auto linearduration = chrono::duration_cast<chrono::microseconds>(linearend - linearstart);
    cout << "Метод поиска: Линейный, Размер массива: 10000, количество итераций: " << linearCount << " Затраченное время " << linearduration.count() << " Милесекунд" << endl;
    auto binarystart = chrono::high_resolution_clock::now();
    int binaryResult = binarySearch(arr2, target2, binaryCount);
    auto binaryend = chrono::high_resolution_clock::now();
    auto binaryduration = chrono::duration_cast<chrono::microseconds>(binaryend - binarystart);
    cout << "Метод поиска: Бинарный, Размер массива: 10000, количество итераций: " << binaryCount << " Затраченное время " << binaryduration.count() << " Милесекунд" << endl;
    cout << "//////////////////////////5.3" << endl;
    std::vector<int> arraySizes3 = { 20, 500, 1000, 3000, 5000, 10000 };


    for (int size : arraySizes3) {
        std::vector<int> arr3(size);

        // Заполняем массив случайными числами
        for (int i = 0; i < size; ++i) {
            arr3[i] = getRandomNumber(1, 10000);
        }

        int target3 = getRandomNumber(1, 10000); // Искомое значение
        int nobariercount = 0;
        int barierCount = 0;
        //clock_t start = clock();
        auto nobarierstart = chrono::high_resolution_clock::now();
        int index = linearSearch(arr3, target3, nobariercount);
        auto nobarierend = chrono::high_resolution_clock::now();
        auto nobarierduration = chrono::duration_cast<chrono::microseconds>(nobarierend - nobarierstart);
        //clock_t end = clock();
        //double elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

       // comparisons.push_back(comparisonCount);
        cout << "Без барьера" << endl;
        std::cout << "Размер массива: " << size << std::endl;
        std::cout << "Время выполнения поиска: " << nobarierduration.count() << " милесекунд" << std::endl;
        std::cout << "Количество сравнений: " << nobariercount << std::endl;
        std::cout << "-----------------------------------" << std::endl;
        auto barierstart = chrono::high_resolution_clock::now();
        int index1 = BarierlinearSearch(arr3, target3, barierCount);
        auto barierend = chrono::high_resolution_clock::now();
        auto barierduration = chrono::duration_cast<chrono::microseconds>(barierend - barierstart);
        cout << "C барьером" << endl;
        std::cout << "Размер массива: " << size << std::endl;
        std::cout << "Время выполнения поиска: " << barierduration.count() << " милесекунд" << std::endl;
        std::cout << "Количество сравнений: " << barierCount << std::endl;
        std::cout << "-----------------------------------" << std::endl;
    }
    return 0;
}