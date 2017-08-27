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

string YES="Possible";
string NO="Impossible";

class HarmoniousGarden {
	public:
	string isPossible(int n, int k, int L) {
		int ok[51][51]={};
		
		int i,j;
		int tot=0;
		for(i=0;i<=n;i++) ok[i][0]=1;
		for(i=1;;i++) {
			if(i==1) tot+=L;
			else tot+=L-1;
			if(tot>n) break;
			for(j=tot;j<=n;j++) ok[j][i]=1;
		}
		
		if(L%2==0) {
			for(int lp=2;lp<=50;lp++) {
				int need=2+(L-2)/2*lp;
				int cycle=lp*(lp-1)/2;
				if(cycle<=k) for(j=need;j<=n;j++) ok[need][cycle]=1;
			}
			for(i=1;i<=n;i++) for(j=1;j<=k;j++) {
				int x,y;
				for(x=4;x<=i;x++) for(y=1;y<=j-1;y++) if(ok[x][y]&&(ok[i-x][j-y] || ok[i-x+1][j-y])) ok[i][j]=1;
				if(ok[i][j]==1) {
					for(x=i+(L-1);x<=n;x+=L-1) ok[x][j]=1;
				}
			}
		}
		
		
		return ok[n][k]?YES:NO;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 8; int Arg1 = 2; int Arg2 = 4; string Arg3 = "Possible"; verify_case(0, Arg3, isPossible(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 3; string Arg3 = "Impossible"; verify_case(1, Arg3, isPossible(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 2; int Arg2 = 3; string Arg3 = "Possible"; verify_case(2, Arg3, isPossible(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 50; int Arg1 = 1; int Arg2 = 47; string Arg3 = "Possible"; verify_case(3, Arg3, isPossible(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 50; int Arg1 = 2; int Arg2 = 47; string Arg3 = "Impossible"; verify_case(4, Arg3, isPossible(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  HarmoniousGarden ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

