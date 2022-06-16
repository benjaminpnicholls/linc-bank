#pragma once
#include <vector>
#include <string>
#include "transaction.h"


class Account {
public:
	Account() {};
	~Account() {};
	virtual bool deposit(double Amount, int Ref = 0) = 0;
	virtual bool withdraw(double Amount, int Ref = 0) = 0;
	virtual std::string toString() const = 0;

protected:
	double m_Balance;
	std::vector<Transaction*> m_History;
	double m_OverdraftLimit = 0;
};


// Custom exceptions.

// Account exceptions.
struct NumberOfAccountsException : public std::exception {
public:
	NumberOfAccountsException() {}
	NumberOfAccountsException(const std::string &Message) {
		const char * c = Message.c_str();
		m_What = c;
	}
	virtual const char* what() const throw() {
		return m_What;
	}
private:
	const char* m_What = "ERROR: Incorrect number of accounts.";
};

struct AccountNumberOutOfRangeException : public std::exception {
public:
	AccountNumberOutOfRangeException() {}
	AccountNumberOutOfRangeException(const std::string &Message) {
		const char * c = Message.c_str();
		m_What = c;
	}
	virtual const char* what() const throw() {
		return m_What;
	}
private:
	const char* m_What = "ERROR: Account number specified out of range.";
};

struct MaxAccountException : public std::exception {
public:
	MaxAccountException() {}
	MaxAccountException(const std::string &Message) {
		const char * c = Message.c_str();
		m_What = c;
	}
	virtual const char* what() const throw() {
		return m_What;
	}
private:
	const char* m_What = "ERROR: You have opened the maximum number of account(s).";
};


// Number exceptions.
struct WrongTypeException : public std::exception {
public:
	WrongTypeException() {}
	WrongTypeException(const std::string &Message) {
		const char * c = Message.c_str();
		m_What = c;
	}
	virtual const char* what() const throw() {
		return m_What;
	}
private:
	const char* m_What = "ERROR: Value was not the correct type/format.";
};


// Parameters exceptions.
struct NotEnoughParametersException : public std::exception {
public:
	NotEnoughParametersException() {}
	NotEnoughParametersException(const std::string &Message) {
		const char * c = Message.c_str();
		m_What = c;
	}
	virtual const char* what() const throw() {
		return m_What;
	}
private:
	const char* m_What = "ERROR: You do not have enough parameters.";
};


// Deposit exceptions.
struct InitialDepositBelowRequiredException : public std::exception {
public:
	InitialDepositBelowRequiredException() {}
	InitialDepositBelowRequiredException(const std::string &Message) {
		const char * c = Message.c_str();
		m_What = c;
	}
	virtual const char* what() const throw() {
		return m_What;
	}
private:
	const char* m_What = "ERROR: Initial deposit below required amount.";
};


// Transaction exceptions.
struct WithdrawFailException : public std::exception {
public:
	WithdrawFailException() {}
	WithdrawFailException(const std::string &Message) {
		const char * c = Message.c_str();
		m_What = c;
	}
	virtual const char* what() const throw() {
		return m_What;
	}
private:
	const char* m_What = "ERROR: Could not withdraw from the account.";
};


// Other exceptions.
struct DynamicCastUnsuccessfulException : public std::exception {
public:
	DynamicCastUnsuccessfulException() {}
	DynamicCastUnsuccessfulException(const std::string &Message) {
		const char * c = Message.c_str();
		m_What = c;
	}
	virtual const char* what() const throw() {
		return m_What;
	}
private:
	const char* m_What = "ERROR: Dynamic cast unsuccessful. Check types.";
};

