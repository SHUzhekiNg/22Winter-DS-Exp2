#include "SeqStack.h"	// ˳��ջ��

int main(void)
{
	char c = '1';
    SeqStack<CarRecord> sa;
    CarRecord x;
    while (c != '0')
	{
        cout << endl << "1. ����ջ.";
        cout << endl << "2. ��ʾջ.";
        cout << endl << "3. ��ջ.";
        cout << endl << "4. ��ջ.";
        cout << endl << "5. ȡջ��.";
		cout << endl << "6. ��ȡջ�������";
		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~6):";
		cin >> c;
		switch (c) 	{
			case '1':
				sa.Clear();
				cout << "�����복�����ƺ�" << endl;
				while (cin >> x.id)
				{
					if (x.id != "0")
					{
						cout << "�����복���������" << endl;
						cin >> x.year;
						cout << "�����복�������·�" << endl;
						cin >> x.month;
						cout << "�����복����������" << endl;
						cin >> x.day;
						cout << "�����복������ʱ�䣨Сʱ��" << endl;
						cin >> x.hour;
						cout << "�����복������ʱ�䣨���ӣ�" << endl;
						cin >> x.minute;
						cout << "�����복������ʱ�䣨�룩" << endl;
						cin >> x.second;
						cout << "���������³�����Ϣ" << endl;
						cout << "�����복�����ƺţ����Ҫ�˳�������0" << " ";
					}
					else {
						break;
					}
					sa.Push(x ,sa);
				}
				break;
	       case '2':
				cout << endl;
			    sa.Traverse(Write);
				break;
		   case '3':
			   cout << "���������복�����ƺţ��������ꡢ�¡��ա�Сʱ�����ӡ���" << endl;
			   cin >> x.id;
			   cin >> x.year >> x.month >> x.day >> x.hour >> x.minute >> x.second;
			   sa.Push(x, sa);
			   break;
           case '4':
			    if (sa.Pop(x) == SUCCESS)
			           cout << endl << "ջ�����ƺ�Ϊ��" << x.id << "." << endl;
                else
                       cout << endl << "ջΪ�ա� " << endl;
			    break;
           case '5':
			    if (sa.Top(x) == SUCCESS)
			           cout << endl << "ջ�����ƺ�Ϊ��" << x.id << "." << endl;
                else
                       cout << endl << "ջΪ�ա� " << endl;
			    break;
		   case '6':
			   cout << "�������Ϊ��" << sa.GetMax() << endl;
		}
	}

	//system("PAUSE"); 
	return 0;    
}


