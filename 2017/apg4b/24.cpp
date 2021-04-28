#include <bits/stdc++.h>
using namespace std;

// �ȉ��ɁA24���ԕ\�L�̎��v�\���� Clock ���`����

struct Clock {
	int hour,minute,second;
	void set(int h,int m,int s) {
		hour=h;
		minute=m;
		second=s;
	}
	string to_str() {
		char buf[101];
		sprintf(buf,"%02d:%02d:%02d",hour,minute,second);
		return buf;
	}
	void shift(int diff_second) {
		second+=diff_second;
		minute+=second/60;
		second%=60;
		if(second<0) minute--, second+=60;
		hour+=minute/60;
		minute%=60;
		if(minute<0) hour--, minute+=60;
		hour=(hour+24)%24;
	}
};

// Clock�\���̂̃����o�ϐ�������
//   int hour    ���Ԃ�\�� (0~23�̒l���Ƃ�)
//   int minute  ����\��   (0~59�̒l���Ƃ�)
//   int second  �b��\��   (0~59�̒l���Ƃ�)

// �����o�֐� set �̒�`������
//   �֐���: set
//   ����: int h, int m, int s (���ꂼ�ꎞ�A���A�b��\��)
//   �Ԃ�l: �Ȃ�
//   �֐��̐���:
//     ���E���E�b��\��3�̈������󂯎��A
//     ���ꂼ��A�����o�ϐ� hour, minute, second �ɑ������

// �����o�֐� to_str �̒�`������
//   �֐���: to_str
//   ����: �Ȃ�
//   �Ԃ�l: string�^
//   �֐��̎d�l:
//     �����o�ϐ����\�������̕������Ԃ�
//     �����̕�����͎��̃t�H�[�}�b�g
//     "HH:MM:SS"
//     HH�AMM�ASS�͂��ꂼ�ꎞ�ԁA���A�b��2���ŕ\����������

// �����o�֐� shift �̒�`������
//   �֐���: shift
//   ����: int diff_second
//   �Ԃ�l: �Ȃ�
//   �֐��̎d�l:
//     diff_second �b���������o�ϐ����\��������ύX����(�������A���t�₤�邤�b�͍l���Ȃ�)
//     diff_second �̒l�����̏ꍇ�A������߂�
//     diff_second �̒l�����̏ꍇ�A������i�߂�
//     diff_second �̒l�� -86400 ~ 86400 �͈̔͂���Ƃ肤��


// -------------------
// ���������͕ύX���Ȃ�
// -------------------

int main() {
  // ���͂��󂯎��
  int hour, minute, second;
  cin >> hour >> minute >> second;
  int diff_second;
  cin >> diff_second;

  // Clock�\���̂̃I�u�W�F�N�g��錾
  Clock clock;

  // set�֐����Ăяo���Ď�����ݒ肷��
  clock.set(hour, minute, second);

  // �������o��
  cout << clock.to_str() << endl;

  // ���v��i�߂�(�߂�)
  clock.shift(diff_second);

  // �ύX��̎������o��
  cout << clock.to_str() << endl;
}
