#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

class MinProduct {
	public:
	long long findMin(vector <int> amount, int blank1, int blank2) {
		vector<int> V;
		int i,j;
		FOR(i,10) FOR(j,amount[i]) if(V.size()<blank1+blank2) V.push_back(i);
		
		ll ret=1LL<<60;
		for(int mask=0;mask<1<<(blank1+blank2);mask++) if(__builtin_popcount(mask)==blank1) {
			ll a=0,b=0;
			FOR(i,V.size()) {
				if(mask&(1<<i)) a=a*10+V[i];
				else b=b*10+V[i];
			}
			ret=min(ret,a*b);
		}
		return ret;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1,1,2,1,1,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; long long Arg3 = 3042LL; verify_case(0, Arg3, findMin(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 8; long long Arg3 = 0LL; verify_case(1, Arg3, findMin(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1,3,0,0,0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; long long Arg3 = 11LL; verify_case(2, Arg3, findMin(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0,20,20,20,20,20,20,20,20,20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; int Arg2 = 9; long long Arg3 = 12345678987654321LL; verify_case(3, Arg3, findMin(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {1,0,0,0,1,0,0,5,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; int Arg2 = 3; long long Arg3 = 36556078253LL; verify_case(4, Arg3, findMin(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {0,0,0,0,0,0,0,0,0,18}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; int Arg2 = 8; long long Arg3 = 99999998900000001LL; verify_case(5, Arg3, findMin(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MinProduct ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

