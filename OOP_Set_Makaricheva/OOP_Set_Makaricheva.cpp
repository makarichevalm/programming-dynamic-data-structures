#include "Set_Makaricheva.h"
using namespace Set3;

int main()
{
	srand(time(nullptr));
	setlocale(LC_ALL, "Russian");
	cout << endl;
	cout << "========================== Множество А ==========================" << endl;
	cout << endl;
	Set A = Set::createSet(6 + rand() % (10 - 6), 10, 99, 4);//множество чисел, последняя цифра которых меньше 4-х
	cout << "Размерность множества А: " << A.sizeOfSet() << endl;
	cout << "Вывод элементов множества А: " << A.printSet(" , ") << endl;
	cout << endl;
	cout << "========================== Множество В ==========================" << endl;
	cout << endl;
	Set B = Set::createSet(6 + rand() % (10 - 6), 10, 99, 7);//множество чисел, последняя цифра которых меньше 7-и
	cout << "Размерность множества B: " << B.sizeOfSet() << endl;
	cout << "Вывод элементов множества B: " << B.printSet(" , ") << endl;
	cout << endl;
	cout << "========================== Операции над множествами ==========================" << endl;
	cout << endl;
	cout << "Проверка на принадлежность множества А множеству В:" << endl << Set::isSubsetAB(A, B) << endl;
	cout << "Проверка на равенство множеств AB:" << endl << Set::isEquallyAB(A, B) << endl;
	cout << "Проверка на принадлежность множества А множеству A:" << endl << Set::isSubsetAB(A, A) << endl;
	cout << "Проверка на равенство множеств AA:" << endl << Set::isEquallyAB(A, A) << endl;
	Set ConsAB = Set::consolidationAB(A, B);
	cout << "Объединение множеств: " << endl << ConsAB.printSet(" , ") << endl;
	Set IntAB = Set::intersectionAB(A, B);
	cout << "Пересечение множеств:" << endl << IntAB.printSet(" , ") << endl;
	Set DiffAB = Set::differenceAB(A, B);
	cout << "Разность А - В:" << endl << DiffAB.printSet(" , ") << endl;
	Set DiffBA = Set::differenceAB(B, A);
	cout << "Разность В - А:" << endl << DiffBA.printSet(" , ") << endl;
	cout << "Симметричная разность:" << endl << Set::symmetricDifferenceAB(A, B).printSet(" , ") << endl;
	cout << endl;
	cout << "========================== Очистка памяти ==========================" << endl;
	cout << endl;
	A.deleteSet();
	cout << "Размерность множества А после очистки памяти: " << endl << A.sizeOfSet() << endl;
	cout << "Вывод элементов множества А после очистки памяти: " << endl << A.printSet(", ") << endl;
	cout << endl;
	B.deleteSet();
	cout << "Размерность множества B после очистки памяти: " << endl << B.sizeOfSet() << endl;
	cout << "Вывод элементов множества B после очистки памяти: " << endl << B.printSet(", ") << endl;
}

