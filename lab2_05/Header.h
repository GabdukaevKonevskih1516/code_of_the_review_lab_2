#pragma once

#include <vector>
#include <deque>
#include <list>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <ctime>

// Определение типов 
using int32 = std::int32_t;
using uint8 = std::uint8_t;
using uint32 = std::uint32_t;

// Перечисление способов ввода данных
enum class EInputMethod : uint8
{
    Manual = 1,
    Random = 2,
    File = 3
};

// Заполняет контейнер выбранным способом.
// Обязательно использует итераторы для добавления.

template <typename Container>
void FillContainer(Container & OutContainer, int32 InSize);

//Выводит содержимое контейнера в прямом и обратном порядке(через итераторы).
template <typename Container>
void PrintContainer(const Container & InContainer);

//Меняет местами два средних элемента контейнера.
// Использует std::swap.
template <typename Container>
void SwapMiddleElements(Container & OutContainer);
