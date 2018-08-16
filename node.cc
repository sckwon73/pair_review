// Copyright 2018 <Author>

#include "node.h"

Node::Node(char data) {
	_data = data;
	_prev = nullptr;
	_next = nullptr;
}

char Node::GetData() {
	
	return _data;
}

Node* Node::GetPreviousNode() {
	return _prev;
}

Node* Node::GetNextNode() {
	return _next;
}

Node* Node::InsertPreviousNode(char data) {
	Node *prevNode;
	Node *newNode;

	newNode = new Node(data);
	if (newNode == nullptr)
		return nullptr;

	prevNode = _prev;

	if (prevNode == nullptr){
		_prev = newNode;
		newNode->_next = this;
	}else{
		prevNode = _prev;
		prevNode->_next = newNode;

		newNode->_prev = prevNode;
		newNode->_next = this;

		_prev = newNode;
	}
  return newNode;
}

Node* Node::InsertNextNode(char data) {

	Node *nextNode;
	Node *newNode;

	newNode = new Node(data);
	if (newNode == nullptr)
		return nullptr;

	nextNode = _next;
	_next = newNode;
	newNode->_prev = this;
	if (nextNode != nullptr){
		newNode->_next = nextNode;
		nextNode->_prev = newNode;
	}

  return newNode;
}

bool Node::ErasePreviousNode() {

	Node* prevNode;

	prevNode = _prev;
	if (prevNode == nullptr)
		return false;

	if (prevNode->_prev != nullptr){
		_prev = prevNode->_prev;
		_prev->_next = this;
	}else{
		_prev = nullptr;
	}
	delete prevNode;

	
  return true;
}

bool Node::EraseNextNode() {
	Node* nextNode;

	nextNode = _next;
	if (nextNode == nullptr)
		return false;

	if (nextNode->_next != nullptr){
		_next = nextNode->_next;
		_next->_prev = this;
	}
	else{
		_next = nullptr;
	}

	delete nextNode;

  return true;
}
