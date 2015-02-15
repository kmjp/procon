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

class ThreeLLogo {
	public:
	ll wid[31][31];
	ll hei[31][31];
	vector<pair<int,int> > OK;
	
	ll cross3(int a,int b,int c) {
		// cross a&b&c
		ll ax=OK[a].first, ay=OK[a].second;
		ll bx=OK[b].first, by=OK[b].second;
		ll cx=OK[c].first, cy=OK[c].second;
		ll aw=wid[ay][ax], ah=hei[ay][ax];
		ll bw=wid[by][bx], bh=hei[by][bx];
		ll cw=wid[cy][cx], ch=hei[cy][cx];
		ll maw=1,mah=1;
		ll mbw=1,mbh=1;
		ll mcw=1,mch=1;
		
		if(ax==bx && by-bh<ay) mbh=max(mbh,ay-by);
		else if(ay==by && ax+aw>=bx) maw=max(maw,bx-ax);
		else if(ax<bx && ay<by && ax+aw>=bx && by-bh<=ay) maw=max(maw,bx-ax),mbh=max(mbh,by-ay);
		else return 0;
		
		if(ax==cx && cy-ch<ay) mch=max(mch,ay-cy);
		else if(ay==cy && ax+aw>=cx) maw=max(maw,cx-ax);
		else if(ax<cx && ay<cy && ax+aw>=cx && cy-ch<=ay) maw=max(maw,cx-ax),mch=max(mch,cy-by);
		else return 0;
		
		if(bx==cx && cy-ch<by) mch=max(mch,by-cy);
		else if(by==cy && bx+bw>=cx) mbw=max(mbw,cx-bx);
		else if(bx<cx && by<cy && bx+bw>=cx && cy-ch<=by) mbw=max(mbw,cx-bx),mch=max(mch,cy-by);
		else return 0;
		if(aw<maw || ah<mah || bw<mbw || bh<mbh || cw<mcw || ch<mch) return 0;
		_P("++ %lld %lld %lld %lld %lld %lld\n",aw,ah,bw,bh,cw,ch);
		_P("+- %lld %lld %lld %lld %lld %lld\n",maw,mah,mbw,mbh,mcw,mch);
		_P("-- %lld\n",(aw-maw+1)*(bw-mbw+1)*(cw-mcw+1)*(ah-mah+1)*(bh-mbh+1)*(ch-mch+1));
		return (aw-maw+1)*(bw-mbw+1)*(cw-mcw+1)*(ah-mah+1)*(bh-mbh+1)*(ch-mch+1);
	}
	ll cross21(int a,int b,int c) {
		// cross a&b but not a&c, b&c
		ll ax=OK[a].first, ay=OK[a].second;
		ll bx=OK[b].first, by=OK[b].second;
		ll cx=OK[c].first, cy=OK[c].second;
		ll aw=wid[ay][ax], ah=hei[ay][ax];
		ll bw=wid[by][bx], bh=hei[by][bx];
		ll cw=wid[cy][cx], ch=hei[cy][cx];
		ll maw=1,mah=1;
		ll mbw=1,mbh=1;
		ll mcw=1,mch=1;
		
		if(ax==bx && by-bh<ay) mbh=max(mbh,by-ay);
		else if(ay==by && ax+aw>=bx) maw=max(maw,bx-ax);
		else if(ax<bx && ay<by && ax+aw>=bx && by-bh<=ay) maw=max(maw,bx-ax),mbh=max(mbh,by-ay);
		else return 0;
		
		if(b<c) {
			if(bx==cx && cy-ch<by) ch=by-cy-1;
			else if(by==cy && bx+bw>=cx) bw=cx-bx-1;
			else if(bx<cx && by<cy && bx+bw>=cx && cy-ch<=by) ch=by-cy-1,aw=cx-bx-1;
		}
		else {
			if(cx==bx && by-bh<cy) bh=cy-by-1;
			else if(cy==by && cx+cw>=bx) cw=bx-cx-1;
			else if(cx<bx && cy<by && cx+cw>=bx && by-bh<=cy) bh=cy-by-1,aw=bx-cx-1;
		}
		
		if(a<c) {
			if(ax==cx && cy-ch<ay) ch=ay-cy-1;
			else if(ay==cy && ax+aw>=cx) aw=cx-ax-1;
			else if(ax<cx && ay<cy && ax+aw>=cx && cy-ch<=ay) ch=ay-cy-1,aw=cx-ax-1;
		}
		else {
			if(cx==ax && ay-ah<cy) ah=cy-ay-1;
			else if(cy==ay && cx+cw>=ax) cw=ax-cx-1;
			else if(cx<ax && cy<ay && cx+cw>=ax && ay-ah<=cy) ah=cy-ay-1,aw=ax-cx-1;
		}
		
		_P("21-+ %d %d %d (%lld,%lld) (%lld,%lld) (%lld,%lld)\n",a,b,c,ax,ay,bx,by,cx,cy);
		_P("21++ %lld %lld %lld %lld %lld %lld\n",aw,ah,bw,bh,cw,ch);
		_P("21+- %lld %lld %lld %lld %lld %lld\n",maw,mah,mbw,mbh,mcw,mch);
		_P("21-- %lld\n",(aw-maw+1)*(bw-mbw+1)*(cw-mcw+1)*(ah-mah+1)*(bh-mbh+1)*(ch-mch+1));
		if(aw<maw || ah<mah || bw<mbw || bh<mbh || cw<mcw || ch<mch) return 0;
		
		return (aw-maw+1)*(bw-mbw+1)*(cw-mcw+1)*(ah-mah+1)*(bh-mbh+1)*(ch-mch+1);
	}
	ll cross22(int a,int b,int c) {
		// cross a&b && b&c but not a&c
		ll ax=OK[a].first, ay=OK[a].second;
		ll bx=OK[b].first, by=OK[b].second;
		ll cx=OK[c].first, cy=OK[c].second;
		ll aw=wid[ay][ax], ah=hei[ay][ax];
		ll bw=wid[by][bx], bh=hei[by][bx];
		ll cw=wid[cy][cx], ch=hei[cy][cx];
		ll maw=1,mah=1;
		ll mbw=1,mbh=1;
		ll mcw=1,mch=1;
		
		if(a<b) {
			if(ax==bx && by-bh<ay) mbh=max(mbh,by-ay);
			else if(ay==by && ax+aw>=bx) maw=max(maw,bx-ax);
			else if(ax<bx && ay<by && ax+aw>=bx && by-bh<=ay) maw=max(maw,bx-ax),mbh=max(mbh,by-ay);
			else return 0;
		}
		else {
			if(bx==ax && ay-ah<by) mah=max(mah,ay-by);
			else if(by==ay && bx+bw>=ax) mbw=max(mbw,ax-bx);
			else if(bx<ax && by<ay && bx+bw>=ax && ay-ah<=by) mbw=max(mbw,ax-bx),mah=max(mah,ay-by);
			else return 0;
		}
		
		if(b<c) {
			if(bx==cx && cy-ch<by) mch=max(mch,cy-by);
			else if(by==cy && bx+bw>=cx) mbw=max(mbw,cx-bx);
			else if(bx<cx && by<cy && bx+bw>=cx && cy-ch<=by) mbw=max(mbw,cx-bx),mch=max(mch,cy-by);
			else return 0;
		}
		else {
			if(cx==bx && by-bh<cy) mbh=max(mbh,by-cy);
			else if(cy==by && cx+cw>=bx) mcw=max(mcw,bx-cx);
			else if(cx<bx && cy<by && cx+cw>=bx && by-bh<=cy) mcw=max(mcw,bx-cx),mbh=max(mbh,by-cy);
			else return 0;
		}
		
		if(a<c) {
			if(ax==cx && cy-ch<ay) ch=ay-cy-1;
			else if(ay==cy && ax+aw>=cx) aw=cx-ax-1;
			else if(ax<cx && ay<cy && ax+aw>=cx && cy-ch<=ay) ch=ay-cy-1,aw=cx-ax-1;
		}
		else {
			if(cx==ax && ay-ah<cy) ah=cy-ay-1;
			else if(cy==ay && cx+cw>=ax) cw=ax-cx-1;
			else if(cx<ax && cy<ay && cx+cw>=ax && ay-ah<=cy) ah=cy-ay-1,cw=ax-cx-1;
		}
		
		if(aw<maw || ah<mah || bw<mbw || bh<mbh || cw<mcw || ch<mch) return 0;
		_P("22-+ %d %d %d (%lld,%lld) (%lld,%lld) (%lld,%lld)\n",a,b,c,ax,ay,bx,by,cx,cy);
		_P("22++ %lld %lld %lld %lld %lld %lld\n",aw,ah,bw,bh,cw,ch);
		_P("22+- %lld %lld %lld %lld %lld %lld\n",maw,mah,mbw,mbh,mcw,mch);
		_P("22-- %lld\n",(aw-maw+1)*(bw-mbw+1)*(cw-mcw+1)*(ah-mah+1)*(bh-mbh+1)*(ch-mch+1));
		
		return (aw-maw+1)*(bw-mbw+1)*(cw-mcw+1)*(ah-mah+1)*(bh-mbh+1)*(ch-mch+1);
		
	}
	
