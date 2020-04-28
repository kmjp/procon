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

ll C[15];

unordered_map<ll,int> memo;
vector<int> B;

class ReProduct {
	public:
	ll hoge(ll cur) {
		if(cur<10) return B[cur];
		if(memo.count(cur)) return memo[cur];
		ll v=1,w=cur;
		while(w) {
			v*=w%10;
			w/=10;
		}
		memo[cur]=hoge(v)+1;
		return memo[cur];
	}
	
	void dfs(int cur,ll sum,ll dig,int d) {
		if(d>18) return;
		if(sum%10==0 && sum!=10) return;
		if(d>1) {
			ll v=hoge(sum)+1;
			if(v<=11) C[v]=min(C[v],dig);
		}
		for(int i=cur;i<=9;i++) dfs(i,sum*i,dig*10+i,d+1);
	}
	
	
	long long minimize(vector <int> base, int goal) {
		int i,j;
		B=base;
		FOR(i,12) C[i]=1LL<<60;
		C[1+base[0]]=min(C[1+base[0]],10LL);
		FOR(i,10) C[base[i]]=min(C[base[i]],(ll)i);
		memo.clear();
		vector<int> V;
		dfs(1,1,0,0);
		
		return C[goal];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; long long Arg2 = 11LL; verify_case(0, Arg2, minimize(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0,0,0,0,0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; long long Arg2 = 39LL; verify_case(1, Arg2, minimize(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {2,0,0,0,0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; long long Arg2 = 0LL; verify_case(2, Arg2, minimize(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {2,2,2,2,2,2,2,2,0,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; long long Arg2 = 18LL; verify_case(3, Arg2, minimize(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {2,1,2,2,1,1,1,0,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; long long Arg2 = 268LL; verify_case(4, Arg2, minimize(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ReProduct ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

