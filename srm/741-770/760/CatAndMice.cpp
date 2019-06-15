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

int P[5050505];
int T[5050505];

class CatAndMice {
	public:
	long long countDirections(int N, int C) {
		if(N==C) return 8;
		
		int i,j;
		FOR(i,5000001) {
			P[i]=1;
			T[i]=i;
		}
		for(i=2;i<=5000000;i++) if(P[i]) {
			for(j=i;j<=5000000;j+=i) {
				P[j]=0;
				T[j]=T[j]/i*(i-1);
			}
		}
		
		
		ll ret=0;
		for(int x=C;x<=N;x+=C) {
			int a=x/C;
			if(1LL*a*(C+1)>N) {
				ret+=T[a];
			}
		}
		
		return ret*8;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; long long Arg2 = 8LL; verify_case(0, Arg2, countDirections(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 1; long long Arg2 = 8LL; verify_case(1, Arg2, countDirections(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 19; int Arg1 = 3; long long Arg2 = 48LL; verify_case(2, Arg2, countDirections(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1234; int Arg1 = 3; long long Arg2 = 180608LL; verify_case(3, Arg2, countDirections(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1234; int Arg1 = 1212; long long Arg2 = 0LL; verify_case(4, Arg2, countDirections(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CatAndMice ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

