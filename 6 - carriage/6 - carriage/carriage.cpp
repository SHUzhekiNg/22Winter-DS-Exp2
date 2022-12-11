#include"SeqStack.h"

SeqStack<int> sta;

int main()
{
    int n, cnt = 1, x;
    int t;
    cout << "六、车厢调度" << endl << "请输入车厢数目：";
    cin >> n;
    cout << endl << "请输入排列顺序：" << endl;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        sta.Top(t);
        if (x == cnt) {
            cout << x << " to the platform" << endl;
            ++cnt;
        }
        else{
            sta.Push(x, sta);
        }
        while (t == cnt) {
            cout << t << " from sub to the platform" << endl;
            ++cnt;
            sta.Pop(t);
            sta.Top(t);
        }
    }
    cout << endl;
    if (sta.IsEmpty()) cout << "调度成功" << endl;
    else cout << "调度失败" << endl;
    return 0;
}
