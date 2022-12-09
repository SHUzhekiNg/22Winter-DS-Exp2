#include "SeqStack.h"	// 顺序栈类

int main(void)
{
	char c = '1';
    SeqStack<CarRecord> sa;
    CarRecord x;
    while (c != '0')
	{
        cout << endl << "1. 生成栈.";
        cout << endl << "2. 显示栈.";
        cout << endl << "3. 入栈.";
        cout << endl << "4. 出栈.";
        cout << endl << "5. 取栈顶.";
		cout << endl << "6. 获取栈最大容量";
		cout << endl << "0. 退出";
		cout << endl << "选择功能(0~6):";
		cin >> c;
		switch (c) 	{
			case '1':
				sa.Clear();
				cout << "请输入车辆车牌号" << endl;
				while (cin >> x.id)
				{
					if (x.id != "0")
					{
						cout << "请输入车辆进入年份" << endl;
						cin >> x.year;
						cout << "请输入车辆进入月份" << endl;
						cin >> x.month;
						cout << "请输入车辆进入日期" << endl;
						cin >> x.day;
						cout << "请输入车辆进入时间（小时）" << endl;
						cin >> x.hour;
						cout << "请输入车辆进入时间（分钟）" << endl;
						cin >> x.minute;
						cout << "请输入车辆进入时间（秒）" << endl;
						cin >> x.second;
						cout << "继续输入新车辆信息" << endl;
						cout << "请输入车辆车牌号，如果要退出，输入0" << " ";
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
			   cout << "请依次输入车辆车牌号，进场的年、月、日、小时、分钟、秒" << endl;
			   cin >> x.id;
			   cin >> x.year >> x.month >> x.day >> x.hour >> x.minute >> x.second;
			   sa.Push(x, sa);
			   break;
           case '4':
			    if (sa.Pop(x) == SUCCESS)
			           cout << endl << "栈顶车牌号为：" << x.id << "." << endl;
                else
                       cout << endl << "栈为空。 " << endl;
			    break;
           case '5':
			    if (sa.Top(x) == SUCCESS)
			           cout << endl << "栈顶车牌号为：" << x.id << "." << endl;
                else
                       cout << endl << "栈为空。 " << endl;
			    break;
		   case '6':
			   cout << "最大容量为：" << sa.GetMax() << endl;
		}
	}

	//system("PAUSE"); 
	return 0;    
}


