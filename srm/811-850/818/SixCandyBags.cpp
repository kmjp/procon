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

map<int,set<int>> memo[4];

class SixCandyBags {
	public:
	int search(int lef,int cur,int M) {
		if(lef==0&&cur<=M) return cur;
		if(lef<=0||cur>=M) return -2;
		
		int ma=-2;
		int i;
		for(i=1;i<=3;i++) if(memo[i].count(lef)) {
			set<int>& S=memo[i][lef];
			auto it=S.lower_bound(M-cur+1);
			if(it!=S.begin()) {
				it--;
				ma=max(ma,cur+*it);
			}
		
		}
		return ma;
	}
	int buy(vector <int> C, vector <int> P, int G, int M) {
		int N=C.size();
		int ma=-1;
		
		int a,b,c,i;
		FOR(a,4) memo[a].clear();
		memo[0][0].insert(0);
		for(c=N-1;c>=0;c--) {
			ma=max(ma,search(G-C[c],P[c],M));
			FOR(b,c) {
				ma=max(ma,search(G-C[c]-C[b],P[c]+P[b],M));
				FOR(a,b) {
					ma=max(ma,search(G-C[c]-C[b]-C[a],P[c]+P[b]+P[a],M));
				}
			}
			for(i=2;i>=0;i--) {
				FORR(m,memo[i]) {
					int a=m.first;
					set<int>& b=m.second;
					if(a+C[c]<G) {
						FORR(v,b) if(v+P[c]<M) memo[i+1][a+C[c]].insert(v+P[c]);
					}
				}
			}
		}
		return ma;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 3, 4, 5, 6, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 4, 8, 16, 32, 64}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 27; int Arg3 = 123456789; int Arg4 = 126; verify_case(0, Arg4, buy(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {1, 2, 3, 4, 5, 6, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 4, 8, 16, 32, 64}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 27; int Arg3 = 125; int Arg4 = -1; verify_case(1, Arg4, buy(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {1, 2, 3, 4, 5, 6, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 4, 8, 16, 32, 64}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; int Arg3 = 40; int Arg4 = 36; verify_case(2, Arg4, buy(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {1, 2, 3, 4, 5, 6, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 4, 8, 16, 32, 64}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; int Arg3 = 35; int Arg4 = 35; verify_case(3, Arg4, buy(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8605, 32642, 16565, 6363, 24597, 22316, 25290, 11461, 18689, 16000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; int Arg3 = 80000; int Arg4 = 79933; verify_case(4, Arg4, buy(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SixCandyBags ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

