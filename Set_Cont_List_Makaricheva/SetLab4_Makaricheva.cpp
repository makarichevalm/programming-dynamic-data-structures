#include "Set_Cont_List.h"
using namespace Set4;

Set:: Set() {
	myList = list<int>();
}

Set Set::createEmptySet() {
	Set* newSet = new Set();
	return *newSet;
}

//�������� �� �������
bool Set::checkEmpty() {
	return myList.empty();
}

//�������� �������������� ���� ��-��
bool Set::checkElemInSet(int val) {
	if (checkEmpty()) return false;
	for (auto iter : myList) {
		if(iter == val) 
			return true;
	}
	 return false;
}

// ���������� ������ ��������
void Set::addNewElem(int val) {
	if (!checkElemInSet(val)) {
		myList.push_front(val);
	}
	return;
}

//�������� ���������    num - 4 ��� 7
Set Set::createSet(int size, int min, int max, int num) {
	Set new_set = *new Set();
	int s = 0;
	while (s < size) {
		int temp = min + rand() % (max - min + 1);
		if (temp % 10 < num) {
			new_set.addNewElem(temp);
			s++;
		}
	}
	return new_set;
}

//�������� ����-��
int Set::sizeOfSet() {
	return myList.size();
}

// ����� ��������� 
string Set::printSet(const string symb) {
	if (checkEmpty())
		return "Set is empty!";
	string result;
	for (auto i = myList.begin(); i != myList.end(); i++) {
		if (*i == *std::prev(myList.end()))
			result+= to_string(*i);
		else result+= to_string(*i) + symb;
	}
	return result;
}

// �������� ��-��
void Set::deleteSet() {
	myList.clear();
}

//��������: A �������� ������������� ��������� B
bool Set::isSubsetAB(Set firstA, Set firstB) {
	if (firstA.checkEmpty())
		return true;
	if (firstA.sizeOfSet() > firstB.sizeOfSet())
		return false;
	for (auto i = firstA.myList.begin(); i != firstA.myList.end(); i++) {
		if (!firstB.checkElemInSet(*i))
			return false;
	}
	return true;
}

// �������� �� ��������� �������� A � B
bool Set::isEquallyAB(Set firstA, Set firstB) {
	return (isSubsetAB(firstB, firstA) && isSubsetAB(firstA, firstB));
}

// ����������� ��������
Set Set::consolidationAB(Set firstA, Set firstB) {
	if (firstA.checkEmpty())// ����������� �� � � ������ = �� �
		return firstB;
	if (firstB.checkEmpty())
		return firstA;
	Set firstC = firstA;
	
	for (auto i = firstB.myList.begin(); i != firstB.myList.end(); i++) {
		if (!firstC.checkElemInSet(*i)) {
			firstC.addNewElem(*i);
		}
	}
	return firstC;
}
//����������� ��������
Set Set::intersectionAB(Set firstA, Set firstB) {
	if (firstA.checkEmpty() || firstB.checkEmpty())
		return createEmptySet();
	Set firstC = createEmptySet();
	
	for (auto i = firstA.myList.begin(); i != firstA.myList.end(); i++) {
		if (firstB.checkElemInSet(*i)) {
			firstC.addNewElem(*i);
		}
	}
	return firstC;
}

// �������� ��������
Set Set::differenceAB(Set firstA, Set firstB) {
	Set firstC = createEmptySet();
	if (firstA.checkEmpty())
		return firstC;
	if (firstB.checkEmpty())
		return firstA;
	for (auto i = firstA.myList.begin(); i != firstA.myList.end(); i++) {
		if (!firstB.checkElemInSet(*i)) {
			firstC.addNewElem(*i);
		}
	}
	return firstC;
}

//������������ �������� ��������
Set Set::symmetricDifferenceAB(Set firstA, Set firstB) {
	return differenceAB(consolidationAB(firstA, firstB), intersectionAB(firstA, firstB));
}