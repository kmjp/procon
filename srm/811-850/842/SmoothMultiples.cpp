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

ll dp[13][2][2][10][10000];
ll p10[15];

class SmoothMultiples {
	public:
	int smooth(ll v,int k) {
		int pre=-1;
		while(v) {
			int cur=v%10;
			v/=10;
			if(pre!=-1&&abs(pre-cur)>k) return 0;
			pre=cur;
		}
		return 1;
		
	}
	
	ll hoge(int K,ll B,ll C) {
		ZERO(dp);
		dp[12][1][1][0][0]=1;
		int d,z,l,p,m,n;
		for(d=11;d>=0;d--) FOR(z,2) FOR(l,2) FOR(p,10) FOR(m,C) {
			ll v=dp[d+1][z][l][p][m];
			if(v==0) continue;
			FOR(n,10) {
				if(z==0&&abs(n-p)>K) continue;
				if(l==1&&n>B/p10[d]%10) continue;
				int nz=(z==1&&n==0);
				ll nl=l&&(n==B/p10[d]%10);
				int nm=(m*10+n)%C;
				dp[d][nz][nl][n][nm]+=v;
			}
		}
		ll ret=0;
		FOR(l,2) FOR(p,10) ret+=dp[0][0][l][p][0];
		return ret;
	}
	
	long long count(int K, long long A, long long B, long long C) {
		if(C>10000) {
			ll ret=0;
			for(ll a=0;a<=B;a+=C) if(a>=A) {
				if(smooth(a,K)) ret++;
			}
			return ret;
		}
		p10[0]=1;
		int i;
		FOR(i,14) p10[i+1]=p10[i]*10;
		
		ll ret=hoge(K,B,C);
		if(A>1) ret-=hoge(K,A-1,C);
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; long long Arg1 = 10LL; long long Arg2 = 33LL; long long Arg3 = 1LL; long long Arg4 = 8LL; verify_case(0, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 1; long long Arg1 = 97LL; long long Arg2 = 102LL; long long Arg3 = 1LL; long long Arg4 = 4LL; verify_case(1, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; long long Arg1 = 97LL; long long Arg2 = 102LL; long long Arg3 = 2LL; long long Arg4 = 2LL; verify_case(2, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 9; long long Arg1 = 123LL; long long Arg2 = 45678LL; long long Arg3 = 3LL; long long Arg4 = 15186LL; verify_case(3, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 3; long long Arg1 = 1234LL; long long Arg2 = 5678LL; long long Arg3 = 73LL; long long Arg4 = 13LL; verify_case(4, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 0; long long Arg1 = 123LL; long long Arg2 = 4567LL; long long Arg3 = 1LL; long long Arg4 = 12LL; verify_case(5, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { int Arg0 = 9; long long Arg1 = 3LL; long long Arg2 = 99999999995LL; long long Arg3 = 1LL; long long Arg4 = 99999999993LL; verify_case(6, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SmoothMultiples ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

