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

template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; FOR(i,um) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};


class RGBTree {
	public:
	int N,ok;
	vector<pair<int,int>> E[3];
	
	void dfs(UF<13>& uf,int ph,int d,int l) {
		int i;
		
		if(d==E[ph].size()) {
			if(l) return;
			if(ph==1) {
				l=(N-1)/3;
				FOR(i,E[2].size()) if(l>0 && uf[E[2][i].first]!=uf[E[2][i].second]) {
					l--;
					uf(E[2][i].first,E[2][i].second);
				}
				if(uf.count(0)==N) ok=1;
			}
			else {
				dfs(uf,ph+1,0,(N-1)/3);
			}
			return;
		}
		
		if(l>0 && uf[E[ph][d].first]!=uf[E[ph][d].second]) {
			UF<13> uf2=uf;
			uf2(E[ph][d].first,E[ph][d].second);
			dfs(uf2,ph,d+1,l-1);
			if(ph==2) return;
		}
		dfs(uf,ph,d+1,l);
	}
	
	
	string exist(vector <string> G) {
		int x,y;
		N=G.size();
		FOR(x,3) E[x].clear();
		FOR(y,N) FOR(x,y) {
			if(G[y][x]=='R') E[0].push_back({x,y});
			if(G[y][x]=='G') E[1].push_back({x,y});
			if(G[y][x]=='B') E[2].push_back({x,y});
		}
		if(E[0].size()>E[1].size()) swap(E[0],E[1]);
		if(E[1].size()>E[2].size()) swap(E[1],E[2]);
		if(E[0].size()>E[1].size()) swap(E[0],E[1]);
		ok=0;
		UF<13> uf;
		dfs(uf,0,0,(N-1)/3);
		if(ok) return "Exist";
		return "Does not exist";
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".RGB",
 "R...",
 "G...",
 "B..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Exist"; verify_case(0, Arg1, exist(Arg0)); }
	void test_case_1() { string Arr0[] = {".RRB",
 "R...",
 "R...",
 "B..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Does not exist"; verify_case(1, Arg1, exist(Arg0)); }
	void test_case_2() { string Arr0[] = {".R..BG..G..RG","R...GG..BR.G.","...G.GG.RR.BB","..G.RR.B..GRB","BG.R.G.BRRR.G","GGGRG.R....RR","..G..R.BGRR..","...BB.B.RB.G.","GBR.R.GR.B.R.",".RR.R.RBB.BRB","...GR.R..B...","RGBR.R.GRR...","G.BBGR...B..."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Exist"; verify_case(2, Arg1, exist(Arg0)); }
	void test_case_3() { string Arr0[] = {".............",".......BB.R..",".......RR....",".....G.G....R","........BB...","...G.........","........B...R",".BRG.......G.",".BR.B.B...GB.","....B......GR",".R......G....",".......GBG..B","...R..R..R.B."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Does not exist"; verify_case(3, Arg1, exist(Arg0)); }
	void test_case_4() { string Arr0[] = {"..B.BB...RB..","......R..B.G.","B.......BB...",".......R...G.","B....GRB..R..","B...G.RG.R...",".R..RR..B.RB.","...RBG...G...","..B...B......","RBB..R.G....R","B...R.R......",".G.G..B.....R",".........R.R."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Exist"; verify_case(4, Arg1, exist(Arg0)); }
	void test_case_5() { string Arr0[] = {"....",
 "....",
 "....",
 "...."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Does not exist"; verify_case(5, Arg1, exist(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RGBTree ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
