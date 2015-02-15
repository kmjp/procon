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

ll dp[3600000];
set<int> S,S2;

class YetAnotherTwoTeamsProblem {
	public:
	int N;
	long long count(vector <int> skill) {
		int i,j,k,tot=0;
		N=skill.size();
		sort(skill.begin(),skill.end());
		FOR(i,N) tot+=skill[i];
		ll ret = 0;
		
		ZERO(dp);
		dp[0]=1;
		for(i=N-1;i>=0;i--) {
			for(k=max(tot/2+1,skill[i]);2*k <tot+2*skill[i];k++) ret += dp[k-skill[i]];
			for(k=60000*(N-i);k>=0;k--)  dp[k+skill[i]] += dp[k];
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, 4, 7, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2LL; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { int Arr0[] = {1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 10LL; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 2, 3, 5, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 5LL; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { int Arr0[] = {1, 2, 3, 4, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(3, Arg1, count(Arg0)); }
	void test_case_24() { int Arr0[] = {999, 999, 999, 1000, 1000, 1001, 999, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
 1000, 1000, 1000, 999, 1000, 512, 511, 1001, 1001, 1001, 1001, 1001, 1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 17672631900LL; verify_case(4, Arg1, count(Arg0)); }

	void test_case_4() { int Arr0[] = {56709, 32581, 23159, 40328, 14924, 22231, 14457, 53622, 14346, 55254, 58820, 57260, 14223, 12245, 28234, 56764, 32034, 34198, 54543, 27911, 37030, 33276, 48299, 54512, 53249, 8496, 23860, 35884, 33915, 599, 24252, 54549, 20933, 35243, 25862, 31680, 39485, 37801, 43943, 4239, 58292, 36666, 15207, 33481, 51105, 24892, 3437}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 17672631900LL; verify_case(4, Arg1, count(Arg0)); }
	

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  YetAnotherTwoTeamsProblem ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

