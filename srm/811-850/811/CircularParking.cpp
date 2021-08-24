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

class CircularParking {
	public:
	long long park(int N, int A, int B, int C) {
		vector<ll> P;
		int i;
		set<int> S;
		FOR(i,N) {
			P.push_back((1LL*A*i*i+1LL*B*i+C)%N);
			S.insert(i);
		}
		ll ret=0;
		FORR(p,P) {
			auto it=S.lower_bound(p);
			if(it==S.end()) it=S.begin(),ret+=N;
			ret+=*it-p;
			S.erase(it);
			
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 47; int Arg1 = 0; int Arg2 = 1; int Arg3 = 0; long long Arg4 = 0LL; verify_case(0, Arg4, park(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 47; int Arg1 = 0; int Arg2 = 0; int Arg3 = 42; long long Arg4 = 1081LL; verify_case(1, Arg4, park(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 30; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; long long Arg4 = 175LL; verify_case(2, Arg4, park(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 1; int Arg2 = 2; int Arg3 = 3; long long Arg4 = 4LL; verify_case(3, Arg4, park(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CircularParking ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

