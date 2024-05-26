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

class NumReverseEasy {
	public:
	ll rev(ll a) {
		ll v=0;
		while(a) v=v*10+a%10,a/=10;
		return v;
	}
	long long getsum(int A, int B) {
		ll ret=0;
		for(int i=A;i<=B;i++) ret+=max(rev(i),(ll)i);
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 21; int Arg1 = 23; long long Arg2 = 75LL; verify_case(0, Arg2, getsum(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 12; int Arg1 = 21; long long Arg2 = 489LL; verify_case(1, Arg2, getsum(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 97; int Arg1 = 101; long long Arg2 = 495LL; verify_case(2, Arg2, getsum(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 123; int Arg1 = 127; long long Arg2 = 2605LL; verify_case(3, Arg2, getsum(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 100000; long long Arg2 = 6226873030LL; verify_case(4, Arg2, getsum(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  NumReverseEasy ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

