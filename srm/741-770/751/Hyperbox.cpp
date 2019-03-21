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

class Hyperbox {
	public:
	int count(int volume) {
		if(volume%2) return 0;
		ll V=volume/2;
		
		ll ret=0;
		for(ll a=1;4*a*a*a<=V;a++) {
			for(ll b=a;4*a*b*b<=V;b++) {
				for(ll c=b;a*c*c+b*c*c<=V;c++) {
					ll X=a*b*c;
					ll Y=(a*b+b*c+c*a);
					if((V-X)%Y) continue;
					ll d=(V-X)/Y;
					if(d>=c) ret++;
				}
			}
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 8; int Arg1 = 1; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { int Arg0 = 1234567; int Arg1 = 0; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { int Arg0 = 120; int Arg1 = 3; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { int Arg0 = 123456; int Arg1 = 52; verify_case(3, Arg1, count(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Hyperbox ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

