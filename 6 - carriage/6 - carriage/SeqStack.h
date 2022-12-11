#ifndef __SQ_STACK_H__
#define __SQ_STACK_H__
#include "Assistance.h"

template<class ElemType>
class SeqStack 
{
public:
	SeqStack(int size = 99);
	~SeqStack();
	int GetLength() const;
	int GetMax() const;
	bool IsEmpty() const;
	void Clear();
	void Traverse(void (*Visit)(const ElemType &)) const;
	void Push(const ElemType e,SeqStack<ElemType> &sa);
	Status Top(ElemType &e) const;
	Status Pop(ElemType &e);
	SeqStack(const SeqStack<ElemType> &s);
	SeqStack<ElemType> &operator =(const SeqStack<ElemType> &s);

private:
	void stackfull(SeqStack<ElemType> &s);
	int top;
	int maxSize;
	ElemType* elems;
};


template<class ElemType>
void SeqStack<ElemType>::stackfull(SeqStack<ElemType> &s)
{
	int max = 2 * s.maxSize;
	SeqStack<ElemType> t(max);
	t.top = s.top;
	for (int i = 0; i <= s.top; i++)
		t.elems[i] = s.elems[i];
	s = t;
	cout << "扩栈成功" << endl;
	return;

}

template<class ElemType>
SeqStack<ElemType>::SeqStack(int size)
{
	maxSize = size;
	if (elems != nullptr) delete []elems;
	elems = new ElemType[maxSize];
	top = -1;	
}

template<class ElemType>
SeqStack<ElemType>::~SeqStack()
{
	delete []elems;
}

template <class ElemType>
int SeqStack<ElemType>::GetLength() const
{
	return top + 1;
}

template <class ElemType>
int SeqStack<ElemType>::GetMax() const
{
	return maxSize;
}

template<class ElemType>
bool SeqStack<ElemType>::IsEmpty() const
{
	return top == -1;
}

template<class ElemType>
void SeqStack<ElemType>::Clear()
{
	top = -1;
}

template <class ElemType>
void SeqStack<ElemType>::Traverse(void (*Visit)(const ElemType &)) const
{
	for (int i = top; i >=0 ; i--) 
		(*Visit)(elems[i]);
}

template<class ElemType>
void SeqStack<ElemType>::Push(const ElemType e,SeqStack<ElemType> &sa)
{
	if (top == maxSize - 1)	stackfull(sa);
	sa.elems[++top] = e;
	//cout << "操作成功" << endl;
	return;
}

template<class ElemType>
Status SeqStack<ElemType>::Top(ElemType &e) const
{
	if(IsEmpty())
		return UNDER_FLOW;
	else{
		e = elems[top];
		return SUCCESS;
	}
}

template<class ElemType>
Status SeqStack<ElemType>::Pop(ElemType &e)
{
	if (IsEmpty())
		return UNDER_FLOW;
	else{
		e = elems[top--];
		return SUCCESS;
	}
}

template<class ElemType>
SeqStack<ElemType>::SeqStack(const SeqStack<ElemType> &s) 
{
    maxSize = s.maxSize;
    if (elems != nullptr) delete []elems;
    elems = new ElemType[maxSize];
	top = s.top;
	for (int i = 0; i <= top; i++)
		elems[i] = s.elems[i];
}

template<class ElemType>
SeqStack<ElemType> &SeqStack<ElemType>::operator = (const SeqStack<ElemType> &s)
{
	if (&s != this)	{
		maxSize = s.maxSize;
	    if (elems != nullptr) delete []elems;
	    elems = new ElemType[maxSize];
		top = s.top;
		for (int i = 0; i <= top; i++)
			elems[i] = s.elems[i];
	}
	return *this;
}

#endif
