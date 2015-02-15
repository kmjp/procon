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

class SquaredSubsets {
	public:
	
	long long countSubsets(int n, vector <int> x, vector <int> y) {
		int i,l,r,t,b;
		int N=x.size();
		vector<int> x2=x,y2=y;
		x2.push_back(-1<<29);
		x2.push_back(1<<29);
		y2.push_back(-1<<29);
		y2.push_back(1<<29);
		sort(x2.begin(),x2.end());
		sort(y2.begin(),y2.end());
		x2.erase(unique(x2.begin(),x2.end()),x2.end());
		y2.erase(unique(y2.begin(),y2.end()),y2.end());
		
		set<ll> bm;
		for(l=1;l<=x2.size()-2;l++) for(r=l;r<=x2.size()-2;r++) for(t=1;t<=y2.size()-2;t++) for(b=t;b<=y2.size()-2;b++) {
			if(x2[r]-x2[l]>n) continue;
			if(x2[r+1]-x2[l-1]<=n) continue;
			if(y2[b]-y2[t]>n) continue;
			if(y2[b+1]-y2[t-1]<=n) continue;
			
			ll mask=0;
			FOR(i,N) if(x[i]>=x2[l]&&x[i]<=x2[r]&&y[i]>=y2[t]&&y[i]<=y2[b]) mask |= 1LL<<i;
			if(mask) bm.insert(mask);
		}
		
		return bm.size();
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arr1[] = {-5,0,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 5LL; verify_case(0, Arg3, countSubsets(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10; int Arr1[] = {-5,0,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 5LL; verify_case(1, Arg3, countSubsets(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 100000000; int Arr1[] = {-1,-1,-1,0,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {-1,0,1,1,-1,0,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 21LL; verify_case(2, Arg3, countSubsets(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 5; int Arr1[] = {5,3,6,2,1,6,4,4,7,-1,-4,-7,2,-2,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,-1,8,-5,2,5,-8,8,-6,4,3,2,7,3,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 66LL; verify_case(3, Arg3, countSubsets(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1; int Arr1[] = {-1,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 3LL; verify_case(4, Arg3, countSubsets(Arg0, Arg1, Arg2)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SquaredSubsets ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

