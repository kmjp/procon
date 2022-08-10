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

ll memo[3][71][71][71];
const ll mo=1000000007;
vector<int> X,Y;

class PreInPostOrder {
	public:
	
	ll hoge(int L1,int L2,int len,int turn) {
		if(len==0) return 1;
		if(len==1) return X[L1]==Y[L2];
		if(memo[turn][L1][L2][len]>=0) return memo[turn][L1][L2][len];
		ll ret=0;
		
		int i;
		if(turn==0) {
			FOR(i,len) if(X[L1]==Y[L2+i]) ret+=hoge(L1+1,L2,i,1)*hoge(L1+1+i,L2+i+1,len-(i+1),1)%mo;
		}
		else if(turn==1) {
			FOR(i,len) if(X[L1+i]==Y[L2+len-1]) ret+=hoge(L1,L2,i,2)*hoge(L1+1+i,L2+i,len-(i+1),2)%mo;
		}
		else {
			if(X[L1+len-1]==Y[L2]) {
				FOR(i,len) ret+=hoge(L1,L2+1,i,0)*hoge(L1+i,L2+i+1,len-(i+1),0)%mo;
			}
		}
		
		
		return memo[turn][L1][L2][len]=ret%mo;
	}
	
	int reconstruct(vector <int> PIP, vector <int> IPP) {
		X=PIP;
		Y=IPP;
		MINUS(memo);
		return hoge(0,0,X.size(),0);
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, reconstruct(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 2, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 0, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, reconstruct(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1, 2, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, reconstruct(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {2, 1, 3, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 3, 1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(3, Arg2, reconstruct(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {0, 3, 4, 2, 1, 7, 8, 6, 5, 10, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 3, 4, 1, 0, 6, 7, 8, 9, 10, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 18; verify_case(4, Arg2, reconstruct(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {0,1,3,5,4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,2,3,5,4,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(5, Arg2, reconstruct(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PreInPostOrder ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

