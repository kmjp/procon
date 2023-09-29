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

string dp[155][155];

class LongSimplePath {
	public:
	string traverse(int R, int C, vector <int> obsR, vector <int> obsC) {
		vector<int> Ys={0,R};
		vector<int> Xs={0,C};
		int i;
		FOR(i,obsR.size()) {
			if(obsR[i]) Ys.push_back(obsR[i]-1);
			Ys.push_back(obsR[i]);
		}
		FOR(i,obsC.size()) {
			if(obsC[i]) Xs.push_back(obsC[i]-1);
			Xs.push_back(obsC[i]);
		}
		sort(ALL(Ys));
		sort(ALL(Xs));
		Xs.erase(unique(ALL(Xs)),Xs.end());
		Ys.erase(unique(ALL(Ys)),Ys.end());
		int x,y;
		set<pair<int,int>> NG;
		FOR(i,obsR.size()) {
			x=lower_bound(ALL(Xs),obsC[i])-Xs.begin();
			y=lower_bound(ALL(Ys),obsR[i])-Ys.begin();
			NG.insert({y,x});
		}
		R=Ys.size();
		C=Xs.size();
		FOR(x,R) FOR(y,C) dp[y][x].clear();
		FOR(y,R) FOR(x,C) if(y+x==0||dp[y][x].size()) {
			if(y+1<R&&NG.count({y+1,x})==0) {
				dp[y+1][x]=dp[y][x];
				int dif=Ys[y+1]-Ys[y];
				while(dif>=1<<25) {
					dp[y+1][x]+='a'+25;
					dif-=1<<25;
				}
				FOR(i,26) if(dif&(1<<i)) dp[y+1][x]+='a'+i;
			}
			if(x+1<C&&NG.count({y,x+1})==0) {
				dp[y][x+1]=dp[y][x];
				int dif=Xs[x+1]-Xs[x];
				while(dif>=1<<25) {
					dp[y][x+1]+='A'+25;
					dif-=1<<25;
				}
				FOR(i,26) if(dif&(1<<i)) dp[y][x+1]+='A'+i;
			}
			
		}
		return dp[R-1][C-1];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 6; int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "CB"; verify_case(0, Arg4, traverse(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 0; int Arg1 = 6; int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = ""; verify_case(1, Arg4, traverse(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 2; int Arr2[] = {0, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "AaAa"; verify_case(2, Arg4, traverse(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 123; int Arg1 = 456; int Arr2[] = {0, 122}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 456}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "gfedaIHGCBAbA"; verify_case(3, Arg4, traverse(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 3; int Arg1 = 1234; int Arr2[] = {0, 1, 2, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {7, 7, 111, 111}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = ""; verify_case(4, Arg4, traverse(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  LongSimplePath ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

