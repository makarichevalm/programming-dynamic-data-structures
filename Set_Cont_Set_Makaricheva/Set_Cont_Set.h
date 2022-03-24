#pragma once
#include <set>
#include <iostream>
#include <string>
using namespace std;

class Set {
	set<int> mySet;
public:
	Set();
	static Set createEmptySet();//�������� ������� ���������
	bool checkEmpty();//�������� �� �������
	bool checkElemInSet(int val);//�������� �������������� ���� ��-��
	void addNewElem(int val);// ���������� ������ ��������
	static Set createSet(int size, int min, int max, int num);//�������� ���������    num - 4 ��� 7
	int sizeOfSet();//�������� ����-��
	string printSet(const string symb);// ����� ���������
	void deleteSet();// �������� ��-��
	static bool isSubsetAB(Set firstA, Set firstB);//��������: A �������� ������������� ��������� B
	static bool isEquallyAB(Set firstA, Set firstB);// �������� �� ��������� �������� A � B
	static Set consolidationAB(Set firstA, Set firstB);// ����������� ��������
	static Set intersectionAB(Set firstA, Set firstB);//����������� ��������
	static Set differenceAB(Set firstA, Set firstB);// �������� ��������
	static Set symmetricDifferenceAB(Set firstA, Set firstB);//������������ �������� ��������
};
