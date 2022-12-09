#ifndef __LK_QUEUE_H__
#define __LK_QUEUE_H__

#include "Assistance.h"
#include "Node.h"

template<class ElemType>
class LinkQueue 
{
public:
	LinkQueue();
	~LinkQueue();
	int GetLength() const;			 
	bool IsEmpty() const;
	void Clear();
	void Traverse(void (*Visit)(const ElemType &)) const ;
	Status DelQueue(ElemType &e);
	Status GetHead(ElemType &e) const;
	Status EnQueue(const ElemType e);

private:
	Node* rear;
};

template<class ElemType>
LinkQueue<ElemType>::LinkQueue()
{
	rear = nullptr;
}
template<class ElemType>
LinkQueue<ElemType>::~LinkQueue()
{
	Clear();
    delete rear;		
}

template<class ElemType>
int LinkQueue<ElemType>::GetLength() const
{
	if (IsEmpty()) return 0;
	int count = 1;
	for (Node *p = rear->next; p != rear; p = p->next)
		count++;
	return count;
}

template<class ElemType>
bool LinkQueue<ElemType>::IsEmpty() const
{
	return rear == nullptr;
}

template<class ElemType>
void LinkQueue<ElemType>::Clear() 
{
	Node *p = rear;
	if (p == nullptr) return;
	if (p->next == rear)
	{
		delete rear;
		rear = nullptr;
		return;
	}
	else
	{
		p = rear->next; 
		while (p->next != rear)	{
			rear->next = p->next;
			delete p;        
			p = p->next;
		}
		delete p;
		delete rear;
		rear = nullptr;
	}
}

template <class ElemType>
void LinkQueue<ElemType>::Traverse(void (*Visit)(const ElemType &)) const 
{
	if (IsEmpty())
	{
		cout << "没有元素在队列中" << endl;
		return;
	}
	for (Node *p = rear->next; p != rear; p = p->next)
		(*Visit)(p->data);
	(*Visit)(rear->data);
}


template<class ElemType>
Status LinkQueue<ElemType>::DelQueue(ElemType &e)
{
	if (!IsEmpty()) {
		Node *p = rear;
		if (p->next == rear)
		{
			e = p->data;
			rear = nullptr;
			return SUCCESS;
		}
		Node* q = rear->next;
		rear->next = q->next;
		e = q->data;
		delete q;
		return SUCCESS;
	}
	else
		return UNDER_FLOW;
}

template<class ElemType>
Status LinkQueue<ElemType>::GetHead(ElemType &e) const
{

	if (!IsEmpty())
	{
		Node* p = rear;
		while (p->next != rear)
		{
			p = p->next;
		}
		e = p->data;
		return SUCCESS;
	}
	else
		return UNDER_FLOW;
}

template<class ElemType>
Status LinkQueue<ElemType>::EnQueue(const ElemType e)
{
	Node *p; 
    p = new Node(e);
	if (IsEmpty())
	{
		rear = p;
		rear->next = rear;
		return SUCCESS;
	}
    if (p) { 
		p->next = rear->next;
		rear->next = p;
		rear = p;
	    return SUCCESS;
    }
    else
		return OVER_FLOW;        
}


#endif
