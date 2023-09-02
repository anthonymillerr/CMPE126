#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Expression {
private:
    string infx, pfx;
    stack<char> s;
    bool precedence(char op1, char op2) {
        if (op1 == '*' || op1 == '/') {
            return true;
        }
        if (op1 == '+' || op1 == '-') {
            if (op2 == '*' || op2 == '/') {
                return false;
            } else {
                return true;
            }
        }
        return false;
    }
public:
    Expression() {
        infx = "";
        pfx = "";
    }
    void convertToPostfix() {
        pfx = "";
        for (int i = 0; i < infx.length(); i++) {
            char c = infx[i];
            if (isalnum(c)) {
                pfx += c;
            } else if (c == '(') {
                s.push(c);
            } else if (c == ')') {
                while (!s.empty() && s.top() != '(') {
                    pfx += s.top();
                    s.pop();
                }
                s.pop();
            } else if (c == '+' || c == '-' || c == '*' || c == '/') {
                while (!s.empty() && s.top() != '(' && precedence(s.top(), c)) {
                    pfx += s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        while (!s.empty()) {
            pfx += s.top();
            s.pop();
        }
    }
    void getInfix(string input) {
        infx = input;
    }
    void showInfix() {
        cout << "Infix expression: " << infx << endl;
    }
    void showPostfix() {
        cout << "Postfix expression: " << pfx << endl;
    }
    ~Expression() {}
};

int main() {
    Expression expr;
    
    expr.getInfix("A + B - C");
    expr.showInfix();
    expr.convertToPostfix();
    expr.showPostfix();
    cout<<"\n";

    expr.getInfix("(A + B) * C");
    expr.showInfix();
    expr.convertToPostfix();
    expr.showPostfix();
    cout<<"\n";

    expr.getInfix("(A + B) * (C + D)");
    expr.showInfix();
    expr.convertToPostfix();
    expr.showPostfix();
    cout<<"\n";

    expr.getInfix("A + ((B + C) * (E + F) - G) / (H - I)");
    expr.showInfix();
    expr.convertToPostfix();
    expr.showPostfix();
    cout<<"\n";

    expr.getInfix("A + B * (C + D) - E / F * G + H");
    expr.showInfix();
    expr.convertToPostfix();
    expr.showPostfix();
    cout<<"\n";

    return 0;
}
