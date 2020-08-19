#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main() {
    while (true) {
        char temp[101];
        cin.getline(temp,101);
        
        if (!strcmp(temp, ".")) break;

        stack<char> s;
        bool flag = 0;
        
        for (int i = 0;i < strlen(temp);i++) {
            if (temp[i] == '(' || temp[i] == '[')
                s.push(temp[i]);
            else if (temp[i] == ')') {
                if (!s.empty() && s.top() == '(') s.pop();
                else {
                    cout << "no\n";
                    flag = 1;
                    break;
                }
            }
            else if (temp[i] == ']') {
                if (!s.empty() && s.top() == '[') s.pop();
                else {
                    cout << "no\n";
                    flag = 1;
                    break;
                }
            }
        }
		if (flag) continue;

		if (!s.empty()) cout << "no\n";
		else cout << "yes\n";

    }
}
//