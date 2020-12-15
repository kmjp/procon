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

ll D[50][50];

const int MAT=50;
struct Mat { ll v[MAT][MAT]; Mat(){ZERO(v);};};

Mat mulmat(Mat& a,Mat& b,int n=MAT) {
	int x,y,z; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=1LL<<60;
	FOR(x,n) FOR(z,n) FOR(y,n) {
		r.v[x][y]=min(r.v[x][y],a.v[x][z]+b.v[z][y]);
	}
	return r;
}

Mat powmat(ll p,Mat a,int n=MAT) {
	int i,x,y; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=1LL<<60;
	FOR(i,n) r.v[i][i]=0;
	while(p) {
		if(p%2) r=mulmat(r,a,n);
		a=mulmat(a,a,n);
		p>>=1;
	}
	return r;
}

class AtLeastKDays {
	public:
	long long sumOfMinCosts(vector <string> costs, int minDays) {
		int N=costs.size();
		int y,x,z;
		Mat A;
		FOR(y,N) FOR(x,N) {
			if(x==y) D[y][x]=A.v[y][x]=1LL<<60;
			else D[y][x]=A.v[y][x]=costs[y][x]-'0';
		}
		FOR(z,N) FOR(y,N) FOR(x,N) D[y][x]=min(D[y][x],D[y][z]+D[z][x]);
		A=powmat(minDays,A,N);
		
		ll ret=0;
		FOR(y,N) FOR(x,N) {
			ll mi=A.v[y][x];
			FOR(z,N) mi=min(mi,A.v[y][z]+D[z][x]);
			ret+=mi;
		}
		return ret;
		
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"-12",
 "3-6",
 "45-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; long long Arg2 = 34LL; verify_case(0, Arg2, sumOfMinCosts(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"-111111111",
 "1-11111111",
 "11-1111111",
 "111-111111",
 "1111-11111",
 "11111-1111",
 "111111-111",
 "1111111-11",
 "11111111-1",
 "111111111-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000000; long long Arg2 = 100000000000LL; verify_case(1, Arg2, sumOfMinCosts(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"-12",
 "3-6",
 "45-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; long long Arg2 = 122LL; verify_case(2, Arg2, sumOfMinCosts(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  AtLeastKDays ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

