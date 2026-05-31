#include <iostream>
#include <windows.h>

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
    for (int i = 0; i < actual_size; ++i) {
        if (i < logical_size) {
            std::cout << arr[i];
        }
        else {
            std::cout << '_';
        }
        if (i != actual_size - 1) {
            std::cout << ' ';
        }
    }
    std::cout << std::endl;
}

int* remove_dynamic_array_head(int* arr, int& logical_size, int& actual_size) {
    if (logical_size == 0) {
        return arr; 
    }
    int new_logical = logical_size - 1;
    if (new_logical <= actual_size / 3) {
        int new_actual = actual_size / 3;
        if (new_actual < 1) new_actual = 1;
        int* new_arr = new int[new_actual];
        for (int i = 0; i < new_logical; ++i) {
            new_arr[i] = arr[i + 1];
        }
        delete[] arr;
        logical_size = new_logical;
        actual_size = new_actual;
        return new_arr;
    }
    else {
        for (int i = 0; i < logical_size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        logical_size = new_logical;
        return arr;
    }
}

int main() {

    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int actual_size, logical_size;

    std::cout << "Введите фактичеcкий размер массива: ";
    std::cin >> actual_size;
    std::cout << "Введите логический размер массива: ";
    std::cin >> logical_size;

    if (logical_size > actual_size) {
        std::cout << "Ошибка! Логический размер массива не может превышать фактический!" << std::endl;
        return 1;
    }

    int* arr = new int[actual_size];
    for (int i = 0; i < logical_size; ++i) {
        std::cout << "Введите arr[" << i << "]: ";
        std::cin >> arr[i];
    }

    std::cout << "Динамический массив: ";
    print_dynamic_array(arr, logical_size, actual_size);

    std::string answer;
    while (true) {
        if (logical_size == 0) {
            std::cout << "Невозможно удалить первый элемент, так как массив пустой. До свидания!" << std::endl;
            break;
        }
        std::cout << "Удалить первый элемент? ";
        std::cin >> answer;
        if (answer == "да") {
            arr = remove_dynamic_array_head(arr, logical_size, actual_size);
            std::cout << "Динамический массив: ";
            print_dynamic_array(arr, logical_size, actual_size);
        }
        else if (answer == "нет") {
            std::cout << "Спасибо! Ваш динамический массив: ";
            print_dynamic_array(arr, logical_size, actual_size);
            break;
        }
        else {
            std::cout << "Пожалуйста, введите 'да' или 'нет'." << std::endl;
        }
    }

    delete[] arr;
    return 0;
}
