#include "SetLab1_18_Makaricheva.h"

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    
    cout << endl;
    cout << "-------------------------------- Лабораторная работа 1 ------------------------------" << endl;
    Elem* setA = createSet(6 + rand() % (10 - 6), 10, 99, 4);//множество чисел, последняя цифра которых меньше 4-х
    cout << "================= Множество А ==================" << endl;
    cout << endl;
    cout << "Размерность множества А: " << endl << sizeOfSet(setA) << endl;
    cout << "Вывод элементов множества А: " << endl << printSet(setA, ", ") << endl;
    /*deleteSet(setA);
    cout << "Размерность множества А после очистки памяти: " << endl << sizeOfSet(setA) << endl;
    cout << "Вывод элементов множества А после очистки памяти: " << endl << printSet(setA, ", ") << endl;*/
    cout << endl;
    Elem* setB = createSet(6 + rand() % (10 - 6), 10, 99, 7);//множество чисел, последняя цифра которых меньше 7-и
    cout << "================= Множество B ==================" << endl;
    cout << endl;
    cout << "Размерность множества B: " << endl << sizeOfSet(setB) << endl;
    cout << "Вывод элементов множества B: " << endl << printSet(setB, ", ") << endl;
    /*deleteSet(setB);
    cout << "Размерность множества B после очистки памяти: " << endl << sizeOfSet(setB) << endl;
    cout << "Вывод элементов множества B после очистки памяти: " << endl << printSet(setB, ", ") << endl;*/
    cout << endl;
    cout << "-------------------------------- Лабораторная работа 2 ------------------------------" << endl;
    cout << "Проверка на принадлежность множества А множеству В:" << endl << isSubsetAB(setA, setB) << endl;
    cout << "Проверка на равенство множеств:" << endl << isEquallyAB(setA, setB) << endl;
    cout << "Объединение множеств: " << endl << printSet(consolidationAB(setA, setB), " , ") << endl;
    cout << "Вывод элементов множества А: " << endl << printSet(setA, ", ") << endl;
    cout << "Пересечение множеств:" << endl << printSet(intersectionAB(setA, setB), " , ") << endl;
    cout << "Разность А - В:" << endl << printSet(differenceAB(setA, setB), " , ") << endl;
    cout << "Разность В - А:" << endl << printSet(differenceAB(setB, setA), " , ") << endl;
    cout << "Симметричная разность:" << endl << printSet(symmetricDifferenceAB(setA, setB), " , ") << endl;
    cout << endl;
    cout << "Проверка на принадлежность множества А множеству В:" << endl << isSubsetAB(setA, setA) << endl;
    cout << "Проверка на равенство множеств:" << endl << isEquallyAB(setA, setA) << endl;

}
