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

vector<string> split(const string &str, char delim){
	vector<string> res;
	size_t current = 0, found;
	while((found = str.find_first_of(delim, current)) != string::npos){
		res.push_back(string(str, current, found - current));
		current = found + 1;
	}
	res.push_back(string(str, current, str.size() - current));
	return res;
}

class PalindromizationDiv1 {
	public:
	int N;
	string S;
	ll change[26][26];
	ll add[26];
	ll del[26];
	ll memo[51][51];
	
	ll dodo(int L,int R) {
		if(L>=R) return 0;
		if(memo[L][R]>=0) return memo[L][R];
		memo[L][R]=1LL<<40;
		
		int i;
		FOR(i,26) {
			memo[L][R]=min(memo[L][R],dodo(L+1,R-1)+change[S[L]][i]+change[S[R]][i]);
			memo[L][R]=min(memo[L][R],dodo(L+1,R)+add[i]+change[S[L]][i]);
			memo[L][R]=min(memo[L][R],dodo(L,R-1)+add[i]+change[S[R]][i]);
		}
		memo[L][R]=min(memo[L][R],dodo(L+1,R)+del[S[L]]);
		memo[L][R]=min(memo[L][R],dodo(L,R-1)+del[S[R]]);
		//if(memo[L][R] <1LL<<40) _P("%d %d %lld\n",L,R,memo[L][R]);
		return memo[L][R];
	}
	
	int getMinimumCost(string word, vector <string> operations) {
		int i,x,y,z;
		
		N=operations.size();
		FOR(x,26) FOR(y,26) change[x][y]=1LL<<40;
		FOR(x,26) change[x][x]=0;
		FOR(x,26) add[x]=del[x]=1LL<<40;
		S="";
		FOR(i,word.size()) S+=word[i]-'a';
		
		FOR(i,N) {
			vector<string> OO=split(operations[i],' ');
			if(OO[0]=="erase") del[OO[1][0]-'a']=atoi(OO[2].c_str());
			if(OO[0]=="add") add[OO[1][0]-'a']=atoi(OO[2].c_str());
			if(OO[0]=="change") change[OO[1][0]-'a'][OO[2][0]-'a']=atoi(OO[3].c_str());
		}
		FOR(i,26) FOR(x,26) FOR(y,26) change[x][y]=min(change[x][y],change[x][i]+change[i][y]);
		FOR(y,26) FOR(i,26) FOR(x,26) del[x]=min(del[x],change[x][i]+del[i]);
		FOR(y,26) FOR(i,26) FOR(x,26) add[x]=min(add[x],change[i][x]+add[i]);
		
		MINUS(memo);
		ll res=dodo(0,S.size()-1);
		if(res>=1LL<<40) return -1;
		return (int)res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "racecar"; string Arr1[] = {}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(0, Arg2, getMinimumCost(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "topcoder"; string Arr1[] = {"erase t 1", "erase o 1", "erase p 1", "erase c 1", "erase d 1", "erase e 1", "erase r 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(1, Arg2, getMinimumCost(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "topcoder"; string Arr1[] = {"erase t 10", "erase o 1", "erase p 1", "erase c 1", "erase d 1", "erase e 1", "erase r 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; verify_case(2, Arg2, getMinimumCost(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "caaaaaab"; string Arr1[] = {"change b a 100000", "change c a 100000", "change c d 50000", "change b e 50000", "erase d 50000", "erase e 49999"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 199999; verify_case(3, Arg2, getMinimumCost(Arg0, Arg1)); }
	//void test_case_4() { string Arg0 = "moon"; string Arr1[] = {"erase o 5", "add u 7", "change d p 3", "change m s 12", "change n d 6", "change s l 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(4, Arg2, getMinimumCost(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "ltbgpjcsaknlzctionkqffrpevmybpptydvizassekdoznkln"; string Arr1[] = {"change g n 47673", "erase r 77264", "change l t 42081", "add r 4800", "add b 96464", "erase k 51662", "change b n 39898", "erase d 22461", "erase g 27854", "change p u 14295", "add d 51496", "add e 75369", "add o 87389", "change t z 27185", "change c z 71695", "change b l 54216", "add i 19003", "add f 27638", "add u 85866", "change j u 67802", "erase t 57582", "erase i 22054", "add k 10000", "change q b 34740", "add q 72938", "change x m 44234", "erase s 36666", "erase b 14907", "add h 69181", "erase f 99058", "change p b 90898", "erase l 21277", "add x 32316", "change c m 85633", "change v o 96383", "change y u 61797", "change h v 19755", "change p r 8901", "change n h 99960"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1629924; verify_case(4, Arg2, getMinimumCost(Arg0, Arg1)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PalindromizationDiv1 ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

