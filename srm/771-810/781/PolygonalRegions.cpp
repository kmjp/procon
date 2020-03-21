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

const ll mo=1000000007;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

class PolygonalRegions {
	public:
	int expectedRegions(int N) {
		ll ret=1;
		ll rev=modpow(N);
		int i,j,x,y;
		for(i=1;i<=N;i++) {
			for(j=1;j<i-1;j++) {
				if(i==N&&j==1) continue;
				ll prob=i*rev%mo*j%mo*rev%mo;
				ret+=prob;
				for(x=1;x<j;x++) for(y=j+1;y<i;y++) {
					ll prob2=x*rev%mo*y%mo*rev%mo;
					ret+=prob*prob2%mo;
				}
			}
		}
		return ret%mo;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; verify_case(0, Arg1, expectedRegions(Arg0)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 31250002; verify_case(1, Arg1, expectedRegions(Arg0)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 346100029; verify_case(2, Arg1, expectedRegions(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PolygonalRegions ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

