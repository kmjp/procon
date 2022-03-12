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

double dp[55];
double prob[55];

class RollAllOnes {
	public:
	double solve(int N, int D) {
		double p=1.0/D;
		double q=1-p;
		ZERO(dp);
		
		int i,x,y;
		
		for(i=1;i<=N;i++) {
			
			ZERO(prob);
			prob[0]=1;
			FOR(x,i) {
				for(y=i;y>=0;y--) {
					prob[y+1]+=prob[y]*p;
					prob[y]=prob[y]*q;
				}
			}
			double fail=prob[0];
			double success=1-fail;
			dp[i]+=1.0/success;
			for(x=1;x<=i;x++) {
				dp[i]+=prob[x]/success*dp[i-x];
			}
			cout<<i<<" "<<dp[i]<<endl;
		}
		return dp[N];
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 6; double Arg2 = 6.000000000000002; verify_case(0, Arg2, solve(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; double Arg2 = 2.6666666666666665; verify_case(1, Arg2, solve(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 10; double Arg2 = 17.900563216158464; verify_case(2, Arg2, solve(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RollAllOnes ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