	ll dodo(int a,int b,int c) {
		ll ax=OK[a].first, ay=OK[a].second;
		ll bx=OK[b].first, by=OK[b].second;
		ll cx=OK[c].first, cy=OK[c].second;
		ll aw=wid[ay][ax], ah=hei[ay][ax];
		ll bw=wid[by][bx], bh=hei[by][bx];
		ll cw=wid[cy][cx], ch=hei[cy][cx];
		
		if(ax==cx && ay+1==cy) return 0;
		if(ax+1==cx && ay==cy) return 0;
		if(bx==cx && by+1==cy) return 0;
		if(bx+1==cx && by==cy) return 0;
		
		_P("(%lld,%lld),(%lld,%lld),(%lld,%lld)\n",ax,ay,bx,by,cx,cy);
		
		ll ret=aw*ah*bw*bh*cw*ch;
		_P("%lld %lld %lld %lld %lld\n",ret,cross21(a,b,c),cross21(b,c,a),cross21(a,c,b),cross3(a,b,c));
		_P("%lld %lld %lld \n",cross22(a,b,c),cross22(a,c,b),cross22(b,a,c));
		ret-=cross21(a,b,c);
		ret-=cross21(b,c,a);
		ret-=cross21(a,c,b);
		ret-=cross22(a,b,c);
		ret-=cross22(a,c,b);
		ret-=cross22(b,a,c);
		ret-=cross3(a,b,c);
		
		return ret;
	}
	
