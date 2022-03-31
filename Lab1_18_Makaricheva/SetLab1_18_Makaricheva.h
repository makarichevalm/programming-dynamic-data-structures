#pragma once

#include <iostream>
#include <string>
using namespace std;

struct Elem {
	int value;//�������� �������� ���������
	Elem* next;// ��������� �� ���� ����

};
Elem* createEmptySet();//�������� ������� ���������
bool checkEmpty(Elem* first);//�������� �� �������
bool checkElemInSet(Elem* first, int val);//�������� �������������� ���� ��-��
Elem* addNewElem(Elem*& first, int val);// ���������� ������ ��������
Elem* createSet(int size, int min, int max, int num);//�������� ���������    num - 4 ��� 7
int sizeOfSet(Elem* first);//�������� ����-��
string printSet(Elem* first, string symb);// ����� ���������
Elem* deleteSet(Elem*& first);// �������� ��-��
bool isSubsetAB(Elem* firstA, Elem* firstB);//��������: A �������� ������������� ��������� B
bool isEquallyAB(Elem* firstA, Elem* firstB);// �������� �� ��������� �������� A � B
Elem* consolidationAB(Elem* firstA, Elem* firstB);// ����������� ��������
Elem* intersectionAB(Elem* firstA, Elem* firstB);//����������� ��������
Elem* differenceAB(Elem* firstA, Elem* firstB);// �������� ��������
Elem* symmetricDifferenceAB(Elem* firstA, Elem* firstB);//������������ �������� ��������





