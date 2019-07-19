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

vector<ll> C;
vector<int> E[202020];
int T[202020];
ll mo=1000000007;
int id;
ll ret;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

class ETSums {
	public:
	void dfs(int cur,int d) {
		int L=id++;
		FORR(e,E[cur]) dfs(e,d+1);
		int R=id;
		
		if(d==1) {
			(ret+=C[cur]*(R-L))%=mo;
		}
		else if(d>1) {
			ll a=modpow(d,L)*(modpow(d,R-L)+mo-1)%mo*modpow(d-1)%mo;
			(ret+=C[cur]*a)%=mo;
		}
		
		
	}
	int findSumOfETSums(int N, vector <int> parent, vector <int> cost, int D, int seed, int MX) {
		vector<ll> A(2*N);
		A[0]=seed;
		int i;
		for(i=1;i<2*N;i++) A[i] = (A[i-1] * 1103515245LL + 12345) %2147483648;
		for(i=parent.size();i<N;i++) parent.push_back(A[i]%min(i,D)+i-min(i,D));
		for(i=cost.size();i<N;i++) cost.push_back(A[N+i]%MX);
		C.clear();
		FOR(i,N) C.push_back(cost[i]);
		FOR(i,N) E[i].clear();
		for(i=1;i<N;i++) E[parent[i]].push_back(i);
		id=1;
		ret=0;
		dfs(0,0);
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arr1[] = {-1,0,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4,3,3,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; int Arg4 = 0; int Arg5 = 5; int Arg6 = 405; verify_case(0, Arg6, findSumOfETSums(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 5; int Arr1[] = {-1,0,0,1,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5,0,3,2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; int Arg4 = 0; int Arg5 = 6; int Arg6 = 294; verify_case(1, Arg6, findSumOfETSums(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 4; int Arr1[] = {-1,0,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,2,3,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; int Arg4 = 0; int Arg5 = 4; int Arg6 = 5; verify_case(2, Arg6, findSumOfETSums(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arg0 = 10; int Arr1[] = {-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7; int Arg4 = 176; int Arg5 = 15; int Arg6 = 2425; verify_case(3, Arg6, findSumOfETSums(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { int Arg0 = 100000; int Arr1[] = {-1,0,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; int Arg4 = 0; int Arg5 = 1000000000; int Arg6 = 412779665; verify_case(4, Arg6, findSumOfETSums(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ETSums ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

