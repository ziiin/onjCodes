#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<cctype>
#include<cstdlib>
using namespace std;

class EvaluateExpression {
        public:
                void insertOperator (char operatorChar);
                void insertOperand (int operand);
                int doOperation (int operand1, char operatorChar,
                                 int operand2);
                void popAndDoOperation ();
                int getPriority (char operatorChar);
                int evaluate ();
                void setExpression (string expression);
                EvaluateExpression ();
                EvaluateExpression (string expression);
        private:
                stack<char> operatorStack;
                stack<int> operandStack;
                string expression;
};

EvaluateExpression::EvaluateExpression () {
        expression = "";
}

EvaluateExpression::EvaluateExpression (string expression) {
        this->expression = "";
        this->expression +=expression;
}

void
EvaluateExpression::setExpression (string expression) {
        this->expression = "";
        this->expression = expression;
}

void
EvaluateExpression::insertOperator (char operatorChar) {
        operatorStack.push (operatorChar);
}

void
EvaluateExpression::insertOperand (int operand) {
        operandStack.push (operand);
}

int
EvaluateExpression::doOperation(int operand1, char operatorChar,
                                int operand2) {
        int ret;
        switch (operatorChar)
        {
                case '+': ret = operand1 + operand2;
                          break;
                case '-': ret = operand1 - operand2;
                          break;
                case '*': ret = operand1 * operand2;
                          break;
                case '/': ret = operand1 / operand2;
                          break;
                default:
                          break;
        }
        return ret;
}

void
EvaluateExpression::popAndDoOperation () {
        char operator1;
        int operand1;
        int operand2;
        int result;
        operator1 = operatorStack.top();
        operatorStack.pop();
        operand1 = operandStack.top();
        operandStack.pop();
        operand2 = operandStack.top();
        operandStack.pop();
        result = doOperation (operand2, operator1, operand1);
        operandStack.push (result);
}

int
EvaluateExpression::getPriority (char operatorChar) {
        int ret;
        switch (operatorChar)
        {
                case '(': ret = 1;
                           break;
                case '+':
                case '-': ret = 2;
                          break;
                case '/':
                case '*': ret = 3;
                          break;
                default :
                          break;

        }
        return ret;
}

int
EvaluateExpression::evaluate (){
        int     tempOperand;
        int     temp1;
        int     temp2;
        string  operandStr;

        for (int i = 0 ; i < expression.length() ; ++i) {
                operandStr = "";
                if (expression[i] == ' ')
                        continue;

                if (isdigit (expression[i])) {
                        while (isdigit (expression[i])) {
                                operandStr += expression[i];
                                i++;
                        }
                        tempOperand = atoi (operandStr.c_str());
                        insertOperand (tempOperand);
                        i--;
                }
                else if (expression[i] == '(') {
                        insertOperator (expression[i]);
                }
                else if (expression[i] == ')') {
                        while (operatorStack.top() != '(') {
                                popAndDoOperation();
                        }
                        operatorStack.pop();

                }
                else { /* default case of operators " * + / - " */
                        while ( !operatorStack.empty() ) {
                                temp1 = getPriority (operatorStack.top());
                                temp2 = getPriority (expression[i]);
                                if ( !(temp1 >= temp2) )
                                        break;
                                popAndDoOperation();
                        }
                        operatorStack.push (expression[i]);
                }
        } /*  end of expression iteration "for" */
        while (!operatorStack.empty()) {
                popAndDoOperation();
        }
        return operandStack.top();
}

int main(){
        int t;
        cin >>t;
        cin.get();
        while (t--){
                string s;
                getline(cin, s);
                EvaluateExpression exp(s);
                cout<<exp.evaluate()<<endl;
        }
}
