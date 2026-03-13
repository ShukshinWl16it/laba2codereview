#include "Header.h"

int32_t main()
{
    setlocale(LC_ALL, "ru");

    // FIX_ME: Имена переменных должны быть в PascalCase
    // Старый код: Queue q; string in; string inum; int num; int n;
    FQueue Queue;
    std::string InputString;
    std::string ValueString;
    int32_t Value;
    int32_t ElementCount;

    // FIX_ME: Неинформативные имена переменных, отсутствие проверки ввода
    // Старый код: 
    // cout << "Введите количество элементов в очереди: ";
    // cin >> in;
    std::cout << "Введите количество элементов в очереди: ";
    std::cin >> InputString;

    // FIX_ME: Добавлена проверка на число
    if (!IsNumber(InputString))
    {
        std::cout << "Недопустимое значение.\n";
        return 1;
    }

    ElementCount = std::stoi(InputString);

    // FIX_ME: Неинформативные имена переменных, дублирование кода проверки
    std::cout << "Введите элементы очереди: ";
    for (int32_t Index = 1; Index <= ElementCount; ++Index)
    {
        std::cin >> ValueString;
        if (!IsNumber(ValueString))
        {
            std::cout << "Недопустимое значение.\n";
            return 1;
        }
        Value = std::stoi(ValueString);
        Queue.Push(Value);
    }

    // FIX_ME: Изменение названий 
    std::cout << "Изначальная очередь:  ";
    Queue.Show();

    std::cout << "Извлеченные элементы: ";
    Queue.RemoveUntilEven();

    std::cout << "Измененная очередь: ";
    Queue.Show();

    // FIX_ME: Методы должны называться понятно
    // Старый код: q.getP1data();
    std::cout << "Значение первого элемента: ";
    Queue.PrintHeadValue();
    std::cout << "\n";

    // FIX_ME: Методы должны называться понятно, добавлен перевод строки
    // Старый код: cout << "Новый адрес начала очереди (P1): " << q.getP1() << endl;
    std::cout << "Новый адрес начала очереди (Head): " << Queue.GetHead() << "\n";

    std::cout << "Значение последнего элемента: ";
    Queue.PrintTailValue();
    std::cout << "\n";
    std::cout << "Новый адрес конца очереди (Tail): " << Queue.GetTail() << "\n";
    
    return 0;
}