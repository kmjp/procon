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


class SlimeXResidentSlime {
	public:
	int R,C;
	vector<string> F;
	vector<int> V;
	int cost[51][51];
	
	int bfs(int id) {
		int i,dist[51][51],x,y;
		
		FOR(y,R) FOR(x,C) dist[y][x]=10000000;
		dist[V[id]/100][V[id]%100]=0;
		queue<int> Q;
		Q.push(V[id]);
		
		while(!Q.empty()) {
			int cy=Q.front()/100,cx=Q.front()%100;
			Q.pop();
			FOR(i,4) {
				int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
				int tx=cx+dx[i],ty=cy+dy[i];
				if(tx<0 || tx>=C || ty<0 || ty>=R || F[ty][tx]=='#') continue;
				if(dist[ty][tx]>dist[cy][cx]+1) {
					dist[ty][tx]=dist[cy][cx]+1;
					Q.push(ty*100+tx);
				}
			}
		}
		
		FOR(x,V.size()) cost[id][x]=dist[V[x]/100][V[x]%100];
	}
	
	int exterminate(vector <string> field) {
		F=field;
		R=field.size();
		C=field[0].size();
		int y,x,z;
		
		V.clear();
		FOR(y,R) FOR(x,C) if(field[y][x]=='$') V.push_back(y*100+x);
		FOR(y,R) FOR(x,C) if(field[y][x]>='1' && field[y][x]<='9') V.push_back(y*100+x);
		if(V.size()>10) return -1;
		
		FOR(x,V.size()) bfs(x);
		int mi=10000000,i;
		vector<int> CC;
		for(x=1;x<V.size();x++) CC.push_back(x);
		z=CC.size();
		do {
			int tc[11],c=0;
			tc[0]=0;
			FOR(x,z) tc[x+1]=tc[x]+cost[c][CC[x]], c=CC[x];
			if(tc[z]<mi) {
				int ng=0;
				FOR(x,z) {
					if(tc[z]-tc[x+1]>=F[V[CC[x]]/100][V[CC[x]]%100]-'0') ng++;
				}
				if(ng==0) mi=tc[z];
			}
			
		} while(next_permutation(CC.begin(),CC.end()));
		
		if(mi<10000000) return mi;
		return -1;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = 
{
"#1$",
".2."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, exterminate(Arg0)); }
	void test_case_1() { string Arr0[] = {
"$",
"1",
"1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, exterminate(Arg0)); }
	void test_case_2() { string Arr0[] = {
"$124"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(2, Arg1, exterminate(Arg0)); }
	void test_case_5() { string Arr0[] = {"$.#2"
,"#..1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(3, Arg1, exterminate(Arg0)); }
	void test_case_3() { string Arr0[] = {"..999..", ".9999..", ".99$..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(3, Arg1, exterminate(Arg0)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SlimeXResidentSlime ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

