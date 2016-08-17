#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int first[20][20];
int firsec[20];
int second[20][20];
int fi[1<<10];
int sc[1<<20];
map<pair<int,int>,int> M;

class Clicounting {
	public:
	int count(vector <string> g) {
		int i,x,y,mask;
		
		ZERO(fi);
		ZERO(sc);
		ZERO(firsec);
		M.clear();
		
		while(g.size()<40) {
			FORR(s,g) s+="0";
			g.push_back(string(g[0].size(),'0'));
		}
		vector<int> V;
		int did[40]={};
		FOR(i,40) if(std::count(g[i].begin(),g[i].end(),'?')) V.push_back(i), did[i]=1;
		FOR(i,40) if(did[i]==0) V.push_back(i);
		
		int numh=0;
		FOR(y,20) {
			first[y][y]=second[y][y]=1;
			FOR(x,y) {
				if(g[V[x]][V[y]]=='0') first[x][y]=first[y][x]=0;
				if(g[V[x]][V[y]]=='1') first[x][y]=first[y][x]=1;
				if(g[V[x]][V[y]]=='?') first[x][y]=first[y][x]=2, M[{x,y}]=M[{y,x}]=numh++;
				if(g[V[x+20]][V[y+20]]=='0') second[x][y]=second[y][x]=0;
				if(g[V[x+20]][V[y+20]]=='1') second[x][y]=second[y][x]=1;
			}
			FOR(x,20) firsec[x] |= (g[V[x]][V[y+20]]=='1')<<y;
		}
		
		FOR(mask,1<<20) {
			int yes=1;
			FOR(y,20) if(mask&(1<<y)) FOR(x,y) if(mask&(1<<x)) {
				if(second[x][y]==0) yes=0;
			}
			if(yes) sc[mask]=__builtin_popcount(mask);
		}
		FOR(mask,1<<10) fi[mask]=sc[(1<<20)-1];
		FOR(i,20) FOR(mask,1<<20) sc[mask | (1<<i)] = max(sc[mask | (1<<i)], sc[mask]);
		FOR(mask,1<<20) {
			int need=0, yes=1,secmask=(1<<20)-1;
			FOR(y,20) if(mask&(1<<y)) {
				secmask &= firsec[y];
				FOR(x,y) if(mask&(1<<x)) {
					if(first[x][y]==0) yes=0;
					if(first[x][y]==2) need |= 1<<M[{x,y}];
				}
			}
			if(yes) fi[need] = max(fi[need],__builtin_popcount(mask) + sc[secmask]);
		}
		FOR(i,numh) FOR(mask,1<<numh) fi[mask | (1<<i)] = max(fi[mask | (1<<i)], fi[mask]);
		return accumulate(fi,fi+(1<<numh),0);
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"011","101","110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arr0[] = {"01?","101","?10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arr0[] = {"0?","?0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arr0[] = {"0??","?0?","??0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { string Arr0[] = {"0???","?0??","??0?","???0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 151; verify_case(4, Arg1, count(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Clicounting ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
