#include "SeqStack.h"

void func(string s);
int priority(char op);

int main()
{
    string str;
    cout << "五、中缀表达式转后缀表达式" << endl;
    cout << "请输入中缀表达式：" << endl;
    cin >> str;
    cout << "后缀表达式为：";
    func(str);
    cout << endl;
    return 0;
}

void func(string s) {
    SeqStack<char> sta;
    char ch;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9') cout << s[i];
        else
        {
            if(sta.IsEmpty()) sta.Push(s[i], sta);
            else if (s[i] == '(') sta.Push(s[i], sta);
            else if (s[i] == ')')
            {
                sta.Top(ch);
                while (ch != '(')
                {
                    cout << ch;
                    sta.Pop(ch);
                    sta.Top(ch);
                }
                sta.Pop(ch);
            }
            else
            {
                sta.Top(ch);
                while (priority(s[i]) <= priority(ch))
                { 
                    cout << ch;
                    sta.Pop(ch);
                    sta.Top(ch);
                    if (sta.IsEmpty()) break;
                }
                sta.Push(s[i],sta);
            }
        }
    }
    while (!sta.IsEmpty())
    {
        sta.Top(ch);
        cout << ch;
        sta.Pop(ch);
    }
    return;
}

int priority(char op)
{
    int p;
    if (op == '*' || op == '/') p = 2;
    if (op == '+' || op == '-') p = 1;
    if (op == '(') p = 0;
    return p;
}
