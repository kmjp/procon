#include <bits/stdc++.h>
using namespace std;

// 1�l�̃e�X�g�̓_����\���z�񂩂獇�v�_���v�Z���ĕԂ��֐�
// ���� scores: scores.at(i)��i�Ԗڂ̃e�X�g�̓_���������Ă���
// �Ԃ�l: 1�l�̃e�X�g�̍��v�_
int sum(vector<int> scores) {
  // �����Ƀv���O������ǋL
  int S=0;
  int i;
  for(i=0;i<scores.size();i++) S+=scores[i];
  return S;
}

// 3�l�̍��v�_����v���[���g�̗\�Z���v�Z���ďo�͂���֐�
// ���� sum_a: A�N�̃e�X�g�̍��v�_
// ���� sum_b: B�N�̃e�X�g�̍��v�_
// ���� sum_c: C�N�̃e�X�g�̍��v�_
// �Ԃ�l: �Ȃ�
void output(int sum_a, int sum_b, int sum_c) {
  // �����Ƀv���O������ǋL
  cout<<sum_a*sum_b*sum_c<<endl;
}

// -------------------
// ���������͕ύX���Ȃ�
// -------------------

// N�̓��͂��󂯎���Ĕz��ɓ���ĕԂ��֐�
// ���� N: ���͂��󂯎���
// �Ԃ�l: �󂯎����N�̓��͂̔z��
vector<int> input(int N) {
  vector<int> vec(N);
  for (int i = 0; i < N; i++) {
    cin >> vec.at(i);
  }
  return vec;
}

int main() {
  // �Ȗڂ̐�N���󂯎��
  int N;
  cin >> N;

  // ���ꂼ��̃e�X�g�̓_�����󂯎��
  vector<int> A = input(N);
  vector<int> B = input(N);
  vector<int> C = input(N);

  // ���ꂼ��̍��v�_���v�Z
  int sum_A = sum(A);
  int sum_B = sum(B);
  int sum_C = sum(C);

  // �v���[���g�̗\�Z���o��
  output(sum_A, sum_B, sum_C);
}
