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

class LandSplitter {
	public:
	long long cheapest(int N, int A, int B) {
		ll mi=1LL<<60;
		
		for(ll i=1;1LL*A*i<=N;i++) {
			ll a=1LL*i*A;
			ll b=1LL*i*B;
			
			if(a<=N&&N<=b) {
				ll pat=0;
				if(A==B || b==N) {
					pat=1LL*B*(N/B)*(N-B);
				}
				else {
					ll lef=N-a;
					int nb=lef/(B-A);
					pat+=1LL*nb*B*(N-B);
					pat+=1LL*(A+(lef%(B-A)))*(N-(A+(lef%(B-A))));
					pat+=1LL*(i-nb-1)*A*(N-A);
				}
				mi=min(mi,pat);
			}
			
		}
		if(mi==1LL<<60) return -1;
		mi/=2;
		return mi;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 12; int Arg1 = 3; int Arg2 = 3; long long Arg3 = 54LL; verify_case(0, Arg3, cheapest(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 3; int Arg2 = 4; long long Arg3 = 33LL; verify_case(1, Arg3, cheapest(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 47; int Arg1 = 1; int Arg2 = 47; long long Arg3 = 0LL; verify_case(2, Arg3, cheapest(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 70; int Arg1 = 40; int Arg2 = 50; long long Arg3 = -1LL; verify_case(3, Arg3, cheapest(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 47; int Arg1 = 4; int Arg2 = 7; long long Arg3 = 945LL; verify_case(4, Arg3, cheapest(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  LandSplitter ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

