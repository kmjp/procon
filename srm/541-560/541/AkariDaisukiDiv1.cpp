#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

//-------------------------------------------------------

ll mo=1000000007;

class AkariDaisukiDiv1 {
	public:
	int dp[2][51];
	int countF(string W, string A, string D, string S, string F, int k) {
		int i,j;
		ll ret=0,add;
		
		while(S.size()<=100 && k) S=W+S+A+S+D, k--;
		FOR(i,(int)S.size()-(int)F.size()+1) ret+=S.substr(i,F.size())==F;
		if(k<=0) return (int) ret;
		string s1=S,s2=S;
		
		FOR(i,F.size()+5) {
			if(k--<=0) return (int) ret;
			s1=s1.substr(0,100);
			s2=s2.substr(s2.size()-100);
			
			add=0;
			
			string ss=s2+A+s1;
			s1=W+s1;
			s2=s2+D;
			FOR(j,W.size()) add+=F==s1.substr(j,F.size());
			for(j=100-F.size()+1;j<100+A.size();j++) add+=F==ss.substr(j,F.size());
			FOR(j,D.size()) add+=F==s2.substr(s2.size()-F.size()-j,F.size());
			s1=s1.substr(0,100);
			s2=s2.substr(s2.size()-100);
			
			ret = (ret*2+add) % mo;
		}
		
		while(k-->0) ret=(ret*2+add) % mo;
		return (int)ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "a"; string Arg1 = "b"; string Arg2 = "c"; string Arg3 = "x"; string Arg4 = "axb"; int Arg5 = 2; int Arg6 = 2; verify_case(0, Arg6, countF(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { string Arg0 = "a"; string Arg1 = "b"; string Arg2 = "c"; string Arg3 = "x"; string Arg4 = "abcdefghij"; int Arg5 = 1; int Arg6 = 0; verify_case(1, Arg6, countF(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { string Arg0 = "a"; string Arg1 = "a"; string Arg2 = "a"; string Arg3 = "b"; string Arg4 = "aba"; int Arg5 = 2; int Arg6 = 4; verify_case(2, Arg6, countF(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { string Arg0 = "a"; string Arg1 = "b"; string Arg2 = "c"; string Arg3 = "d"; string Arg4 = "baadbdcbadbdccccbaaaadbdcbadbdccbaadbdcba"; int Arg5 = 58; int Arg6 = 191690599; verify_case(3, Arg6, countF(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { string Arg0 = "a"; string Arg1 = "x"; string Arg2 = "y"; string Arg3 = "b"; string Arg4 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"; int Arg5 = 49; int Arg6 = 1; verify_case(4, Arg6, countF(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_5() { string Arg0 = "waai"; string Arg1 = "akari"; string Arg2 = "daisuki"; string Arg3 = "usushio"; string Arg4 = "id"; int Arg5 = 10000000; int Arg6 = 127859200; verify_case(5, Arg6, countF(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_6() { string Arg0 = "vfsebgjfyfgerkqlr"; string Arg1 = "ezbiwls"; string Arg2 = "kjerx"; string Arg3 = "jbmjvaawoxycfndukrjfg"; string Arg4 = "bgjfyfgerkqlrvfsebgjfyfgerkqlrvfsebgjfyfgerkqlrvfs"; int Arg5 = 1575724; int Arg6 = 483599313; verify_case(6, Arg6, countF(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  AkariDaisukiDiv1 ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
