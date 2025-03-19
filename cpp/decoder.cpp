#include<iostream>
using namespace std;

int main() {
 cout << "two-digit number: ";
 char charnum = cin.get();
 int num = (charnum - '0') * 10;
 charnum = cin.get();
 num += (charnum - '0');
 cout << "That number as an integer: " << num << "\n";
}
