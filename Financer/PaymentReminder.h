#ifndef PAYMENTREMINDER_H
#define PAYMENTREMINDER_H

#include <iostream>
#include <string>

// PaymentReminder class definition
class PaymentReminder {

private:

	// Member variables
	int reminderDays;
	bool showOverduePayments;
	bool showDueToday;
	int gracePeriod;
	double lateFee;

public:

	// Constructor
	PaymentReminder (int days,bool overdue, bool dueToday, int grace, double fee) {
		
		reminderDays = (days >= 0) ? days : 3; // Default reminder days
		showOverduePayments = overdue; // Default to show overdue payments
		showDueToday = dueToday; // Default to show due today payments
		gracePeriod = (grace >= 0) ? grace : 0; // Default grace period
		lateFee = (fee >= 0) ? fee : 0.0; // Default late fee
	}

	// Changes how many days before a bill is due that a reminder is sent. Default is 3 days.
	bool setReminderDays (int days) {
		
		if (days < 1 || days > 30) {
			std::cout << "\nReminder days must be between 1 and 31\n";
			return false;
		}

		reminderDays = days;
		return true;
	}

	// Changes whether overdue payments are shown in the reminder. Default is true.
	void setShowOverDuePayments (bool choice) {
		
		showOverduePayments = choice;
	}

	void setShowDueDates (bool choice) {
		
		showDueToday = choice;
	}

	// Changes the grace period for late payments. Default is 0 days.
	bool setGracePeriod (int days) {
		
		if (days < 1 || days > 31) {
			std::cout << "\nGrace period must be between 1 and 31 days.\n";
			return false;
		}

		gracePeriod = days;
		return true;
	}

	// Changes the late fee for overdue payments. Default is 0.0.
	bool setLateFee (double fee) {

		if (fee < 0) {
			std::cout << "\nLate fee cannot be negative\n";
			return false;
		}

		lateFee = fee;
		return true;
	}

	void checkReminder(std::string paymentName, double amount,
		int dueDay, int currDay) {

		// Checkes for invalid information
		if (paymentName.empty() || amount <= 0) {
			std::cout << "\nInvalid payment information\n";
			return;
		}

		// Checks for invalid days
		if (dueDay < 1 || dueDay > 31 || currDay < 1 || currDay > 31) {
			std::cout << "\nInvalid day entered.\n";
			return;
		}
	
		// payment is overdue
		if (currDay > dueDay + gracePeriod) {
			if (showOverduePayments) {
				std::cout << "\nPayment " << paymentName << " of $" << amount
					<< " is overdue. Late fee applied: $" << lateFee << "\n";
			}
		}

		// Payment is due today
		else if (currDay == dueDay) {
			if (showDueToday) {
				std::cout << "\nPayment " << paymentName << " of $" << amount
					<< " is due today." << " Amount owed: $" << amount << "\n";
			}
		}

		// Payment passed due date but is still in grace period
		else if (currDay > dueDay) {
			std::cout << "\nPayment " << paymentName << " of $" << amount
				<< " is past due but still in grace period. No late fee applied.\n";
		}

		// Payment is due soon
		else if (currDay >= dueDay - reminderDays && currDay < dueDay) {
			std::cout << "\nPayment " << paymentName << " of $" << amount
				<< " is due in " << (dueDay - currDay) << " days.\n";
		}

		// No reminder needed
		else {
			std::cout << "\nNo reminder needed for payment " << paymentName << ".\n";
		}
	}

};

#endif

