#include "SetLab1_18_Makaricheva.h"
//�������� ������� ���������
Elem* createEmptySet() {
	Elem* first = nullptr;
	return first;
}
//�������� �� �������
bool checkEmpty(Elem* first) {
	return first == nullptr;
}
//�������� �������������� ���� ��-��
bool checkElemInSet(Elem* first, int val) {
	if (checkEmpty(first)) return false;
	Elem* temp = first;
	while (temp->next && temp->value != val) {
		temp = temp->next;
	}
	return temp->value == val;

}
// ���������� ������ �������� � ������ ������
Elem* addNewElem(Elem*& first, int val) {
	if (!checkElemInSet(first, val)) {   //Elem*& - ������ �� ���������, ����� ��������� ����������� � ��������� ���������
		Elem* new_elem = new Elem;
		new_elem->value = val;
		new_elem->next = first;
		first = new_elem;
	}
	return first;
}
//�������� ���������
Elem* createSet(int size, int min, int max, int num) {
	Elem* new_set = createEmptySet();
	int s = 0;
	while (s < size) {
		int temp = min + rand() % (max - min + 1);
		if (temp % 10 < num) {
			addNewElem(new_set, temp);
			s++;
		}
	}
	return new_set;
}
//�������� ����-��
int sizeOfSet(Elem* first) {
	int size = 0;
	if (checkEmpty(first))
		return 0;
	Elem* temp = first;
	while (temp != nullptr) {
		size++;
		temp = temp->next;
	}
	return size;

}
//����� ���������
string printSet(Elem* first, string symb) {
	if (checkEmpty(first))
		return "Set is empty!";
	Elem* temp = first;
	string result;
	while (temp->next) {
		result += to_string(temp->value) + symb;
		temp = temp->next;
	}
	result += to_string(temp->value);
	return result;
}
// �������� ��-��
Elem* deleteSet(Elem*& first) {
	Elem* cur = first;
	while (cur) {
		Elem* temp = cur;
		cur = cur->next;
		delete temp;
	}
	first = nullptr;
	return first;
}
//��������: A �������� ������������� ��������� B
bool isSubsetAB(Elem* firstA, Elem* firstB) {
	if (checkEmpty(firstA))
		return true;
	if (sizeOfSet(firstA) > sizeOfSet(firstB))
		return false;
	Elem* temp = firstA;
	while (temp->next){
		if (!checkElemInSet(firstB, temp->value))
			return false;
		temp = temp->next;
	}
	return true;
}
// �������� �� ��������� �������� A � B
bool isEquallyAB(Elem* firstA, Elem* firstB) {
	return (isSubsetAB(firstB, firstA) && isSubsetAB(firstA, firstB));
}
// ����������� ��������
Elem* consolidationAB(Elem* firstA, Elem* firstB) {
	if (checkEmpty(firstA))// ����������� �� � � ������ = �� �
		return firstB;
	if (checkEmpty(firstB))
		return firstA;
	Elem* firstC = firstA;
	Elem* temp = firstB;
	while (temp != nullptr) {
		if (!checkElemInSet(firstC, temp->value)) {
			addNewElem(firstC, temp->value);
		}
		temp = temp->next;
	}
	return firstC;

}

//����������� ��������
Elem* intersectionAB(Elem* firstA, Elem* firstB) {
	if (checkEmpty(firstA) || checkEmpty(firstB))
		return createEmptySet();
	Elem* firstC = createEmptySet();
	Elem* temp = firstA;
	while (temp != nullptr) {
		if (checkElemInSet(firstB, temp->value)) {
			addNewElem(firstC, temp->value);
		}
		temp = temp->next;
	}
	return firstC;
}

// �������� ��������
Elem* differenceAB(Elem* firstA, Elem* firstB) {
	Elem* firstC = createEmptySet();
	if (checkEmpty(firstA))
		return firstC;
	if (checkEmpty(firstB))
		return firstA;
	Elem* temp = firstA;
	while (temp != nullptr) {
		if (!checkElemInSet(firstB, temp->value)) {
			addNewElem(firstC, temp->value);
		}
		temp = temp->next;
	}
	return firstC;
}
//������������ �������� ��������
Elem* symmetricDifferenceAB(Elem* firstA, Elem* firstB) {
	return differenceAB(consolidationAB(firstA, firstB), intersectionAB(firstA, firstB));
}

