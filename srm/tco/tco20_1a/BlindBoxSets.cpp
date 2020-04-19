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

double prob[51][51][51][51];
double num[51][51][51][51];

class BlindBoxSets {
	public:
	double expectedPurchases(int numSets, int N) {
		ZERO(prob);
		ZERO(num);
		if(numSets==1) prob[0][0][0][N]=1;
		if(numSets==2) prob[0][0][N][0]=1;
		if(numSets==3) prob[0][N][0][0]=1;
		if(numSets==4) prob[N][0][0][0]=1;
		
		int a,b,c,d;
		for(a=N;a>=0;a--) for(b=N;b>=0;b--) for(c=N;c>=0;c--) for(d=N;d>=0;d--) if(prob[a][b][c][d]>0 && a+b+c+d) {
			int all=a+b+c+d;
			double ex=N*1.0/all;
			double p=prob[a][b][c][d];
			double n=num[a][b][c][d]/p;
			
			if(a) {
				prob[a-1][b+1][c][d]+=p*a/all;
				num[a-1][b+1][c][d]+=(ex+n)*p*a/all;
			}
			if(b) {
				prob[a][b-1][c+1][d]+=p*b/all;
				num[a][b-1][c+1][d]+=(ex+n)*p*b/all;
			}
			if(c) {
				prob[a][b][c-1][d+1]+=p*c/all;
				num[a][b][c-1][d+1]+=(ex+n)*p*c/all;
			}
			if(d) {
				prob[a][b][c][d-1]+=p*d/all;
				num[a][b][c][d-1]+=(ex+n)*p*d/all;
			}
		}
		
		return num[0][0][0][0];
		
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; double Arg2 = 1.0; verify_case(0, Arg2, expectedPurchases(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 2; double Arg2 = 3.0; verify_case(1, Arg2, expectedPurchases(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 1; double Arg2 = 2.0; verify_case(2, Arg2, expectedPurchases(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 2; double Arg2 = 5.5; verify_case(3, Arg2, expectedPurchases(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BlindBoxSets ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

