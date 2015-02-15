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


ll mo=1000000009;

ll stt[6][51][26];
map<ll,int> SI;
vector<ll> V;
int ST2[50001][26];
ll dpdp[51][50000];

void CreateSTT(int tar,string& pat) {
	int x,y,z,l;
	ZERO(stt[tar]);
	l=pat.size();
	FOR(x,l) {
		FOR(y,26) {
			if('a'+y == pat[x]) stt[tar][x][y]=x+1;
			else {
				string pre=pat.substr(0,x)+(char)('a'+y);
				for(z=1;z<=x;z++) if(pre.substr(pre.size()-z) == pat.substr(0,z)) stt[tar][x][y]=z;
			}
		}
	}
	FOR(y,26) stt[tar][l][y]=l;
}

class RequiredSubstrings {
	public:
	int solve(vector <string> words, int C, int L) {
		int i,x,y;
		vector<string> W;
		FOR(i,words.size()) if(words[i].size()<=L) W.push_back(words[i]);
		
		int N=W.size();
		FOR(i,N) CreateSTT(i,W[i]);
		
		ZERO(ST2);
		SI.clear();
		V.clear();
		queue<ll> Q;
		
		Q.push(0);
		V.push_back(0);
		SI[0]=0;
		
		while(!Q.empty()) {
			ll cur=Q.front();
			Q.pop();
			
			FOR(i,26) {
				ll ne=0;
				FOR(x,N) ne |= stt[x][(cur>>(6*x))&63][i]<<(6*x);
				if(SI.find(ne)==SI.end()) SI[ne]=SI.size()-1, Q.push(ne), V.push_back(ne);
				ST2[SI[cur]][i]=SI[ne];
			}
		}
		
		ZERO(dpdp);
		dpdp[0][0]=1;
		FOR(i,L) {
			FOR(x,V.size()) {
				FOR(y,26) dpdp[i+1][ST2[x][y]] = (dpdp[i+1][ST2[x][y]]+dpdp[i][x])%mo;
			}
		}
		
		ll ret=0;
		FOR(x,V.size()) {
			int num=0;
			FOR(y,N) if(((V[x]>>(6*y))&63)==W[y].size()) num++;
			if(num==C) ret+=dpdp[L][x];
		}
		
		return ret%mo;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"a","aa","aaa","aaaa"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; int Arg3 = 50; verify_case(0, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"abcdefgh"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 7; int Arg3 = 31810104; verify_case(1, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"abcdefgh"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 7; int Arg3 = 0; verify_case(2, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"a","b","c","d"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 3; int Arg3 = 24; verify_case(3, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"ab","bc","xy","yz"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; int Arg3 = 2; verify_case(4, Arg3, solve(Arg0, Arg1, Arg2)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RequiredSubstrings ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

