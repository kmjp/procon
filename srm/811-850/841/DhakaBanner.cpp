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

class DhakaBanner {
	public:
	int edit(string S) {
		int N=S.size();
		int ret=N+5;
		
		string T="DHAKA";
		FORR(c,S) {
			FORR(a,T) if(c==a) ret=N+3;
		}
		int i,j,k,x,y;
		FOR(y,N) FOR(j,5) {
			if(S[y]!=T[j]) continue;
			FOR(x,y) FOR(i,j) {
				if(j-i>y-x) continue;
				if(S[x]!=T[i]) continue;
				int cost=N+5;
				
				int a=120*120*(y-x)/(j-i);
				int b=120*120*x-i*a;
				FOR(k,5) {
					int c=a*k+b;
					if(c%(120*120)) continue;
					c/=120*120;
					if(c<0||c>=N) continue;
					if(S[c]==T[k]) cost-=2;
				}
				ret=min(ret,cost);
				
			}
		}
		
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "DHAKA"; int Arg1 = 0; verify_case(0, Arg1, edit(Arg0)); }
	void test_case_1() { string Arg0 = "WELCOMETODHAKABANGLADESH"; int Arg1 = 19; verify_case(1, Arg1, edit(Arg0)); }
	void test_case_2() { string Arg0 = "DDHHAAKKAA"; int Arg1 = 5; verify_case(2, Arg1, edit(Arg0)); }
	void test_case_3() { string Arg0 = "AA"; int Arg1 = 5; verify_case(3, Arg1, edit(Arg0)); }
	void test_case_4() { string Arg0 = "ABBA"; int Arg1 = 5; verify_case(4, Arg1, edit(Arg0)); }
	void test_case_5() { string Arg0 = "RIYADH"; int Arg1 = 7; verify_case(5, Arg1, edit(Arg0)); }
	void test_case_6() { string Arg0 = "TOPCODER"; int Arg1 = 11; verify_case(6, Arg1, edit(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DhakaBanner ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

