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

ll mo=1000000007;
map<int,vector<int>> M;

map<ll,int> enumpr(ll n) {
	map<ll,int> V;
	for(ll i=2;i*i<=n;i++) while(n%i==0) V[i]++,n/=i;
	if(n>1) V[n]++;
	return V;
}
ll modpow(ll a, ll n) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


class GCDLCM2 {
	public:
	int getMaximalSum(vector <int> start, vector <int> d, vector <int> cnt) {
		int N=start.size();
		int i,j;
		vector<ll> V;
		FOR(i,N) FOR(j,cnt[i]) V.push_back(start[i]+d[i]*j);
		sort(V.begin(),V.end());
		
		M.clear();
		FORR(r,V) {
			auto v=enumpr(r);
			FORR(rr,v) M[rr.first].push_back(rr.second);
		}
		
		vector<ll> VV;
		FOR(i,V.size()) VV.push_back(1);
		FORR(r,M) {
			vector<int> vv=r.second;
			sort(vv.begin(),vv.end());
			reverse(vv.begin(),vv.end());
			FOR(i,vv.size()) (VV[i]*=modpow(r.first,vv[i]))%=mo;
		}
		
		ll ret=0;
		FORR(r,VV) ret+=r;
		return ret%mo;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; verify_case(0, Arg3, getMaximalSum(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 15; verify_case(1, Arg3, getMaximalSum(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 32; verify_case(2, Arg3, getMaximalSum(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 33; verify_case(3, Arg3, getMaximalSum(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {5 ,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {23, 45}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {50000, 50000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 804225394; verify_case(4, Arg3, getMaximalSum(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  GCDLCM2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
