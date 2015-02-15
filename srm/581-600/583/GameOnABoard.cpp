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

#define DEBUG
#ifdef DEBUG
#define DBG(...) cerr << #__VA_ARGS__ << ": " << __VA_ARGS__ << endl
#define DV(...) cerr << __VA_ARGS__ << endl
#else
#define DBG(...)
#define DV(...)
#endif

typedef signed long long ll;
typedef unsigned long long ull;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

class GameOnABoard {
	public:
	int H,W;
	int cc[40][40];
	int dodo(int X,int Y,int cm) {
		int i,j,k,x,y,ma;
		int dist[40][40];
		
		FOR(y,H) FOR(x,W) dist[y][x]=999;
		ma=dist[Y][X]=cc[Y][X];
		
		set<int> Q;
		Q.insert(dist[Y][X]*10000+Y*100+X);
		while(!Q.empty()) {
			int k=*Q.begin();
			Q.erase(k);
			int cx=k%100,cy=(k/100)%100;
			
			int dx[4]={0,0,1,-1};
			int dy[4]={1,-1,0,0};
			FOR(i,4) {
				int tx=cx+dx[i],ty=cy+dy[i];
				if(tx<0||tx>=W||ty<0||ty>=H) continue;
				
				if(dist[ty][tx]>dist[cy][cx]+cc[ty][tx]) {
					dist[ty][tx]=dist[cy][cx]+cc[ty][tx];
					ma=max(ma,dist[ty][tx]);
					if(ma>=cm) return ma;
					Q.insert(dist[ty][tx]*10000+ty*100+tx);
				}
			}
		}
		return ma;
	}
	
	int optimalChoice(vector <string> cost) {
		int x,y;
		H=cost.size();
		W=cost[0].size();
		
		int mi=41;
		FOR(y,H) FOR(x,W) cc[y][x]=cost[y][x]-'0';
		FOR(y,H) FOR(x,W) mi=min(mi,dodo(x,y,mi));
		
		return mi;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"11",
 "10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, optimalChoice(Arg0)); }
	void test_case_1() { string Arr0[] = {"01",
 "10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, optimalChoice(Arg0)); }
	void test_case_2() { string Arr0[] = {"111001",
 "001000",
 "111111",
 "001111",
 "001100",
 "001011",
 "111001",
 "010011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, optimalChoice(Arg0)); }
	void test_case_3() { string Arr0[] = {"001001101011",
 "110011001101",
 "111111000001",
 "111101010001",
 "011100101111",
 "110010111000",
 "111111110101",
 "111011110111",
 "111100100011",
 "000000000110",
 "101011011110",
 "011111000111",
 "101111001011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(3, Arg1, optimalChoice(Arg0)); }
	void test_case_4() { string Arr0[] = {"110010100101010110100010001100111011",
 "001000000110100011010100000001001000",
 "011000110111101001011101110111000100",
 "111001011000100101111010100110110011",
 "111000011101001010000100001010000010",
 "111001110010100101000001001100011011",
 "111110100111010101100000100111000111",
 "011111111100100111111110000001110111",
 "110000010101001111100011110000001000",
 "010010110111111100011101100000011010",
 "110001100001111001101000101110110001",
 "110010000111011110000010110111010101",
 "100100110101001001101000001101101101",
 "001011101101001100111110101111001110",
 "111010111111111100110100000011111100",
 "110101101000001001000100101011100000",
 "011011001011010001001000100000110101",
 "011111111100000011010111010011010100",
 "111001111110001110001110010100111010",
 "000001111000001100101010000001101110",
 "010000110000010010111110111000010101",
 "100010010100110011000111101001101011",
 "111010110001101011010001111101111100",
 "000111110000110000000101100101000110",
 "110000010111001001110001101010111100",
 "011111101101001011011010011111100010",
 "110101111101010100110010000011001101",
 "101101111001010100101111100001110001",
 "000110010100101111011011110010010010",
 "110101010011101000111011100000010011",
 "110001010001110011010100110000010001",
 "111010101100111100100011001101010100",
 "011000000000100001011010000100010001",
 "100000110110000001010001001111010000",
 "100011111110010011011011001110011111",
 "101100001111100101001101100000100001",
 "010000111011010110011001110011111000",
 "100010100111110111001010100101111010",
 "000110011110111011111000101000001000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(4, Arg1, optimalChoice(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  GameOnABoard ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
