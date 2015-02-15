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

class BitwiseAnd {
	public:
	int M,L;
	
	vector<long long> lexSmallest(vector<long long> S, int N) {
		int b[61],c[61],aa[61];
		int i,j,x,y,z;
		sort(S.begin(),S.end());
		M=S.size();
		L=N-M;
		ZERO(aa);
		ZERO(b);
		
		FOR(j,60) FOR(i,M) if(S[i] & (1LL<<j)) b[j]++,aa[j]=i;
		
		FOR(x,M) for(y=x+1;y<M;y++) if((S[x] & S[y])==0) return vector<long long>();
		FOR(x,M) for(y=x+1;y<M;y++) for(z=y+1;z<M;z++) {
			if((S[x] & S[y] & S[z])!=0) return vector<long long>();
		}
		
		if(L==0) return S;
		
		vector<ll> S2;
		FOR(i,L) {
			ll t=0;
			ll ma=0;
			FOR(j,60) {
				if(b[j]!=1) continue;
				if((ma & (1LL<<aa[j]))==0) {
					ma |= 1LL<<aa[j];
					t |= 1LL<<j;
					b[j]++;
				}
			}
			if(ma != (1LL<<M)-1) return vector<long long>();
			
			S2.push_back(t);
		}
		
		FOR(i,60) {
			if(b[i]!=0) continue;
			FOR(x,L) for(y=x+1;y<L;y++) {
				if((S2[x] & S2[y])==0) {
					S2[x] |= 1LL<<i;
					S2[y] |= 1LL<<i;
					goto out;
				}
			}
			out:
			;
		}
		
		FOR(x,L) for(y=x+1;y<L;y++) if((S2[x] & S2[y])==0) return vector<long long>();
		FOR(i,L) S.push_back(S2[i]);
		sort(S.begin(),S.end());
		
		
		return S;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector<long long> &Expected, const vector<long long> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { ll Arr0[] = {14, 20}; vector<ll> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; ll Arr2[] = {14, 18, 20 }; vector<ll> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, lexSmallest(Arg0, Arg1)); }
	void test_case_1() { ll Arr0[] = {11, 17, 20}; vector<ll> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; ll Arr2[] = { }; vector<ll> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, lexSmallest(Arg0, Arg1)); }
	void test_case_2() { ll Arr0[] = {99, 157}; vector<ll> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; ll Arr2[] = {99, 157, 262, 296 }; vector<ll> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, lexSmallest(Arg0, Arg1)); }
	void test_case_3() { ll Arr0[] = {1152921504606846975LL}; vector<ll> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; ll Arr2[] = { }; vector<ll> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, lexSmallest(Arg0, Arg1)); }
	void test_case_4() { ll Arr0[] = {}; vector<ll> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; ll Arr2[] = {15, 113, 402, 676, 840 }; vector<ll> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, lexSmallest(Arg0, Arg1)); }
	void test_case_52() { ll Arr0[] = {1, 3, 5, 7, 9, 11}; vector<ll> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; ll Arr2[] = { }; vector<ll> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, lexSmallest(Arg0, Arg1)); }
	void test_case_5() { ll Arr0[] = {256,257,512}; vector<ll> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; ll Arr2[] = { }; vector<ll> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, lexSmallest(Arg0, Arg1)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BitwiseAnd ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

