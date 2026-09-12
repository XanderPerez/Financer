#ifndef PAYMENTQUEUE_H
#define PAYMENTQUEUE_H

#include <iostream>
#include <string>

struct Payment {
	std::string name;
	double amount;
	Payment* next;
};

struct QueueNode {
	Payment* data;
	QueueNode* next;

	QueueNode(const Payment& p) 
		: data(new Payment(p)), next(nullptr) {}
	
	~QueueNode() { delete data; }
};

class PaymentQueue {

private:
	QueueNode* front;
	QueueNode* rear;

public:

	bool isEmpty() const {
		return front == nullptr;
	}

	PaymentQueue() {
		front = nullptr;
		rear = nullptr;
	}

	void Dequeue() {
		if (isEmpty()) {
			return;
		}

		QueueNode* temp = front;
		front = front->next;
		delete temp;

		if (front == nullptr) {
			rear = nullptr;
		}
	}

	~PaymentQueue() {
		while (!isEmpty()) {
			Dequeue();
		}
	}

};

#endif
