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

int dist[16][16][16][16][16][16];

class TwoByTwo {
	public:
	int H,W;
	vector <string> B;
	priority_queue<pair<int,int>> PQ;
	
	void update(int ty,int tx,int ay,int ax,int by,int bx,int co) {
		if(ay>by) swap(ay,by),swap(ax,bx);
		if(ay==by && ax>ax) swap(ay,by),swap(ax,bx);
		
		if(dist[ty][tx][ay][ax][by][bx]>co) {
			dist[ty][tx][ay][ax][by][bx]=co;
			PQ.push({-co,(ty<<20)+(tx<<16)+(ay<<12)+(ax<<8)+(by<<4)+(bx<<0)});
		}
	}
	
	void hoge(int ty,int tx,int ay,int ax,int by,int bx,int y1,int x1,int y2,int x2,int co) {
		if(B[y1][x1] && ((ay!=y1)||(ax!=x1))&&((by!=y1)||(bx!=x1))) co++;
		if(B[y2][x2] && ((ay!=y2)||(ax!=x2))&&((by!=y2)||(bx!=x2))) co++;
		
		update(ty,tx,ay,ax,by,bx,co);
		update(ty,tx,y1,x1,by,bx,co);
		update(ty,tx,y2,x2,by,bx,co);
		update(ty,tx,ay,ax,y1,x1,co);
		update(ty,tx,ay,ax,y2,x2,co);
		update(ty,tx,y1,x1,y2,x2,co);
	}
	
	int minimal(vector <string> board) {
		
		B=board;
		H=B.size(),W=B[0].size();
		int y,x,ret=0;
		FOR(y,H) FOR(x,W) {
			B[y][x]=B[y][x]=='#';
			if((y<=1&&x<=1) || (y>=H-2&&x>=W-2)) {
				ret+=B[y][x];
				B[y][x]=0;
			}
		}
		
		while(PQ.size()) PQ.pop();
		memset(dist,0x3f,sizeof(dist));
		dist[0][0][0][0][0][0]=0;
		PQ.push({0,0});
		
		while(PQ.size()) {
			int co=-PQ.top().first;
			int cy=(PQ.top().second>>20)&0xF;
			int cx=(PQ.top().second>>16)&0xF;
			int ay=(PQ.top().second>>12)&0xF;
			int ax=(PQ.top().second>>8)&0xF;
			int by=(PQ.top().second>>4)&0xF;
			int bx=(PQ.top().second>>0)&0xF;
			PQ.pop();
			if(co!=dist[cy][cx][ay][ax][by][bx]) continue;
			
			if(cy==H-2&&cx==W-2) return co+ret;
			if(cy) hoge(cy-1,cx,ay,ax,by,bx,cy-1,cx,cy-1,cx+1,co);
			if(cy<H-2) hoge(cy+1,cx,ay,ax,by,bx,cy+2,cx,cy+2,cx+1,co);
			if(cx) hoge(cy,cx-1,ay,ax,by,bx,cy,cx-1,cy+1,cx-1,co);
			if(cx<W-2) hoge(cy,cx+1,ay,ax,by,bx,cy,cx+2,cy+1,cx+2,co);
			
		}
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"..#",
 "...",
 "#.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, minimal(Arg0)); }
	void test_case_1() { string Arr0[] = {"#..#.#",
 "##.##."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(1, Arg1, minimal(Arg0)); }
	void test_case_2() { string Arr0[] = {"......",
 "......",
 "####..",
 "####..",
 "......",
 "......",
 "..####",
 "..####",
 "......",
 "......"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, minimal(Arg0)); }
	void test_case_3() { string Arr0[] = {".###.#.#",
 "#.#.#..#",
 "#..#..#.",
 "#..#.#.#",
 "#.#....#",
 "#.##.##.",
 ".#.##...",
 "#.####.#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(3, Arg1, minimal(Arg0)); }
	void test_case_4() { string Arr0[] = {"##",
 "##"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(4, Arg1, minimal(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TwoByTwo ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

