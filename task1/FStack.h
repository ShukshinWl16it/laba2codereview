#pragma once
#include "TNode.h"
class FStack
{
public:
    FStack();

    ~FStack();
    
    void Push(int32_t InValue);//Добавление элемента
    
    void Pop();//Удаление элемента
    
    void Print() const;//Вывод элементов
    
    TNode* GetTop() const;//Получение верхушки стека
    
    void Clear();//Очищение 
    
    bool IsEmpty() const;//Проверка на пустоту
private:
    // FIX_ME: Переменная должна называться Top, а не top (PascalCase)
    // Старый код: Node* top;
    TNode* Top;
};
// FIX_ME: Функция в PascalCase
//Старый код: void addElementAndPrintAddress
void AddElementAndPrintAddress(FStack& InStack, int32_t InValue);