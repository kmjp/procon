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

ll mo=744444499;
ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}
ll rev(ll a) {
	ll r=1, n=mo-2; a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

class CountSubarrays {
	public:
	long long count(vector <int> A, int n, int a, int b, int m, int X) {
		vector<ll> B;
		FORR(v,A) B.push_back(v);
		for(int i=A.size();i<n;i++) B.push_back((B[i-A.size()]*a+b)%m);
		ll ret=0;
		if(X==0) {
			int num=0;
			ret=1LL*n*(n+1)/2;
			FORR(b,B) {
				if(b==0) num=0;
				else num++;
				ret-=num;
			}
		}
		else {
			map<ll,int> mp;
			mp[1]=1;
			ll cur=1;
			FORR(b,B) {
				if(b==0) {
					mp.clear();
					mp[1]=1;
					cur=1;
				}
				else {
					cur=cur*b%mo;
					ret+=mp[cur*modpow(X)%mo];
					mp[cur]++;
				}
			}
		}
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 5; int Arg3 = 7; int Arg4 = 11; int Arg5 = 2; long long Arg6 = 4LL; verify_case(0, Arg6, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 0; int Arg3 = 0; int Arg4 = 744444499; int Arg5 = 0; long long Arg6 = 5LL; verify_case(1, Arg6, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arr0[] = {332561219,121884851,427632830,369957091,549417829,685227621,436551677,351304445,243813223,371998688}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 94749; int Arg2 = 330563283; int Arg3 = 311776610; int Arg4 = 744444499; int Arg5 = 222370756; long long Arg6 = 8LL; verify_case(2, Arg6, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CountSubarrays ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

