#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

class MagicalHats {
public:
	int N,CO,NG;
	vector<int> ok;
	map<pair<int,int>,int > vis;
	
	int dfs(int mask1,int mask2) {
		int i;
		if(vis.find(make_pair(mask1,mask2))!=vis.end()) return vis[make_pair(mask1,mask2)];
		
		
		if(__builtin_popcount(mask1)==NG) return vis[make_pair(mask1,mask2)]=__builtin_popcount(mask1&mask2);
		
		int ma=0;
		FOR(i,N) if((mask1&(1<<i))==0) {
			int sel[2]={0,0};
			ITR(it,ok) if((*it & mask1)==mask2 && ((*it&(1<<i))==0)) sel[0]=1;
			ITR(it,ok) if((*it & mask1)==mask2 && ((*it&(1<<i))>0)) sel[1]=1;
			if(sel[0]&&sel[1]) ma=max(ma,min(dfs(mask1|(1<<i),mask2|(1<<i)),dfs(mask1|(1<<i),mask2)));
			else if(sel[0]) ma=max(ma,dfs(mask1|(1<<i),mask2));
			else if(sel[1]) ma=max(ma,dfs(mask1|(1<<i),mask2|(1<<i)));
		}
		return vis[make_pair(mask1,mask2)]=ma;
	}
	
	int findMaximumReward(vector <string> board, vector <int> coins, int numGuesses) {
		int i,x,y,mask,mask2;
		int H=board.size(),W=board[0].size();
		int X[13],Y[13],R[13],C[13];
		
		NG=numGuesses;
		CO=coins.size();
		N=0;
		FOR(y,H) FOR(x,W) if(board[y][x]=='H') X[N]=x,Y[N]=y,N++;
		ok.clear();
		
		FOR(mask,1<<N) 	if(__builtin_popcount(mask)==CO) {
			ZERO(R);
			ZERO(C);
			FOR(i,N) if((mask&(1<<i))==0) R[Y[i]]^=1,C[X[i]]^=1;
			x=1;
			FOR(i,13) if(R[i]|C[i]) x=0;
			if(x) ok.push_back(mask);
		}
		if(ok.empty()) return -1;
		
		vis.clear();
		x=dfs(0,0);
		
		int ret=0;
		sort(coins.begin(),coins.end());
		FOR(i,x) ret+=coins[i];
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 1; verify_case(0, Arg3, findMaximumReward(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"HHH",
 "H.H",
 "HH."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 9; verify_case(1, Arg3, findMaximumReward(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"HH",
 "HH"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 6; verify_case(2, Arg3, findMaximumReward(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"HHH",
 "HHH",
 "H.H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {13,13,13,13}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 13; verify_case(3, Arg3, findMaximumReward(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"HHH",
 "HHH",
 "H.H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {13,13,13,13}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 26; verify_case(4, Arg3, findMaximumReward(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"H.H.",
 ".H.H",
 "H.H."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {17}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; int Arg3 = -1; verify_case(5, Arg3, findMaximumReward(Arg0, Arg1, Arg2)); }
	void test_case_6() { string Arr0[] = {"HHH",
 "H.H",
 "HHH",
 "H.H",
 "HHH"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {33,337,1007,2403,5601,6003,9999}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; int Arg3 = 1377; verify_case(6, Arg3, findMaximumReward(Arg0, Arg1, Arg2)); }
	void test_case_7() { string Arr0[] = {".............",
 ".............",
 ".............",
 ".............",
 ".............",
 ".............",
 ".....H.H.....",
 "......H......",
 ".....H.H.....",
 ".............",
 ".............",
 ".............",
 "............."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {22}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 22; verify_case(7, Arg3, findMaximumReward(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  MagicalHats ___test;
  ___test.run_test(-1);
}
// END CUT HERE
