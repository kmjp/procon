#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> data(5);
  for (int i = 0; i < 5; i++) {
    cin >> data.at(i);
  }
  for (int i = 0; i < 4; i++) {
	if(data[i]==data[i+1]) {
		cout<<"YES"<<endl;
		return 0;
	}
}
		cout<<"NO"<<endl;

  // data�̒��ŗׂ荇���������v�f�����݂���Ȃ�"YES"���o�͂��A�����łȂ����"NO"���o�͂���
  // �����Ƀv���O������ǋL
}

