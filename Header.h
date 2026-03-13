#pragma once

#include <iostream>
#include <string>
#include <cctype>
#include <memory>

// FIX_ME: Функция была объявлена глобально
// Старый код: bool IsNumber(const string& str)
bool IsNumber(const std::string& String);

// FIX_ME: Имя класса должно быть с большой буквы, структура Node должна быть приватной
// Старый код: class Queue (без префикса F)
class FQueue
{
private:
    struct FNode
    {
        int32_t Data;
        FNode* Next;
    };

    // FIX_ME: Имена указателей должны отражать суть (голова и хвост)
    // Старый код: Node* P1; Node* P2;
    FNode* Head;
    FNode* Tail;

public:
    FQueue() : Head(nullptr), Tail(nullptr) {}

    // FIX_ME: Имена методов в PascalCase, параметры с большой буквы
    // Старый код: void push(int num)
    void Push(int32_t Value);

    // FIX_ME: Изменяем названия и меняем формат 
    // Старый код: bool pop(int& num)
    bool Pop(int32_t& OutValue);

    // FIX_ME: Метод должен быть константным
    // Старый код: void show()
    void Show() const;

    // FIX_ME: Название метода не отражает суть
    // Старый код: void EvenHead()
    void RemoveUntilEven();

    // FIX_ME: Меняем названия 
    // Старый код: Node* getP1() const 
    FNode* GetHead() const;
    FNode* GetTail() const;

    // FIX_ME: Методы вывода должны быть с понятными названиями
    // Старый код: void getP1data()
    void PrintHeadValue() const;
    void PrintTailValue() const;

    ~FQueue();
};