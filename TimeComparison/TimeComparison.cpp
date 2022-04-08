#include <chrono>//time
#include <iomanip>//setw
#include <string>
#include <vector>
#include "SetLab1_18_Makaricheva.h"
#include "Set_Makaricheva.h"
#include "Set_Cont_List.h"
#include "Set_Cont_Set.h"

using namespace std;

double timeclassList(int N){
    cout << "List(class)" << endl;
    double timet[10];
    //vector<std::chrono::time_point<std::chrono::system_clock>> timet;
    Elem* setA = createSet(N, 0, N * 10, 4);
    Elem* setB = createSet(N, 0, N * 10, 7);

    auto start1 = std::chrono::high_resolution_clock::now();
    createSet(N, 0, N * 10, 4);
    auto finish1 = std::chrono::high_resolution_clock::now();
    double time1 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish1 - start1).count();
    timet[0] =  time1;
    cout << "Создание " << timet[0] << endl;
    auto start2 = std::chrono::high_resolution_clock::now();
    sizeOfSet(setA);
    auto finish2 = std::chrono::high_resolution_clock::now();
    double time2 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish2 - start2).count();
    timet[1] = time2;
    cout << "Мощность " << timet[1] << endl;
    auto start3 = std::chrono::high_resolution_clock::now();
    isSubsetAB(setA, setA);
    auto finish3 = std::chrono::high_resolution_clock::now();
    double time3 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish3 - start3).count();
    timet[2] = time3;
    cout << "Подмножество АА " << timet[2] << endl;
    auto start4 = std::chrono::high_resolution_clock::now();
    isSubsetAB(setA, setB);
    auto finish4 = std::chrono::high_resolution_clock::now();
    double time4 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish4 - start4).count();
    timet[3] = time4;
    cout << "Подмножество АB " << timet[3] << endl;
    auto start5 = std::chrono::high_resolution_clock::now();
    isEquallyAB(setA, setA);
    auto finish5 = std::chrono::high_resolution_clock::now();
    double time5 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish5 - start5).count();
    timet[4] = time5;
    cout << "Равенство АA " << timet[4] << endl;
    auto start6 = std::chrono::high_resolution_clock::now();
    isEquallyAB(setA, setB);
    auto finish6 = std::chrono::high_resolution_clock::now();
    double time6 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish6 - start6).count();
    timet[5] = time6;
    cout << "Равенство АB " << timet[5] << endl;
    auto start7 = std::chrono::high_resolution_clock::now();
    consolidationAB(setA, setB);
    auto finish7 = std::chrono::high_resolution_clock::now();
    double time7 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish7 - start7).count();
    timet[6] = time7;
    cout << "Объединение " << timet[6] << endl;
    auto start8 = std::chrono::high_resolution_clock::now();
    intersectionAB(setA, setB);
    auto finish8 = std::chrono::high_resolution_clock::now();
    double time8 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish8 - start8).count();
    timet[7] = time8;
    cout << "Пересечение " << timet[7] << endl;
    auto start9 = std::chrono::high_resolution_clock::now();
    differenceAB(setA, setB);
    auto finish9 = std::chrono::high_resolution_clock::now();
    double time9 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish9 - start9).count();
    timet[8] = time9;
    cout << "Разность " << timet[8] << endl;
    auto start10 = std::chrono::high_resolution_clock::now();
    symmetricDifferenceAB(setA, setB);
    auto finish10 = std::chrono::high_resolution_clock::now();
    double time10 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish10 - start10).count();
    timet[9] = time10;
    cout << "Сим разность " << timet[9] << endl;
    return *timet;
}

