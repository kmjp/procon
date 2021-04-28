#include <bits/stdc++.h>
using namespace std;

// �e������s���֐�����������

// A��B�ɋ��ʂ��Ċ܂܂��v�f����Ȃ�W����Ԃ�
bitset<50> intersection(bitset<50> A, bitset<50> B) {
	return A&B;
}
// A��B�̂������Ȃ��Ƃ�����Ɋ܂܂��v�f����Ȃ�W����Ԃ�
bitset<50> union_set(bitset<50> A, bitset<50> B) {
	return A|B;
}
// A��B�̂����ǂ��炩����ɂ����܂܂��v�f����Ȃ�W����Ԃ�
bitset<50> symmetric_diff(bitset<50> A, bitset<50> B) {
	return A^B;
}
// A����lx������
bitset<50> subtract(bitset<50> A, int x) {
	if(A[x]) A[x]=0;
	return A;
}
// A�Ɋ܂܂��v�f��1��������(�������A�v�f49���܂܂��ꍇ��0�ɂȂ���̂Ƃ���)
bitset<50> increment(bitset<50> A) {
	if(A[49]) {
		A<<=1;
		A[0]=1;
	}
	else {
		A<<=1;
	}
	return A;
}
// A�Ɋ܂܂��v�f����1������(�������A�v�f0���܂܂��ꍇ��49�ɂȂ���̂Ƃ���)
bitset<50> decrement(bitset<50> A) {
	if(A[0]) {
		A>>=1;
		A[49]=1;
	}
	else {
		A>>=1;
	}
	return A;
	
}

// S�ɒlx��������
bitset<50> add(bitset<50> S, int x) {
  S.set(x, 1);  // x�r�b�g�ڂ�1�ɂ���
  return S;
}

// �W��S�̓��e�������ŏo�͂���(�X�y�[�X��؂�Ŋe�v�f�̒l���o�͂���)
void print_set(bitset<50> S) {
  vector<int> cont;
  for (int i = 0; i < 50; i++) {
    if (S.test(i)) {
      cont.push_back(i);
    }
  }
  for (int i = 0; i < cont.size(); i++) {
    if (i > 0) cout << " ";
    cout << cont.at(i);
  }
  cout << endl;
}

// �����艺�͏��������Ȃ�

int main() {
  bitset<50> A, B;
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    A = add(A, x);
  }
  int M;
  cin >> M;
  for (int i = 0; i < M; i++) {
    int x;
    cin >> x;
    B = add(B, x);
  }

  // ����
  string com;
  cin >> com;

  if (com == "intersection") {
    print_set(intersection(A, B));
  } else if (com == "union_set") {
    print_set(union_set(A, B));
  } else if (com == "symmetric_diff") {
    print_set(symmetric_diff(A, B));
  } else if (com == "subtract") {
    int x;
    cin >> x;
    print_set(subtract(A, x));
  } else if (com == "increment") {
    print_set(increment(A));
  } else if (com == "decrement") {
    print_set(decrement(A));
  }
}
