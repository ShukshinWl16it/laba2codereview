#include "FStack.h"
#include <limits>

void ClearInputBuffer()//очищение буфер ввода
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int32_t main()
{
    setlocale(LC_ALL, "Russian");

    FStack Stack;
    int32_t Choice = 0;
    int32_t Value = 0;

    while (true)
    {
        std::cout << "1. Добавить элемент в стек\n";
        std::cout << "2. Удалить элемент из стека\n";
        std::cout << "3. Вывести элементы стека\n";
        std::cout << "4. Очистить стек\n";
        std::cout << "5. Выйти\n";
        std::cout << "Введите ваш выбор: ";
        std::cin >> Choice; 
        if (!(std::cin >> Choice))
        {
            std::cout << "Неправильный ввод. Введите число.\n";
            ClearInputBuffer();
            continue;
        }
        switch (Choice)
        {
        case 1:
        {
            std::cout << "Введите число для добавления в стек: ";
            if (!(std::cin >> Value))
            {
                std::cout << "Пожалуйста введите число.\n";
                ClearInputBuffer();
                break;
            }
            // FIX_ME: Функция должна называться с большой буквы
            //Старый код: addElementAndPrintAddress(stack, value);

            AddElementAndPrintAddress(Stack, Value);
            break;
        }
        // FIX_ME: Добавлены фигурные скобки и изменение названий 
        case 2:
        {
            Stack.Pop();
            break;
        }

        case 3:
        {
            Stack.Print();
            break;
        }

        case 4:
        {
            Stack.Clear();
            break;
        }

        case 5:
        {
            std::cout << "Выход из программы.\n";
            return 0;
        }

        default:
        {
            std::cout << "Неверный выбор! Пожалуйста, попробуйте снова.\n";
            break;
        }
        }
    }

    // FIX_ME: Возврат 0 гарантирован
    return 0;
}