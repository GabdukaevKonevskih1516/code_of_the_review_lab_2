#include "Header.h"

int main()
{
    setlocale(LC_ALL, "ru");
    FDoubleLinkedList MyList;

    std::cout << "=== Работа с двусвязным списком ===" << std::endl;
    std::cout << "Введите количество уникальных чисел: ";
    int N;
    if (!(std::cin >> N) || N <= 0) return 0;

    for (int i = 0; i < N; ++i)
    {
        int Value;
        std::cout << "Элемент [" << i + 1 << "]: ";
        std::cin >> Value;
        MyList.Append(Value);
    }

    std::cout << "\nВаш список: ";
    MyList.Print();

    MyList.DisplayElementsBetweenMinMax();

    return 0;
}
