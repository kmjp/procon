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

ll pos[1010101];

class JumpAcrossTheRiver {
	public:
	int ok(ll L,int N,int J) {
		int cur=0;
		int i;
		FOR(i,J) {
			if(cur>=N) return 1;
			cur=lower_bound(pos,pos+N+1,pos[cur]+L+1)-pos-1;
		}
		return cur>=N;
		
	}
	long long minLength(int N, int M, int J) {
		int i;
		for(i=1;i<=N;i++) {
			pos[i]=pos[i-1]+1+(1LL*(i-1)*(i-1))%M;
		}
		pos[N+1]=1LL<<61;
		ll ret=1LL<<60;
		for(i=59;i>=0;i--) if(ok((ret-(1LL<<i)),N,J)) ret-=1LL<<i;
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 1; int Arg2 = 1; long long Arg3 = 10LL; verify_case(0, Arg3, minLength(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 1; int Arg2 = 3; long long Arg3 = 4LL; verify_case(1, Arg3, minLength(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 1234567; int Arg2 = 10; long long Arg3 = 82LL; verify_case(2, Arg3, minLength(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 1234567; int Arg2 = 4; long long Arg3 = 87LL; verify_case(3, Arg3, minLength(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 123456; int Arg1 = 1000000007; int Arg2 = 2; long long Arg3 = 27561114912135LL; verify_case(4, Arg3, minLength(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  JumpAcrossTheRiver ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

