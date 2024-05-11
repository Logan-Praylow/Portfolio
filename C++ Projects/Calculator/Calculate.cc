//Logan Praylow
#include "Calculate.h"
#include <iostream>
#include <sstream>
#include <cctype>
#include <stdexcept>

Calculate::Calculate() {}

//check if user actaully inputed operators
bool Calculate::isOperator(char op) {
    return (op == '+' || op == '-' || op == '*' || op == '/');
}

//assigns priority to operators
int Calculate::getOperatorPriority(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    return 0; 
}

//perfroms the function of each operator and stops divison by zero
double Calculate::applyOperation(double operand1, double operand2, char op) {
    switch (op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 != 0)
                return operand1 / operand2;
            else
                throw std::invalid_argument("Division by zero");
        default:
            throw std::invalid_argument("Invalid operator");
    }
}

//Calculates Results
double Calculate::calculateExpression(const std::string &expression) {
    std::stack<double> operandStack;
    std::stack<char> operatorStack;

    std::istringstream iss(expression);

    double number;
    char op;

    while (iss >> number) {
        operandStack.push(number);

        // Check for an operator after each number
        if (iss >> op ) {

	    // Handles negative numbers
            if (op == '-' ) {
                double nextNumber;
                 if (iss >> nextNumber) {
        // If the previous token is not an operator, treat '-' as addition with a negative number
        if (!operatorStack.empty() && !isOperator(operatorStack.top())) {
            operandStack.push(-nextNumber);
        } else {
            // Otherwise, treat '-' as subtraction
            operandStack.push(nextNumber);
            operatorStack.push('-');
        }
                } else {
                    throw std::invalid_argument("Invalid input after unary minus");
                }
            } else {

        // Process the operator
	while (!operatorStack.empty() && getOperatorPriority(op) <= getOperatorPriority(operatorStack.top())) {
                double operand2 = operandStack.top();
                operandStack.pop();

                double operand1 = operandStack.top();
                operandStack.pop();

                char currentOp = operatorStack.top();
                operatorStack.pop();

                operandStack.push(applyOperation(operand1, operand2, currentOp));
            }

            operatorStack.push(op);
	    }
        }
    }

    // Process any remaining operators
    while (!operatorStack.empty()) {
        double operand2 = operandStack.top();
        operandStack.pop();

        double operand1 = operandStack.top();
        operandStack.pop();

        char currentOp = operatorStack.top();
        operatorStack.pop();

        operandStack.push(applyOperation(operand1, operand2, currentOp));
    }

    if (operandStack.size() == 1 && operatorStack.empty()) {
        return operandStack.top();
    }else if (operandStack.empty() && operatorStack.size() == 1 && operatorStack.top() == '-') {
        return operandStack.top(); // Handles cases where the expression ends with a negative number
    }
    else {
        throw std::invalid_argument("Invalid input");
    }
}


  

