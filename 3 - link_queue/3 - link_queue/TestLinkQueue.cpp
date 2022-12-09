#include "LinkQueue.h"

int main(void)
{
	char c = '1';
    LinkQueue<AirId> qa;
    AirId x;

    while (c != '0')
	{
        cout << endl << "1. 生成队列.";
        cout << endl << "2. 显示队列.";
        cout << endl << "3. 入队列.";
        cout << endl << "4. 出队列.";
        cout << endl << "5. 取队列头.";
		cout << endl << "0. 退出";
		cout << endl << "选择功能(0~5):";
		cin >> c;
		switch (c)		{
			case '1':
                qa.Clear(); 
				cout << endl << "输入e(航班号 = 0时退出)";
				while (1) {
					cout << "请输入航班号";
					cin >> x.Id;
					if (x.Id == "0") break;
					cout << "请输入起飞时间，年：";
					cin >> x.ayear;
					cout << "月：";
					cin >> x.amonth;
					cout << "日：";
					cin >> x.aday;
					cout << "时：";
					cin >> x.ahour;
					cout << "分：";
					cin >> x.aminute;
					cout << "秒：";
					cin >> x.asecond;
					cout << "请输入起飞地点：";
					cin >> x.aplace;
					cout << "请输入降落时间，年：";
					cin >> x.byear;
					cout << "月：";
					cin >> x.bmonth;
					cout << "日：";
					cin >> x.bday;
					cout << "时：";
					cin >> x.bhour;
					cout << "分：";
					cin >> x.bminute;
					cout << "秒：";
					cin >> x.bsecond;
					cout << "请输入降落地点：";
					cin >> x.bplace;
					cout << "请输入总座位数：";
					cin >> x.SeatNum;
					cout << "请输入机票价格：";
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
				cout << "请输入航班号";
				cin >> x.Id;
				cout << "请输入起飞时间，年：";
				cin >> x.ayear;
				cout << "月：";
				cin >> x.amonth;
				cout << "日：";
				cin >> x.aday;
				cout << "时：";
				cin >> x.ahour;
				cout << "分：";
				cin >> x.aminute;
				cout << "秒：";
				cin >> x.asecond;
				cout << "请输入起飞地点：";
				cin >> x.aplace;
				cout << "请输入降落时间，年：";
				cin >> x.byear;
				cout << "月：";
				cin >> x.bmonth;
				cout << "日：";
				cin >> x.bday;
				cout << "时：";
				cin >> x.bhour;
				cout << "分：";
				cin >> x.bminute;
				cout << "秒：";
				cin >> x.bsecond;
				cout << "请输入降落地点：";
				cin >> x.bplace;
				cout << "请输入总座位数：";
				cin >> x.SeatNum;
				cout << "请输入机票价格：";
				cin >> x.price;
			    qa.EnQueue(x);
			    break;
           case '4':
			   if (qa.DelQueue(x) == UNDER_FLOW)
			   {
				   cout << "没元素";
			   }
			   else {
					cout << endl << "队头飞机航班号为 " << x.Id << " ." << endl;
			   }
			    break;
           case '5':
			   if (qa.GetHead(x) == UNDER_FLOW)
			   {
				   cout << "没元素";
			   }
			   else {
				   cout << endl << "队头飞机航班号为 " << x.Id << " ." << endl;
			   }
			    break;
		}
	}

	system("PAUSE");
	return 0; 
}


