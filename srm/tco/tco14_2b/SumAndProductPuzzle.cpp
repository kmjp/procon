#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

const int MA=5000000+50;
int divp[MA];
int comp[MA];
int samp[MA];
int ok[MA];

class SumAndProductPuzzle {
	public:
	
	long long getSum(int A, int B) {
		int i,j,k;
		
		ZERO(divp);
		ZERO(comp);
		ZERO(samp);
		ZERO(ok);
		for(i=2;i<MA;i++) if(divp[i]==0) {
			divp[i]=1;
			for(j=i*2;j<MA;j+=i) divp[j]=i;
		}
		for(i=1;i*i<MA;i++) for(j=i;i*(ll)j<MA;j++) if(divp[i+j-1]>1 && comp[i*j]<2) comp[i*j]++,samp[i*j]=i+j;
		for(i=2;i<MA;i++) if(comp[i]==1) ok[samp[i]]=1;
		ll ret=0;
		for(i=A;i<=B;i++) if(ok[i]) ret+=i;
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 30; int Arg1 = 33; long long Arg2 = 33LL; verify_case(0, Arg2, getSum(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 8; int Arg1 = 11; long long Arg2 = 19LL; verify_case(1, Arg2, getSum(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 40; int Arg1 = 43; long long Arg2 = 0LL; verify_case(2, Arg2, getSum(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 47; int Arg1 = 74; long long Arg2 = 168LL; verify_case(3, Arg2, getSum(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 2; long long Arg2 = 0LL; verify_case(4, Arg2, getSum(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE 
int main(int argc,char** argv) {
  SumAndProductPuzzle ___test;
  if(argc==1)  ___test.run_test(-1);
  else  ___test.run_test(atoi(argv[1]));
}
