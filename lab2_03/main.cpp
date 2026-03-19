#include "Header.h"

int main()
{
    setlocale(LC_ALL, "ru");
    FOrderedList MyList;
    std::string Filename;

    std::cout << "Упорядоченный список (убывание)" << std::endl;
    std::cout << "Введите имя файла для загрузки: ";
    std::cin >> Filename;

    // FIX_ME: В оригинале не проверялся результат выполнения LoadFromFile
    if (MyList.LoadFromFile(Filename))
    {
        std::cout << "Данные успешно загружены." << std::endl;
    }
    else
    {
        std::cout << "Ошибка: Не удалось прочитать файл " << Filename << std::endl;
    }

    std::cout << "Текущий список: ";
    MyList.Print();

    // Пример работы стандартного набора методов
    int Choice, Val;
    while (true)
    {
        std::cout << "\n1. Добавить 2. Удалить 3. Очистить 4. Выход\nВыбор: ";
        std::cin >> Choice;
        if (Choice == 4) break;

        switch (Choice)
        {
        case 1:
            std::cout << "Число: "; std::cin >> Val;
            MyList.InsertSorted(Val);
            break;
        case 2:
            std::cout << "Число для удаления: "; std::cin >> Val;
            MyList.Remove(Val);
            break;
        case 3:
            MyList.Clear();
            break;
        }
        MyList.Print();
    }

    return 0;
}
