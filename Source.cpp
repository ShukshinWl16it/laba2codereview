#include "Header.h"

// FIX_ME: Функция не обрабатывала случай с пустой строкой и не проверяла знак
bool IsNumber(const std::string& String)
{
    // FIX_ME: Добавлена явная проверка на пустую строку
    if (String.empty())
    {
        return false;
    }

    // FIX_ME: Индекс старта теперь называется понятно, исправлен тип на int32_t
    int32_t StartIndex = (String[0] == '-' || String[0] == '+') ? 1 : 0;

    // FIX_ME: Переменная цикла переименована в Index
    for (int32_t Index = StartIndex; Index < String.length(); ++Index)
    {
        if (!std::isdigit(String[Index]))
        {
            return false;
        }
    }

    // FIX_ME: Изменения названий в PascalCase
    //Старый код: return start < str.length();
    return StartIndex < String.length();
}

// FIX_ME:Изменяем названия
// Старый код: Queue() : P1(nullptr), P2(nullptr) {}

// FIX_ME: Изменение названий в PascalCase, отсутствие проверок, дублирование кода
void FQueue::Push(int32_t Value)
{
    FNode* NewNode = new FNode;
    NewNode->Data = Value;
    NewNode->Next = nullptr;

    // FIX_ME: Условие проверяет Tail
    if (!Tail)
    {
        Head = Tail = NewNode;
    }
    else
    {
        Tail->Next = NewNode;
        Tail = NewNode;
    }
    // FIX_ME: Убрано дублирование кода (newNode->next = nullptr)
}

// FIX_ME: Изменение названий, использование temp вместо понятного имени

void FQueue::Show() const
{
    FNode* Current = Head;
    if (!Current)
    {
        std::cout << "Очередь пустая\n";
        return;
    }

    while (Current)
    {
        std::cout << Current->Data << " ";
        Current = Current->Next;
    }
    std::cout << "\n";
}

// FIX_ME: Параметр должен называться OutValue тк это выходной параметр
// Старый код: bool pop(int& num)
bool FQueue::Pop(int32_t& OutValue)
{
    if (!Head)
    {
        return false;
    }

    FNode* Temp = Head;
    OutValue = Head->Data;
    Head = Head->Next;

    // FIX_ME: Если очередь стала пустой, обнуляем Tail
    if (!Head)
    {
        Tail = nullptr;
    }

    delete Temp;
    return true;
}

// FIX_ME: Геттер должен возвращать указатель на Head 
// Старый код: Node* getP1() const
FQueue::FNode* FQueue::GetHead() const
{
    return Head;
}

// FIX_ME: Геттер должен возвращать указатель на Tail
// Старый код: Node* getP2() const
FQueue::FNode* FQueue::GetTail() const
{
    return Tail;
}

// FIX_ME: Метод должен обрабатывать случай пустой очереди
// Старый код: void getP1data() const
void FQueue::PrintHeadValue() const
{
    if (Head)
    {
        std::cout << Head->Data;
    }
    else
    {
        std::cout << "Очередь пуста";
    }
}

// FIX_ME: Метод должен обрабатывать случай пустой очереди
// Старый код: void getP2data() const
void FQueue::PrintTailValue() const
{
    if (Tail)
    {
        std::cout << Tail->Data;
    }
    else
    {
        std::cout << "Очередь пуста";
    }
}

// FIX_ME: Изменение названий, отсутствовал вывод извлеченных элементов
// Старый код:
// void EvenHead() {
//     int num;
//     while (!(P1 == nullptr) && (P1->data % 2 != 0)) { 
//         pop(num);
//         cout << num << " ";
//     }
//     cout << endl;
// }
void FQueue::RemoveUntilEven()
{
    int32_t RemovedValue;

    // FIX_ME: Условие переписано более читаемо
    while (Head && (Head->Data % 2 != 0))
    {
        Pop(RemovedValue);
        std::cout << RemovedValue << " ";
    }
    std::cout << "\n";
}

// FIX_ME: Изменяем названия 
// Старый код: ~Queue() { int del; while (pop(del)); }
FQueue::~FQueue()
{
    int32_t TempValue;
    while (Pop(TempValue));
}