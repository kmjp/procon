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
ll dp[5050],S[5050];

struct KMP {
	vector<int> failto;
	string p;
	KMP(string s) :p(s) {
		int n=s.size();
		failto.resize(n+1);
		int i,j; j=failto[0]=-1;
		for(i=1;i<=n;i++) {
			while(j>=0&&s[j]!=s[i-1]) j=failto[j];
			failto[i]=++j;
		}
	}
	pair<int,int> match(string& s) { //sのprefixのサイズと、マッチした長さ
		int a,b;
		for(a=b=0;a<s.size();a++) {
			while(b>=0&&p[b]!=s[a]) b=failto[b];
			b++;
			if(b==p.size()) return {a+1,b};
		}
		return {s.size(),b};
		
	}
};


ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

class RollMe {
	public:

	int solve(vector <int> die, string goal) {
		vector<ll> D;
		int N=die.size(),M=goal.size();
		int i,j;
		int s=0;
		
		FORR(d,die) s+=d;
		FORR(d,die) D.push_back(d*modpow(s)%mo);
		
		FORR(g,goal) g-='0';
		KMP kmp(goal);
		
		FOR(i,M) {
			dp[i]=1;
			ll same=0;
			FOR(j,N) {
				string s=goal.substr(0,i)+((char)j);
				int tar=kmp.match(s).second;
				if(tar<=i) {
					same+=D[j];
					(dp[i]+=D[j]*(mo+S[i]-S[tar]))%=mo;
				}
			}
			(dp[i]=dp[i]*modpow(1+mo-same%mo))%=mo;
			S[i+1]=(S[i]+dp[i]+mo)%mo;
		}
		
		return S[M];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {7, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "01"; int Arg2 = 4; verify_case(0, Arg2, solve(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "00"; int Arg2 = 6; verify_case(1, Arg2, solve(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "1011"; int Arg2 = 500000047; verify_case(2, Arg2, solve(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "0123401"; int Arg2 = 78150; verify_case(3, Arg2, solve(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RollMe ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

