#include "FStack.h"

FStack::FStack() : Top(nullptr)
{
    // FIX_ME: Инициализация в списке инициализации, а не в теле конструктора
    // Старый код: Stack() : top(nullptr) {}
}

FStack::~FStack()
{
    Clear();
    // FIX_ME: Деструктор должен очищать память
}
// FIX_ME: название в PascalCase
// Старый код: void push(int value)
void FStack::Push(int32_t InValue)//Добавление элемента
{
    TNode* NewNode = new TNode(InValue);
    // FIX_ME: Проверка на валидность указателя
    if (NewNode == nullptr)
    {
        std::cerr << "Error: Memory allocation failed\n";
        return;
    }
    // FIX_ME: название в PascalCase
    // Старый код: newNode->next = top;             // Новый узел указывает на текущую вершину
    //top = newNode; 
    NewNode->Next = Top;
    Top = NewNode;

    std::cout << "Элемент " << InValue << " добавлен в стек.\n";
}

void FStack::Pop()//Удаление элемента
{
    // FIX_ME: замена проверки через IsEmpty и \n
    //Старый код: if (top == nullptr)
    if (IsEmpty())
    {
        std::cout << "Стек пустой. Нельзя удалить элемент.\n";
        return;
    }
    // FIX_ME: Изменения названий
    TNode* Temp = Top;
    Top = Top->Next;

    std::cout << "Элемент " << Temp->Data << " удален из стека.\n";

    delete Temp;
    Temp = nullptr;
    // FIX_ME: Обнуление указателя после удаления
}

void FStack::Print() const //Вывод элементов
{
    // FIX_ME: замена проверки через IsEmpty и \n
    //Старый код: if (top == nullptr)
    if (IsEmpty())
    {
        std::cout << "Стек пустой\n";
        return;
    }
    // FIX_ME: Изменения названий
    TNode* Current = Top;
    std::cout << "Элементы стека: ";

    while (Current != nullptr)
    {
        std::cout << Current->Data << " ";
        Current = Current->Next;
    }
    // FIX_ME: endl вместо \n
    // Старый код: cout << endl;  
    std::cout << "\n";
}

TNode* FStack::GetTop() const //Получение верхушки стека
{
    // FIX_ME: Изменения названия
    // Старый код: return top;
    return Top;
}

void FStack::Clear()//Очищение 
{
    // FIX_ME: замена проверки через IsEmpty и \n
    //Старый код: if (top == nullptr)
    while (!IsEmpty())
    {
        TNode* Temp = Top;
        Top = Top->Next;
        delete Temp;
    }

    Top = nullptr;
    std::cout << "Стек  очищен.\n";
}

bool FStack::IsEmpty() const //Проверка на пустоту
{
    return Top == nullptr;
}

void AddElementAndPrintAddress(FStack& InStack, int32_t InValue)
{
    // FIX_ME: Проверка на валидность ссылки
    InStack.Push(InValue);

    TNode* NewTop = InStack.GetTop();
    std::cout << "Адрес новой вершины стека: " << NewTop << "\n";

}