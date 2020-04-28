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

class Byes {
	public:
	
	long long getNumberOfPlayers(long long L, int B) {
		
		if(L==1 && B==0) return 1;
		
		ll cand=1LL<<62;
		int i;
		for(int step=B+1;step<=61;step++) {
			ll tot=2;
			FOR(i,step-1) tot=tot*2-1;
			ll dif=L-tot;
			
			int lef=step-1-B;
			
			for(i=step-2;i>=0&&lef>=0;i--) {
				if(lef==i+1 || ((((1LL<<lef)-1)<<(i-lef))<dif)) {
					lef--;
					tot+=1LL<<i;
					dif-=1LL<<i;
				}
			}
			if(lef==0 && dif<=0) cand=min(cand,tot);
		}
		
		return cand;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 3LL; int Arg1 = 1; long long Arg2 = 3LL; verify_case(0, Arg2, getNumberOfPlayers(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 4LL; int Arg1 = 1; long long Arg2 = 6LL; verify_case(1, Arg2, getNumberOfPlayers(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 1234567890123LL; int Arg1 = 0; long long Arg2 = 2199023255552LL; verify_case(2, Arg2, getNumberOfPlayers(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 200LL; int Arg1 = 4; long long Arg2 = 202LL; verify_case(3, Arg2, getNumberOfPlayers(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Byes ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

