#pragma once
#include<string>
#include<set>

using namespace std;

enum class validatorresult {
	accept,
	reject,
	keepgoing
};

class Validator
{
protected:
	set<char> validdigits;
	set<char> validfirstdigit;
	unsigned int validlength = 1;
	virtual void initialize() {};
public:
	Validator() {
		initialize();
	};
	~Validator() {};

	virtual validatorresult IsValid(string tokens);
	virtual bool IsValidFirstDigit(char digit) { return validfirstdigit.count(digit) != 0; }
	virtual bool IsValidNonFirstDigit(char digit) { return validdigits.count(digit) != 0; }
	virtual bool IsValidLength(int n) { return n == validlength; }
};

class SevenDigitPhoneNumberValidator : public Validator
{
protected:
	virtual void initialize();
public:
	SevenDigitPhoneNumberValidator() {
		initialize();
	}
};

class TenDigitPhoneNumberValidator : public Validator
{
protected:
	virtual void initialize();
public:
	TenDigitPhoneNumberValidator() {
		initialize();
	}
};
