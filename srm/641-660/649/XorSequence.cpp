#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll A[300000];

class XorSequence {
	public:
	ll ret;
	
	ll dfs(int D,vector<vector<int> >& V) {
		if(D<0 || V.empty()) return 0;
		int i,j;
		vector<vector<int> > NV;
		ll ret0=0,ret1=0;
		
		FOR(i,V.size()) {
			vector<int> v[2];
			int n0=0,n1=0;
			FOR(j,V[i].size()) {
				if(V[i][j]&(1<<D)) {
					n1++;
					ret1 += n0;
					v[1].push_back(V[i][j]);
				}
				else {
					n0++;
					ret0 += n1;
					v[0].push_back(V[i][j]);
				}
			}
			if(v[0].size()>1) NV.push_back(v[0]);
			if(v[1].size()>1) NV.push_back(v[1]);
		}
		return max(ret0,ret1)+dfs(D-1,NV);
		
	}
	
	long long getmax(int N, int sz, int A0, int A1, int P, int Q, int R) {
		int i;
		
		A[0]=A0;
		A[1]=A1;
		for(i=2;i<sz;i++) A[i]=(A[i-2]*P+A[i-1]*Q+R)%N;
		
		vector<vector<int> > V;
		V.push_back(vector<int>());
		FOR(i,sz) V.back().push_back(A[i]);
		return dfs(29,V);
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 6; int Arg2 = 3; int Arg3 = 2; int Arg4 = 0; int Arg5 = 1; int Arg6 = 3; long long Arg7 = 8LL; verify_case(0, Arg7, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_1() { int Arg0 = 8; int Arg1 = 8; int Arg2 = 2; int Arg3 = 5; int Arg4 = 3; int Arg5 = 1; int Arg6 = 4; long long Arg7 = 13LL; verify_case(1, Arg7, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_2() { int Arg0 = 8; int Arg1 = 7; int Arg2 = 3; int Arg3 = 0; int Arg4 = 1; int Arg5 = 2; int Arg6 = 4; long long Arg7 = 12LL; verify_case(2, Arg7, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_3() { int Arg0 = 32; int Arg1 = 15; int Arg2 = 7; int Arg3 = 9; int Arg4 = 11; int Arg5 = 2; int Arg6 = 1; long long Arg7 = 60LL; verify_case(3, Arg7, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_4() { int Arg0 = 131072; int Arg1 = 131072; int Arg2 = 7; int Arg3 = 7; int Arg4 = 1; int Arg5 = 0; int Arg6 = 0; long long Arg7 = 0LL; verify_case(4, Arg7, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_5() { int Arg0 = 131072; int Arg1 = 131070; int Arg2 = 411; int Arg3 = 415; int Arg4 = 398; int Arg5 = 463; int Arg6 = 9191; long long Arg7 = 4302679760LL; verify_case(5, Arg7, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }

// END CUT HERE


};
// BEGIN CUT HERE 
int main(int argc,char** argv) {
  XorSequence ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
