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
	cout << "**** 5-清空通讯录 ****" << endl;
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

// 添加通讯录
void addAddressBox(AddressBox* addressBox) {
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
	while(true) {
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
	addressBox->personArr[addressBox->total].name = name;
	addressBox->personArr[addressBox->total].age = age;
	addressBox->personArr[addressBox->total].sex = sex;
	addressBox->personArr[addressBox->total].phone = phone;
	addressBox->personArr[addressBox->total].address = address;
	addressBox->total++;
}

// 显示通讯录
void showAddressBox(AddressBox addressBox) {
	for (int i = 0; i < addressBox.total; i++) {
		string sex = addressBox.personArr[i].sex == 1 ? "女" : "男";
		cout << "姓名： " << addressBox.personArr[i].name
			<< " 性别： " << sex
			<< " 年龄： " << addressBox.personArr[i].age
			<< " 电话： " << addressBox.personArr[i].phone
			<< " 地址： " << addressBox.personArr[i].address
			<< endl;
	};
}

int main() {
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
				addAddressBox(&data);
				break;

			// 添加通讯录
			case 2:
				cout << "显示通讯录" << endl;
				showAddressBox(data);
				break;

			// 修改通讯录
			case 3:
				cout << "修改通讯录" << endl;
				break;

			// 删除通讯录
			case 4:
				cout << "删除通讯录" << endl;
				break;

			// 清空通讯录
			case 5:
				cout << "清空通讯录" << endl;
				break;

			// 退出通讯录
			case 0:
				cout << "退出通讯录" << endl;
				system("pause");
				return 0;
				break;

			// 无效值
			default:
				cout << "无效值，请重新输入" << endl;
				break;
		}
	}
	system("pause");
	return 0;
}