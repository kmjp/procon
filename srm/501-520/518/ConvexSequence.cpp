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

class ConvexSequence {
	public:
	int N;
	long long getMinimum(vector <int> a) {
		int i,x,y,j;
		vector<ll> b,c;
		
		N=a.size();
		if(N<=2) return 0;
		
		ll ret=0;
		FOR(i,N-1) b.push_back((a[i+1]-a[i]));
		
		FOR(i,N-2) {
			ll mi=1LL<<35;
			ll tot=0;
			FOR(j,N-1-i) {
				tot+=b[i+j];
				ll hoge=tot/(j+1);
				if(tot<0 && tot%(j+1)) hoge--;
				mi=min(mi,hoge);
			}
			
			if(mi<b[i]) {
				ret+=b[i]-mi;
				b[i+1]+=b[i]-mi;
				b[i]=mi;
			}
		}
		
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {6,5,1,5,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 7LL; verify_case(0, Arg1, getMinimum(Arg0)); }
	void test_case_1() { int Arr0[] = {3,0,1,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(1, Arg1, getMinimum(Arg0)); }
	void test_case_2() { int Arr0[] = {1,1,1,0,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 5LL; verify_case(2, Arg1, getMinimum(Arg0)); }
	void test_case_3() { int Arr0[] = {854159326, 317144183, 781399725, 287076509, 894967145, 882577367, 174517516, 134415519,
 274494874, 709819883, 59717133, 732212854, 40551288, 232526958, 811785438, 930853743,
 946882902, 321325300, 397702677, 376192501, 599310562, 889156198, 135776890, 882710939,
 823196361, 681959076, 318666702, 94469186, 536320456, 116468376, 530320850, 436708006,
 903344748, 659080120, 774722507, 967315412, 566063635, 43970906, 497687103, 781266213,
 876086123, 366960001, 587364849, 191948103, 172568553, 539762057, 83507466, 71569625,
 686305822, 663789601}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 20178337330LL; verify_case(3, Arg1, getMinimum(Arg0)); }
	void test_case_4() { int Arr0[] = {5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(4, Arg1, getMinimum(Arg0)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ConvexSequence ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

