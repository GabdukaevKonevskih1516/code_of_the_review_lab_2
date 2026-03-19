#include "Header.h"

FDoubleLinkedList::FDoubleLinkedList() : Head(nullptr), Tail(nullptr) {}

FDoubleLinkedList::~FDoubleLinkedList()
{
    Clear();
}


void FDoubleLinkedList::Append(int InValue)
{
    TNode* NewNode = new TNode(InValue);
    if (!Head)
    {
        Head = Tail = NewNode;
        return;
    }

    Tail->Next = NewNode;
    NewNode->Prev = Tail;
    Tail = NewNode;
}

void FDoubleLinkedList::Remove(int InValue)
{
    TNode* Current = Head;
    while (Current && Current->Data != InValue)
    {
        Current = Current->Next;
    }

    if (!Current) return;

    if (Current->Prev) Current->Prev->Next = Current->Next;
    else Head = Current->Next;

    if (Current->Next) Current->Next->Prev = Current->Prev;
    else Tail = Current->Prev;

    delete Current;
}

void FDoubleLinkedList::Clear()
{
    TNode* Current = Head;
    while (Current)
    {
        TNode* Next = Current->Next;
        delete Current;
        Current = Next;
    }
    Head = Tail = nullptr;
}

void FDoubleLinkedList::Print() const
{
    TNode* Current = Head;
    while (Current)
    {
        std::cout << Current->Data << (Current->Next ? " <-> " : "");
        Current = Current->Next;
    }
    std::cout << std::endl;
}

void FDoubleLinkedList::FindMinMaxNodes(TNode*& OutMin, TNode*& OutMax) const
{
    if (!Head) { OutMin = OutMax = nullptr; return; }

    OutMin = OutMax = Head;
    TNode* Current = Head->Next;

    while (Current)
    {
        if (Current->Data < OutMin->Data) OutMin = Current;
        if (Current->Data > OutMax->Data) OutMax = Current;
        Current = Current->Next;
    }
}

void FDoubleLinkedList::DisplayElementsBetweenMinMax() const
{
    TNode* MinNode = nullptr;
    TNode* MaxNode = nullptr;
    FindMinMaxNodes(MinNode, MaxNode);

    if (!MinNode || !MaxNode || MinNode == MaxNode)
    {
        std::cout << "Недостаточно элементов для анализа." << std::endl;
        return;
    }

    // Определяем, кто из них идет в списке первым
    TNode* Start = nullptr;
    TNode* End = nullptr;

    TNode* Current = Head;
    while (Current)
    {
        if (Current == MinNode) { Start = MinNode; End = MaxNode; break; }
        if (Current == MaxNode) { Start = MaxNode; End = MinNode; break; }
        Current = Current->Next;
    }

    std::cout << "Элементы между " << Start->Data << " и " << End->Data << ": ";

    bool bFoundAny = false;
    Current = Start->Next; // Начинаем СЛЕДУЮЩИМ после первого встреченного

    while (Current && Current != End)
    {
        std::cout << Current->Data << " ";
        bFoundAny = true;
        Current = Current->Next;
    }

    if (!bFoundAny) std::cout << "[пусто]";
    std::cout << std::endl;
}