	long long countWays(vector <string> grid) {
		int H,W,x,y,z;
		H=grid.size();
		W=grid[0].size();
		OK.clear();
		
		MINUS(wid);
		MINUS(hei);
		FOR(y,H) {
			for(x=W-1;x>=0;x--) if(grid[y][x]!='#') wid[y][x]=wid[y][x+1]+1;
		}
		FOR(x,W) {
			FOR(y,H) if(grid[y][x]!='#') hei[y][x]=((y>0)?hei[y-1][x]:-1)+1;
		}
		FOR(y,H) FOR(x,W) if(wid[y][x]>0 && hei[y][x]>0) OK.push_back(make_pair(x,y));
		
		ll ret=0;
		FOR(x,OK.size()) for(y=x+1;y<OK.size();y++) {
			if(OK[x].first==OK[y].first && OK[x].second+1==OK[y].second) continue;
			if(OK[x].first+1==OK[y].first && OK[x].second==OK[y].second) continue;
			
			for(z=y+1;z<OK.size();z++) {
				ret+=dodo(x,y,z);
			}
		}
		
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"......",
 "......"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(0, Arg1, countWays(Arg0)); }
	void test_case_1() { string Arr0[] = {".##..",
 ".....",
 ".#.#.",
 "#...#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 3LL; verify_case(1, Arg1, countWays(Arg0)); }
	void test_case_2() { string Arr0[] = {"....",
 "#...",
 "....",
 "..#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 4LL; verify_case(2, Arg1, countWays(Arg0)); }
	void test_case_3() { string Arr0[] = {"..",
 ".."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(3, Arg1, countWays(Arg0)); }
	void test_case_4() { string Arr0[] = {".#.#",
 "....",
 ".#.#",
 "...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 12LL; verify_case(4, Arg1, countWays(Arg0)); }
	void test_case_5() { string Arr0[] = {"######.#######",
 "######.#######",
 "#.####.#######",
 "#.####.#######",
 "#.####........",
 "#.############",
 "#.############",
 "#.############",
 "#.#####.######",
 "#.#####.######",
 "#.#####.######",
 "#....##.######",
 "#######.######",
 "#######.######",
 "#######.######",
 "#######.######",
 "#######.######",
 "#######.######",
 "#######......#",
 "##############"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 37800LL; verify_case(5, Arg1, countWays(Arg0)); }
	void test_case_6() { string Arr0[] = {"#......",
 ".#....#",
 ".#.#...",
 "#....#.",
 ".##..#.",
 ".#.....",
 ".....#.",
 ".#.#...",
 ".#...#.",
 "..##..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 27750LL; verify_case(6, Arg1, countWays(Arg0)); }
	void test_case_7() { string Arr0[] = {"...#..........................",
 "............#..#........#.....",
 ".#............................",
 "...#..........#...#..##.......",
 ".........#....#...#...#.....#.",
 "#...#......#...........#..#...",
 "#...##..#..#..#.....#.........",
 ".............##...............",
 ".....#..#..#..#...............",
 "......#................#......",
 "...#....#.........#.....#...#.",
 ".........#....................",
 ".........#.........##......#..",
 ".#.#..#.....#.#....#.#........",
 "....#.........#...#...........",
 "..##.....#.............#......",
 ".#............................",
 "......................#.......",
 "......#..............#.......#",
 "##..#.........#........#.....#",
 "......#.......#.....#.........",
 ".....#...#...#.#............#.",
 "......#..##....#..............",
 "....#....................#....",
 ".#..........................#.",
 ".............#..........#.....",
 ".#.........#..................",
 "................#.........##..",
 ".......................#.....#",
 ".............#...............#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2178497179123LL; verify_case(7, Arg1, countWays(Arg0)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ThreeLLogo ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

