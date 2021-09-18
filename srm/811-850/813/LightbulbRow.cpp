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

class LightbulbRow {
	public:
	string solve(string bulbStates, int startIndex, int goalCount) {
		string ret;
		int i;
		int N=bulbStates.size();
		FOR(i,startIndex) ret+="<";
		FOR(i,N) {
			if(i<goalCount&&bulbStates[i]=='X') ret+="S";
			if(i>=goalCount&&bulbStates[i]=='O') ret+="S";
			if(i<N-1) ret+=">";
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "XXXXXXXXXX"; int Arg1 = 4; int Arg2 = 3; string Arg3 = "S<S>>>S"; verify_case(0, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "XXXXOOOXXX"; int Arg1 = 0; int Arg2 = 3; string Arg3 = "SSSS"; verify_case(1, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "XXXXOOOXXX"; int Arg1 = 0; int Arg2 = 2; string Arg3 = ">>>>S"; verify_case(2, Arg3, solve(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  LightbulbRow ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

