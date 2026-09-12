#ifndef PAYMENTREMINDER_H
#define PAYMENTREMINDER_H

#include <iostream>
#include <string>

// PaymentReminder class definition
class PaymentReminder {

private:

	int reminderDays;
	bool showOverDuePayments;
	bool showDueToday;

public:

	// Constructor
	PaymentReminder() {
		reminderDays = 7; // Default reminder days
		showOverDuePayments = true; // Default to show overdue payments
		showDueToday = true; // Default to show due today payments
	}

	// Getter for reminderDays
	void setReminderDays(int days) {
		reminderDays = days;
	}

	void

};

#endif
