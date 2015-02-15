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


ll pw(int cur,int p) {
	static ll pw_[14][3010], mo=1000000007;
	if(!pw_[cur][0]) {
		pw_[cur][0]=1;
		for(int j=0;j<3000;j++) pw_[cur][j+1]=pw_[cur][j]*cur%mo;
	}
	return pw_[cur][p];
}

class CandyCupRunningCompetition {
	public:
	int M;
	vector<int> E[2002];
	int reach(int t){
		int vis[2001],i;
		ZERO(vis);
		queue<int> Q;
		vis[0]=1;
		Q.push(0);
		while(Q.size()) {
			int cur=Q.front();
			Q.pop();
			FOR(i,E[cur].size()) {
				int tar=E[cur][i];
				if(vis[tar]==0) vis[tar]=1,Q.push(tar);
			}
		}
		return vis[t];
	}
	
	int findMaximum(int N, vector <int> A, vector <int> B) {
		
		M=A.size();
		int i;
		ll ret=0;
		FOR(i,N) E[i].clear();
		for(i=M-1;i>=0;i--) {
			E[A[i]].push_back(B[i]);
			E[B[i]].push_back(A[i]);
			if(reach(N-1)) {
				ret+=pw(3,i);
				E[A[i]].pop_back();
				E[B[i]].pop_back();
			}
		}
		return (int)(ret%1000000007);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(0, Arg3, findMaximum(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arr1[] = {0,1,0,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,3,2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; verify_case(1, Arg3, findMaximum(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(2, Arg3, findMaximum(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 5; int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(3, Arg3, findMaximum(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 6; int Arr1[] = {1,1,2,0,4,3,0,1,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,2,3,1,5,5,2,4,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 39; verify_case(4, Arg3, findMaximum(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CandyCupRunningCompetition ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
