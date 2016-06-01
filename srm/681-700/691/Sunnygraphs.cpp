#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


class Sunnygraphs {
	public:
	int mat[60][60];
	
	long long count(vector <int> a) {
		int N=a.size();
		int i,x,y,z;
		ZERO(mat);
		
		FOR(x,N) FOR(y,N) mat[x][y]=1010;
		FOR(i,N) mat[i][a[i]]=1, mat[i][i]=0;
		FOR(z,N) FOR(x,N) FOR(y,N) mat[x][y] = min(mat[x][y],mat[x][z]+mat[z][y]);
		
		ll m0=0,m1=0;
		FOR(i,N) if(mat[0][i]<1000) m0 |= 1LL<<i;
		FOR(i,N) if(mat[1][i]<1000) m1 |= 1LL<<i;
		int only0 = __builtin_popcountll(m0 ^ (m0&m1));
		int only1 = __builtin_popcountll(m1 ^ (m0&m1));
		int both = __builtin_popcountll(m0&m1);
		int nor = N-(both+only0+only1);
		
		_P("%llx,%llx, %d %d %d %d : %d\n",m0,m1,only1,only1,both,nor,N);
		if(both==0) return (1LL<<nor)*((1LL<<only0)-1)*((1LL<<only1)-1);
		return (1LL<<nor)*(((((1LL<<only0)-1)*((1LL<<only1)-1)+1)<<both)+(((1LL<<only0)-1)+((1LL<<only1)-1))*((1LL<<both)-1));
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 4LL; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { int Arr0[] = {2,2,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 7LL; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { int Arr0[] = {2,3,0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 9LL; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { int Arr0[] = {2,2,3,4,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 30LL; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { int Arr0[] = {18,18,20,28,7,27,8,13,40,3,7,21,30,17,13,34,29,16,15,11,0,9,39,36,38,23,24,8,4,9,29,22,35,5,13,23,3,27,34,23,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2198754820096LL; verify_case(4, Arg1, count(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Sunnygraphs ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
