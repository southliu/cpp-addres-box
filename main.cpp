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
	cout << "**** 5-���ͨѶ¼ ****" << endl;
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

// ���ͨѶ¼
void addAddressBox(AddressBox* addressBox) {
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
	while(true) {
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
	addressBox->personArr[addressBox->total].name = name;
	addressBox->personArr[addressBox->total].age = age;
	addressBox->personArr[addressBox->total].sex = sex;
	addressBox->personArr[addressBox->total].phone = phone;
	addressBox->personArr[addressBox->total].address = address;
	addressBox->total++;
}

// ��ʾͨѶ¼
void showAddressBox(AddressBox addressBox) {
	for (int i = 0; i < addressBox.total; i++) {
		string sex = addressBox.personArr[i].sex == 1 ? "Ů" : "��";
		cout << "������ " << addressBox.personArr[i].name
			<< " �Ա� " << sex
			<< " ���䣺 " << addressBox.personArr[i].age
			<< " �绰�� " << addressBox.personArr[i].phone
			<< " ��ַ�� " << addressBox.personArr[i].address
			<< endl;
	};
}

int main() {
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
				addAddressBox(&data);
				break;

			// ���ͨѶ¼
			case 2:
				cout << "��ʾͨѶ¼" << endl;
				showAddressBox(data);
				break;

			// �޸�ͨѶ¼
			case 3:
				cout << "�޸�ͨѶ¼" << endl;
				break;

			// ɾ��ͨѶ¼
			case 4:
				cout << "ɾ��ͨѶ¼" << endl;
				break;

			// ���ͨѶ¼
			case 5:
				cout << "���ͨѶ¼" << endl;
				break;

			// �˳�ͨѶ¼
			case 0:
				cout << "�˳�ͨѶ¼" << endl;
				system("pause");
				return 0;
				break;

			// ��Чֵ
			default:
				cout << "��Чֵ������������" << endl;
				break;
		}
	}
	system("pause");
	return 0;
}