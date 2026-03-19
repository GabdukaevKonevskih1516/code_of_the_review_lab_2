#include "Header.h"

FOrderedList::FOrderedList() : Head(nullptr) {}

FOrderedList::~FOrderedList()
{
    Clear();
}


void FOrderedList::InsertSorted(int InValue)
{
    TNode* NewNode = new TNode(InValue);

    // Случай 1: Список пуст или новый элемент больше головы (вставка в начало для убывания)
    if (!Head || Head->Data < InValue)
    {
        NewNode->Next = Head;
        Head = NewNode;
        return;
    }

    // Случай 2: Поиск позиции в середине или конце
    TNode* Current = Head;
    while (Current->Next && Current->Next->Data > InValue)
    {
        Current = Current->Next;
    }

    NewNode->Next = Current->Next;
    Current->Next = NewNode;
}

void FOrderedList::Remove(int InValue)
{
    if (!Head) return;

    if (Head->Data == InValue)
    {
        TNode* Temp = Head;
        Head = Head->Next;
        delete Temp;
        return;
    }

    TNode* Current = Head;
    while (Current->Next && Current->Next->Data != InValue)
    {
        Current = Current->Next;
    }

    if (Current->Next)
    {
        TNode* Temp = Current->Next;
        Current->Next = Current->Next->Next;
        delete Temp;
    }
}

void FOrderedList::Print() const
{
    if (!Head)
    {
        std::cout << "Список пуст." << std::endl;
        return;
    }

    TNode* Current = Head;
    while (Current)
    {
        std::cout << Current->Data << (Current->Next ? " -> " : "");
        Current = Current->Next;
    }
    std::cout << std::endl;
}

void FOrderedList::Clear()
{
    while (Head)
    {
        TNode* Temp = Head;
        Head = Head->Next;
        delete Temp;
    }
}

bool FOrderedList::LoadFromFile(const std::string& InFilename)
{
    std::ifstream File(InFilename);
    if (!File.is_open())
    {
        return false;
    }

    int Count = 0;
    if (!(File >> Count)) return false;

    for (int i = 0; i < Count; ++i)
    {
        int Value;
        if (File >> Value)
        {
            InsertSorted(Value);
        }
    }

    File.close();
    return true;
}
