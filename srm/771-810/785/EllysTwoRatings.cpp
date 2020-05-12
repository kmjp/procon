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

double F[1010][1010];
double T[1010][1010];


class EllysTwoRatings {
	public:
	double getChance(int N, int A, int B) {
		
		ZERO(F);
		ZERO(T);
		F[A][B]=1;
		double sum=0;
		int x,y;
		while(N--) {
			ZERO(T);
			
			for(y=1;y<=1000;y++) {
				int L=max(1,y-100);
				int R=min(1000,y+100);
				int C=R-L+1;
				for(x=1;x<=1000;x++) if(F[y][x]) {
					T[L][x]+=F[y][x]/C;
					T[R+1][x]-=F[y][x]/C;
				}
			}
			swap(F,T);
			for(y=1;y<=1000;y++) {
				for(x=1;x<=1000;x++) {
					F[y][x]+=F[y-1][x];
				}
			}
			for(y=1;y<=1000;y++) {
				sum+=F[y][y];
				F[y][y]=0;
			}
				
			ZERO(T);
			
			for(y=1;y<=1000;y++) {
				int L=max(1,y-100);
				int R=min(1000,y+100);
				int C=R-L+1;
				for(x=1;x<=1000;x++) if(F[x][y]) {
					T[x][L]+=F[x][y]/C;
					T[x][R+1]-=F[x][y]/C;
				}
			}
			swap(F,T);
			for(y=1;y<=1000;y++) {
				for(x=1;x<=1000;x++) {
					F[x][y]+=F[x][y-1];
				}
			}
			for(y=1;y<=1000;y++) {
				sum+=F[y][y];
				F[y][y]=0;
			}
		}
		return sum;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 13; int Arg1 = 42; int Arg2 = 666; double Arg3 = 0.001968164704; verify_case(0, Arg3, getChance(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 1000; double Arg3 = 0.0; verify_case(1, Arg3, getChance(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 20; int Arg1 = 216; int Arg2 = 219; double Arg3 = 0.083322288706; verify_case(2, Arg3, getChance(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 42; int Arg1 = 973; int Arg2 = 123; double Arg3 = 0.019345240789; verify_case(3, Arg3, getChance(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EllysTwoRatings ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

