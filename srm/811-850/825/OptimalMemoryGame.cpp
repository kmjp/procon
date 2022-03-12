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

class OptimalMemoryGame {
	public:
	int findPairs(string known) {
		int N=known.size()/2;
		int C[26]={};
		FORR(c,known) if(c!='-') C[c-'A']++;
		int D[3]={};
		int i;
		FOR(i,26) {
			if(C[i]==1) D[1]++;
			if(C[i]==2) D[2]++;
		}
		D[0]=N-D[1]-D[2];
		int ret=D[2];
		if(D[0]==0) {
			ret+=D[1];
		}
		else if(D[1]==0&&D[0]==1) {
			ret++;
		}
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "AEIOUIAEUO"; int Arg1 = 5; verify_case(0, Arg1, findPairs(Arg0)); }
	void test_case_1() { string Arg0 = "----------"; int Arg1 = 0; verify_case(1, Arg1, findPairs(Arg0)); }
	void test_case_2() { string Arg0 = "--------A----E-----IAO----U---"; int Arg1 = 1; verify_case(2, Arg1, findPairs(Arg0)); }
	void test_case_3() { string Arg0 = "-X"; int Arg1 = 1; verify_case(3, Arg1, findPairs(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  OptimalMemoryGame ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

