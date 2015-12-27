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

class FourStrings {
	public:
	
	int shortestLength(string a, string b, string c, string d) {
		int i,ret=6060,j;
		vector<string> V={a,b,c,d};
		FOR(i,24) {
			int L[4]={};
			for(L[1]=0;L[1]<=V[1].size();L[1]++)
			for(L[2]=0;L[2]<=V[2].size();L[2]++)
			for(L[3]=0;L[3]<=V[3].size();L[3]++) {
				string s=V[0].substr(L[0])+V[1].substr(L[1])+V[2].substr(L[2])+V[3].substr(L[3]);
				if(s.size()>ret) continue;
				int ok=1;
				FOR(j,4) if(s.find(V[j])==string::npos) ok=0;
				if(ok) ret=s.size();
			}
			next_permutation(V.begin(),V.end());
		}
		return ret;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "abc"; string Arg1 = "ab"; string Arg2 = "bc"; string Arg3 = "b"; int Arg4 = 3; verify_case(0, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arg0 = "a"; string Arg1 = "bc"; string Arg2 = "def"; string Arg3 = "ghij"; int Arg4 = 10; verify_case(1, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arg0 = "top"; string Arg1 = "coder"; string Arg2 = "opco"; string Arg3 = "pcode"; int Arg4 = 8; verify_case(2, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arg0 = "thereare"; string Arg1 = "arelots"; string Arg2 = "lotsof"; string Arg3 = "ofcases"; int Arg4 = 19; verify_case(3, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { string Arg0 = "aba"; string Arg1 = "b"; string Arg2 = "b"; string Arg3 = "b"; int Arg4 = 3; verify_case(4, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3)); }
//	void test_case_5() { string Arg0 = "x"; string Arg1 = "x"; string Arg2 = "x"; string Arg3 = "x"; int Arg4 = 1; verify_case(5, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { string Arg0 = "ab"; string Arg1 = "cd"; string Arg2 = "bdc"; string Arg3 = "e"; int Arg4 = 1; verify_case(5, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FourStrings ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
