//Logan Praylow
#ifndef CALCULATE_H
#define CALCULATE_H

#include <string>
#include <stack>

class Calculate {
public:
    Calculate();
    //calculates results of the operations
    double calculateExpression(const std::string& expression);

private:
    //checks if user inputed operators
    bool isOperator(char op);
    //assigns of op
    int getOperatorPriority(char op);
    //perfroms order of op
    double applyOperation(double operand1, double operand2, char op);
};

#endif

