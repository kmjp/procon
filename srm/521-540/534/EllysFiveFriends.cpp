#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef signed long long ll;
typedef unsigned long long ull;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(x) x.begin(),x.end()
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

int mo=1000000007;
const int NN=27;
int dp[NN][NN][NN][NN][NN];

class EllysFiveFriends {
	public:
	vector<int> V[5];
	vector<int> Podd[5];
	vector<int> Pdiv[5];
	
	void enumnum(int ind,int val) {
		int vis[10001],i;
		ZERO(vis);
		vis[val]=1;
		V[ind].clear();
		
		for(int i=val;i>=0;i--) {
			if(!vis[i]) continue;
			V[ind].push_back(i);
			if(i%2) vis[i-1]=1;
			vis[i/2]=1;
		}
		sort(V[ind].begin(),V[ind].end());
		
		Podd[ind].clear();
		Pdiv[ind].clear();
		map<int,int> rev;
		FOR(i,V[ind].size()) {
			rev[V[ind][i]]=i;
			if((V[ind][i]%2)==0) Podd[ind].push_back(-1);
			else Podd[ind].push_back(rev[V[ind][i]-1]);
			Pdiv[ind].push_back(rev[V[ind][i]/2]);
		}
		
	}
	
	int getZero(vector <int> numbers) {
		int i,a,b,c,d,e,I[5];
		FOR(i,5) enumnum(i,numbers[i]);
		
		ZERO(dp);
		dp[V[0].size()-1][V[1].size()-1][V[2].size()-1][V[3].size()-1][V[4].size()-1]=1;
		for(I[0]=V[0].size()-1;I[0]>=0;I[0]--) for(I[1]=V[1].size()-1;I[1]>=0;I[1]--)
		for(I[2]=V[2].size()-1;I[2]>=0;I[2]--) for(I[3]=V[3].size()-1;I[3]>=0;I[3]--) {
			for(I[4]=V[4].size()-1;I[4]>=0;I[4]--) {
				int hoge=dp[I[0]][I[1]][I[2]][I[3]][I[4]];
				if(hoge==0) continue;
				if(I[0]&&I[1]) dp[Pdiv[0][I[0]]][Pdiv[1][I[1]]][I[2]][I[3]][I[4]] += hoge, dp[Pdiv[0][I[0]]][Pdiv[1][I[1]]][I[2]][I[3]][I[4]] %= mo;
				if(I[1]&&I[2]) dp[I[0]][Pdiv[1][I[1]]][Pdiv[2][I[2]]][I[3]][I[4]] += hoge, dp[I[0]][Pdiv[1][I[1]]][Pdiv[2][I[2]]][I[3]][I[4]] %= mo;
				if(I[2]&&I[3]) dp[I[0]][I[1]][Pdiv[2][I[2]]][Pdiv[3][I[3]]][I[4]] += hoge, dp[I[0]][I[1]][Pdiv[2][I[2]]][Pdiv[3][I[3]]][I[4]] %= mo;
				if(I[3]&&I[4]) dp[I[0]][I[1]][I[2]][Pdiv[3][I[3]]][Pdiv[4][I[4]]] += hoge, dp[I[0]][I[1]][I[2]][Pdiv[3][I[3]]][Pdiv[4][I[4]]] %= mo;
				if(I[4]&&I[0]) dp[Pdiv[0][I[0]]][I[1]][I[2]][I[3]][Pdiv[4][I[4]]] += hoge, dp[Pdiv[0][I[0]]][I[1]][I[2]][I[3]][Pdiv[4][I[4]]] %= mo;
				if(Podd[0][I[0]]!=-1 && Podd[1][I[1]]!=-1) dp[Podd[0][I[0]]][Podd[1][I[1]]][I[2]][I[3]][I[4]] += hoge, dp[Podd[0][I[0]]][Podd[1][I[1]]][I[2]][I[3]][I[4]] %= mo;
				if(Podd[1][I[1]]!=-1 && Podd[2][I[2]]!=-1) dp[I[0]][Podd[1][I[1]]][Podd[2][I[2]]][I[3]][I[4]] += hoge, dp[I[0]][Podd[1][I[1]]][Podd[2][I[2]]][I[3]][I[4]] %= mo;
				if(Podd[2][I[2]]!=-1 && Podd[3][I[3]]!=-1) dp[I[0]][I[1]][Podd[2][I[2]]][Podd[3][I[3]]][I[4]] += hoge, dp[I[0]][I[1]][Podd[2][I[2]]][Podd[3][I[3]]][I[4]] %= mo;
				if(Podd[3][I[3]]!=-1 && Podd[4][I[4]]!=-1) dp[I[0]][I[1]][I[2]][Podd[3][I[3]]][Podd[4][I[4]]] += hoge, dp[I[0]][I[1]][I[2]][Podd[3][I[3]]][Podd[4][I[4]]] %= mo;
				if(Podd[4][I[4]]!=-1 && Podd[0][I[0]]!=-1) dp[Podd[0][I[0]]][I[1]][I[2]][I[3]][Podd[4][I[4]]] += hoge, dp[Podd[0][I[0]]][I[1]][I[2]][I[3]][Podd[4][I[4]]] %= mo;
			}
		}
		
		return dp[0][0][0][0][0];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, 1, 1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(0, Arg1, getZero(Arg0)); }
	void test_case_1() { int Arr0[] = {2, 1, 1, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, getZero(Arg0)); }
	void test_case_2() { int Arr0[] = {3, 4, 1, 4, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 520; verify_case(2, Arg1, getZero(Arg0)); }
	void test_case_3() { int Arr0[] = {42, 666, 1337, 666, 42}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 549119981; verify_case(3, Arg1, getZero(Arg0)); }
	void test_case_4() { int Arr0[] = {8792, 9483, 6787, 9856, 6205}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 165501353; verify_case(4, Arg1, getZero(Arg0)); }
	void test_case_5() { int Arr0[] = {10000, 10000, 10000, 10000, 10000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 952019520; verify_case(5, Arg1, getZero(Arg0)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EllysFiveFriends ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

