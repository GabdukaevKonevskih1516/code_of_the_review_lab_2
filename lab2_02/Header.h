#include "Header.h"

FQueue::FQueue() : Head(nullptr), Tail(nullptr) {}

FQueue::~FQueue()
{
    Clear();
}

void FQueue::Enqueue(int InData)
{
    // FIX_ME: Имена Uzel заменены на TNode 
    TNode* NewNode = new TNode(InData);

    if (!Head)
    {
        Head = NewNode;
        Tail = NewNode;
    }
    else
    {
        Tail->Next = NewNode;
        Tail = NewNode;
    }
}

void FQueue::Dequeue()
{
    if (!Head)
    {
        std::cout << "Ошибка: Очередь пуста!" << std::endl;
        return;
    }

    TNode* Temp = Head;
    Head = Head->Next;
    delete Temp;

    if (!Head)
    {
        Tail = nullptr;
    }
}

void FQueue::Print() const
{
    TNode* Current = Head;
    while (Current)
    {
        std::cout << Current->Data << " ";
        Current = Current->Next;
    }
    std::cout << std::endl;
}

void FQueue::DisplayPointers() const
{
    // FIX_ME: Явное приведение к void* для корректного отображения HEX-адресов
    std::cout << "Указатель Head: " << (void*)Head;
    if (Head) std::cout << " (Data: " << Head->Data << ")";
    std::cout << std::endl;

    std::cout << "Указатель Tail: " << (void*)Tail;
    if (Tail) std::cout << " (Data: " << Tail->Data << ")";
    std::cout << std::endl;
}

void FQueue::Clear()
{
    while (Head)
    {
        Dequeue();
    }
}
