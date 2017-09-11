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

const int MAT=2;
struct Mat { double v[MAT][MAT]; };
Mat mulmat(Mat& a,Mat& b,int n=MAT) {
	int x,y,z; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(x,n) FOR(z,n) FOR(y,n) r.v[x][y] += a.v[x][z]*b.v[z][y];
	return r;
}

Mat powmat(ll p,Mat a,int n=MAT) {
	int i,x,y; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(i,n) r.v[i][i]=1;
	while(p) {
		if(p%2) r=mulmat(r,a,n);
		a=mulmat(a,a,n);
		p>>=1;
	}
	return r;
}

class ArmorUp {
	public:
	
	int ok(double D,int ma,int cur,int K) {
		Mat M,M2;
		M.v[0][0]=1-D/(2.0*ma);
		M.v[0][1]=-D/2.0;
		M.v[1][0]=0;
		M.v[1][1]=1;
		
		if(D*K/2.0 >=cur) return 1;
		
		M2=powmat(K,M);
		return cur*M2.v[0][0] + M2.v[0][1]<=0;
	}
	
	/*double minimalDamage(int maxHP, int currentHP, int k) {
		double L=0,R=1e10;
		int i;
		FOR(i,100) {
			double M=(L+R)/2;
			if(ok(M,maxHP,currentHP,k)) R=M;
			else L=M;
		}
		return L;
	}
	*/
	double minimalDamage(int maxHP, int currentHP, int k) {
		double a=1.0*currentHP/maxHP;
		double b=1/(1+a);
		double c=pow(b,1.0/k);
		double d=1-c;
		
		return d*maxHP*2;
		
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 100; int Arg1 = 100; int Arg2 = 1; double Arg3 = 100.0; verify_case(0, Arg3, minimalDamage(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 100; int Arg1 = 20; int Arg2 = 1; double Arg3 = 33.333333333333336; verify_case(1, Arg3, minimalDamage(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 100; int Arg1 = 100; int Arg2 = 2; double Arg3 = 58.57864376269048; verify_case(2, Arg3, minimalDamage(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1000000000; int Arg1 = 987654321; int Arg2 = 1234; double Arg3 = 1113069.7492973686; verify_case(3, Arg3, minimalDamage(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ArmorUp ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

