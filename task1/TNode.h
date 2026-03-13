#pragma once
#include <iostream>

// FIX_ME: Ќе использовать using namespace std (плоха€ практика, загр€зн€ет глобальное пространство имен)
// —тарый код: using namespace std;
struct TNode
{
    int32_t Data;
    TNode* Next;
    // FIX_ME: прин€то использовать explicit дл€ конструкторов с одним параметром
    // FIX_ME: »спользование int вместо int32_t
    explicit TNode(int32_t InValue) : Data(InValue), Next(nullptr) {}
};