#include "RPN.hpp"


RPN::RPN()
{
}

RPN::RPN(RPN const &src): stack(src.stack)
{
}

RPN	&RPN::operator=(RPN const &src)
{
	if (this != &src) {
		stack = src.stack;
	}
	return (*this);
}

static void add(std::stack<int> &stack)
{
	if (stack.size() < 2) {
		throw (std::invalid_argument("Error: Not enough operands for addition."));
	}
	int a = stack.top(); stack.pop();
	int b = stack.top(); stack.pop();
	stack.push(b + a);
}

static void subtract(std::stack<int> &stack)
{
	if (stack.size() < 2) {
		throw (std::invalid_argument("Error: Not enough operands for subtraction."));
	}
	int a = stack.top(); stack.pop();
	int b = stack.top(); stack.pop();
	stack.push(b - a);
}

static void multiply(std::stack<int> &stack)
{
	if (stack.size() < 2) {
		throw (std::invalid_argument("Error: Not enough operands for multiplication."));
	}
	int a = stack.top(); stack.pop();
	int b = stack.top(); stack.pop();
	stack.push(b * a);
}

static void divide(std::stack<int> &stack) {
	if (stack.size() < 2) {
		throw (std::invalid_argument("Error: Not enough operands for division."));
	}
	int a = stack.top(); stack.pop();
	int b = stack.top(); stack.pop();
	if (a == 0) {
		throw (std::invalid_argument("Error: Division by zero."));
	}
	stack.push(b / a);
}


void RPN::compute(std::string const &expression)
{
	try {
		std::istringstream stream(expression);
		std::string token;
		while (stream >> token) {
			if (isdigit(token[0])) {
				int num = std::atoi(token.c_str());
				if (num > 9) {
					throw (std::invalid_argument("Invalid token: " + token));
				}
				stack.push(num);
			} else if (token == "+") {
				add(stack);
			} else if (token == "-") {
				subtract(stack);
			} else if (token == "*") {
				multiply(stack);
			} else if (token == "/") {
				divide(stack);
			} else {
				throw (std::invalid_argument("Invalid token: " + token));
			}
		}
		if (!stack.empty()) {
			std::cout << "Result: " << stack.top() << std::endl;
		}
		else {
			throw (std::invalid_argument("Error: No result in stack."));
		}
	} catch (const std::invalid_argument &e) {
		std::cerr << e.what() << std::endl;
	}
	while (!stack.empty()) {
		stack.pop();
	}
}

RPN::~RPN()
{
}