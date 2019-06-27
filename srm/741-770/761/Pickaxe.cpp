#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

template<int um> class UF {
	public:
	vector<int> par,rank;
	UF() {rank=vector<int>(um,0); for(int i=0;i<um;i++) par.push_back(i);}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};


class Pickaxe {
	public:
	int countWalls(vector <string> S) {
		int H=S.size(),W=S[0].size();
		int y,x;
		UF<10000> uf;
		FOR(y,H) {
			FOR(x,W) {
				if(y&&S[y][x]=='.' && S[y-1][x]=='.') uf(y*W+x,(y-1)*W+x);
				if(x&&S[y][x]=='.' && S[y][x-1]=='.') uf(y*W+x,y*W+x-1);
			}
		}
		
		int num=0;
		FOR(y,H) FOR(x,W) if(S[y][x]=='#') {
			int mask=0;
			if(y&&uf[(y-1)*W+x]==uf[0]) mask|=1;
			if(y&&uf[(y-1)*W+x]==uf[H*W-1]) mask|=2;
			if(y+1<H&&uf[(y+1)*W+x]==uf[0]) mask|=1;
			if(y+1<H&&uf[(y+1)*W+x]==uf[H*W-1]) mask|=2;
			if(x&&uf[y*W+x-1]==uf[0]) mask|=1;
			if(x&&uf[y*W+x-1]==uf[H*W-1]) mask|=2;
			if(x+1<W&&uf[y*W+x+1]==uf[0]) mask|=1;
			if(x+1<W&&uf[y*W+x+1]==uf[H*W-1]) mask|=2;
			if(mask==3) num++;
		}
		return num;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"..#",
 ".#.",
 "#.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, countWalls(Arg0)); }
	void test_case_1() { string Arr0[] = {"..##..",
 "..##..",
 "...#..",
 "..##.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, countWalls(Arg0)); }
	void test_case_2() { string Arr0[] = {"..##..",
 "..##..",
 "..##..",
 "..##.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, countWalls(Arg0)); }
	void test_case_3() { string Arr0[] = {".....#.",
 ".###.#.",
 ".#.#...",
 ".###.##",
 ".#.#.#.",
 ".#.###.",
 "##....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(3, Arg1, countWalls(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Pickaxe ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

