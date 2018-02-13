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

ll dp[102][102];

class XorAndLIS {
	public:
	vector<ll> X;
	int N;
	
	void hogege(int n) {
		if(n==0) return;
		sort(X.begin(),X.begin()+n);
		if(X[n-1]==0) return;
		ll v=0;
		for(int i=0;i<=61;i++) if(X[n-1]&(1LL<<i)) v=1LL<<i;
		for(int i=0;i<n-1;i++) if(X[i]&v) X[i]^=X[n-1];
		hogege(n-1);
	}
	
	ll hoge(ll A,ll B,int d) {
		if(A>=1LL<<60) return A;
		if(A==B) return B;
		ll L,R;
		if(A<B) L=-1,R=B;
		if(A>B) L=B,R=1LL<<60;
		
		while(d>=0) {
			ll LL=L,RR=R;
			if((LL^X[d])>=A) R=min(R,(LL^X[d]));
			if((LL^X[d])<A)  L=max(L,(LL^X[d]));
			if((RR^X[d])>=A) R=min(R,(RR^X[d]));
			if((RR^X[d])<A)  L=max(L,(RR^X[d]));
			d--;
		}
		
		return R;
	}
	
	int maximalLength(vector<long long> v) {
		X=v;
		
		N=X.size();
		int i,x,y;
		FOR(x,101) FOR(y,101) dp[x][y]=1LL<<60;
		dp[0][0]=-1;
		FOR(i,N) {
			hogege(i);
			FOR(x,N+1) {
				dp[i+1][x]=min(dp[i+1][x],dp[i][x]);
				if(x) dp[i+1][x]=min(dp[i+1][x],hoge(dp[i][x-1]+1,X[i],i-1));
			}
		}
		
		
		for(i=N;i>=0;i--) if(dp[N][i]<1LL<<60) return i;
		
		return 0;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long Arr0[] = {4,2,1}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, maximalLength(Arg0)); }
	void test_case_1() { long Arr0[] = {0,0,0,0,0,0,0,0,0,0}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, maximalLength(Arg0)); }
	void test_case_2() { long Arr0[] = {1,2,3,4,5,6,7,8,9,10}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(2, Arg1, maximalLength(Arg0)); }
	void test_case_3() { long Arr0[] = {7,3,1}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, maximalLength(Arg0)); }
	void test_case_4() { long Arr0[] = {1008,42,7,5,2,9,75,0,0,12,3,6,81,4,3}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(4, Arg1, maximalLength(Arg0)); }
	void test_case_5() { long Arr0[] = {1000000000000000000}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(5, Arg1, maximalLength(Arg0)); }
	void test_case_6() { long Arr0[] = {10000000000,10000000001}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(6, Arg1, maximalLength(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  XorAndLIS ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

