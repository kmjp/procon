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
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

vector<int> LIS(vector<int>& v) {
	int i,N=v.size();
	vector<int> dp(N,1<<30),id(N);
	FOR(i,v.size()) {
		id[i] = lower_bound(dp.begin(),dp.end(),v[i]) - dp.begin();
		// id[i] = lower_bound(dp.begin(),dp.end(),v[i]+1) - dp.begin(); //‚±‚¤‚·‚é‚Æ“¯‚¶’l‚à‹–—e‚·‚é
		dp[id[i]] = v[i];
	}
	int nl = *max_element(id.begin(),id.end());
	vector<int> ret(nl+1);
	FOR(i,N) if(id[N-1-i] == nl) ret[nl--] = v[N-1-i];
	return ret;
}

class YetAnotherGraphColoring {
	public:
	int minColors(int n, int a1, int a2, int x, int y, int z, int m) {
		vector<int> A;
		A.push_back(a1);
		A.push_back(a2);
		while(A.size()<n) {
			A.push_back((1LL*x*A[A.size()-1]+1LL*y*A[A.size()-2]+z)%m);
		}
		FORR(v,A) v=m-v;
		auto V=LIS(A);
		return V.size();
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 987654321; int Arg2 = 123456789; int Arg3 = 12345; int Arg4 = 678; int Arg5 = 9; int Arg6 = 1000000000; int Arg7 = 3; verify_case(0, Arg7, minColors(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void _test_case_1() { int Arg0 = 100; int Arg1 = 10; int Arg2 = 20; int Arg3 = 1; int Arg4 = 0; int Arg5 = 10; int Arg6 = 123456789; int Arg7 = 1; verify_case(1, Arg7, minColors(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_1() { int Arg0 = 200000; int Arg1 = 200000; int Arg2 = 199999; int Arg3 = 1; int Arg4 = 0; int Arg5 = 200000; int Arg6 = 200001; int Arg7 = 1; verify_case(1, Arg7, minColors(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  YetAnotherGraphColoring ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

