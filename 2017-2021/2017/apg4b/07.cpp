#include <bits/stdc++.h>
using namespace std;

int main() {
  // �ϐ�a,b,c��true�܂���false��������AtCoder�Əo�͂����悤�ɂ���B
  bool a = 1;
  bool b = 0;
  bool c = 1;

  // ���������͕ύX���Ȃ�����

  if (a) {
    cout << "At";
  }
  else {
    cout << "Yo";
  }

  if (!a && b) {
    cout << "Bo";
  }
  else if (!b || c) {
    cout << "Co";
  }

  if (a && b && c) {
    cout << "foo!";
  }
  else if (true && false) {
    cout << "yeah!";
  }
  else if (!a || c) {
    cout << "der";
  }

  cout << endl;
}
