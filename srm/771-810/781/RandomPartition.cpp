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


const ll mo=786433;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

class RandomPartition {
	public:
	int expectedSum(vector <int> A, int N, int M, int B1, int B2) {
		
		int i;
		for(i=A.size();i<2*N;i++) {
			A.push_back((1LL*A[i-1]*B1+1LL*A[i-2]*B2)%M);
		}
		sort(ALL(A));
		ll sum=0;
		FOR(i,N) sum+=mo-A[i];
		FOR(i,N) sum+=A[i+N];
		sum=(sum%mo+mo)%mo;
		
		return sum*modpow(N)%mo;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 14; int Arg3 = 13; int Arg4 = 13; int Arg5 = 1; verify_case(0, Arg5, expectedSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arr0[] = {17,29,1,2,1,10,9,1729}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 9271; int Arg3 = 9; int Arg4 = 10; int Arg5 = 593461; verify_case(1, Arg5, expectedSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arr0[] = {1,7,2,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 1729; int Arg3 = 17; int Arg4 = 29; int Arg5 = 315441; verify_case(2, Arg5, expectedSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RandomPartition ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

