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

const int prime_max = 1000000;
int NP,prime[100000],divp[prime_max];
map<int,int> M;

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime[NP++]=i;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

class SimpleMathProblemDiv2 {
	public:
	long long calculate(int X) {
		
		cprime();
		ll ret=0;
		int i;
		FOR(i,NP) {
			ll v=1;
			for(int j=prime[i];j<=X;j+=prime[i]) {
				if(v*prime[i]<=j) v*=prime[i];
				ret+=v;
			}
		}
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; long long Arg1 = 0LL; verify_case(0, Arg1, calculate(Arg0)); }
	void test_case_1() { int Arg0 = 8; long long Arg1 = 36LL; verify_case(1, Arg1, calculate(Arg0)); }
	void test_case_2() { int Arg0 = 15; long long Arg1 = 128LL; verify_case(2, Arg1, calculate(Arg0)); }
	void test_case_3() { int Arg0 = 77444; long long Arg1 = 3296580744LL; verify_case(3, Arg1, calculate(Arg0)); }
	void test_case_4() { int Arg0 = 444777; long long Arg1 = 111293895799LL; verify_case(4, Arg1, calculate(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SimpleMathProblemDiv2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

