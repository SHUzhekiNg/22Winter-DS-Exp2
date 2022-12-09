#include "seqstack.h"
int main(void)
{
	char c = '1';
	SeqStack<int> sa;
	int x,i;

	while (c != '0')
	{
		cout << endl << "1. 生成栈.";
		cout << endl << "2. 显示栈.";
		cout << endl << "3. 入栈.";
		cout << endl << "4. 出栈.";
		cout << endl << "5. 取栈顶.";
		cout << endl << "6. 获取长度.";
		cout << endl << "0. 退出";
		cout << endl << "选择功能(0~6):";
		cin >> c;
		switch (c) {
		case '1':
			sa.Clear();
			cout << "请选择需要操作的栈：" << endl;
			cin >> i;
			cout << "输入e(e = 0时退出)" << endl;
			cin >> x;
			while (x != 0) {
				sa.Push(i,x);
				cin >> x;
			}
			break;
		case '2':
			cout << endl;
			cout << "请输入您想要遍历的栈：" << endl;
			cin >> i;
			sa.Traverse(i,Write<int>);
			break;
		case '3':
			cout << "输入您要入的栈：" << endl;
			cin >> i;
			cout << endl << "输入元素值:";
			cin >> x;
			if (sa.Push(i,x) == SUCCESS)
				cout << endl << "入栈成功." << endl;
			else
				cout << endl << "空间不够，入栈失败." << endl;
			break;
		case '4':
			cout << "输入您要操作的栈：" << endl;
			cin >> i;
			if (sa.Pop(i,x) == SUCCESS)
				cout << endl << "栈顶元素值为：" << x << "." << endl;
			else
				cout << endl << "栈为空。 " << endl;
			break;
		case '5':
			cout << "输入您要查询的栈：" << endl;
			cin >> i;
			if (sa.Top(i,x) == SUCCESS)
				cout << endl << "栈顶元素值为：" << x << "." << endl;
			else
				cout << endl << "栈为空。 " << endl;
			break;
		case '6':
			cout << "输入您要查询的栈：" << endl;
			cin >> i;
			cout << sa.GetLength(i) << endl;
			break;
		}
	}
	return 0;
}