auto timeclassSet(int N) {
    cout << "Set(class)" << endl;
    int timet[10];

    Set3::Set A = Set3::Set::createSet(N, 0, N * 10, 4);
    Set3::Set B = Set3::Set::createSet(N, 0, N * 10, 7);

    auto start1 = std::chrono::high_resolution_clock::now();
    Set3::Set::createSet(N, 0, N * 10, 4);
    auto finish1 = std::chrono::high_resolution_clock::now();
    auto time1 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish1 - start1);
    timet[0] = time1.count();
    cout << "Создание " << timet[0] << endl;
    auto start2 = std::chrono::high_resolution_clock::now();
    A.sizeOfSet();
    auto finish2 = std::chrono::high_resolution_clock::now();
    auto time2 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish2 - start2);
    timet[1] = time2.count();
    cout << "Мощность " << timet[1] << endl;
    auto start3 = std::chrono::high_resolution_clock::now();
    Set3::Set::isSubsetAB(A, A);
    auto finish3 = std::chrono::high_resolution_clock::now();
    auto time3 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish3 - start3);
    timet[2] = time3.count();
    cout << "Подмножество АА " << timet[2] << endl;
    auto start4 = std::chrono::high_resolution_clock::now();
    Set3::Set::isSubsetAB(A, B);
    auto finish4 = std::chrono::high_resolution_clock::now();
    auto time4 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish4 - start4);
    timet[3] = time4.count();
    cout << "Подмножество АB " << timet[3] << endl;
    auto start5 = std::chrono::high_resolution_clock::now();
    Set3::Set::isEquallyAB(A, A);
    auto finish5 = std::chrono::high_resolution_clock::now();
    auto time5 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish5 - start5);
    timet[4] = time5.count();
    cout << "Равенство АA " << timet[4] << endl;
    auto start6 = std::chrono::high_resolution_clock::now();
    Set3::Set::isEquallyAB(A, B);
    auto finish6 = std::chrono::high_resolution_clock::now();
    auto time6 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish6 - start6);
    timet[5] = time6.count();
    cout << "Равенство АB " << timet[5] << endl;
    auto start7 = std::chrono::high_resolution_clock::now();
    Set3::Set::consolidationAB(A, B);
    auto finish7 = std::chrono::high_resolution_clock::now();
    auto time7 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish7 - start7);
    timet[6] = time7.count();
    cout << "Объединение " << timet[6] << endl;
    auto start8 = std::chrono::high_resolution_clock::now();
    Set3::Set::intersectionAB(A, B);
    auto finish8 = std::chrono::high_resolution_clock::now();
    auto time8 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish8 - start8);
    timet[7] = time8.count();
    cout << "Пересечение " << timet[7] << endl;
    auto start9 = std::chrono::high_resolution_clock::now();
    Set3::Set::differenceAB(A, B);
    auto finish9 = std::chrono::high_resolution_clock::now();
    auto time9 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish9 - start9);
    timet[8] = time9.count();
    cout << "Разность " << timet[8] << endl;
    auto start10 = std::chrono::high_resolution_clock::now();
    Set3::Set::symmetricDifferenceAB(A, B);
    auto finish10 = std::chrono::high_resolution_clock::now();
    auto time10 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish10 - start10);
    timet[9] = time10.count();
    cout << "Сим разность " << timet[9] << endl;
    return timet;
}

