#include "Header.h"


int main()
{
    setlocale(LC_ALL, "ru");
    std::srand(static_cast<uint32>(std::time(nullptr)));

    std::vector<int> V;
    std::deque<int> D;
    std::list<int> L;

    int32 Size;
    std::cout << "Введите размер для всех контейнеров (четное, >= 2): ";
    std::cin >> Size;

    std::cout << "\nЗаполнение Вектора";
    FillContainer(V, Size);
    std::cout << "\nЗаполнение Дека";
    FillContainer(D, Size);
    std::cout << "\nЗаполнение Списка";
    FillContainer(L, Size);



    std::cout << "\n ИСХОДНЫЕ ДАННЫЕ" << std::endl;
    std::cout << "ВЕКТОР:" << std::endl; PrintContainer(V);
    std::cout << "ДЕК:" << std::endl; PrintContainer(D);
    std::cout << "СПИСОК:" << std::endl; PrintContainer(L);

    SwapMiddleElements(V);
    SwapMiddleElements(D);
    SwapMiddleElements(L);

    std::cout << "\nПОСЛЕ ПЕРЕСТАНОВКИ СРЕДНИХ ЭЛЕМЕНТОВ" << std::endl;
    std::cout << "ВЕКТОР: "; for (int x : V) std::cout << x << " ";
    std::cout << "\nДЕК:    "; for (int x : D) std::cout << x << " ";
    std::cout << "\nСПИСОК: "; for (int x : L) std::cout << x << " ";

    std::cout << "\n\nЗадание выполнено успешно!" << std::endl;
    return 0;
}
