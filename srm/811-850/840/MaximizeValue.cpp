#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

ll mo;
ll T;

__int128 modpow(__int128 a, ll n = mo-2) {
	__int128 r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

vector<ll> enumdiv(ll n) {
	vector<ll> S;
	for(ll i=2;i*i<=n;i++) if(n%i==0) {S.push_back(i); if(i*i!=n) S.push_back(n/i); }
	sort(S.begin(),S.end());
	return S;
}

class MaximizeValue {
	public:
	
	long long solve(long long P, int K) {
		ll N=2;
		int i;
		FOR(i,K) N*=P;
		
		mo=N;
		T=N/2/P*(P-1);
		
		vector<ll> cand=enumdiv(T);
		ll ma=0,ret=0;
		cout<<N<<endl;
		for(i=2;i<=min(10000LL,N);i++) if(__gcd((ll)i,N)==1) {
			int ok=1;
			FORR(c,cand) {
				if(modpow(i,c)==1) {
					ok=0;
					break;
				}
			}
			cout<<i<<" "<<ok<<endl;
			if(ok) return i;
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 3LL; int Arg1 = 1; long long Arg2 = 5LL; verify_case(0, Arg2, solve(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 23LL; int Arg1 = 9; long long Arg2 = 47LL; verify_case(1, Arg2, solve(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MaximizeValue ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

