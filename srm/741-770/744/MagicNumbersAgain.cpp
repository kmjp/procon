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

class MagicNumbersAgain {
	public:
	int ok(ll v) {
		vector<int> a;
		while(v) {
			a.push_back(v%10);
			v/=10;
		}
		reverse(ALL(a));
		int i;
		FOR(i,(int)a.size()-1) {
			if(i%2==0 && a[i]>=a[i+1]) return 0;
			if(i%2==1 && a[i]<=a[i+1]) return 0;
		}
		return 1;
	}
	
	int count(long long A, long long B) {
		vector<ll> V;
		for(ll i=1;i<=100001;i++) {
			if(ok(i*i)) V.push_back(i*i);
		}
		
		return lower_bound(ALL(V),B+1)-lower_bound(ALL(V),A);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 64LL; int Arg2 = 7; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 50LL; long long Arg1 = 60LL; int Arg2 = 0; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 121LL; long long Arg1 = 121LL; int Arg2 = 1; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 5679LL; long long Arg1 = 1758030LL; int Arg2 = 73; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 1304164LL; long long Arg1 = 2000000LL; int Arg2 = 14; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MagicNumbersAgain ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

