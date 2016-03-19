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

int T[51][51];

class MultiplicationTable2 {
	public:
	int minimalGoodSet(vector <int> table) {
		int N=1;
		int y,x,i;
		while((N+1)*(N+1) <= table.size()) N++;
		FOR(y,N) FOR(x,N) T[y][x]=table[y*N+x];
		
		int mi=N;
		FOR(x,N) {
			int in[50]={};
			vector<int> V,V2;
			V2.push_back(x);
			in[x]=1;
			
			while(V2.size()) {
				FORR(r,V2) V.push_back(r);
				V2.clear();
				int x2,y2;
				FORR(r,V) FORR(r2,V) {
					int z=T[r][r2];
					if(in[z]==0) {
						V2.push_back(z);
						in[z]=1;
					}
				}
			}
			mi=min(mi,(int)V.size());
		}
		return mi;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,1,2,3,
 1,0,3,2,
 2,0,1,3,
 1,2,3,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, minimalGoodSet(Arg0)); }
	void test_case_1() { int Arr0[] = {0,1,2,3,
 1,2,3,0,
 2,3,0,1,
 3,0,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, minimalGoodSet(Arg0)); }
	void test_case_2() { int Arr0[] = {1,1,1,1,
 2,2,2,2,
 3,3,3,3,
 0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, minimalGoodSet(Arg0)); }
	void test_case_3() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, minimalGoodSet(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MultiplicationTable2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
