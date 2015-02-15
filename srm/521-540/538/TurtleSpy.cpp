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

class TurtleSpy {
	public:
	double maxDistance(vector <string> commands) {
		vector<int> cmd;
		int dp[51][360];
		int i,x;
		double fw=0,bw=0;
		ITR(it,commands) {
			if(sscanf(it->c_str(),"forward %d",&i)>0) fw+=i;
			if(sscanf(it->c_str(),"backward %d",&i)>0) bw+=i;
			if(sscanf(it->c_str(),"left %d",&i)>0)  cmd.push_back(i);
			if(sscanf(it->c_str(),"right %d",&i)>0)  cmd.push_back(360-i);
		}
		
		ZERO(dp);
		dp[0][0]=1;
		FOR(i,cmd.size()) {
			FOR(x,360) if(dp[i][x]) {
				dp[i+1][x] = dp[i+1][(x+cmd[i])%360] = 1;
			}
		}
		double ma=0;
		FOR(x,360) if(dp[cmd.size()][x]) {
			double dist=sqrt(fw*fw+bw*bw-2*fw*bw*cos((x)*atan(1)*4/180.0));
			ma=max(ma,dist);
		}
		return ma;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"forward 100", "backward 100", "left 90" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 141.4213562373095; verify_case(0, Arg1, maxDistance(Arg0)); }
	void test_case_1() { string Arr0[] = {"left 45", "forward 100", "right 45", "forward 100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 200.0; verify_case(1, Arg1, maxDistance(Arg0)); }
	void test_case_2() { string Arr0[] = {"left 10", "forward 40",  "right 30", "left 10", "backward 4", "forward 4" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 40.58520737741619; verify_case(2, Arg1, maxDistance(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TurtleSpy ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
