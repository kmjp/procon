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

class IOIVoting {
	public:
	vector <int> winners(int N, vector <int> votes) {
		int A[55][55];
		int y,x;
		int i;
		FOR(y,N) FOR(x,N) A[y][x]=votes[y*N+x];
		FOR(y,N) FOR(x,y) {
			int z=min(A[x][y],A[y][x]);
			A[x][y]-=z;
			A[y][x]-=z;
		}
		FOR(i,N) A[i][i]=10000;
		int z;
		FOR(z,N) FOR(x,N) FOR(y,N) A[x][y]=max(A[x][y],min(A[x][z],A[z][y]));
		
		vector<int> ret;
		FOR(y,N) {
			int ok=1;
			FOR(x,N) if(A[y][x]<A[x][y]) ok=0;
			if(ok) ret.push_back(y);
		}
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 5; int Arr1[] = { 0, 20, 26, 30, 22,
 25,  0, 16, 33, 18,
 19, 29,  0, 17, 24,
 15, 12, 28,  0, 14,
 23, 27, 21, 31,  0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, winners(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arr1[] = {0, 1, 1, 1,
 1, 0, 1, 1,
 1, 1, 0, 1,
 1, 1, 1, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 2, 3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, winners(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, winners(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 4; int Arr1[] = { 0, 10, 11, 12,
 13,  0, 14, 15,
 97, 98,  0, 99,
 16, 17, 18,  0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, winners(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 5; int Arr1[] = { 0,  0,  0,  0,  0,
  3,  0,  3, 99,  3,
  0,  0,  0,  0,  0,
  4, 99,  5,  0,  6,
  0,  0,  0,  0,  0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, winners(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 3; int Arr1[] = {0, 1, 0,
 0, 0, 1,
 1, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, winners(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  IOIVoting ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

