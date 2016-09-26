#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

class OthersXor {
	public:
	long long minSum(vector <int> X) {
		
		ll ret=0;
		int i;
		FOR(i,30) {
			ll n[2]={};
			int mi=0;
			ll num=1010;
			FORR(x,X) {
				if(x==-1) mi++;
				else n[(x>>i)&1]++;
			}
			
			if(n[1]%2==0) num=min(num,n[1]);
			if(n[0]%2==1) num=min(num,n[0]);
			if(mi) {
				if(n[1]%2==1) num=min(num,n[1]+1);
				if(n[0]%2==0) num=min(num,n[0]+1);
			}
			if(num>1000) return -1;
			ret += num<<i;
		}
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,-1,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 3LL; verify_case(0, Arg1, minSum(Arg0)); }
	void test_case_1() { int Arr0[] = {0,0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = -1LL; verify_case(1, Arg1, minSum(Arg0)); }
	void test_case_2() { int Arr0[] = {70,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 170LL; verify_case(2, Arg1, minSum(Arg0)); }
	void test_case_3() { int Arr0[] = {-1,0,-1,100,36}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 164LL; verify_case(3, Arg1, minSum(Arg0)); }
	void test_case_4() { int Arr0[] = {0,536870912,0,536870912,0,536870912,0,536870912,0,536870912,
0,536870912,0,536870912,0,536870912,0,536870912,0,536870912,
1073741823,1073741823,1073741823,123456789,987654321,804289383}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 11992352010LL; verify_case(4, Arg1, minSum(Arg0)); }
	void test_case_5() { int Arr0[] = {1287325,424244444,92759185,812358213,1000000000,825833522,749092703}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = -1LL; verify_case(5, Arg1, minSum(Arg0)); }
	void test_case_6() { int Arr0[] = {-1,-1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(6, Arg1, minSum(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  OthersXor ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
