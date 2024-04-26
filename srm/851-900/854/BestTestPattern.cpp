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

class BestTestPattern {
	public:
	string solve(string correctAnswers, int maxLen) {
		string ret="Z";
		int num=0;
		int i,j,k;
		int N=correctAnswers.size();
		for(i=1;i<=maxLen;i++) {
			string V;
			int ok=0;
			FOR(j,i) {
				int C[6]={};
				for(k=j;k<N;k+=i) C[correctAnswers[k]-'A']++;
				int x=0;
				FOR(k,6) if(C[k]>C[x]) x=k;
				ok+=C[x];
				V+=(char)('A'+x);
			}
			if(ok>num) {
				num=ok;
				ret=V;
			}
			else if(ok==num) ret=min(ret,V);
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "AACAAACBAACA"; int Arg1 = 5; string Arg2 = "AACA"; verify_case(0, Arg2, solve(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "ABCABCAB"; int Arg1 = 3; string Arg2 = "ABC"; verify_case(1, Arg2, solve(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "FCFBFAFDFEFCFBFEFDF"; int Arg1 = 4; string Arg2 = "FAFB"; verify_case(2, Arg2, solve(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "EEEEEEE"; int Arg1 = 3; string Arg2 = "E"; verify_case(3, Arg2, solve(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "AACAAACBAACA"; int Arg1 = 3; string Arg2 = "A"; verify_case(4, Arg2, solve(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BestTestPattern ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

