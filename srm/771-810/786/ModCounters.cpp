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

vector<ll> A;
const ll mo=1000000007;

vector<ll> mulvec(vector<ll>& a,vector<ll>& b) {
	vector<ll> c(a.size(),0);
	int x,y;
	FOR(x,a.size()) FOR(y,b.size()) (c[(x+y)%a.size()]+=a[x]*b[y])%=mo;
	return c;
}

vector<ll> powvec(ll p,vector<ll> a) {
	int i,x,y; vector<ll> r;
	r.resize(a.size());
	r[0]=1;
	while(p) {
		if(p%2) r=mulvec(r,a);
		a=mulvec(a,a);
		p>>=1;
	}
	return r;
}

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


class ModCounters {
	public:
	int findExpectedSum(vector <int> P, int A0, int X, int Y, int N, int K) {
		A.clear();
		A.push_back(A0);
		while(A.size()<N) A.push_back((A.back()*X+Y)%1812447359);
		while(P.size()<N) P.push_back(A[P.size()]);
		int i,j,x,y;
		
		
		int C[512]={};
		FORR(a,P) C[a%512]++;
		
		vector<ll> V(512);
		V[0]=(1-modpow(N)+mo)%mo;
		V[1]=modpow(N)%mo;
		V=powvec(K,V);
		
		ll ret=0;
		FOR(y,512) FOR(x,512) {
			ret+=V[x]*C[(y-x+512)%512]%mo*y%mo;
		}
		
		
		return ret%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 511}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 2; int Arg5 = 1; int Arg6 = 256; verify_case(0, Arg6, findExpectedSum(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1001; int Arg2 = 1001; int Arg3 = 1001; int Arg4 = 2; int Arg5 = 2; int Arg6 = 508; verify_case(1, Arg6, findExpectedSum(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arr0[] = {}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3583; int Arg2 = 1000; int Arg3 = 1812447358; int Arg4 = 2; int Arg5 = 2; int Arg6 = 152; verify_case(2, Arg6, findExpectedSum(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arr0[] = {100, 101}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5000; int Arg2 = 50000; int Arg3 = 100000; int Arg4 = 1000; int Arg5 = 1000; int Arg6 = 856925612; verify_case(3, Arg6, findExpectedSum(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { int Arr0[] = {}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100000000; int Arg2 = 100000000; int Arg3 = 100000000; int Arg4 = 10; int Arg5 = 1000; int Arg6 = 454731206; verify_case(4, Arg6, findExpectedSum(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_5() { int Arr0[] = {}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 501296088; int Arg2 = 234548363; int Arg3 = 703491623; int Arg4 = 2000000; int Arg5 = 41894643; int Arg6 = 804222535; verify_case(5, Arg6, findExpectedSum(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ModCounters ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

