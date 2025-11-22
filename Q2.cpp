#include <iostream>
using namespace std;


int main() {
    double abc, big, G;
   
    // Read values from console
    cout << "Enter value for big: ";
    cin >> big;
   
    cout << "Enter value for abc: ";
    cin >> abc;
   
    // Evaluate the expression
    G = big / 2 + big * 4 / big - big + abc / 3;
   
    // Display the result
    cout << "\nGiven values:" << endl;
    cout << "big = " << big << endl;
    cout << "abc = " << abc << endl;
    cout << "\nExpression: G = big / 2 + big * 4 / big - big + abc / 3" << endl;
    cout << "Result: G = " << G << endl;
   
    return 0;
}





