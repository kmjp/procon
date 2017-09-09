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

int N;
int P[2020],R[2020];

int D[2020];
vector<int> DV[2020];
int ET[2020];
int S[2020];

class RewardOnATree {
	public:
	int collect(vector <int> parent, vector <int> reward) {
		N=parent.size()+1;
		int i;
		FOR(i,N) DV[i].clear(),ET[i]=0,R[i]=reward[i];
		
		FOR(i,N-1) {
			P[i+1]=parent[i];
			D[i+1]=D[P[i+1]]+1;
			DV[D[i+1]].push_back(i+1);
			if(R[i+1]>=0) ET[D[i+1]]+=R[i+1];
		}
		
		int ma=S[0]=ET[0]=R[0];
		for(int d=1;d<N;d++) if(DV[d].size()) {
			FORR(b,DV[d]) {
				S[b]=-1<<30;
				FORR(a,DV[d]) if(a!=b) S[b]=max(S[b],S[P[a]]+ET[d]+min(0,R[a])+min(0,R[b]));
				S[b]=max(S[b],S[P[b]]+ET[d]+min(0,R[b]));
				ma=max(ma,S[b]);
			}
		}
		
		return ma;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 1, 0, 0, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 3, 2, 1, -1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; verify_case(0, Arg2, collect(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0, 1, 2, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, -2, -1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(1, Arg2, collect(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0, 1, 2, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, -2, -1, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; verify_case(2, Arg2, collect(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-10000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -10000; verify_case(3, Arg2, collect(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {0, 1, 2, 3, 0, 5, 6, 0, 8, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-2, 0, 0, 0, 1, -1, 1, -1, -1, 1, -1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(4, Arg2, collect(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {0, 1, 2, 3, 4, 5, 5, 3, 8, 9, 2, 11, 12, 13, 
12, 11, 16, 1, 18, 19, 20, 21, 21, 20, 19, 25, 
18, 27, 28, 29, 28, 27, 0, 33, 34, 35, 34, 33, 38}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {16, -2745, 504, 1467, 1826, 9191, 9594, -2723, 2120, 
7001, -1555, -2476, -1348, -6262, -9114, -973, 1480, 
-8002, 918, 1364, 133, 8499, -1503, 8823, 5728, -5209,
 8342, 1994, 5696, -6712, 1222, -1272, -2434, 4952, 
-6979, -115, -9386, -5071, 5102, 2180}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 88152; verify_case(5, Arg2, collect(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RewardOnATree ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

