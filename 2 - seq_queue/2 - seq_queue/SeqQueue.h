#ifndef __SQ_QUEUE_H__
#define __SQ_QUEUE_H__
#include "Assistance.h"	// ¸¨ÖúÈí¼þ°ü

template<class ElemType>
class SeqQueue 
{
public:
	SeqQueue(int size = DEFAULT_SIZE);
	~SeqQueue();
	int GetLength() const;			 
	bool IsEmpty() const;
	void Clear();
	void Traverse(void (*Visit)(const ElemType &)) const;
	Status DelQueue(ElemType &e);
	Status GetHead(ElemType &e) const;
	Status EnQueue(const ElemType e);
	SeqQueue(const SeqQueue<ElemType> &q);
	SeqQueue<ElemType> &operator =(const SeqQueue<ElemType> &q);

private:
	int front, length;
	int maxSize;
	ElemType* elems;
};


template<class ElemType>
SeqQueue<ElemType>::SeqQueue(int size)
{
	maxSize = size;
	if (elems != nullptr) delete []elems;
	elems = new ElemType[maxSize];
	length = front = 0;
}

template <class ElemType>
SeqQueue<ElemType>::~SeqQueue()
{
	delete []elems;
}

template<class ElemType>
int SeqQueue<ElemType>::GetLength() const
{
	return length;
}

template<class ElemType>
bool SeqQueue<ElemType>::IsEmpty() const
{
   return length == 0;
}

template<class ElemType>
void SeqQueue<ElemType>::Clear() 
{
	length = 0;
}

template <class ElemType>
void SeqQueue<ElemType>::Traverse(void (*Visit)(const ElemType &)) const
{
	for (int i = 0; i < length; i++)
		(*Visit)(elems[front+i]);
}


template<class ElemType>
Status SeqQueue<ElemType>::DelQueue(ElemType &e)
{
	if (!IsEmpty()){
		e = elems[front];
		front++;
		front = front % maxSize;
		length--;
		return SUCCESS;
	}
	else
		return UNDER_FLOW;
}

template<class ElemType>
Status SeqQueue<ElemType>::GetHead(ElemType &e) const
{
	if (!IsEmpty()){
		e = elems[front];
		return SUCCESS;
	}
	else
		return UNDER_FLOW;
}

template<class ElemType>
Status SeqQueue<ElemType>::EnQueue(const ElemType e)
{
	if (length == maxSize)
		return OVER_FLOW;
	else{
		elems[(front+length)%maxSize] = e;
		length++;
		return SUCCESS;
	}
}

template<class ElemType>
SeqQueue<ElemType>::SeqQueue(const SeqQueue<ElemType> &q)
{
    maxSize = q.maxSize;
    if (elems != nullptr) delete []elems;
    elems = new ElemType[maxSize];
	front = q.front;
	length = q.length;
	for (int i = 0; i < length; i++)
		elems[i] = q.elems[i];
}

template<class ElemType>
SeqQueue<ElemType> &SeqQueue<ElemType>::operator =(const SeqQueue<ElemType> &q)
{
	if (&q != this)	{
        maxSize = q.maxSize;
	    if (elems != nullptr) delete []elems;
	    elems = new ElemType[maxSize];
		front = q.front;
		length = q.length;
		for (int i = 0 ;i < length; i++)
			elems[i] = q.elems[i];
	}
	return *this;
}

#endif
