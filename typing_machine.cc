// Copyright 2018 <Author>

#include "typing_machine.h"

#define MAX_CNT	100

TypingMachine::TypingMachine() {
	_start = new Node(' ');
	_cur = _start;
	_cnt = 0;
}

void TypingMachine::HomeKey() {
	_cur = _start;
}

void TypingMachine::EndKey() {
	Node *node;

	node = _cur;
	while (1) {
		if (node->GetNextNode() == nullptr)
			break;
		node = node->GetNextNode();
	} 
	_cur = node;

}

void TypingMachine::LeftKey() {
	Node *prevNode;

	prevNode = _cur->GetPreviousNode();
	if (prevNode == nullptr)
		return;

	_cur = prevNode;
}

void TypingMachine::RightKey() {
	Node *nextNode;
	
	nextNode = _cur->GetNextNode();
	if (nextNode == nullptr)
		return;
	_cur = nextNode;

  return;
}

bool TypingMachine::TypeKey(char key) {

	Node * curNode;

	if  ( (key < 32) || (key >126) )
		return false;

	if (_cnt >= MAX_CNT)
		return false;

	curNode= _cur->InsertNextNode(key);
	if (curNode == nullptr)
		return false;

	_cnt++;
	
	_cur = curNode;

   return true;
}

bool TypingMachine::EraseKey() {
	
	if (_cur == _start)
		return false;

	_cur = _cur->GetPreviousNode();

	_cur->EraseNextNode();
	_cnt--;

	return true;
}

std::string TypingMachine::Print(char separator) {
	std::string outString;
	Node *node;

	if  ( (_cur == _start) && (separator != 0) )
	{
		outString += separator;
	}

	node = _start->GetNextNode();

	while (node != nullptr){
		outString += node->GetData();
		if ((node == _cur) && (separator != 0))  {
			outString += separator;
		}
		node = node->GetNextNode();
	} 

	return outString;
}
