#include <bits/stdc++.h>
using namespace std;

int N,M;
string S[101];

int total;
int sumH[101][101];
int sumV[101][101];

int get_sumH(int y, int l, int r) {
	// 横方向、S[y][l]～S[y][r]がすべて有効なチャンネルか？
	if (sumH[y][r+1] - sumH[y][l] == r+1-l) return r+1-l;
	else return -100000;
}

int get_sumV(int x, int t, int b) {
	// 縦方向、S[t][x]～S[b][x]がすべて有効なチャンネルか？
	if (sumV[b+1][x] - sumV[t][x] == b+1-t) return b+1-t;
	else return -100000;
}

int main(int argc,char** argv){
	int x,y;
	
	// 入力
	cin >> N >> M;
	for(y=0; y<N; y++) cin >> S[y];
	
	// 有効なチャンネル数を数え上げしつつ、
	// 左端・右端・上端・下端の位置を求める
	int left=M-1, right=0, top=N-1, bottom=0;
	for(y=0; y<N; y++) {
		for(x=0; x<M; x++) {
			if (S[y][x] == '.') {
				total++;
				left = min(left,x);
				right = max(right,x);
				top = min(top,y);
				bottom = max(bottom,y);
			}
		}
	}
	
	// 高さと幅は2以上でなければならない
	if (right - left < 1 || bottom - top < 1) {
		cout << "NO" << endl;
		return 0;
	}
	
	// 累積和を作っておく
	for(y=0; y<N; y++) for(x=0; x<M; x++) sumH[y][x+1] = sumH[y][x] + (S[y][x]=='.');
	for(y=0; y<N; y++) for(x=0; x<M; x++) sumV[y+1][x] = sumV[y][x] + (S[y][x]=='.');
	
	int ok = 0;
	
	// 長方形ルートかどうかチェック
	int sum=0;
	sum += get_sumH(top,left,right) + get_sumH(bottom,left,right); // 上下の辺の有効チャンネル数
	sum += get_sumV(left,top,bottom) + get_sumV(right,top,bottom); // 左右の辺の有効チャンネル数
	sum -= 4; // 4つ角を二重カウントしているので、その分減らす
	if (sum == total) ok = 1;
	
	// 1回右折する点が内部にあるかチェック
	for(y=top+1; y<=bottom-1; y++) {
		for(x=left+1; x<=right-1; x++) {
			if (S[y][x] == '.') {
				
				// 右上が欠けるケース
				sum = get_sumH(top,left,x) + get_sumH(y,x,right) + get_sumH(bottom,left,right);
				sum += get_sumV(left,top,bottom) + get_sumV(x,top,y) + get_sumV(right,y,bottom);
				sum -= 6;
				if (sum == total) ok=1;
				
				// 右下が欠けるケース
				sum = get_sumH(top,left,right) + get_sumH(y,x,right) + get_sumH(bottom,left,x);
				sum += get_sumV(left,top,bottom) + get_sumV(x,y,bottom) + get_sumV(right,top,y);
				sum -= 6;
				if (sum == total) ok=1;
				
				// 左上が欠けるケース
				sum = get_sumH(y,left,x) + get_sumH(top,x,right) + get_sumH(bottom,left,right);
				sum += get_sumV(left,y,bottom) + get_sumV(x,top,y) + get_sumV(right,top,bottom);
				sum -= 6;
				if (sum == total) ok=1;
				
				// 左下が欠けるケース
				sum = get_sumH(top,left,right) + get_sumH(y,left,x) + get_sumH(bottom,x,right);
				sum += get_sumV(left,top,y) + get_sumV(x,y,bottom) + get_sumV(right,top,bottom);
				sum -= 6;
				if (sum == total) ok=1;
			}
		}
	}
	
	if (ok==1) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	return 0;
}

