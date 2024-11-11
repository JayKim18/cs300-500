#include <iostream>

using namespace std;

int main() {
    int a, b;
    
    while (true) {
        cin >> a >> b;
        
        if (a == 0 && b == 0) {
            break;
        }
        
        int carry = 0;
        int carryCount = 0;
        
        while (a > 0 || b > 0) {
            int digitA = a % 10;
            int digitB = b % 10;
            int sum = digitA + digitB + carry;
            
            if (sum >= 10) {
                carry = 1;
                carryCount++;
            } else {
                carry = 0;
            }
            
            a /= 10;
            b /= 10;
        }
        
        if (carryCount == 0) {
            cout << "No carry operation." << endl;
        } else if (carryCount == 1) {
            cout << "1 carry operation." << endl;
        } else {
            cout << carryCount << " carry operations." << endl;
        }
    }
    
    return 0;
}
