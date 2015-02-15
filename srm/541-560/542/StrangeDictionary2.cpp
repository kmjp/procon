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

double dp[17][1<<16];
int ngmask[50];
int samemask[50];


class StrangeDictionary2 {
	public:
	int N,L;
	vector<string> W;
	
	double dfs(int cur,int mask) {
		if(dp[cur][mask]>=0) return dp[cur][mask];
		if(__builtin_popcount(mask)==1) return dp[cur][mask]=1;
		dp[cur][mask]=0;
		int pat=0,x,i;
		FOR(i,L) {
			if(ngmask[i] & mask) pat++;
			else if((samemask[i] & mask)!=mask) pat++, dp[cur][mask]+=dfs(cur,samemask[i] & mask);
		}
		if(pat==0) return dp[cur][mask]=0;
		return dp[cur][mask]/=pat;
	}
	
	vector <double> getProbabilities(vector <string> words) {
		W=words;
		N=W.size();
		L=W[0].size();
		
		int i,j,x,y;
		FOR(i,16) FOR(j,1<<16) dp[i][j]=-1;
		vector<double> V;
		FOR(i,N) {
			FOR(x,L) {
				ngmask[x]=samemask[x]=0;
				FOR(y,N) ngmask[x] |=(W[y][x]<W[i][x])<<y;
				FOR(y,N) samemask[x] |=(W[y][x]==W[i][x])<<y;
			}
			V.push_back(dfs(i,(1<<N)-1));
		}
		return V;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <double> &Expected, const vector <double> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"hardesttestever"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {1.0 }; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getProbabilities(Arg0)); }
	void test_case_1() { string Arr0[] = {"ab", "ba"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {0.5, 0.5 }; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getProbabilities(Arg0)); }
	void test_case_2() { string Arr0[] = {"aza", "aab", "bba"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {0.3333333333333333, 0.5, 0.16666666666666666 }; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getProbabilities(Arg0)); }
	void test_case_3() { string Arr0[] = {"abababab", "babababa", "acacacac", "cacacaca", "bcbcbcbc", "cbcbcbcb"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {0.5, 0.5, 0.0, 0.0, 0.0, 0.0 }; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getProbabilities(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  StrangeDictionary2 ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
