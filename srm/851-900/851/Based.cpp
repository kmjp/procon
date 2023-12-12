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

const ll mo=1000000007;
const ll ma=1LL<<60;

ll mult(ll a, ll b) {
	if(a==0||b==0) return 0;
	if(b==1) return a;
	if(ma/a<=b) return ma;
	return a*b;
}

ll mypow(ll a, ll n) {
	ll r=1;
	if(n<0) return 0;
	while(n) r=mult(r,((n%2)?a:1)),a=mult(a,a),n>>=1;
	return r;
}
map<ll,ll> memo;

class Based {
	public:
	ll hoge(ll v,int a,int b) {
		ll L=1,R=sqrt(v)+3;
		while(L+1<R) {
			ll M=(L+R)/2;
			if(mypow(M,a)+mypow(M,b)>=v) R=M;
			else L=M;
		}
		if(mypow(R,a)+mypow(R,b)==v) {
			return R;
		}
		else {
			return ma;
		}
		
	}
	
	ll hoge(ll v) {
		if(v<=6) return 2;
		ll ret=v-1;
		if(v%2==0) ret=v/2;
		if(memo.count(v)) ret=min(ret,memo[v]);
		
		ret=min(ret,hoge(v,3,3));
		ret=min(ret,hoge(v,3,2));
		ret=min(ret,hoge(v,3,1));
		ret=min(ret,hoge(v,3,0));
		ret=min(ret,hoge(v,3,-1));
		ret=min(ret,hoge(v,2,2));
		ret=min(ret,hoge(v,2,1));
		ret=min(ret,hoge(v,2,0));
		ret=min(ret,hoge(v,2,-1));
		
		return ret;
	}
	int solve(long long A, long long S, int N) {
		int i;
		for(ll a=2;a<=1000000;a++) {
			ll b=a*a*a*a;
			if(b>=ma) break;
			while(b<ma) {
				if(memo.count(b)==0) memo[b]=a;
				ll c=b;
				while(1) {
					if(memo.count(b+c)==0) memo[b+c]=a;
					if(c==0) break;
					c/=a;
				}
				b=mult(b,a);
			}
		}
		ll ret=0;
		FOR(i,N) (ret+=hoge(A+S*i))%=mo;
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 30LL; long long Arg1 = 2LL; int Arg2 = 5; int Arg3 = 28; verify_case(0, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_1() { long long Arg0 = 1LL; long long Arg1 = 4417LL; int Arg2 = 2; int Arg3 = 49; verify_case(1, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_2() { long long Arg0 = 987654321987654321LL; long long Arg1 = 12347LL; int Arg2 = 2; int Arg3 = 611117350; verify_case(2, Arg3, solve(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Based ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

