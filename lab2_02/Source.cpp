#pragma once

#include <iostream>

struct TNode
{
    int Data;
    TNode* Next;

    TNode(int InValue) : Data(InValue), Next(nullptr) {}
};

// Класс очереди (Queue) на базе связанных узлов TNode.
// Реализует методы добавления, удаления и вывода адресов Head / Tail.

class FQueue
{
public:
    FQueue();
    ~FQueue();

    // Добавить элемент в конец очереди(Tail) 
        void Enqueue(int InData);

    // Удалить элемент из начала очереди(Head) 
        void Dequeue();

    // Вывод всех элементов в консоль 
        void Print() const;

    // Вывод адресов начала и конца очереди 
        void DisplayPointers() const;

    // Полная очистка очереди 
    void Clear();

private:
    TNode* Head; // Начало очереди
    TNode* Tail; // Конец очереди
};
