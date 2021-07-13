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

ll K[303030];
int O[303030];
class LunchLine {
	public:
	long long simulate(int N, int M, int A, int B, int C, int D, int E) {
		K[0]=A;
		K[1]=B;
		int i,j,x,y;
		for(i=2;i<M;i++) K[i]=(C*K[i-1]+D*K[i-2]+E)%N;
		FOR(i,N) O[i]=i;
		FOR(i,M) O[K[i]]=N+i;
		
		vector<pair<int,int>> V;
		FOR(i,N) V.push_back({O[i],i});
		ll ret=0;
		sort(ALL(V));
		FOR(i,N) ret+=1LL*i*V[i].second;
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 250000; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; int Arg6 = 0; long long Arg7 = 5208302083375000LL; verify_case(0, Arg7, simulate(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 5; int Arg2 = 2; int Arg3 = 3; int Arg4 = 1; int Arg5 = 0; int Arg6 = 1; long long Arg7 = 225LL; verify_case(1, Arg7, simulate(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 5; int Arg2 = 2; int Arg3 = 4; int Arg4 = 1; int Arg5 = 0; int Arg6 = 2; long long Arg7 = 210LL; verify_case(2, Arg7, simulate(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 100000; int Arg2 = 4; int Arg3 = 7; int Arg4 = 0; int Arg5 = 0; int Arg6 = 3; long long Arg7 = 249LL; verify_case(3, Arg7, simulate(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_4() { int Arg0 = 11; int Arg1 = 30; int Arg2 = 4; int Arg3 = 7; int Arg4 = 1; int Arg5 = 2; int Arg6 = 3; long long Arg7 = 229LL; verify_case(4, Arg7, simulate(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  LunchLine ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

