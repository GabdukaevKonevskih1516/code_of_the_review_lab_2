#pragma once

#include <iostream>

// Структура узла стека согласно условию задачи 
struct TNode
{
    int Data;
    TNode* Next;

    TNode(int InValue) : Data(InValue), Next(nullptr) {}
};

// Класс стека с дружественным интерфейсом и методами управления 
class FStack
{
public:
    FStack();
    ~FStack();

    // Добавить элемент в вершину(Push) 
        void Push(int InData);

    // Удалить элемент из вершины(Pop) 
        void Pop();

    // Вывод всех элементов в консоль 
        void Print() const;

    // Очистка всей памяти стека 
        void Clear();

    // Получить указатель на вершину 
        TNode * GetTop() const { return Top; }

private:
    TNode* Top;
};

// Функция для выполнения конкретного задания подгруппы 
void ExecuteTaskStep(FStack & InStack, int InD);
