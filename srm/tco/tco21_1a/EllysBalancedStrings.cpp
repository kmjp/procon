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
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

class EllysBalancedStrings {
	public:
	int getMin(string S) {
		int C[26]={};
		map<char,int> M;
		M['A']=M['E']=M['U']=M['I']=M['O']=1;
		int x,y;
		FOR(x,26) {
			C[x]=100;
			FOR(y,26) if(M['A'+x]!=M['A'+y]) C[x]=min(C[x],abs(x-y));
		}
		int X=0,Y=0,i;
		vector<int> AA,BB;
		FORR(s,S) {
			if(M[s]==1) {
				X++;
				AA.push_back(1);
			}
			else {
				Y++;
				BB.push_back(C[s-'A']);
			}
		}
		sort(ALL(AA));
		sort(ALL(BB));
		int ret=0;
		if(X>Y) {
			ret=(X-Y)/2;
		}
		else {
			FOR(i,(Y-X)/2) ret+=BB[i];
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "TOPCODER"; int Arg1 = 1; verify_case(0, Arg1, getMin(Arg0)); }
	void test_case_1() { string Arg0 = "BANANA"; int Arg1 = 0; verify_case(1, Arg1, getMin(Arg0)); }
	void test_case_2() { string Arg0 = "WITHOUTITIAMJUSTESPR"; int Arg1 = 2; verify_case(2, Arg1, getMin(Arg0)); }
	void test_case_3() { string Arg0 = "NOZAPHODJUSTVERYVERYIMPROBABLE"; int Arg1 = 5; verify_case(3, Arg1, getMin(Arg0)); }
	void test_case_4() { string Arg0 = "SYZYGY"; int Arg1 = 8; verify_case(4, Arg1, getMin(Arg0)); }
	void test_case_5() { string Arg0 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; int Arg1 = 8; verify_case(5, Arg1, getMin(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EllysBalancedStrings ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

