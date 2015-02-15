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

ll mo=1000000009;
ll pows[64][64];

class YetAnotherORProblem {
	public:
	int N;
	
	ll dpdp(int bit,vector<ll>& R, int left) {
		ll ret=0;
		ll num=1LL<<bit;
		int i,j;
		
		if(bit<0) return 1;
		if(R.empty()) return pows[left+1][bit+1];
		
		int l2=0;
		vector<ll> V;
		V.reserve(16);
		
		FOR(i,R.size()) {
			if(R[i]>=num-1) l2++;
			else V.push_back(R[i]);
		}
		ret = (left+1) * dpdp(bit-1,V,left+l2) % mo;
		
		FOR(i,R.size()) if(R[i]>=num) {
			if(R[i]==num) ret += dpdp(bit-1,V,left+l2-1);
			else {
				V.push_back(R[i]-num);
				ret += dpdp(bit-1,V,left+l2-1);
				V.pop_back();
			}
			if(ret>=mo) ret -= mo;
		}
		return ret;
	}
	
	
	int countSequences(vector<long long> R) {
		int x,y;
		FOR(x,64) {
			pows[x][0]=1;
			FOR(y,63) pows[x][y+1]=(pows[x][y]*x)%mo;
		}
		N=R.size();
		return dpdp(59,R,0)%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long Arr0[] = {3,5}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(0, Arg1, countSequences(Arg0)); }
	void test_case_1() { long Arr0[] = {3,3,3}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(1, Arg1, countSequences(Arg0)); }
	void test_case_2() { long Arr0[] = {1,128}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 194; verify_case(2, Arg1, countSequences(Arg0)); }
	void test_case_3() { long Arr0[] = {26,74,25,30}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8409; verify_case(3, Arg1, countSequences(Arg0)); }
//	void test_case_4() { long Arr0[] = {1000000000,1000000000}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 420352509; verify_case(4, Arg1, countSequences(Arg0)); }
	void test_case_4() { ll Arr0[] = {698592418393878689LL, 41176158769631317LL, 5928437347348326LL, 627483485536712LL, 56556167864743LL, 1612168692743LL, 232947913547LL, 41334996277LL, 3447279799LL, 459298488LL}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 420352509; verify_case(4, Arg1, countSequences(Arg0)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  YetAnotherORProblem ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

