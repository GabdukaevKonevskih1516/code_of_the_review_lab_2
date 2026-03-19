#include "Header.h"

template <typename Container>
void FillContainer(Container& OutContainer, int32 InSize)
{
    if (InSize < 2 || InSize % 2 != 0)
    {
        std::cout << "Ошибка: Размер должен быть четным и >= 2." << std::endl;
        return;
    }

    std::cout << "\nСпособы заполнения:\n1) Клавиатура\n2) Рандом\n3) Файл\nВыбор: ";
    int32 MethodInt;
    std::cin >> MethodInt;
    EInputMethod Method = static_cast<EInputMethod>(MethodInt);

    // Используем back_insert_iterator для заполнения контейнера
    auto It = std::back_inserter(OutContainer);

    switch (Method)
    {
    case EInputMethod::Manual:
        for (int32 i = 0; i < InSize; ++i)
        {
            int32 Value;
            std::cout << "Элемент [" << i << "]: ";
            std::cin >> Value;
            *It = Value; // Заполнение через итератор
        }
        break;

    case EInputMethod::Random:
        for (int32 i = 0; i < InSize; ++i)
        {
            *It = std::rand() % 101 - 50;
        }
        break;

    case EInputMethod::File:
    {
        std::ifstream File("a.txt");
        if (!File.is_open())
        {
            std::cout << "Ошибка открытия файла a.txt!" << std::endl;
            return;
        }
        for (int32 i = 0; i < InSize; ++i)
        {
            int32 Value;
            if (File >> Value) *It = Value;
        }
        File.close();
        break;
    }
    }
}

template <typename Container>
void PrintContainer(const Container& InContainer)
{
    std::cout << "Прямой порядок: ";
    for (auto It = InContainer.begin(); It != InContainer.end(); ++It)
    {
        std::cout << *It << " ";
    }

    // Использование обратных итераторов согласно ТЗ
    std::cout << "\nОбратный порядок: ";
    for (auto RIt = InContainer.rbegin(); RIt != InContainer.rend(); ++RIt)
    {
        std::cout << *RIt << " ";
    }
    std::cout << std::endl;
}


template <typename Container>
void SwapMiddleElements(Container& OutContainer)
{
    if (OutContainer.size() < 2) return;

    auto It1 = OutContainer.begin();
    auto It2 = OutContainer.begin();

    // Находим индексы двух средних элементов (например, для 6 элементов это индексы 2 и 3)
    int32 Mid2 = OutContainer.size() / 2;
    int32 Mid1 = Mid2 - 1;

    std::advance(It1, Mid1);
    std::advance(It2, Mid2);

    // Используем алгоритм std::swap из <algorithm>
    std::swap(*It1, *It2);
}

template void FillContainer<std::vector<int32>>(std::vector<int32>&, int32);
template void FillContainer<std::deque<int32>>(std::deque<int32>&, int32);
template void FillContainer<std::list<int32>>(std::list<int32>&, int32);

template void PrintContainer<std::vector<int32>>(const std::vector<int32>&);
template void PrintContainer<std::deque<int32>>(const std::deque<int32>&);
template void PrintContainer<std::list<int32>>(const std::list<int32>&);

template void SwapMiddleElements<std::vector<int32>>(std::vector<int32>&);
template void SwapMiddleElements<std::deque<int32>>(std::deque<int32>&);
template void SwapMiddleElements<std::list<int32>>(std::list<int32>&);
