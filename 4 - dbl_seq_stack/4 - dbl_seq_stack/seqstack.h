#ifndef __SQ_STACK_H__
#define __SQ_STACK_H__
#include "assistance.h"

template<class ElemType>
class SeqStack
{
public:
	SeqStack(int size = 10);
	virtual ~SeqStack();
	int GetLength(const int i) const;	 
	bool IsEmpty() const;
	void Clear();
	void Traverse(const int i,void (*Visit)(const ElemType&)) const;
	Status Push(const int i,const ElemType e);
	Status Top(const int i,ElemType& e) const;
	Status Pop(const int i,ElemType& e);

private:
	int top, bottom;
	int maxSize;
	ElemType* elems;
};


template<class ElemType>
SeqStack<ElemType>::SeqStack(int size)
{
	maxSize = size;
	if (elems != NULL) delete[]elems;
	elems = new ElemType[maxSize];
	top = -1;
	bottom = maxSize;
}

template<class ElemType>
SeqStack<ElemType>::~SeqStack()
{
	delete[]elems;
}

template <class ElemType>
int SeqStack<ElemType>::GetLength(const int i) const
{
	if (i == 1) return top + 1;
	if (i == 2) return maxSize - bottom;
}

template<class ElemType>
bool SeqStack<ElemType>::IsEmpty() const
{
	return (top == -1 && bottom == maxSize);
}

template<class ElemType>
void SeqStack<ElemType>::Clear()
{
	top = -1;
	bottom = maxSize;
}

template <class ElemType>
void SeqStack<ElemType>::Traverse(const int p,void (*Visit)(const ElemType&)) const
{
	if (p == 1)
	{
		for (int i = top; i >= 0; i--)
			(*Visit)(elems[i]);
	}
	else if (p == 2)
	{
		for (int i = bottom; i < maxSize; i++)
			(*Visit)(elems[i]);
	}
}

template<class ElemType>
Status SeqStack<ElemType>::Push(const int i,const ElemType e)
{
	if (top == bottom - 1) return OVER_FLOW;
	if (i == 1)
	{
		elems[++top] = e;
		return SUCCESS;
	}
	if (i == 2)
	{
		elems[--bottom] = e;
		return SUCCESS;
	}
}

template<class ElemType>
Status SeqStack<ElemType>::Top(const int i,ElemType& e) const
{
	if (IsEmpty())
		return UNDER_FLOW;
	if (i == 1)
	{
		e = elems[top];
		return SUCCESS;
	}
	else if (i == 2)
	{
		e = elems[bottom];
		return SUCCESS;
	}
}

template<class ElemType>
Status SeqStack<ElemType>::Pop(const int i,ElemType& e)
{
	if (IsEmpty())
		return UNDER_FLOW;
	if (i == 1)
	{
		e = elems[top--];
		return SUCCESS;
	}
	else if (i == 2)
	{
		e = elems[bottom++];
		return SUCCESS;
	}
}

#endif
