#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer {
	private:
		int id;
		int startTime;
	public:
		Customer(int = -1, int = -1);
		int getId() const;
		int getStartTime() const;
};

#endif