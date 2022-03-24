#include "Set_Cont_Set.h"

Set::Set() {
	mySet = set<int>();
}
Set Set::createEmptySet() {
	Set* newSet = new Set();
	return *newSet;
}
//�������� �� �������
bool Set::checkEmpty() {
	return mySet.empty();
}
//�������� �������������� ���� ��-��
bool Set::checkElemInSet(int val) {
	if (checkEmpty()) return false;
	if (mySet.find(val) != mySet.end())
			return true;
	return false;
}
// ���������� ������ ��������
void Set::addNewElem(int val) {
		mySet.insert(val);
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
	return mySet.size();
}
// ����� ��������� 
string Set::printSet(const string symb) {
	if (checkEmpty())
		return "Set is empty!";
	string result;
	for (auto i = mySet.begin(); i != mySet.end(); i++) {
		if (*i == *std::prev(mySet.end()))
			result += to_string(*i);
		else result += to_string(*i) + symb;
	}
	return result;
}
// �������� ��-��
void Set::deleteSet() {
	mySet.clear();
}
//��������: A �������� ������������� ��������� B
bool Set::isSubsetAB(Set firstA, Set firstB) {
	if (firstA.checkEmpty())
		return true;
	if (firstA.sizeOfSet() > firstB.sizeOfSet())
		return false;

	for (auto i = firstA.mySet.begin(); i != firstA.mySet.end(); i++) {
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

	for (auto i = firstB.mySet.begin(); i != firstB.mySet.end(); i++) {
			firstC.addNewElem(*i);
	}
	return firstC;
}
//����������� ��������
Set Set::intersectionAB(Set firstA, Set firstB) {
	if (firstA.checkEmpty() || firstB.checkEmpty())
		return createEmptySet();
	Set firstC = createEmptySet();

	for (auto i = firstA.mySet.begin(); i != firstA.mySet.end(); i++) {
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
	for (auto i = firstA.mySet.begin(); i != firstA.mySet.end(); i++) {
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