auto timeList(int N) {
    cout << "List(std)" << endl;
    int timet[10];

    Set4::Set A = Set4::Set::createSet(N, 0, N * 10, 4);
    Set4::Set B = Set4::Set::createSet(N, 0, N * 10, 7);
   
    auto start1 = std::chrono::high_resolution_clock::now();
    Set4::Set::createSet(N, 0, N * 10, 4);
    auto finish1 = std::chrono::high_resolution_clock::now();
    auto time1 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish1 - start1);
    timet[0] = time1.count();
    cout << "Создание " << timet[0] << endl;
    auto start2 = std::chrono::high_resolution_clock::now();
    A.sizeOfSet();
    auto finish2 = std::chrono::high_resolution_clock::now();
    auto time2 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish2 - start2);
    timet[1] = time2.count();
    cout << "Мощность " << timet[1] << endl;
    auto start3 = std::chrono::high_resolution_clock::now();
    Set4::Set::isSubsetAB(A, A);
    auto finish3 = std::chrono::high_resolution_clock::now();
    auto time3 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish3 - start3);
    timet[2] = time3.count();
    cout << "Подмножество АА " << timet[2] << endl;
    auto start4 = std::chrono::high_resolution_clock::now();
    Set4::Set::isSubsetAB(A, B);
    auto finish4 = std::chrono::high_resolution_clock::now();
    auto time4 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish4 - start4);
    timet[3] = time4.count();
    cout << "Подмножество АB " << timet[3] << endl;
    auto start5 = std::chrono::high_resolution_clock::now();
    Set4::Set::isEquallyAB(A, A);
    auto finish5 = std::chrono::high_resolution_clock::now();
    auto time5 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish5 - start5);
    timet[4] = time5.count();
    cout << "Равенство АA " << timet[4] << endl;
    auto start6 = std::chrono::high_resolution_clock::now();
    Set4::Set::isEquallyAB(A, B);
    auto finish6 = std::chrono::high_resolution_clock::now();
    auto time6 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish6 - start6);
    timet[5] = time6.count();
    cout << "Равенство АB " << timet[5] << endl;
    auto start7 = std::chrono::high_resolution_clock::now();
    Set4::Set::consolidationAB(A, B);
    auto finish7 = std::chrono::high_resolution_clock::now();
    auto time7 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish7 - start7);
    timet[6] = time7.count();
    cout << "Объединение " << timet[6] << endl;
    auto start8 = std::chrono::high_resolution_clock::now();
    Set4::Set::intersectionAB(A, B);
    auto finish8 = std::chrono::high_resolution_clock::now();
    auto time8 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish8 - start8);
    timet[7] = time8.count();
    cout << "Пересечение " << timet[7] << endl;
    auto start9 = std::chrono::high_resolution_clock::now();
    Set4::Set::differenceAB(A, B);
    auto finish9 = std::chrono::high_resolution_clock::now();
    auto time9 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish9 - start9);
    timet[8] = time9.count();
    cout << "Разность " << timet[8] << endl;
    auto start10 = std::chrono::high_resolution_clock::now();
    Set4::Set::symmetricDifferenceAB(A, B);
    auto finish10 = std::chrono::high_resolution_clock::now();
    auto time10 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish10 - start10);
    timet[9] = time10.count();
    cout << "Сим разность " << timet[9] << endl;
    /*auto start = std::chrono::high_resolution_clock::now();
    Set4::Set::createSet(N, 10, 99, 4);
    auto finish = std::chrono::high_resolution_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
    cout << time.count() << endl;*/
    return timet;
}

