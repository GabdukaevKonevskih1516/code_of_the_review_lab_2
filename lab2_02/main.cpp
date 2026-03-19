int main()
{
    setlocale(LC_ALL, "ru");

    // FIX_ME: Переменные переименованы в PascalCase (Ochered1 -> OddQueue)
    FQueue OddQueue;  // Для нечетных номеров (1, 3, 5, 7, 9)
    FQueue EvenQueue; // Для четных номеров (2, 4, 6, 8, 10)

    std::cout << "Введите набор из 10 чисел:" << std::endl;

    for (int i = 1; i <= 10; ++i)
    {
        int InputValue;
        std::cout << "Элемент #" << i << ": ";

        if (!(std::cin >> InputValue))
        {
            std::cout << "Ошибка ввода! Ожидается целое число." << std::endl;
            return 1;
        }

        // Распределение согласно порядковому номеру i
        if (i % 2 != 0)
        {
            OddQueue.Enqueue(InputValue);
        }
        else
        {
            EvenQueue.Enqueue(InputValue);
        }
    }



    std::cout << "\n ПЕРВАЯ ОЧЕРЕДЬ (нечетные позиции 1,3,5,7,9) " << std::endl;
    OddQueue.Print();
    OddQueue.DisplayPointers();

    std::cout << "\n ВТОРАЯ ОЧЕРЕДЬ (четные позиции 2,4,6,8,10) " << std::endl;
    EvenQueue.Print();
    EvenQueue.DisplayPointers();

    return 0;
}
