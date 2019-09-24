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

ll D[5050505];

class MahdiJumping {
	public:
	long long minDis(int n, int A, int B, int a, int b) {
		int i;
		FOR(i,n+1) D[i]=1LL<<60;
		D[0]=0;
		queue<int> Q1,Q2;
		Q1.push(0);
		while(Q1.size() || Q2.size()) {
			int cur;
			if(Q2.empty() || (Q1.size() && D[Q1.front()]<=D[Q2.front()])) {
				cur=Q1.front();
				Q1.pop();
			}
			else {
				cur=Q2.front();
				Q2.pop();
			}
			
			int na=cur+1;
			int nb=(1LL*A*cur+B)%n;
			if(na<n && D[na]>D[cur]+a) {
				D[na]=D[cur]+a;
				Q1.push(na);
			}
			if(D[nb]>D[cur]+b) {
				D[nb]=D[cur]+b;
				Q2.push(nb);
			}
		}
		return D[n-1];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 7; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; int Arg4 = 5; long long Arg5 = 6LL; verify_case(0, Arg5, minDis(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 2; int Arg2 = 2; int Arg3 = 1; int Arg4 = 2; long long Arg5 = 3LL; verify_case(1, Arg5, minDis(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 5; int Arg2 = 5; int Arg3 = 5; int Arg4 = 5; long long Arg5 = 20LL; verify_case(2, Arg5, minDis(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MahdiJumping ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

