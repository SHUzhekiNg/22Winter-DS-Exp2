#include "LinkQueue.h"

int main(void)
{
	char c = '1';
    LinkQueue<AirId> qa;
    AirId x;

    while (c != '0')
	{
        cout << endl << "1. ���ɶ���.";
        cout << endl << "2. ��ʾ����.";
        cout << endl << "3. �����.";
        cout << endl << "4. ������.";
        cout << endl << "5. ȡ����ͷ.";
		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~5):";
		cin >> c;
		switch (c)		{
			case '1':
                qa.Clear(); 
				cout << endl << "����e(����� = 0ʱ�˳�)";
				while (1) {
					cout << "�����뺽���";
					cin >> x.Id;
					if (x.Id == "0") break;
					cout << "���������ʱ�䣬�꣺";
					cin >> x.ayear;
					cout << "�£�";
					cin >> x.amonth;
					cout << "�գ�";
					cin >> x.aday;
					cout << "ʱ��";
					cin >> x.ahour;
					cout << "�֣�";
					cin >> x.aminute;
					cout << "�룺";
					cin >> x.asecond;
					cout << "��������ɵص㣺";
					cin >> x.aplace;
					cout << "�����뽵��ʱ�䣬�꣺";
					cin >> x.byear;
					cout << "�£�";
					cin >> x.bmonth;
					cout << "�գ�";
					cin >> x.bday;
					cout << "ʱ��";
					cin >> x.bhour;
					cout << "�֣�";
					cin >> x.bminute;
					cout << "�룺";
					cin >> x.bsecond;
					cout << "�����뽵��ص㣺";
					cin >> x.bplace;
					cout << "����������λ����";
					cin >> x.SeatNum;
					cout << "�������Ʊ�۸�";
					cin >> x.price;
					x.EmptyNum = x.SeatNum;
					qa.EnQueue(x);
				}
				break;
	       case '2':
				cout << endl;
			    qa.Traverse(Write);
				break;
		   case '3':
				cout << "�����뺽���";
				cin >> x.Id;
				cout << "���������ʱ�䣬�꣺";
				cin >> x.ayear;
				cout << "�£�";
				cin >> x.amonth;
				cout << "�գ�";
				cin >> x.aday;
				cout << "ʱ��";
				cin >> x.ahour;
				cout << "�֣�";
				cin >> x.aminute;
				cout << "�룺";
				cin >> x.asecond;
				cout << "��������ɵص㣺";
				cin >> x.aplace;
				cout << "�����뽵��ʱ�䣬�꣺";
				cin >> x.byear;
				cout << "�£�";
				cin >> x.bmonth;
				cout << "�գ�";
				cin >> x.bday;
				cout << "ʱ��";
				cin >> x.bhour;
				cout << "�֣�";
				cin >> x.bminute;
				cout << "�룺";
				cin >> x.bsecond;
				cout << "�����뽵��ص㣺";
				cin >> x.bplace;
				cout << "����������λ����";
				cin >> x.SeatNum;
				cout << "�������Ʊ�۸�";
				cin >> x.price;
			    qa.EnQueue(x);
			    break;
           case '4':
			   if (qa.DelQueue(x) == UNDER_FLOW)
			   {
				   cout << "ûԪ��";
			   }
			   else {
					cout << endl << "��ͷ�ɻ������Ϊ " << x.Id << " ." << endl;
			   }
			    break;
           case '5':
			   if (qa.GetHead(x) == UNDER_FLOW)
			   {
				   cout << "ûԪ��";
			   }
			   else {
				   cout << endl << "��ͷ�ɻ������Ϊ " << x.Id << " ." << endl;
			   }
			    break;
		}
	}

	system("PAUSE");
	return 0; 
}


