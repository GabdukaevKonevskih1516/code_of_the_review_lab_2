#include "Header.h"

void ShowMenu()
{
    std::cout << "\n=== МЕНЮ УПРАВЛЕНИЯ СТЕКОМ ===" << std::endl;
    std::cout << "1. Добавить элемент (P1 -> P2)" << std::endl;
    std::cout << "2. Удалить элемент" << std::endl;
    std::cout << "3. Показать стек" << std::endl;
    std::cout << "4. Очистить стек" << std::endl;
    std::cout << "5. Выйти" << std::endl;
    std::cout << "Введите выбор: ";
}

int main()
{
    setlocale(LC_ALL, "ru");
    FStack MyStack;
    int Choice = 0;
    int InputValue = 0;

    while (true)
    {
        ShowMenu();
        if (!(std::cin >> Choice)) break;

        switch (Choice)
        {
        case 1:
            std::cout << "Введите значение D: ";
            std::cin >> InputValue;
            ExecuteTaskStep(MyStack, InputValue);
            break;
        case 2:
            MyStack.Pop();
            break;
        case 3:
            MyStack.Print();
            break;
        case 4:
            MyStack.Clear();
            break;
        case 5:
            return 0;
        default:
            std::cout << "Неверный ввод, попробуйте снова." << std::endl;
        }
    }

    return 0;
}
