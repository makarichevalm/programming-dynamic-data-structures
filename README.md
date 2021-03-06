# programming-dynamic-data-structures
Лабораторные работы по предмету "Программирование динамических структур данных"

## Lab1_18_Makaricheva
	
### Лабораторная работа № 1

***Создание функций, реализующих операции создания и работы с множествами***

Для представления множества использовать односвязный список целочисленных значений. 

Реализовать множество А – множество чисел, последняя цифра которых меньше 4-х и множество В – множество чисел, последняя цифра которых меньше 7-х. 

Интервал значений множеств – от 10 до 99.

Структура программы:

| Название файла | Назначение |
|:----:|:----:|
| SetLab1_18_Makaricheva.h| заголовочный файл |
| SetLab1_18_Makaricheva.cpp | файл реализации  |
| Lab1_18_Makaricheva.cpp |  начальная точка для выполнения программы |

Функции:

***F1.*** `Elem* createEmptySet()` - создание пустого множества. 

Входные параметры: нет. 

Выходные параметры: указатель на первый элемент списка, равный NULL.

***F2.*** `bool checkEmpty(Elem* first)`  - проверка множества на пустоту.

Входные параметры: указатель на первый элемент списка. 

Выходные параметры: логическое значение.

***F3.*** `bool checkElemInSet(Elem* first, int val)` - проверка принадлежности элемента множеству. 

Входные параметры: указатель на первый элемент списка, значение элемента. 

Выходные параметры: логическое значение. Использовать F2.

***F4.*** `Elem* addNewElem(Elem*& first, int val) ` - добавление нового элемента в множество. 

Входные параметры: указатель на первый элемент списка, добавляемое в список значение. 

Выходные параметры: указатель на первый элемент списка-результата. Использовать F3. 

Ограничение: добавление осуществлять в начало списка.

***F5.*** `Elem* createSet(int size, int min, int max, int num) ` - cоздание множества. 

Входные параметры: количество элементов, интервал допустимых значений (от min до max). 

Выходные параметры: указатель на первый элемент списка-результата. 

Требования: Генерация значений – датчиком случайных чисел. Использовать F4. Проверить возможность создания множества с заданными параметрами.

***F6.*** `int sizeOfSet(Elem* first)` - мощность множества. 

Входные параметры: указатель на первый элемент списка. 

Выходные параметры: целочисленное значение. Использовать F2.

***F7.*** `string printSet(Elem* first, string symb)` - вывод элементов множества. 

Входные параметры: указатель на первый элемент списка, символ разделителя. 

Выходные параметры: строка, содержащая элементы множества, разделенные символом разделителя. Использовать F2. Требования: в конце строки-результата разделитель стоять не должен.

***F8.*** `Elem* deleteSet(Elem*& first)` - удаление множества (очистка памяти, занимаемой списком). 

Входные параметры: указатель на первый элемент списка. 

Выходные параметры: указатель на первый элемент списка, равный NULL.

### Лабораторная работа № 2

***Создание функций, реализующих операции над множествами***

## OOP_Set_Makaricheva
