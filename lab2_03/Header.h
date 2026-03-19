#pragma once

#include <iostream>
#include <string>
#include <fstream>

// Структура узла односвязного списка 
struct TNode
{
    int Data;
    TNode* Next;

    TNode(int InValue) : Data(InValue), Next(nullptr) {}
};

// Класс упорядоченного связного списка 
class FOrderedList
{
public:
    FOrderedList();
    ~FOrderedList();

    // Вставка элемента с сохранением порядка убывания 
        void InsertSorted(int InValue);

    // Удаление первого вхождения значения 
        void Remove(int InValue);

    // Вывод списка в консоль 
        void Print() const;

    // Полная очистка списка 
        void Clear();

    // Загрузка данных из текстового файла 
    bool LoadFromFile(const std::string& InFilename);

private:
    TNode* Head;
};