auto timeSet(int N) {
    cout << "Set(std)" << endl;
    int timet[10];

    Set5::Set A = Set5::Set::createSet(N, 0, N*10, 4);
    Set5::Set B = Set5::Set::createSet(N, 0, N*10, 7);

    auto start1 = std::chrono::high_resolution_clock::now();
    Set5::Set::createSet(N, 0, N*10, 4);
    auto finish1 = std::chrono::high_resolution_clock::now();
    auto time1 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish1 - start1);
    timet[0] = time1.count();
    cout << "Создание " << timet[0] << endl;
    auto start2 = std::chrono::high_resolution_clock::now();
    A.sizeOfSet();
    auto finish2 = std::chrono::high_resolution_clock::now();
    auto time2 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish2 - start2);
    timet[1] = time2.count();
    cout << "Мощность " << timet[1] << endl;
    auto start3 = std::chrono::high_resolution_clock::now();
    Set5::Set::isSubsetAB(A, A);
    auto finish3 = std::chrono::high_resolution_clock::now();
    auto time3 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish3 - start3);
    timet[2] = time3.count();
    cout << "Подмножество АА " << timet[2] << endl;
    auto start4 = std::chrono::high_resolution_clock::now();
    Set5::Set::isSubsetAB(A, B);
    auto finish4 = std::chrono::high_resolution_clock::now();
    auto time4 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish4 - start4);
    timet[3] = time4.count();
    cout << "Подмножество АB " << timet[3] << endl;
    auto start5 = std::chrono::high_resolution_clock::now();
    Set5::Set::isEquallyAB(A, A);
    auto finish5 = std::chrono::high_resolution_clock::now();
    auto time5 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish5 - start5);
    timet[4] = time5.count();
    cout << "Равенство АA " << timet[4] << endl;
    auto start6 = std::chrono::high_resolution_clock::now();
    Set5::Set::isEquallyAB(A, B);
    auto finish6 = std::chrono::high_resolution_clock::now();
    auto time6 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish6 - start6);
    timet[5] = time6.count();
    cout << "Равенство АB " << timet[5] << endl;
    auto start7 = std::chrono::high_resolution_clock::now();
    Set5::Set::consolidationAB(A, B);
    auto finish7 = std::chrono::high_resolution_clock::now();
    auto time7 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish7 - start7);
    timet[6] = time7.count();
    cout << "Объединение " << timet[6] << endl;
    auto start8 = std::chrono::high_resolution_clock::now();
    Set5::Set::intersectionAB(A, B);
    auto finish8 = std::chrono::high_resolution_clock::now();
    auto time8 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish8 - start8);
    timet[7] = time8.count();
    cout << "Пересечение " << timet[7] << endl;
    auto start9 = std::chrono::high_resolution_clock::now();
    Set5::Set::differenceAB(A, B);
    auto finish9 = std::chrono::high_resolution_clock::now();
    auto time9 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish9 - start9);
    timet[8] = time9.count();
    cout << "Разность " << timet[8] << endl;
    auto start10 = std::chrono::high_resolution_clock::now();
    Set5::Set::symmetricDifferenceAB(A, B);
    auto finish10 = std::chrono::high_resolution_clock::now();
    auto time10 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish10 - start10);
    timet[9] = time10.count();
    cout << "Сим разность " << timet[9] << endl;
    return timet;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int N;
    cout << "Введите количество элементов : \n";
    cin >> N;
    cout << endl;
    string title[10] = {"Создание множества","Мощность множества","Подмножество АА","Подмножество АВ",
        "Равенство А=А","Равенство А=В","Объединение","Пересечение", "Разность", "Симметричная разность"};
    double t1 = timeclassList(N);
    cout << t1;
    auto t2 = timeclassSet(N);
    cout << t2;
    auto t3 = timeList(N);
    cout << t3;
    auto t4 = timeSet(N);
    cout << t4;
    for (int i = 0; i < 10; i++) {
        cout << "|"<<title[i]<<setw(10)<< "|" <<t1[i]<< setw(10)<< "|" <<t2[i]<< setw(10)<< "|" <<t3[i]<<setw(10) << "|" <<t4[i]<<endl;
    }
    cout << "+-----------------------+--------------------+----------------- --+----------+---------+" << endl;
    cout << "|   Название операции   | Односвязный список |  Класс 'Множество  |   List   |   Set   |" << endl;
    cout << "+-----------------------+--------------------+---------------- ---+----------+---------+" << endl;
    cout << "| Создание множества    |                    |                    |          |         |" << endl;
    cout << "| Мощность множества    |                    |                    |          |         |" << endl;
    cout << "| Подмножество АА       |                    |                    |          |         |" << endl;
    cout << "| Подмножество АВ       |                    |                    |          |         |" << endl;
    cout << "| Равенство А=А         |                    |                    |          |         |" << endl;
    cout << "| Равенство А=В         |                    |                    |          |         |" << endl;
    cout << "| Объединение           |                    |                    |          |         |" << endl;
    cout << "| Пересечение           |                    |                    |          |         |" << endl;
    cout << "| Разность              |                    |                    |          |         |" << endl;
    cout << "| Симметричная разность |                    |                    |          |         |" << endl;
    cout << "+-----------------------+--------------------+-------------- -----+----------+---------+" << endl;
    /*cout << "+-----------------------+--------------------+-------------------+----------+---------+" << endl;
    cout << "|   Название операции   | Односвязный список | Класс 'Множество' |   List   |   Set   |"  << endl;
    cout << "+-----------------------+--------------------+-------------------+----------+---------+" << endl;
    cout << "| Создание множества    |                    |                   |          |         |" << endl;
    cout << "| Мощность множества    |                    |                   |          |         |" << endl;
    cout << "| Подмножество АА       |                    |                   |          |         |" << endl;
    cout << "| Подмножество АВ       |                    |                   |          |         |" << endl;
    cout << "| Равенство А=А         |                    |                   |          |         |" << endl;
    cout << "| Равенство А=В         |                    |                   |          |         |" << endl;
    cout << "| Объединение           |                    |                   |          |         |" << endl;
    cout << "| Пересечение           |                    |                   |          |         |" << endl;
    cout << "| Разность              |                    |                   |          |         |" << endl;
    cout << "| Симметричная разность |                    |                   |          |         |" << endl;
    cout << "+-----------------------+--------------------+-------------------+----------+---------+" << endl;*/
    return 0;
}