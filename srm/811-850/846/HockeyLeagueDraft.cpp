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

class HockeyLeagueDraft {
	public:
	int draft(int P, int T, int seed, int MP, int MT) {
		ll state = seed;
		int i;
		vector<ll> A,D,TA,TD;
		set<pair<int,int>> SA,SD;
		FOR(i,P) {
			state = (state * 1103515245 + 12345)%(1LL<<31);
			A.push_back((state/10)%MP);
			state = (state * 1103515245 + 12345)%(1LL<<31);
			D.push_back((state/10)%MP);
			SA.insert({-A[i],i});
			SD.insert({-D[i],i});
		}
		
		int ret;
		FOR(i,T) {
			state = (state * 1103515245 + 12345)%(1LL<<31);
			TA.push_back((state/10)%MT);
			state = (state * 1103515245 + 12345)%(1LL<<31);
			TD.push_back((state/10)%MT);

			int x=SA.begin()->second;
			int y=SD.begin()->second;
			ll v=(TA[i]+A[x])*(TA[i]+A[x])+TD[i]*TD[i];
			ll w=(TD[i]+D[y])*(TD[i]+D[y])+TA[i]*TA[i];
			ret=min(x,y);
			if(v<w) ret=y;
			if(v>w) ret=x;
			SA.erase({-A[ret],ret});
			SD.erase({-D[ret],ret});
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 3; int Arg2 = 47; int Arg3 = 1000000; int Arg4 = 10000000; int Arg5 = 0; verify_case(0, Arg5, draft(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1_() { int Arg0 = 12; int Arg1 = 7; int Arg2 = 42000; int Arg3 = 100; int Arg4 = 100; int Arg5 = 2; verify_case(1, Arg5, draft(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 500000; int Arg1 = 100000; int Arg2 = 42000; int Arg3 = 3; int Arg4 = 3; int Arg5 = 2; verify_case(1, Arg5, draft(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  HockeyLeagueDraft ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

