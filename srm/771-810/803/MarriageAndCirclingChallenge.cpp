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
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int E[601][601];

class MarriageAndCirclingChallenge {
	public:
	ll state;
	ll rnd() {
		state = (state * 1103515245 + 12345)%(1LL<<31);
	    return state %100;
	}
	
	long long solve(int N, int threshold, int s) {
		state=s;
		
		ZERO(E);
		int i,j;
		for(i=0;i<N;i++) {
			for(j=i+1;j<N;j++) {
				if(rnd()<threshold) E[i][j]=1;
				else E[j][i]=1;
			}
		}
		ll ret=0;
		
		for(int B=0;B<N;B++) for(int C=B+1;C<N;C++) {
			int BAC=0,CAB=0;
			for(int A=0;A<N;A++) {
				if(A==B||A==C) continue;
				if(E[B][A]&&E[A][C]) BAC++;
				if(E[C][A]&&E[A][B]) CAB++;
			}
			ret+=BAC*CAB;
		}
		
		return ret/2;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 0; int Arg2 = 12345; long long Arg3 = 0LL; verify_case(0, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 50; int Arg2 = 47; long long Arg3 = 4LL; verify_case(1, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 9; int Arg1 = 20; int Arg2 = 1234567; long long Arg3 = 29LL; verify_case(2, Arg3, solve(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MarriageAndCirclingChallenge ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

