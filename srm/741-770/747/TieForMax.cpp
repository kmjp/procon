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



long double comb(int P_,int Q_) {
	static const int N_=1020;
	static long double C_[N_][N_];
	
	if(C_[0][0]==0) {
		int i,j;
		FOR(i,N_) C_[i][0]=C_[i][i]=1;
		for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j]);
	}
	if(P_<0 || P_>N_ || Q_<0 || Q_>P_) return 0;
	return C_[P_][Q_];
}
long double hcomb(int P_,int Q_) { return (P_==0&&Q_==0)?1:comb(P_+Q_-1,Q_);}

long double dp[51][51][51][2];


class TieForMax {
	public:
	double getProbability(int t, int p) {
		
		ZERO(dp);
		dp[0][t][0][0]=1;
		int i,j,k,l,b;
		FOR(i,p) {
			FOR(j,t+1) FOR(k,t+1) FOR(b,2) if(dp[i][j][k][b]) {
				FOR(l,j+1) {
					if(l>k)       dp[i+1][j-l][l][0]+=dp[i][j][k][b]*comb(j,l);
					else if(l==k) dp[i+1][j-l][k][1]+=dp[i][j][k][b]*comb(j,l);
					else if(l<k)  dp[i+1][j-l][k][b]+=dp[i][j][k][b]*comb(j,l);
				}
			}
		}
		
		double ok=0,tot=0;
		FOR(k,t+1) {
			ok+=dp[p][0][k][1];
			tot+=dp[p][0][k][0]+dp[p][0][k][1];
		}
		
		return ok/tot;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 7; int Arg1 = 1; double Arg2 = 0.0; verify_case(0, Arg2, getProbability(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; double Arg2 = 0.5; verify_case(1, Arg2, getProbability(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; double Arg2 = 0.2222222222222222; verify_case(2, Arg2, getProbability(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 4; double Arg2 = 0.380859375; verify_case(3, Arg2, getProbability(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TieForMax ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

