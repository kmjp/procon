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

class IslandInALake {
	public:
	int build(vector <string> country) {
		int H=country.size();
		int W=country[0].size();
		int y,x,cy,cx;
		UF<2500> uf;
		UF<2500> uf2;
		FOR(y,H) FOR(x,W) if(country[y][x]=='.') {
			if(y&&country[y-1][x]=='.') uf2(y*50+x,(y-1)*50+x);
			if(x&&country[y][x-1]=='.') uf2(y*50+x,y*50+x-1);
		}
		FOR(y,H) FOR(x,W) if(country[y][x]=='#') {
			for(cy=y-1;cy<=y+1;cy++) {
				for(cx=x-1;cx<=x+1;cx++) if(country[cy][cx]=='.') country[cy][cx]='$';
			}
		}
		
		FOR(y,H) FOR(x,W) if(country[y][x]=='.'&&uf2[0]!=uf2[y*50+x]) {
			for(cy=y-1;cy<=y+1;cy++) {
				for(cx=x-1;cx<=x+1;cx++) if(country[cy][cx]=='.'&&uf2[cy*50+cx]!=uf2[0]) uf(y*50+x,cy*50+cx);
			}
		}
		int ma=0;
		FOR(y,H) FOR(x,W) if(country[y][x]=='.') {
			if(uf2[0]==uf2[y*50+x]) continue;
			ma=max(ma,uf.count(y*50+x));
		}
		//FOR(y,H) cout<<country[y]<<endl;
		return ma;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); if ((Case == -1) || (Case == 8)) test_case_8(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"......",
 "......",
 "......",
 "......",
 "......"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, build(Arg0)); }
	void test_case_1() { string Arr0[] = {".......",
 "..##...",
 ".##..#.",
 "..#.#..",
 "......."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, build(Arg0)); }
	void test_case_2() { string Arr0[] = {".......",
 ".####..",
 ".#...#.",
 ".#####.",
 "......."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, build(Arg0)); }
	void test_case_3() { string Arr0[] = {"..........",
 ".####.....",
 ".#...#....",
 ".#...#....",
 ".#...#....",
 ".#####....",
 ".........."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, build(Arg0)); }
	void test_case_4() { string Arr0[] = {"............",
 ".####.#####.",
 ".#...#....#.",
 ".#........#.",
 ".#...#....#.",
 ".#########..",
 "............"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(4, Arg1, build(Arg0)); }
	void test_case_5() { string Arr0[] = {"...........",
 "..#####....",
 "..#....##..",
 "..#.....#..",
 "...#.....#.",
 "..#.#....#.",
 ".#...#...#.",
 "..###.###..",
 "..........."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(5, Arg1, build(Arg0)); }
	void test_case_6() { string Arr0[] = {"...........",
 ".#########.",
 ".#.......#.",
 ".#.#####.#.",
 ".#.#...#.#.",
 ".#.#...#.#.",
 ".#.#...#.#.",
 ".#.#####.#.",
 ".#.......#.",
 ".#########.",
 "..........."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(6, Arg1, build(Arg0)); }
	void test_case_7() { string Arr0[] = {"...........",
 ".#########.",
 ".#.......#.",
 ".#.#####.#.",
 ".#.#...#...",
 ".#.#...#.#.",
 ".#.#...#.#.",
 ".#.###.#.#.",
 ".#.......#.",
 ".#########.",
 "..........."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(7, Arg1, build(Arg0)); }
	void test_case_8() { string Arr0[] = {"...........",
 ".#########.",
 ".#.......#.",
 ".#.......#.",
 ".#.......#.",
 ".#.......#.",
 ".#.......#.",
 ".#.......#.",
 ".#...#...#.",
 ".#.......#.",
 ".#.......#.",
 ".#.......#.",
 ".#########.",
 "..........."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 31; verify_case(8, Arg1, build(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  IslandInALake ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

