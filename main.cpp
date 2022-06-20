using namespace std;
#include <iostream>
#include <string>
#define MAX 1000 // 通讯录最大值

// 显示菜单
void showMenu() {
	cout << endl;
	cout << "**********************" << endl;
	cout << "**** 1-添加通讯录 ****" << endl;
	cout << "**** 2-显示通讯录 ****" << endl;
	cout << "**** 3-修改通讯录 ****" << endl;
	cout << "**** 4-删除通讯录 ****" << endl;
	cout << "**** 5-查找通讯录 ****" << endl;
	cout << "**** 6-清空通讯录 ****" << endl;
	cout << "**** 0-退出通讯录 ****" << endl;
	cout << "**********************" << endl;
	cout << endl;
};

// 人员信息
struct Person {
	string name; // 姓名
	int sex; // 性别
	int age; // 年龄
	int phone; // 电话
	string address; // 地址
};

// 通讯录内容
struct AddressBox {
	Person personArr[MAX]; // 用户信息
	int total; // 总数
};

// 添加/修改通讯录
void addData(AddressBox* addressBox, int total) {
	if (addressBox->total > MAX) {
		cout << "通讯录已满，无法继续添加" << endl;
		system("pause");
		system("cls");
	}
	else {
		// 输入姓名
		cout << "输入姓名:" << endl;
		string name;
		cin >> name;

		// 输入性别
		cout << "输入性别:" << endl;
		cout << "0 --- 男:" << endl;
		cout << "1 --- 女:" << endl;
		int sex;
		cin >> sex;
		while (true) {
			if (sex == 0 || sex == 1) {
				break;
			}
			cout << "输入值无效，请重新输入" << endl;
			cin >> sex;
		}

		// 输入年龄
		cout << "输入年龄:" << endl;
		int age;
		cin >> age;

		// 输入电话
		cout << "输入电话:" << endl;
		int phone;
		cin >> phone;

		// 输入地址
		cout << "输入地址:" << endl;
		string address;
		cin >> address;

		// 赋值
		addressBox->personArr[total].name = name;
		addressBox->personArr[total].age = age;
		addressBox->personArr[total].sex = sex;
		addressBox->personArr[total].phone = phone;
		addressBox->personArr[total].address = address;
		cout << "操作成功" << endl;
		system("pause");
		system("cls");
	}
}

// 显示通讯录
void showData(AddressBox* addressBox) {
	for (int i = 0; i < addressBox -> total; i++) {
		string sex = addressBox -> personArr[i].sex == 1 ? "女" : "男";
		cout << "姓名： " << addressBox->personArr[i].name
			<< " 性别： " << sex
			<< " 年龄： " << addressBox->personArr[i].age
			<< " 电话： " << addressBox->personArr[i].phone
			<< " 地址： " << addressBox->personArr[i].address
			<< endl;
	};
	system("pause");
	system("cls");
}

// 验证是否存在该名字
int isExist(AddressBox* addressBox, string name) {
	for (int i = 0; i < addressBox->total; i++) {
		if (addressBox->personArr[i].name == name) {
			return i;
		}
	}
	cout << "未找到该姓名" << endl;
	return -1;
}

// 修改通讯录
void updateData(AddressBox* addressBox) {
	cout << "请输入需要修改的名字：" << endl;
	string name;
	cin >> name;
	int index = isExist(addressBox, name);
	if (index != -1) addData(addressBox, index);
	system("pause");
	system("cls");
}

// 删除通讯录
void deleteeData(AddressBox* addressBox) {
	cout << "请输入需要删除的名字：" << endl;
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
		cout << "删除成功!" << endl;
		system("pause");
		system("cls");
	}
}

// 查找通讯录
void findData(AddressBox* addressBox) {
	cout << "请输入需要查找的名字：" << endl;
	string name;
	cin >> name;
	int index = isExist(addressBox, name);
	if (index != -1) {
		string sex = addressBox->personArr[index].sex == 1 ? "女" : "男";
		cout << "姓名： " << addressBox->personArr[index].name
			<< " 性别： " << sex
			<< " 年龄： " << addressBox->personArr[index].age
			<< " 电话： " << addressBox->personArr[index].phone
			<< " 地址： " << addressBox->personArr[index].address
			<< endl;
		system("pause");
		system("cls");
	}
}

void main() {
	// 初始化通讯录内容
	AddressBox data;
	data.total = 0;

	while (true) {
		showMenu();

		// 输入值
		int select = 0;
		cout << "输入菜单值：" << endl;
		cin >> select;

		switch (select) {
			// 添加通讯录
			case 1:
				cout << "添加通讯录" << endl;
				addData(&data, data.total);
				data.total++;
				break;

			// 添加通讯录
			case 2:
				cout << "显示通讯录" << endl;
				showData(&data);
				break;

			// 修改通讯录
			case 3:
				cout << "修改通讯录" << endl;
				updateData(&data);
				break;

			// 删除通讯录
			case 4:
				cout << "删除通讯录" << endl;
				deleteeData(&data);
				break;

			// 查找通讯录
			case 5:
				cout << "查找通讯录" << endl;
				findData(&data);
				break;

			// 清空通讯录
			case 6:
				cout << "清空通讯录" << endl;
				data.total = 0;
				cout << "清空成功!" << endl;
				system("pause");
				system("cls");
				break;

			// 退出通讯录
			case 0:
				cout << "退出通讯录" << endl;
				system("pause");
				return;
				break;

			// 无效值
			default:
				cout << "无效值，请重新输入" << endl;
				break;
		}
	}
	system("pause");
	return;
}