#pragma once

#include <iostream>

//Структура узла двусвязного списка.
// Содержит указатели на обоих соседей для двунаправленного обхода.

struct TNode
{
    int Data;
    TNode* Prev;
    TNode* Next;

    TNode(int InValue) : Data(InValue), Prev(nullptr), Next(nullptr) {}
};

//Класс двусвязного линейного списка.
// Реализует поиск диапазона между Min и Max элементами.

class FDoubleLinkedList
{
public:
    FDoubleLinkedList();
    ~FDoubleLinkedList();

    // Добавить элемент в конец списка 
        void Append(int InValue);

    // Удалить первое вхождение значения 
        void Remove(int InValue);

    // Очистить весь список 
        void Clear();

    // Вывести все элементы списка 
        void Print() const;

    // Основная процедура задачи : вывод элементов между Min и Max 
        void DisplayElementsBetweenMinMax() const;

private:
    // Вспомогательный поиск узлов с экстремальными значениями 
        void FindMinMaxNodes(TNode * &OutMin, TNode * &OutMax) const;

    TNode* Head;
    TNode* Tail;
};
