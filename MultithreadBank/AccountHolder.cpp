#include "AccountHolder.h"

AccountHolder::AccountHolder() {
	this->name = "Ivan";
	this->surname = "Petrov";
	this->credit_rate = 5;
	this->registration_date = "27.02.2020";
}
AccountHolder::AccountHolder(string name, string surname, int credit_rate) {
	this->name = name;
	this->surname = surname;
	this->credit_rate = credit_rate <= 10 ? credit_rate : 5;

	time_t now;
	time(&now);
	struct tm timeinfo;
	localtime_s(&timeinfo, &now);
	char formatted_date[50];
	strftime(formatted_date, sizeof(formatted_date), "%Y-%m-%d %H:%M:%S", &timeinfo);
	this->registration_date = formatted_date;
}
string AccountHolder::getName()const {
	return this->name;
};
string AccountHolder::getSurname()const {
	return this->surname;
}
int AccountHolder::getCreditRate()const
{
	return this->credit_rate;
};
string AccountHolder::getRegistrationDate()const
{
	return this->registration_date;
};
AccountHolder::~AccountHolder() {};
