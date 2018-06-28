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

int D[50][50];

class TeleportationMaze {
	public:
	int pathLength(vector <string> a, int r1, int c1, int r2, int c2) {
		int H=a.size();
		int W=a[0].size();
		
		int y,x;
		FOR(y,H) FOR(x,W) D[y][x]=505050;
		priority_queue<pair<int,int>> Q;
		D[r1][c1]=0;
		Q.push({0,r1*100+c1});
		while(Q.size()) {
			int co=-Q.top().first;
			int cy=Q.top().second/100;
			int cx=Q.top().second%100;
			Q.pop();
			if(D[cy][cx]!=co) continue;
			
			for(y=cy+1;y<H;y++) if(a[y][cx]=='.') {
				int ac=(abs(y-cy)<=1)?1:2;
				if(D[y][cx]>co+ac) {
					D[y][cx]=co+ac;
					Q.push({-D[y][cx],y*100+cx});
				}
				break;
			}
			for(y=cy-1;y>=0;y--) if(a[y][cx]=='.') {
				int ac=(abs(y-cy)<=1)?1:2;
				if(D[y][cx]>co+ac) {
					D[y][cx]=co+ac;
					Q.push({-D[y][cx],y*100+cx});
				}
				break;
			}
			for(x=cx+1;x<W;x++) if(a[cy][x]=='.') {
				int ac=(abs(x-cx)<=1)?1:2;
				if(D[cy][x]>co+ac) {
					D[cy][x]=co+ac;
					Q.push({-D[cy][x],cy*100+x});
				}
				break;
			}
			for(x=cx-1;x>=0;x--) if(a[cy][x]=='.') {
				int ac=(abs(x-cx)<=1)?1:2;
				if(D[cy][x]>co+ac) {
					D[cy][x]=co+ac;
					Q.push({-D[cy][x],cy*100+x});
				}
				break;
			}
			
			
		}
		
		if(D[r2][c2]>=505050) D[r2][c2]=-1;
		return D[r2][c2];
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".##.",
 ".###",
 ".###",
 "...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arg3 = 3; int Arg4 = 3; int Arg5 = 4; verify_case(0, Arg5, pathLength(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { string Arr0[] = {"#.",
 ".#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; int Arg3 = 1; int Arg4 = 0; int Arg5 = -1; verify_case(1, Arg5, pathLength(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { string Arr0[] = {"......",
 "#####.",
 "#.###.",
 "#####.",
 "#.###.",
 "#####.",
 "#....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arg3 = 6; int Arg4 = 1; int Arg5 = 5; verify_case(2, Arg5, pathLength(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TeleportationMaze ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

