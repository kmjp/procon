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

class FillInTheMaze {
	public:
	vector <string> filled(int R, int C, int X) {
		vector<string> S;
		int y,x;
		FOR(y,2*R+1) S.push_back(string(2*C+1,'#'));
		FOR(y,R) {
			for(x=1;x<=2*C-1;x++) S[1+2*y][x]='.';
		}
		for(y=1;y<=2*R-1;y++) S[y][1]='.';
		
		for(x=1;x<=2*C-1;x+=2) {
			if(X) S[0][x]='.', X--;
			if(X) S[2*R][x]='.', X--;
		}
		for(y=1;y<=2*R-1;y+=2) {
			if(X) S[y][0]='.', X--;
			if(X) S[y][2*C]='.', X--;
		}
		return S;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 6; int Arg2 = 3; string Arr3[] = {"#######.#####", "......#.#...#", "#.###.#.#.#.#", "#.#.......#.#", "#.#######.#.#", "#.......#.#.#", "#########.###" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, filled(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 3; int Arg2 = 2; string Arr3[] = {"#######", ".......", "#######" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, filled(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 8; string Arr3[] = {"#.#.#", ".....", "#.###", ".....", "#.#.#" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, filled(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FillInTheMaze ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

