#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, B;
  string op;
  cin >> A >> op >> B;
 
  if (op == "+") cout << A + B << endl;
  if (op == "-") cout << A - B << endl;
  if (op == "*") cout << A * B << endl;
  if (op == "/") {
	if(B==0) cout<<"error"<<endl;
	else cout << A / B << endl;
}
  if (op == "?") cout << "error" << endl;
  if (op == "=") cout << "error" << endl;
  if (op == "!") cout << "error" << endl;
  // ‚±‚±‚ÉƒvƒƒOƒ‰ƒ€‚ð’Ç‹L
}
