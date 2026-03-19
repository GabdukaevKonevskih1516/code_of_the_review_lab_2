#include "Header.h"

FStack::FStack() : Top(nullptr) {}

FStack::~FStack()
{
    Clear();
}

void FStack::Push(int InData)
{
    // FIX_ME: Использование Node* заменено на TNode* согласно условию
    TNode* NewNode = new TNode(InData);
    NewNode->Next = Top;
    Top = NewNode;
}

void FStack::Pop()
{
    if (!Top)
    {
        std::cout << "Ошибка: Стек пуст!" << std::endl;
        return;
    }

    TNode* Temp = Top;
    Top = Top->Next;
    delete Temp;
}

void FStack::Print() const
{
    if (!Top)
    {
        std::cout << "Стек пуст." << std::endl;
        return;
    }

    TNode* Current = Top;
    std::cout << "Содержимое стека: ";
    while (Current)
    {
        std::cout << Current->Data << " ";
        Current = Current->Next;
    }
    std::cout << std::endl;
}

void FStack::Clear()
{
    while (Top)
    {
        Pop();
    }
}

void ExecuteTaskStep(FStack& InStack, int InD)
{
    // FIX_ME: Прямое использование указателей P1 и P2 согласно логике задания
    TNode* P1 = InStack.GetTop();

    InStack.Push(InD);

    TNode* P2 = InStack.GetTop();

    std::cout << "--- Выполнение задачи ---" << std::endl;
    std::cout << "Значение D: " << InD << std::endl;
    std::cout << "Адрес новой вершины (P2): " << (void*)P2 << std::endl;
    std::cout << "--------------------------" << std::endl;
}
