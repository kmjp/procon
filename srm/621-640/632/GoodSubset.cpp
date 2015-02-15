#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

vector<ll> enumdiv(ll n) {
	vector<ll> S;
	for(ll i=1;i*i<=n;i++) if(n%i==0) {S.push_back(i); if(i*i!=n) S.push_back(n/i); }
	sort(S.begin(),S.end());
	return S;
}


class GoodSubset {
	public:
	int numberOfSubsets(int goodValue, vector <int> d) {
		vector<ll> V=enumdiv(goodValue);
		ll mo=1000000007;
		map<ll,int> M;
		int i,j,k;
		FOR(i,V.size()) M[V[i]]=i;
		
		vector<ll> dp(V.size(),0);
		dp[0]=1;
		FOR(i,d.size()) {
			ll v=d[i];
			for(j=V.size()-1;j>=0;j--) if(goodValue%(V[j]*v)==0) dp[M[V[j]*v]]=(dp[M[V[j]*v]]+dp[j])%mo;
		}
		return (dp[V.size()-1]+(mo-(goodValue==1)))%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arr1[] = {2,3,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, numberOfSubsets(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 6; int Arr1[] = {2,3,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, numberOfSubsets(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arr1[] = {1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; verify_case(2, Arg2, numberOfSubsets(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 12; int Arr1[] = {1,2,3,4,5,6,7,8,9,10,11,12}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(3, Arg2, numberOfSubsets(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 5; int Arr1[] = {1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(4, Arg2, numberOfSubsets(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  GoodSubset ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
