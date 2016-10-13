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

class XMarksTheSpot {
	public:
	int countArea(vector <string> board) {
		int L=51,R=0,T=51,B=0;
		int H=board.size(), W=board[0].size();
		vector<int> V;
		int y,x;
		FOR(y,H) FOR(x,W) {
			if(board[y][x]=='O') {
				L=min(L,x);
				R=max(R,x);
				T=min(T,y);
				B=max(B,y);
			}
			if(board[y][x]=='?') V.push_back(y*100+x);
		}
		
		int ret=0;
		for(int mask=0;mask<1<<V.size();mask++) {
			int L2=L,R2=R,T2=T,B2=B;
			FOR(x,V.size()) if(mask&(1<<x)) {
				L2=min(L2,V[x]%100);
				R2=max(R2,V[x]%100);
				T2=min(T2,V[x]/100);
				B2=max(B2,V[x]/100);
			}
			ret += (R2-L2+1)*(B2-T2+1);
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
"?.",
".O"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, countArea(Arg0)); }
	void test_case_1() { string Arr0[] = {
"???",
"?O?",
"???"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1952; verify_case(1, Arg1, countArea(Arg0)); }
	void test_case_2() { string Arr0[] = {
"...?.",
"?....",
".O...",
"..?..",
"....?"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 221; verify_case(2, Arg1, countArea(Arg0)); }
	void test_case_3() { string Arr0[] = {"OOOOOOOOOOOOOOOOOOOOO"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 21; verify_case(3, Arg1, countArea(Arg0)); }
	void test_case_4() { string Arr0[] = {"?????????OO??????????"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9963008; verify_case(4, Arg1, countArea(Arg0)); }
	void test_case_5() { string Arr0[] = {
"OOO",
"O?O",
"OOO",
"..."
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 18; verify_case(5, Arg1, countArea(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  XMarksTheSpot ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
