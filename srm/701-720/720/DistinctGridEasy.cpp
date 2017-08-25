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

class DistinctGridEasy {
	public:
	string checkGrid(int n, int k, vector <int> grid) {
		int y,x;
		FOR(y,n) {
			set<int> S,S2;
			FOR(x,n) S.insert(grid[y*n+x]),S2.insert(grid[x*n+y]);
			if(S.size()!=k || S2.size()!=k) return "Bad";
		}
		return "Good";
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 3; int Arr2[] = {
0,1,2,
1,2,0,
2,0,1
}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Good"; verify_case(0, Arg3, checkGrid(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; int Arr2[] = {
0,1,2,
1,2,0,
2,0,0
}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Bad"; verify_case(1, Arg3, checkGrid(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 2; int Arr2[] = {
0,0,0,0,1,
0,1,0,0,0,
0,0,1,0,0,
1,0,0,0,0,
0,0,0,1,0
}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Good"; verify_case(2, Arg3, checkGrid(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 3; int Arr2[] = {
2,2,0,0,1,
0,1,2,2,0,
0,2,1,0,0,
1,0,0,0,2,
0,0,2,1,0
}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Good"; verify_case(3, Arg3, checkGrid(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 7; int Arg1 = 4; int Arr2[] = {
3,2,1,0,3,2,1,
3,2,1,3,2,1,2,
2,0,3,1,1,0,3,
1,3,0,2,0,3,0,
0,3,1,2,3,2,1,
1,1,1,2,1,0,3,
3,1,2,0,3,2,3
}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Bad"; verify_case(4, Arg3, checkGrid(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DistinctGridEasy ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

