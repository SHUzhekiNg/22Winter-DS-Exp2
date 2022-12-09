#ifndef __NODE_H__
#define __NODE_H__

struct AirId
{
	string Id, aplace, bplace;
	int ayear, amonth, aday, ahour, aminute, asecond, byear, bmonth, bday, bhour, bminute, bsecond;
	int SeatNum, EmptyNum, price;
};

struct Node 
{
	AirId data;
	Node *next;

	Node();
	Node(AirId item, Node *link = nullptr);
};

Node::Node()
{
   next = nullptr;
}

Node::Node(AirId item, Node *link)
{
   data = item;
   next = link;
}

#endif
