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

class SubFibonacci {
	public:
	int maxElements(vector <int> S) {
		int i,j,x,y,z,t;
		int lm[51],rm[51];
		ll A[101],B[101];
		
		A[0]=B[1]=1;
		A[1]=B[0]=0;
		for(i=2;i<50;i++) A[i]=A[i-1]+A[i-2], B[i]=B[i-1]+B[i-2];
		
		sort(S.begin(),S.end());
		if(S.size()<=4) return S.size();
		
		set<ll> SS;
		FOR(x,S.size()) for(y=x+1;y<S.size();y++) for(z=1;z<50;z++) {
			ll cur=S[y]-S[x]*A[z];
			if(cur<=0) continue;
			if(cur%B[z]) continue;
			ll tar=cur/B[z];
			ll mask=(1LL<<x)|(1LL<<y);
			t=x+1;
			for(j=1;j<50;j++) {
				ll val=S[x]*A[j]+tar*B[j];
				while(t<S.size() && S[t]<val) t++;
				if(t<S.size() && S[t]==val) mask |= 1LL<<t;
			}
			SS.insert(mask);
		}
		
		ZERO(lm); ZERO(rm);
		ITR(it,SS) {
			int tot=__builtin_popcountll(*it);
			x=0;
			FOR(i,S.size()) {
				x+=(*it&(1LL<<i))>0;
				lm[i]=max(lm[i],x);
				rm[i]=max(rm[i],tot-x);
			}
		}
		
		int ma=0;
		FOR(i,S.size()) ma=max(ma,lm[i]+rm[i]);
		
		return ma;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {8, 1, 20, 3, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, maxElements(Arg0)); }
	void test_case_1() { int Arr0[] = {19, 47, 50, 58, 77, 99}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, maxElements(Arg0)); }
	void test_case_2() { int Arr0[] = {512}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, maxElements(Arg0)); }
	void test_case_3() { int Arr0[] = {3, 5, 7, 10, 13, 15, 20, 90}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(3, Arg1, maxElements(Arg0)); }
	void test_case_4() { int Arr0[] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(4, Arg1, maxElements(Arg0)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SubFibonacci ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

