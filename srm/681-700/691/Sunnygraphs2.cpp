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

int mat[51][51];
int did[51];

class Sunnygraphs2 {
	public:
	long long count(vector <int> a) {
		int i,x,y,z;
		int N=a.size();
		ZERO(mat);
		FOR(i,N) mat[i][a[i]]=mat[i][i]=1;
		FOR(z,N) FOR(x,N) FOR(y,N) mat[x][y] |= mat[x][z] & mat[z][y];
		
		ll ret=0;
		// con?
		FOR(x,N) FOR(y,N) if(x!=y) {
			int ok=0;
			FOR(z,N) if(mat[x][z] && mat[y][z]) ok=1;
			ret &= ok;
		}
		ZERO(did);
		ll r2=1;
		FOR(x,N) if(did[x]==0) {
			int inloop=0;
			FOR(y,N) if(mat[x][y] && mat[y][x]) inloop++;
			if(inloop==1) {
				r2 *= 2;
				did[x]=1;
			}
			else {
				r2 *= (1LL<<inloop)-1;
				FOR(y,N) if(mat[x][y] && mat[y][x]) did[y]=1;
			}
		}
		return ret+r2;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 4LL; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { int Arr0[] = {1,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 7LL; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { int Arr0[] = {2,3,0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 9LL; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { int Arr0[] = {2,3,0,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 18LL; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { int Arr0[] = {2,3,0,1,0,4,5,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 288LL; verify_case(4, Arg1, count(Arg0)); }
	void test_case_5() { int Arr0[] = {29,34,40,17,16,12,0,40,20,35,5,13,27,7,29,13,14,39,42,9,30,38,27,40,34,33,42,20,29,42,12,29,30,21,4,5,7,25,24,17,39,32,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 6184752906240LL; verify_case(5, Arg1, count(Arg0)); }
	void test_case_6() { int Arr0[] = {9,2,0,43,12,14,39,25,24,3,16,17,22,0,6,21,18,29,34,35,23,43,28,28,20,11,5,12,31,24,8,13,17,10,15,9,15,26,4,13,21,27,36,39}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 17317308137473LL; verify_case(6, Arg1, count(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Sunnygraphs2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
