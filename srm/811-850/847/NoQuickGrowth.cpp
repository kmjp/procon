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

template<class CC> int LIS_num(vector<CC>& v) {
	int i,N=v.size();
	vector<CC> dp(N,(numeric_limits<CC>::max)()),id(N);
	FOR(i,v.size()) dp[id[i]=lower_bound(dp.begin(),dp.end(),v[i]) - dp.begin()] = v[i]-1;
	return *max_element(id.begin(),id.end())+1;
}

class NoQuickGrowth {
	public:
	int solve(int N, int delta, int spread, int seed) {
		vector<ll> A;
		ll state = seed;
		int i;
		FOR(i,N) {
		    state = (state * 1103515245 + 12345) % (1LL<<31);
		    ll diff=state%(2*spread + 1);
		    A.push_back(i*delta + diff - spread);
		    A[i]=-(A[i]-10*i);
		}
		
		return N-LIS_num(A);
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 7; int Arg1 = 10; int Arg2 = 0; int Arg3 = 47; int Arg4 = 0; verify_case(0, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 7; int Arg1 = 11; int Arg2 = 0; int Arg3 = 47; int Arg4 = 6; verify_case(1, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = -3; int Arg2 = 10000000; int Arg3 = 4747; int Arg4 = 4; verify_case(2, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 1; int Arg2 = 10; int Arg3 = 428341411; int Arg4 = 0; verify_case(3, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  NoQuickGrowth ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

