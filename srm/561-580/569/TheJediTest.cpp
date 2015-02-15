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


class TheJediTest {
	public:
	int N,K;
	ll memo1[25][25];
	ll memo2[25];
	
	ll gr(vector <int> S, int s, int t) {
		int i;
		if(s>=t) return 0;
		if(memo1[s][t]>=0) return memo1[s][t];
		ll to = 0;
		
		if(t-s<=3) {
			for(i=s;i<t;i++) to+=S[i];
			return memo1[s][t]=(to+(K-1))/K;
		}
		
		ll le = S[s];
		for(i=s+1;i<t-1;i++) {
			if(le==0) le=S[i];
			else {
				int mo = (K-(le%K))%K;
				to += (le+(K-1))/K;
				if(S[i]<mo) {
					if(S[i+1]<mo-S[i]) S[i+1]=0;
					else S[i+1] -= mo-S[i];
					le=0;
				}
				else {
					le = (le+S[i])-((le+(K-1))/K)*K;
					to += le/K;
					le %= K;
				}
			}
		}
		return memo1[s][t]=to + (le+S[t-1]+(K-1))/K;
	}
	
	ll range(vector<int> S, int s) {
		int i;
		if(s>=N) return 0;
		if(memo2[s]>=0) return memo2[s];
		memo2[s]=3e9;
		
		for(i=s+1;i<=N;i++) memo2[s] = min(memo2[s], gr(S,s,i)+range(S,i));
		return memo2[s];
	}
	
	int minimumSupervisors(vector<int> S, int K) {
		int loop,i,x,y;
		this->K=K;
		N=S.size();
		if(N<=3) {
			x=0;
			FOR(i,S.size()) x+=S[i];
			return (x+(K-1))/K;
		}
		
		FOR(x,25) FOR(y,25) memo1[x][y]=-1;
		FOR(x,25) memo2[x]=-1;
		return (int)range(S,0);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3, 6, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 3; verify_case(0, Arg2, minimumSupervisors(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 2; verify_case(1, Arg2, minimumSupervisors(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12345; int Arg2 = 0; verify_case(2, Arg2, minimumSupervisors(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {15, 0, 13, 4, 29, 6, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; int Arg2 = 10; verify_case(3, Arg2, minimumSupervisors(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {1284912, 1009228, 9289247, 2157, 2518, 52781, 2, 2818, 68}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 114; int Arg2 = 102138; verify_case(4, Arg2, minimumSupervisors(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {85917358, 82455907, 96386315, 20319346, 83035486, 7259323, 9548333, 38805062, 5594495, 32063230, 80067860, 90122205, 79347082}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 60637790; int Arg2 = 13; verify_case(4, Arg2, minimumSupervisors(Arg0, Arg1)); }
// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  TheJediTest ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
