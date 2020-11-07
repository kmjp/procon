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

ll dp[101010];
const ll mo=1000000007;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

class Cascade {
	public:
	int expectedPower(int N, vector <int> costPrefix, vector <int> powerPrefix, string S, int seed, int CM, int PM, int CT) {
		vector<ll> C,P;
		FORR(c,costPrefix) C.push_back(c);
		FORR(p,powerPrefix) P.push_back(p);
		FORR(c,S) c=c=='Y';
		int L=C.size();
		ll state=seed;
		int i;
		for(int i=L;i<N;i++) {
			state = (state * 1103515245 + 12345) % (1LL<<31);
			C.push_back(state%CM);
			state = (state * 1103515245 + 12345) % (1LL<<31);
			P.push_back(state%PM);
			state = (state * 1103515245 + 12345) % (1LL<<31);
			S.push_back(state<CT);
		}
		
		vector<pair<int,int>> cand;
		FOR(i,N) cand.push_back({C[i],i});
		sort(ALL(cand));
		int num=0;
		ll sum=0;
		ll ret=0;
		FOR(i,N) {
			while(cand[num].first<cand[i].first) {
				(sum+=dp[num])%=mo;
				num++;
			}
			dp[i]=P[cand[i].second];
			if(S[cand[i].second]&&num) (dp[i]+=sum*modpow(num))%=mo;
			ret+=dp[i];
		}
		return ret%mo*modpow(N)%mo;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = {10, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {100, 200}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "NN"; int Arg4 = 0; int Arg5 = 1; int Arg6 = 1; int Arg7 = 0; int Arg8 = 150; verify_case(0, Arg8, expectedPower(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_1() { int Arg0 = 2; int Arr1[] = {10, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {100, 201}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "NN"; int Arg4 = 0; int Arg5 = 1; int Arg6 = 1; int Arg7 = 0; int Arg8 = 500000154; verify_case(1, Arg8, expectedPower(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_2() { int Arg0 = 2; int Arr1[] = {10, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {100, 200}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "NY"; int Arg4 = 0; int Arg5 = 1; int Arg6 = 1; int Arg7 = 0; int Arg8 = 200; verify_case(2, Arg8, expectedPower(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_3() { int Arg0 = 6; int Arr1[] = {1, 1, 1, 2, 1, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10, 20, 30, 40, 50, 60}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "NNNYNY"; int Arg4 = 0; int Arg5 = 1; int Arg6 = 1; int Arg7 = 0; int Arg8 = 666666712; verify_case(3, Arg8, expectedPower(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_4() { int Arg0 = 10; int Arr1[] = {4, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {47, 42}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "YN"; int Arg4 = 474747; int Arg5 = 10; int Arg6 = 100; int Arg7 = 1250000000; int Arg8 = 487500069; verify_case(4, Arg8, expectedPower(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Cascade ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

