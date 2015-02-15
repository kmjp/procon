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

class RectangleArea {
	public:
	int minimumQueries(vector <string> known) {
		int i,x,y;
		int H=known.size();
		int W=known[0].size();
		
		int ret=0;
		ll ymask=0,xmask=0;
		int vis[51][51];
		ZERO(vis);
		
		FOR(y,H) FOR(x,W) if(vis[y][x]==0 && known[y][x]=='Y') {
			vis[y][x]=1;
			ret++;
			queue<pair<int,int> > Q;
			Q.push(make_pair(x,y));
			while(!Q.empty()) {
				int cx=Q.front().first,cy=Q.front().second;
				Q.pop();
				ymask |= (1LL<<cy);
				xmask |= (1LL<<cx);
				
				FOR(i,H) if(known[i][cx]=='Y' && vis[i][cx]==0) vis[i][cx]=1, Q.push(make_pair(cx,i));
				FOR(i,W) if(known[cy][i]=='Y' && vis[cy][i]==0) vis[cy][i]=1, Q.push(make_pair(i,cy));
			}
		}
		
		int ly = H-__builtin_popcountll(ymask);
		int lx = W-__builtin_popcountll(xmask);
		return ret+(ly+lx-1);
		

	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NN",
 "NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, minimumQueries(Arg0)); }
	void test_case_1() { string Arr0[] = {"YNY",
 "NYN",
 "YNY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, minimumQueries(Arg0)); }
	void test_case_2() { string Arr0[] = {"YY",
 "YY",
 "YY",
 "YY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, minimumQueries(Arg0)); }
	void test_case_3() { string Arr0[] = {"NNNNNNNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(3, Arg1, minimumQueries(Arg0)); }
	void test_case_4() { string Arr0[] = {"NNYYYNN",
 "NNNNNYN",
 "YYNNNNY",
 "NNNYNNN",
 "YYNNNNY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(4, Arg1, minimumQueries(Arg0)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RectangleArea ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

