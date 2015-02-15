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

ll DP[301][301][2]; // Mth sponge, pos, 0-include L
ll fin[301][301]; // Mth sponge, pos

class TheExperiment {
	
	public:
	int countPlacements(vector <string> intensity, int M, int L, int A, int B) {
		int i,x,done,nx,l,y,j,x2;
		ll mo=1000000009;
		string S;
		int SL;
		int tot[302];
		
		FOR(i,intensity.size()) S+=intensity[i];
		SL=S.size();
		
		ZERO(tot);
		FOR(i,SL) tot[i+1]=tot[i]+(S[i]-'0');
		
		ZERO(DP);
		ZERO(fin);
		fin[0][0]=1;
		
		for(x=1;x<=SL;x++) {
			FOR(i,M+1) fin[i][x]=(fin[i][x-1]+DP[i][x-1][1])%mo;
			
			for(l=1;l<=L;l++) {
				if(x-l<0) break;
				if(tot[x]-tot[x-l]<A) continue;
				if(tot[x]-tot[x-l]>B) break;
				FOR(i,M) DP[i+1][x][1]=(DP[i+1][x][1]+DP[i][x-l][1]) % mo;
				FOR(i,M) DP[i+1][x][l==L]=(DP[i+1][x][l==L]+DP[i][x-l][0]+fin[i][x-l]) % mo;
			}
		}
		
		return (fin[M][SL]+DP[M][SL][1])%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"341156"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 3; int Arg3 = 6; int Arg4 = 10; int Arg5 = 2; verify_case(0, Arg5, countPlacements(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { string Arr0[] = {"999112999"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 4; int Arg3 = 21; int Arg4 = 30; int Arg5 = 2; verify_case(1, Arg5, countPlacements(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { string Arr0[] = {"111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; int Arg3 = 2; int Arg4 = 3; int Arg5 = 0; verify_case(2, Arg5, countPlacements(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { string Arr0[] = {"59059", "110", "1132230231"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 5; int Arg3 = 10; int Arg4 = 20; int Arg5 = 6; verify_case(3, Arg5, countPlacements(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { string Arr0[] = {"111111111111111111111111", "111111111111111111111111111", "11111111111111111111111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; int Arg2 = 8; int Arg3 = 4; int Arg4 = 2700; int Arg5 = 418629948; verify_case(4, Arg5, countPlacements(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  TheExperiment ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
