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

class Lasso {
	public:
	double lasso(int R, int C, int R1, int C1, int R2, int C2) {
		vector<int> S;
		int i,x,y;
		for(int y=R1;y<=R2;y++) {
			for(int x=C1;x<=C2;x++) {
				S.push_back(min({x/2+1,(C-x)/2+1,y/2+1,(R-y)/2+1}));
			}
		}
		sort(ALL(S));
		double X=0,Y=1000;
		FOR(i,100) {
			double M=(X+Y)/2;
			FOR(x,S.size()) if(M*(1+x)>S[x]) break;
			if(x==S.size()) X=M;
			else Y=M;
		}
		return X;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; double Arg6 = 1.0; verify_case(0, Arg6, lasso(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 2; int Arg3 = 2; int Arg4 = 2; int Arg5 = 2; double Arg6 = 2.0; verify_case(1, Arg6, lasso(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 0; int Arg3 = 0; int Arg4 = 2; int Arg5 = 1; double Arg6 = 0.16666666666666666; verify_case(2, Arg6, lasso(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 2; int Arg3 = 2; int Arg4 = 2; int Arg5 = 3; double Arg6 = 1.0; verify_case(3, Arg6, lasso(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { int Arg0 = 4; int Arg1 = 7; int Arg2 = 1; int Arg3 = 1; int Arg4 = 3; int Arg5 = 6; double Arg6 = 0.07142857142857142; verify_case(4, Arg6, lasso(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Lasso ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

