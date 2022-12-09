#include "seqstack.h"
int main(void)
{
	char c = '1';
	SeqStack<int> sa;
	int x,i;

	while (c != '0')
	{
		cout << endl << "1. ����ջ.";
		cout << endl << "2. ��ʾջ.";
		cout << endl << "3. ��ջ.";
		cout << endl << "4. ��ջ.";
		cout << endl << "5. ȡջ��.";
		cout << endl << "6. ��ȡ����.";
		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~6):";
		cin >> c;
		switch (c) {
		case '1':
			sa.Clear();
			cout << "��ѡ����Ҫ������ջ��" << endl;
			cin >> i;
			cout << "����e(e = 0ʱ�˳�)" << endl;
			cin >> x;
			while (x != 0) {
				sa.Push(i,x);
				cin >> x;
			}
			break;
		case '2':
			cout << endl;
			cout << "����������Ҫ������ջ��" << endl;
			cin >> i;
			sa.Traverse(i,Write<int>);
			break;
		case '3':
			cout << "������Ҫ���ջ��" << endl;
			cin >> i;
			cout << endl << "����Ԫ��ֵ:";
			cin >> x;
			if (sa.Push(i,x) == SUCCESS)
				cout << endl << "��ջ�ɹ�." << endl;
			else
				cout << endl << "�ռ䲻������ջʧ��." << endl;
			break;
		case '4':
			cout << "������Ҫ������ջ��" << endl;
			cin >> i;
			if (sa.Pop(i,x) == SUCCESS)
				cout << endl << "ջ��Ԫ��ֵΪ��" << x << "." << endl;
			else
				cout << endl << "ջΪ�ա� " << endl;
			break;
		case '5':
			cout << "������Ҫ��ѯ��ջ��" << endl;
			cin >> i;
			if (sa.Top(i,x) == SUCCESS)
				cout << endl << "ջ��Ԫ��ֵΪ��" << x << "." << endl;
			else
				cout << endl << "ջΪ�ա� " << endl;
			break;
		case '6':
			cout << "������Ҫ��ѯ��ջ��" << endl;
			cin >> i;
			cout << sa.GetLength(i) << endl;
			break;
		}
	}
	return 0;
}