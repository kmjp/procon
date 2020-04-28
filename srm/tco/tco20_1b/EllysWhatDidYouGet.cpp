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

class EllysWhatDidYouGet {
	public:
	int getCount(int N) {
		int X,Y,Z;
		int ret=0;
		for(X=1;X<=50;X++) {
			for(Y=1;Y<=50;Y++) {
				for(Z=1;Z<=50;Z++) {
					set<int> S;
					for(int i=1;i<=N;i++) {
						int v=(i*X+Y)*Z;
						int r=0;
						while(v) r+=v%10, v/=10;
						S.insert(r);
					}
					if(S.size()==1) ret++;
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
	void test_case_0() { int Arg0 = 9; int Arg1 = 952; verify_case(0, Arg1, getCount(Arg0)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 3515; verify_case(1, Arg1, getCount(Arg0)); }
	void test_case_2() { int Arg0 = 13; int Arg1 = 456; verify_case(2, Arg1, getCount(Arg0)); }
	void test_case_3() { int Arg0 = 42; int Arg1 = 149; verify_case(3, Arg1, getCount(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EllysWhatDidYouGet ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

