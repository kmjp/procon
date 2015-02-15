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

int mama[1<<16];
int type[1<<16];
class CutTheNumbers {
	public:
	vector<string> B;
	int maximumSum(vector <string> board) {
		int i,mask,x,y,nmask;
		B.clear();
		FOR(i,4) {
			string s="0000";
			if(i>=4-board.size()) s+=board[i-(4-board.size())];
			B.push_back(s.substr(s.size()-4));
		}
		MINUS(type);
		FOR(y,4) FOR(x,4) {
			int tm=1<<(y*4+x);
			type[tm]=B[y][x]-'0';
			for(int tx=x+1;tx<4;tx++) {
				tm |= 1<<(y*4+tx);
				type[tm]=type[tm^(1<<(y*4+tx))]*10+B[y][tx]-'0';
			}
			tm=1<<(y*4+x);
			for(int ty=y+1;ty<4;ty++) {
				tm |= 1<<(ty*4+x);
				type[tm]=type[tm^(1<<(ty*4+x))]*10+B[ty][x]-'0';
			}
		}
		vector<pair<int,int> > V;
		FOR(i,1<<16) if(type[i]>=0) V.push_back(make_pair(i,type[i]));
		
		
		ZERO(mama);
		FOR(mask,1<<16) FOR(i,V.size()) if((mask & V[i].first)==0) 
			mama[mask|V[i].first] = max(mama[mask|V[i].first],mama[mask]+V[i].second);
		return mama[0xFFFF];
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"123",
 "312"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 435; verify_case(0, Arg1, maximumSum(Arg0)); }
	void test_case_1() { string Arr0[] = {"99",
 "11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 182; verify_case(1, Arg1, maximumSum(Arg0)); }
	void test_case_2() { string Arr0[] = {"001",
 "010",
 "111",
 "100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1131; verify_case(2, Arg1, maximumSum(Arg0)); }
	void test_case_3() { string Arr0[] = {"8"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(3, Arg1, maximumSum(Arg0)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CutTheNumbers ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

