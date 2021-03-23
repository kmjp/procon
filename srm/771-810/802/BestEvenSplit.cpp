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
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int E[30];
vector<pair<int,int>> cand[16];
ll ret[2000];

class BestEvenSplit {
	public:
	int count(int N, vector <int> X, vector <int> Y) {
		ZERO(E);
		int x,y,i;
		int mask;
		int M=N/2;
		FOR(i,X.size()) {
			E[X[i]]|=1<<Y[i];
			E[Y[i]]|=1<<X[i];
		}
		ZERO(ret);
		FOR(i,M+1) cand[i].clear();
		
		FOR(mask,1<<M) if((mask&1)==0) {
			int pat=0;
			FOR(i,M) {
				if(mask&(1<<i)) pat+=__builtin_popcount(mask&E[i]);
				else pat+=__builtin_popcount((((1<<M)-1)^mask)&E[i]);
			}
			cand[__builtin_popcount(mask)].push_back({mask,pat});
		}
		FOR(mask,1<<M) {
			int pat=0;
			FOR(i,M) {
				if(mask&(1<<i)) pat+=__builtin_popcount(((mask)<<M)&E[i+M]);
				else pat+=__builtin_popcount(((((1<<M)-1)^mask)<<M)&E[i+M]);
			}
			int v=__builtin_popcount(mask);
			int C[2][16]={};
			FOR(i,M) {
				C[0][i]=2*__builtin_popcount(E[i]&((((1<<M)-1)^mask)<<M));
				C[1][i]=2*__builtin_popcount(E[i]&(mask<<M));
			}
			
			FORR(c,cand[M-v]) {
				int npat=pat+c.second;
				FOR(i,M) npat+=C[(c.first>>i)&1][i];
				ret[npat]++;
				
			}
		}
		
		FOR(i,400) if(ret[i]) cout<<i<<" "<<ret[i]<<endl;
		for(i=1999;i>=0;i--) if(ret[i]) return ret[i];
		return 0;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arr1[] = {0, 0, 1, 1, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 4, 3, 5, 5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(0, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 6; int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; verify_case(1, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 6; int Arr1[] = {3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(2, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 6; int Arr1[] = {0, 2, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 3, 5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; verify_case(3, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 8; int Arr1[] = {0, 1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4, 5, 6, 7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(4, Arg3, count(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BestEvenSplit ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

