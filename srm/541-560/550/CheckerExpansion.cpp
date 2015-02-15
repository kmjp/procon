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

class CheckerExpansion {
	public:
	
	char cha(ll t,ll X,ll Y) {
		if(t==0) return '.';
		if(t==1) return (X==0&&Y==0)?'A':'.';
		if(t==2) {
			if(X==0&&Y==0) return 'A';
			if(X==1&&Y==1) return 'B';
			if(X==2&&Y==0) return 'B';
			return '.';
		}
		
		ll mp=1;
		while(mp*2<t) mp*=2;
		
		if(X<2*mp&&Y<mp) return cha(mp,X,Y);
		if(X<4*mp&&Y<mp) return cha(t-mp,X-2*mp,Y);
		if(X<3*mp&&Y<2*mp) return cha(t-mp,X-mp,Y-mp);
		return '.';
	}
	
	vector <string> resultAfter(long long t, long long x0, long long y0, int w, int h) {
		vector<string> res;
		int x,y;
		FOR(y,h) {
			res.push_back("");
			FOR(x,w) res.back().push_back(cha(t,x0+x,y0+h-1-y));
		}
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 0LL; long long Arg2 = 0LL; int Arg3 = 4; int Arg4 = 4; string Arr5[] = {"....", "....", "....", "A..." }; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(0, Arg5, resultAfter(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { long long Arg0 = 5LL; long long Arg1 = 4LL; long long Arg2 = 1LL; int Arg3 = 3; int Arg4 = 4; string Arr5[] = {"A..", "...", "B..", ".B." }; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(1, Arg5, resultAfter(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { long long Arg0 = 1024LL; long long Arg1 = 1525LL; long long Arg2 = 512LL; int Arg3 = 20; int Arg4 = 2; string Arr5[] = {"B...B...B...........", ".B.A.B.A.B.........." }; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(2, Arg5, resultAfter(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { long long Arg0 = 53LL; long long Arg1 = 85LL; long long Arg2 = 6LL; int Arg3 = 5; int Arg4 = 14; string Arr5[] = {".....", ".....", "B....", ".B.A.", ".....", ".....", ".....", ".....", ".....", ".....", "B....", ".B...", "..B..", ".A.B." }; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(3, Arg5, resultAfter(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};
// BEGIN CUT HERE 
int main(int argc,char** argv) {
  CheckerExpansion ___test;
  if(argc==1)  ___test.run_test(-1);
  else  ___test.run_test(atoi(argv[1]));
}
