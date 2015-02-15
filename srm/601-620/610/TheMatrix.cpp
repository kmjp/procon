#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef signed long long ll;
typedef unsigned long long ull;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(x) x.begin(),x.end()
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

int ma[101][101];

class TheMatrix {
	int R,C;
	public:
	int MaxArea(vector <string> board) {
		int y,x,h;
		R=board.size();
		C=board[0].size();
		ZERO(ma);
		
		FOR(y,R) FOR(x,C) {
			if(x==0 || board[y][x]==board[y][x-1]) ma[y][x]=1;
			else ma[y][x]=ma[y][x-1]+1;
		}
		
		int mama=0;
		FOR(x,C) FOR(y,R) {
			int mi=ma[y][x];
			for(h=1;h+y<=R;h++) {
				if(h>1 && board[y+h-1][x]==board[y+h-2][x]) break;
				mi=min(mi,ma[y+h-1][x]);
				mama=max(mama,h*mi);
			}
		}
		return mama;
		
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1", 
 "0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, MaxArea(Arg0)); }
	void test_case_1() { string Arr0[] = {"0000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, MaxArea(Arg0)); }
	void test_case_2() { string Arr0[] = {"01"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, MaxArea(Arg0)); }
	void test_case_3() { string Arr0[] = {"001",
 "000",
 "100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, MaxArea(Arg0)); }
	void test_case_4() { string Arr0[] = {"0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, MaxArea(Arg0)); }
	void test_case_5() { string Arr0[] = {"101", 
 "010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(5, Arg1, MaxArea(Arg0)); }
	void test_case_6() { string Arr0[] = {"01010101", "01010111", "01010100", "01010100", "01010101", "01010101", "01010001", "01010101", "01010101", "01010101", "11011101", "01010101", "01010101", "01100101", "01010101", "01010101", "01010101", "01010101", "01010101", "01010101", "01010101", "01011101", "00010101", "01010101", "01010101", "01010101", "01011001", "01010101", "01010101", "01010101", "01010101", "01010100", "01010101", "01010101", "01010101", "01010101", "01010101", "01010101", "01010101", "01011101", "01011101", "01010101", "01111101", "01010101", "11010101", "01010101", "01010101", "01010101", "01010101", "01010101", "01010101", "01110101", "01010101", "01010101", "01010101", "01010101", "01000101", "01010101", "01010101", "01010101", "01010101", "01010101", "01010101", "01010101", "01010101", "01010101", "01000100", "00010101", "01010101", "01010111", "01010001", "01010101", "01010101", "01010101", "11010001", "01111101"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(6, Arg1, MaxArea(Arg0)); }
	void test_case_7() { string Arr0[] = {"11001110011000110001111001001110110011010110001011", 
 "10100100010111111011111001011110101111010011100001", 
 "11101111001110100110010101101100011100101000010001", 
 "01000010001010101100010011111000100100110111111000", 
 "10110100000101100000111000100001011101111101010010", 
 "00111010000011100001110110010011010110010011100100", 
 "01100001111101001101001101100001111000111001101010", 
 "11010000000011011010100010000000111011001001100101", 
 "10100000000100010100100011010100110110110001000001", 
 "01101010101100001100000110100110100000010100100010", 
 "11010000001110111111011010011110001101100011100010", 
 "11101111000000011010011100100001100011111111110111", 
 "11000001101100100011000110111010011001010100000001", 
 "00100001111001010000101101100010000001100100001000", 
 "01001110110111101011010000111111101011000110010111", 
 "01001010000111111001100000100010101100100101010100", 
 "11111101001101110011011011011000111001101100011011", 
 "10000100110111000001110110010000000000111100101101", 
 "01010011101101101110000011000110011111001111011100", 
 "01101010011111010000011001111101011010011100001101", 
 "11011000011000110010101111100000101011011111101100", 
 "11100001001000110010100011001010101101001010001100", 
 "11011011001100111101001100111100000101011101101011", 
 "11110111100100101011100101111101000111001111110111", 
 "00011001100110111100111100001100101001111100001111", 
 "10001111100101110111001111100000000011110000100111", 
 "10101010110110100110010001001010000111100110100011", 
 "01100110100000001110101001101011001010001101110101", 
 "10110101110100110110101001100111110000101111100110", 
 "01011000001001101110100001101001110011001001110001", 
 "00100101010001100110110101001010010100001011000011", 
 "00011101100100001010100000000011000010100110011100", 
 "11001001011000000101111111000000110010001101101110", 
 "10101010110110010000010011001100110101110100111011", 
 "01101001010111010001101000100011101001110101000110", 
 "00110101101110110001110101110010100100110000101101", 
 "11010101000111010011110011000001101111010011110011", 
 "10010000010001110011011101001110110010001100011100", 
 "00111101110001001100101001110100110010100110110000", 
 "00010011011000101000100001101110111100100000010100", 
 "01101110001101000001001000001011101010011101011110", 
 "00000100110011001011101011110011011101100001110111", 
 "00110011110000011001011100001110101010100110010110", 
 "00111001010011011111010100000100100000101101110001", 
 "10101101101110111110000011111011001011100011110001", 
 "00101110010101111000001010110100001110111011100011", 
 "01111110010100111010110001111000111101110100111011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(7, Arg1, MaxArea(Arg0)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TheMatrix ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

