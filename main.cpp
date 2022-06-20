using namespace std;
#include <iostream>
#include <string>
#define MAX 1000 // ͨѶ¼���ֵ

// ��ʾ�˵�
void showMenu() {
	cout << endl;
	cout << "**********************" << endl;
	cout << "**** 1-���ͨѶ¼ ****" << endl;
	cout << "**** 2-��ʾͨѶ¼ ****" << endl;
	cout << "**** 3-�޸�ͨѶ¼ ****" << endl;
	cout << "**** 4-ɾ��ͨѶ¼ ****" << endl;
	cout << "**** 5-����ͨѶ¼ ****" << endl;
	cout << "**** 6-���ͨѶ¼ ****" << endl;
	cout << "**** 0-�˳�ͨѶ¼ ****" << endl;
	cout << "**********************" << endl;
	cout << endl;
};

// ��Ա��Ϣ
struct Person {
	string name; // ����
	int sex; // �Ա�
	int age; // ����
	int phone; // �绰
	string address; // ��ַ
};

// ͨѶ¼����
struct AddressBox {
	Person personArr[MAX]; // �û���Ϣ
	int total; // ����
};

// ���/�޸�ͨѶ¼
void addData(AddressBox* addressBox, int total) {
	if (addressBox->total > MAX) {
		cout << "ͨѶ¼�������޷��������" << endl;
		system("pause");
		system("cls");
	}
	else {
		// ��������
		cout << "��������:" << endl;
		string name;
		cin >> name;

		// �����Ա�
		cout << "�����Ա�:" << endl;
		cout << "0 --- ��:" << endl;
		cout << "1 --- Ů:" << endl;
		int sex;
		cin >> sex;
		while (true) {
			if (sex == 0 || sex == 1) {
				break;
			}
			cout << "����ֵ��Ч������������" << endl;
			cin >> sex;
		}

		// ��������
		cout << "��������:" << endl;
		int age;
		cin >> age;

		// ����绰
		cout << "����绰:" << endl;
		int phone;
		cin >> phone;

		// �����ַ
		cout << "�����ַ:" << endl;
		string address;
		cin >> address;

		// ��ֵ
		addressBox->personArr[total].name = name;
		addressBox->personArr[total].age = age;
		addressBox->personArr[total].sex = sex;
		addressBox->personArr[total].phone = phone;
		addressBox->personArr[total].address = address;
		cout << "�����ɹ�" << endl;
		system("pause");
		system("cls");
	}
}

// ��ʾͨѶ¼
void showData(AddressBox* addressBox) {
	for (int i = 0; i < addressBox -> total; i++) {
		string sex = addressBox -> personArr[i].sex == 1 ? "Ů" : "��";
		cout << "������ " << addressBox->personArr[i].name
			<< " �Ա� " << sex
			<< " ���䣺 " << addressBox->personArr[i].age
			<< " �绰�� " << addressBox->personArr[i].phone
			<< " ��ַ�� " << addressBox->personArr[i].address
			<< endl;
	};
	system("pause");
	system("cls");
}

// ��֤�Ƿ���ڸ�����
int isExist(AddressBox* addressBox, string name) {
	for (int i = 0; i < addressBox->total; i++) {
		if (addressBox->personArr[i].name == name) {
			return i;
		}
	}
	cout << "δ�ҵ�������" << endl;
	return -1;
}

// �޸�ͨѶ¼
void updateData(AddressBox* addressBox) {
	cout << "��������Ҫ�޸ĵ����֣�" << endl;
	string name;
	cin >> name;
	int index = isExist(addressBox, name);
	if (index != -1) addData(addressBox, index);
	system("pause");
	system("cls");
}

// ɾ��ͨѶ¼
void deleteeData(AddressBox* addressBox) {
	cout << "��������Ҫɾ�������֣�" << endl;
	string name;
	cin >> name;
	int index = isExist(addressBox, name);
	if (index != -1) {
		for (int i = 0; i < addressBox->total; i++) {
			if (i >= index) {
				addressBox->personArr[i] = addressBox->personArr[i + 1];
			}
		}
		addressBox->total--;
		cout << "ɾ���ɹ�!" << endl;
		system("pause");
		system("cls");
	}
}

// ����ͨѶ¼
void findData(AddressBox* addressBox) {
	cout << "��������Ҫ���ҵ����֣�" << endl;
	string name;
	cin >> name;
	int index = isExist(addressBox, name);
	if (index != -1) {
		string sex = addressBox->personArr[index].sex == 1 ? "Ů" : "��";
		cout << "������ " << addressBox->personArr[index].name
			<< " �Ա� " << sex
			<< " ���䣺 " << addressBox->personArr[index].age
			<< " �绰�� " << addressBox->personArr[index].phone
			<< " ��ַ�� " << addressBox->personArr[index].address
			<< endl;
		system("pause");
		system("cls");
	}
}

void main() {
	// ��ʼ��ͨѶ¼����
	AddressBox data;
	data.total = 0;

	while (true) {
		showMenu();

		// ����ֵ
		int select = 0;
		cout << "����˵�ֵ��" << endl;
		cin >> select;

		switch (select) {
			// ���ͨѶ¼
			case 1:
				cout << "���ͨѶ¼" << endl;
				addData(&data, data.total);
				data.total++;
				break;

			// ���ͨѶ¼
			case 2:
				cout << "��ʾͨѶ¼" << endl;
				showData(&data);
				break;

			// �޸�ͨѶ¼
			case 3:
				cout << "�޸�ͨѶ¼" << endl;
				updateData(&data);
				break;

			// ɾ��ͨѶ¼
			case 4:
				cout << "ɾ��ͨѶ¼" << endl;
				deleteeData(&data);
				break;

			// ����ͨѶ¼
			case 5:
				cout << "����ͨѶ¼" << endl;
				findData(&data);
				break;

			// ���ͨѶ¼
			case 6:
				cout << "���ͨѶ¼" << endl;
				data.total = 0;
				cout << "��ճɹ�!" << endl;
				system("pause");
				system("cls");
				break;

			// �˳�ͨѶ¼
			case 0:
				cout << "�˳�ͨѶ¼" << endl;
				system("pause");
				return;
				break;

			// ��Чֵ
			default:
				cout << "��Чֵ������������" << endl;
				break;
		}
	}
	system("pause");
	return;
}