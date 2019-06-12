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

map<int,int> M;

class DivisorSequences {
	public:
	
	int longest(int N) {
		if(N==0) return 0;
		if(N<=2) return 1;
		if(M.count(N)) return M[N];
		
		int i,j;
		int ma=2;
		for(i=1;i*i<=N;i++) if(N%i==0) {
			vector<int> C={i,N/i};
			
			FORR(c,C) {
				int le=(N-c)/c;
				for(j=2;j*j<=le;j++) if(le%j==0) {
					ma=max(ma,1+longest(le/j));
					ma=max(ma,1+longest(j));
				}
			}
		}
		return M[N]=ma;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 4; verify_case(0, Arg1, longest(Arg0)); }
	void test_case_1() { int Arg0 = 12; int Arg1 = 2; verify_case(1, Arg1, longest(Arg0)); }
	void test_case_2() { int Arg0 = 34; int Arg1 = 4; verify_case(2, Arg1, longest(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DivisorSequences ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

