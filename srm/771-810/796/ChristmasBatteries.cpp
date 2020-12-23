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

vector<ll> V[5];

class ChristmasBatteries {
	public:
	int mostFun(int B, int N, int X, int Y, int Z, int M) {
		int i;
		FOR(i,5) V[i].clear();
		int sum=0;
		FOR(i,N) {
			int a=(1LL*X*i*i+1LL*Y*i+Z)%M;
			if(i%5==0) sum+=a;
			V[i%5].push_back(a);
		}
		FOR(i,5) sort(ALL(V[i]));
		FOR(i,5) reverse(ALL(V[i]));
		
		int ma=0;
		int a1,a2,a3,a4;
		for(a1=0;a1<=min(B,(int)V[1].size());a1++) {
			for(a2=0;a2<=V[2].size()&&a1+a2*2<=B;a2++) {
				for(a3=0;a3<=V[3].size()&&a3*3+a2*2+a1<=B;a3++) {
					for(a4=0;a4<=V[4].size()&&a4*4+a3*3+a2*2+a1<=B;a4++) {
						int tot=0;
						FOR(i,a1) tot+=V[1][i];
						FOR(i,a2) tot+=V[2][i];
						FOR(i,a3) tot+=V[3][i];
						FOR(i,a4) tot+=V[4][i];
						ma=max(ma,tot);
					}
				}
			}
		}
		
		
		return sum+ma;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 5; int Arg2 = 1; int Arg3 = 1; int Arg4 = 1; int Arg5 = 1000; int Arg6 = 1; verify_case(0, Arg6, mostFun(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 5; int Arg2 = 1; int Arg3 = 1; int Arg4 = 1; int Arg5 = 1000; int Arg6 = 14; verify_case(1, Arg6, mostFun(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 5; int Arg2 = 1; int Arg3 = 1; int Arg4 = 1; int Arg5 = 13; int Arg6 = 11; verify_case(2, Arg6, mostFun(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 10000; int Arg2 = 123; int Arg3 = 456; int Arg4 = 789; int Arg5 = 1; int Arg6 = 0; verify_case(3, Arg6, mostFun(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { int Arg0 = 7; int Arg1 = 4; int Arg2 = 3; int Arg3 = 5; int Arg4 = 7; int Arg5 = 997; int Arg6 = 100; verify_case(4, Arg6, mostFun(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_5() { int Arg0 = 2; int Arg1 = 12345; int Arg2 = 234; int Arg3 = 34; int Arg4 = 5; int Arg5 = 117; int Arg6 = 143371; verify_case(5, Arg6, mostFun(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ChristmasBatteries ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

