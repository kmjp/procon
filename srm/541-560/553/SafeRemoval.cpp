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

int dpdp[51][51][51][4];

class SafeRemoval {
	public:
	int okok(int a1,int a2,int a3,int rem) {
		if(a1+a2+a3==0) return 1;
		if(dpdp[a1][a2][a3][rem]!=-1) return dpdp[a1][a2][a3][rem];
		int r=0;
		if(rem!=1 && a1) r |= okok(a1-1,a2,a3,rem-1);
		if(rem!=2 && a2) r |= okok(a1,a2-1,a3,(rem+2)%4);
		if(rem!=3 && a3) r |= okok(a1,a2,a3-1,(rem+1)%4);
		return dpdp[a1][a2][a3][rem]=r;
	}
	
	int removeThem(vector <int> seq, int k) {
		int i,j,a[4];
		vector<int> C[4];
		
		MINUS(dpdp);
		FOR(i,seq.size()) C[seq[i]%4].push_back(seq[i]);
		FOR(i,4) {
			sort(C[i].begin(),C[i].end());
			for(j=C[i].size()-2;j>=0;j--) C[i][j]+=C[i][j+1];
			C[i].push_back(0);
		}
		int ma=-1;
		int S=C[0][0]+C[1][0]+C[2][0]+C[3][0];
		for(a[0]=0;a[0]<=k && a[0]<C[0].size();a[0]++)
			for(a[1]=0;a[1]<=k-a[0] && a[1]<C[1].size();a[1]++)
				for(a[2]=0;a[2]<=k-a[0]-a[1] && a[2]<C[2].size();a[2]++) {
					a[3]=k-a[0]-a[1]-a[2];
					if(a[3]>=C[3].size()) continue;
					if(!okok(a[1],a[2],a[3],S%4)) continue;
					i=a[1]+a[2]*2+a[3]*3;
					if(((S-i)%4)==0) continue;
					ma=max(ma,C[0][a[0]]+C[1][a[1]]+C[2][a[2]]+C[3][a[3]]);
				}
		return ma;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3, 8, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 11; verify_case(0, Arg2, removeThem(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = -1; verify_case(1, Arg2, removeThem(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,6,1,10,1,2,7,11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 21; verify_case(2, Arg2, removeThem(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,1,1,1,1,1,1,1,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 6; verify_case(3, Arg2, removeThem(Arg0, Arg1)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SafeRemoval ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

