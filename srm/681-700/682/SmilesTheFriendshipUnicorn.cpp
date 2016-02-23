#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int M[2020][2020];
vector<int> E[2020];
int dist[2020];

class SmilesTheFriendshipUnicorn {
	public:
	
	string hasFriendshipChain(int N, vector <int> A, vector <int> B) {
		int i,x,y;
		
		ZERO(M);
		FOR(i,N) E[i].clear();
		FOR(i,A.size()) {
			E[A[i]].push_back(B[i]);
			E[B[i]].push_back(A[i]);
			M[A[i]][B[i]]=M[B[i]][A[i]]=1;
		}
		FOR(i,N) {
			FOR(y,E[i].size()) FOR(x,y) {
				int xx=E[i][x], yy=E[i][y];
				int ok=0;
				if(E[xx].size()>2 || (E[xx].size()==2&&M[xx][yy]==0)) ok++;
				if(E[yy].size()>2 || (E[yy].size()==2&&M[xx][yy]==0)) ok++;
				if(ok==2) return "Yay!";
			}
		}
		return ":(";
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
//	void test_case_0() { int Arg0 = 5; int Arr1[] = {0, 1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 3, 4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Yay!"; verify_case(0, Arg3, hasFriendshipChain(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; int Arr1[] = {0, 1, 2, 3, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 3, 0, 4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Yay!"; verify_case(1, Arg3, hasFriendshipChain(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 6; int Arr1[] = {0, 0, 0, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 3, 4, 5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = ":("; verify_case(2, Arg3, hasFriendshipChain(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 8; int Arr1[] = {1, 3, 4, 3, 4, 3, 0, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {7, 7, 7, 4, 6, 5, 4, 7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Yay!"; verify_case(3, Arg3, hasFriendshipChain(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 7; int Arr1[] = {0, 1, 1, 5, 4, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5, 2, 3, 6, 1, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = ":("; verify_case(4, Arg3, hasFriendshipChain(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 42; int Arr1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41}
; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Yay!"; verify_case(5, Arg3, hasFriendshipChain(Arg0, Arg1, Arg2)); }
	void test_case_0() { int Arg0 = 5; int Arr1[] = {0,1,2,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,0,3,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = ":("; verify_case(0, Arg3, hasFriendshipChain(Arg0, Arg1, Arg2)); }


// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SmilesTheFriendshipUnicorn ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
