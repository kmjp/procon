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

class MinesweeperStrings {
	public:
	string generate(int N, long long X) {
		
		if(X>=1LL<<N) return "";
		X++;
		string S;
		
		int i;
		int pre=0;
		FOR(i,N) {
			
			if(pre==0) {
				if(X<=1LL<<(N-1-i)) {
					S+="*";
				}
				else {
					X-=1LL<<(N-1-i);
					S+=".";
					pre=1;
				}
			}
			else {
				if(X<=1LL<<(N-1-i)) {
					S+=".";
				}
				else {
					X-=1LL<<(N-1-i);
					S+="*";
					pre=0;
				}
			}
		}
		FOR(i,N) if(S[i]=='.') {
			int x='0';
			if(i&&S[i-1]=='*') x++;
			if(i+1<N&&S[i+1]=='*') x++;
			S[i]=x;
		}
		
		
		
		return S;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; long long Arg1 = 0LL; string Arg2 = "*"; verify_case(0, Arg2, generate(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; long long Arg1 = 1LL; string Arg2 = "0"; verify_case(1, Arg2, generate(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; long long Arg1 = 47LL; string Arg2 = ""; verify_case(2, Arg2, generate(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 7; long long Arg1 = 71LL; string Arg2 = "0001*2*"; verify_case(3, Arg2, generate(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 14; long long Arg1 = 9876543210987654LL; string Arg2 = ""; verify_case(4, Arg2, generate(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 47; long long Arg1 = 47LL; string Arg2 = "*****************************************11*2*1"; verify_case(5, Arg2, generate(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MinesweeperStrings ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

