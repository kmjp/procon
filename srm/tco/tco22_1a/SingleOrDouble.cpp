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

long double P[11][121];

const int MAT=4;
long double G[MAT][MAT],G2[MAT][MAT];
void powmat(ll p,int n,long double a[MAT][MAT],long double r[MAT][MAT]) {
	int i,x,y,z;
	long double a2[MAT][MAT];
	FOR(x,n) FOR(y,n) a2[x][y]=a[x][y];
	FOR(x,n) FOR(y,n) r[x][y]=(x==y);
	while(p) {
		long double h[MAT][MAT];
		if(p%2) {
			FOR(x,n) FOR(y,n) h[x][y]=0;
			FOR(x,n) FOR(z,n) FOR(y,n) h[x][y] += r[x][z]*a2[z][y];
			FOR(x,n) FOR(y,n) r[x][y]=h[x][y];
		}
		FOR(x,n) FOR(y,n) h[x][y]=0;
		FOR(x,n) FOR(z,n) FOR(y,n) h[x][y] += a2[x][z]*a2[z][y];
		FOR(x,n) FOR(y,n) a2[x][y]=h[x][y];
		p>>=1;
	}
}

class SingleOrDouble {
	public:
	double probAlice(int N, int D, int A, int B) {
		ZERO(P);
		P[0][0]=1;
		int i,j,x,y;
		FOR(i,N) {
			FOR(j,101) {
				FOR(x,D) P[i+1][j+x]+=P[i][j]/D;
			}
		}
		long double X=P[N][A-N];
		long double Y=P[N][B-N];
		
		ZERO(G);
		G[0][0]=1-X-Y;
		G[1][0]=X;
		G[2][0]=Y;
		G[1][1]=1;
		G[0][2]=1-X-Y;
		G[1][2]=X;
		G[3][2]=Y;
		G[3][3]=1;
		
		cout<<X<<" "<<Y<<endl;
		
		powmat(10000000000000000LL,4,G,G2);
		FOR(y,4) {
			FOR(x,4) cout<<G[y][x]<<" ";
			cout<<endl;
		}
		return G2[1][0];
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 1; int Arg3 = 2; double Arg4 = 0.75; verify_case(0, Arg4, probAlice(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 6; int Arg2 = 1; int Arg3 = 2; double Arg4 = 0.8749999999999999; verify_case(1, Arg4, probAlice(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 6; int Arg2 = 2; int Arg3 = 7; double Arg4 = 0.538461538461538; verify_case(2, Arg4, probAlice(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3_() { int Arg0 = 3; int Arg1 = 10; int Arg2 = 29; int Arg3 = 16; double Arg4 = 0.3644067796610159; verify_case(3, Arg4, probAlice(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 11; int Arg3 = 10; double Arg4 = 0.3644067796610159; verify_case(3, Arg4, probAlice(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SingleOrDouble ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

