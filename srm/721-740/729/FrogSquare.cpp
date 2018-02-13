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

int D[4040];
int X[4040],Y[4040];

class FrogSquare {
	public:
	int minimalJumps(int n, int d, int sx, int sy, int tx, int ty) {
		int S,T,P=0;
		int i,x,y;
		
		if(sx==tx && sy==ty) return 0;
		FOR(y,n) FOR(x,n) {
			if(x==0 || x==n-1 || y==0 || y==n-1 || (sx==x&&sy==y) || (tx==x&&ty==y)) {
				X[P]=x;
				Y[P]=y;
				if(sx==x && sy==y) S=P;
				if(tx==x && ty==y) T=P;
				P++;
			}
		}
		
		queue<int> Q;
		FOR(i,P) D[i]=101010;
		Q.push(S);
		D[S]=0;
		while(Q.size()) {
			x=Q.front();
			Q.pop();
			if(x==T) return D[x];
			FOR(y,P) if(D[y]>D[x]+1) {
				if((X[x]-X[y])*(X[x]-X[y])+(Y[x]-Y[y])*(Y[x]-Y[y])>=d*d) {
					D[y]=D[x]+1;
					Q.push(y);
				}
			}
		}
		
		return -1;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 100; int Arg1 = 10; int Arg2 = 0; int Arg3 = 0; int Arg4 = 3; int Arg5 = 4; int Arg6 = 2; verify_case(0, Arg6, minimalJumps(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 100; int Arg1 = 5; int Arg2 = 0; int Arg3 = 0; int Arg4 = 3; int Arg5 = 4; int Arg6 = 1; verify_case(1, Arg6, minimalJumps(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 100; int Arg1 = 200; int Arg2 = 0; int Arg3 = 0; int Arg4 = 3; int Arg5 = 4; int Arg6 = -1; verify_case(2, Arg6, minimalJumps(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 7; int Arg2 = 4; int Arg3 = 4; int Arg4 = 5; int Arg5 = 5; int Arg6 = 3; verify_case(3, Arg6, minimalJumps(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 0; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; int Arg6 = 0; verify_case(4, Arg6, minimalJumps(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FrogSquare ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

