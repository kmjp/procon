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

int N[2];
string S[2];
int P[2][101];

map<vector<int>,int> M;


class TreesAndBrackets {
	public:
	
	int ok(int L1,int R1,int L2,int R2) {
		if(R2<=L2) return 1;
		if(R1-L1<R2-L2) return 0;
		
		if(M.count({L1,R1,L2,R2})) return M[{L1,R1,L2,R2}];
		
		if(ok(L1+1,P[0][L1]-1,L2+1,P[1][L2]-1)) return M[{L1,R1,L2,R2}]=ok(P[0][L1]+1,R1,P[1][L2]+1,R2);
		return M[{L1,R1,L2,R2}]=ok(P[0][L1]+1,R1,L2,R2);
	}
	
	string check(string t1, string t2) {
		M.clear();
		S[0]=t1;
		S[1]=t2;
		int i,j;
		FOR(i,2) {
			N[i]=S[i].size();
			vector<int> V;
			FOR(j,N[i]) {
				if(S[i][j]=='(') {
					V.push_back(j);
				}
				else {
					P[i][j]=V.back();
					P[i][V.back()]=j;
					V.pop_back();
				}
			}
		}
		
		if(ok(0,N[0],0,N[1])) return "Possible";
		else return "Impossible";
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "(())"; string Arg1 = "()"; string Arg2 = "Possible"; verify_case(0, Arg2, check(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "()"; string Arg1 = "()"; string Arg2 = "Possible"; verify_case(1, Arg2, check(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "(()()())"; string Arg1 = "((()))"; string Arg2 = "Impossible"; verify_case(2, Arg2, check(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "((())((())())())"; string Arg1 = "(()(())())"; string Arg2 = "Possible"; verify_case(3, Arg2, check(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "((())((())())())"; string Arg1 = "((()()()()()))"; string Arg2 = "Impossible"; verify_case(4, Arg2, check(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TreesAndBrackets ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

