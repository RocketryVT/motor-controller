#include "stdafx.h"

#include "Assert.h"
#include "../Control.h"
#include <cmath>

unsigned int Test::resstriter = 0;
char Test::resstr[test_str_length] = { 0 };

/**
* Assertion function, with associated exception that it should throw
* This can be used in essentially the same way as the "assert" function in
* MATLAB
*/
struct Test::Failed_Assertion_Exception
{
	int i;
	Failed_Assertion_Exception(int ii) { i = ii; }
};

/**
* Notifies the user that the test has passed
*
* INPUTS
* const char* str -> Output message
*
* OUTPUTS
* bool -> The result of the input logical argument
*/
bool Test::passed(const char* str)
{
//	// Command line
//	std::cout << "PASSED: ";
//	std::cout << str;
//	printf("\n");

	// Fill Results String
	const char* passmsg = "<P>:";
	for (unsigned int i = 0; passmsg[i]; i++) {
		resstr[resstriter] = passmsg[i];
		resstriter++;
	}
	for (unsigned int i = 0; str[i]; i++) {
		resstr[resstriter] = str[i];
		resstriter++;
	}
	resstr[resstriter] = '\n';
	resstriter++;

	return true;
}

/**
* Notifies the user that the test has failed
*
* INPUTS
* const char* str -> Output message
*
* OUTPUTS
* bool -> The result of the input logical argument
*/
bool Test::failed(const char* str)
{
//	// Command line
//	std::cout << "FAILED: ";
//	std::cout << str;
//	printf("\n");

	// Fill Results String
	const char* passmsg = "<F>:";
	for (unsigned int i = 0; passmsg[i]; i++) {
		resstr[resstriter] = passmsg[i];
		resstriter++;
	}
	for (unsigned int i = 0; str[i]; i++) {
		resstr[resstriter] = str[i];
		resstriter++;
	}
	resstr[resstriter] = '\n';
	resstriter++;

	return true;
}

/**
* Debugger message
*
* INPUTS
* bool arg -> Logical argument to test
* const char* str -> Error message
* bool soft -> Soft fail flag, use false to keep from throwing an exception on failure
*
* OUTPUTS
* bool -> The result of the input logical argument
*/
bool Test::dmsg(const char* str)
{
//	std::cout << str << "\n";

	// Fill Results String
	for (unsigned int i = 0; str[i]; i++) {
		resstr[resstriter] = str[i];
		resstriter++;
	}
	resstr[resstriter] = '\n';
	resstriter++;

	return true;
}

/**
* Throws an exception and notifies the user that the assertion failed on the
* command line. It is left to the user to provide details of the failure and
* where it occured because I have no J-unit tests.
*
* INPUTS
* bool arg -> Logical argument to test
* const char* str -> Error message
* bool soft -> Soft fail flag, use false to keep from throwing an exception on failure
*
* OUTPUTS
* bool -> The result of the input logical argument
*/
bool Test::assert_true(bool arg, const char* str, bool hard_fail)
{
	if (!arg)
	{
		// Messages
		const char* assertionfailed = "<!>:";
		const char* testfield = "\tExpected b but was a";

//		// Command line
//		std::cout << assertionfailed;
//		printf(str);
//		printf("\n");

		// Fill Results String
		for (unsigned int i = 0; assertionfailed[i]; i++) { // ASSERTION FAILED
			resstr[resstriter] = assertionfailed[i];
			resstriter++;
		}
		for (unsigned int i = 0; str[i]; i++) { // MESSAGE
			resstr[resstriter] = str[i];
			resstriter++;
		}
		resstr[resstriter] = '\n';
		resstriter++;

		// Throw exception if it's supposed to hard stop
		if (hard_fail) throw Failed_Assertion_Exception(1);
	}
	return arg;
}

/**
* Throws an exception and notifies the user that the assertion failed on the
* command line. It is left to the user to provide details of the failure and
* where it occured because I have no J-unit tests.
*
* INPUTS
* long a -> First int a
* long a -> Second int b, expects this
* const char* str -> Error message
* bool soft -> Soft fail flag, use false to keep from throwing an exception on failure
*
* OUTPUTS
* bool -> The result of the input logical argument
*/
bool Test::assert_equals(long a, long b, const char* str, bool hard_fail)
{
	if (a != b)
	{
		// Messages
		const char* assertionfailed = "<!>:";
		const char* testfield = "\tExpected value but was another"; // TODO

//		// Command line
//		std::cout << assertionfailed;
//		std::cout << str;
//		std::cout << "\n\t" << "Expected " << b << " but was " << a;
//		printf("\n");

		// Fill Results String
		for (unsigned int i = 0; assertionfailed[i]; i++) { // ASSERTION FAILED
			resstr[resstriter] = assertionfailed[i];
			resstriter++;
		}
		for (unsigned int i = 0; str[i]; i++) { // MESSAGE
			resstr[resstriter] = str[i];
			resstriter++;
		}
		resstr[resstriter] = '\n';
		resstriter++;
		for (unsigned int i = 0; testfield[i]; i++) { // EXPECTED
			resstr[resstriter] = testfield[i];
			resstriter++;
		}
		resstr[resstriter] = '\n';
		resstriter++;

		// Throw exception if it's supposed to hard stop
		if (hard_fail) throw Failed_Assertion_Exception(1);
	}

	return a == b;
}

/**
* Throws an exception and notifies the user that the assertion failed on the
* command line. It is left to the user to provide details of the failure and
* where it occured because I have no J-unit tests.
*
* INPUTS
* double a -> First double argument
* double a -> Second double argument, expects this
* double prec -> Precision of equality
* const char* str -> Error message
* bool soft -> Soft fail flag, use false to keep from throwing an exception on failure
*
* OUTPUTS
* bool -> The result of the input logical argument
*/
bool Test::assert_equals(double a, double b, double prec, const char* str, bool hard_fail)
{
	if (std::abs(a - b) > prec)
	{
		// Messages
		const char* assertionfailed = "ASSERTION FAILED: ";
		const char* testfield = "\tExpected value but was another"; // TODO

//		// Command line
//		std::cout << assertionfailed;
//		std::cout << str;
//		std::cout << "\n\t";
//		std::cout << "Expected " << b << " but was " << a << std::endl;
		
		// Fill Results String
		for (unsigned int i = 0; assertionfailed[i]; i++) { // ASSERTION FAILED
			resstr[resstriter] = assertionfailed[i];
			resstriter++;
		}
		for (unsigned int i = 0; str[i]; i++) { // MESSAGE
			resstr[resstriter] = str[i];
			resstriter++;
		}
		resstr[resstriter] = '\n';
		resstriter++;
		for (unsigned int i = 0; testfield[i]; i++) { // EXPECTED
			resstr[resstriter] = testfield[i];
			resstriter++;
		}
		resstr[resstriter] = '\n';
		resstriter++;

		// Throw exception if it's supposed to hard stop
		if (hard_fail) throw Failed_Assertion_Exception(1);
	}
	return (std::abs(a - b) <= prec);
}
