#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int dp[52][52][4][52];

class JumpingTiger {
	public:
	int travel(vector <string> plan) {
		int H=plan.size();
		int W=plan[0].size();
		int y,x,i,j;
		FOR(y,H) FOR(x,W) FOR(i,4) FOR(j,51) dp[y][x][i][j]=1<<30;
		
		queue<int> Q;
		FOR(y,H) FOR(x,W) {
			if(plan[y][x]=='T') {
				FOR(i,4) {
					dp[y][x][i][1]=0;
					Q.push(y*1000000+x*10000+i*100+1);
				}
			}
		}
		int d[4]={0,1,0,-1};
		while(Q.size()) {
			int cy=Q.front()/1000000;
			int cx=Q.front()/10000%100;
			int dir=Q.front()/100%100;
			int step=Q.front()%100;
			Q.pop();
			int co=dp[cy][cx][dir][step];
			int ndir;
			FOR(ndir,4) {
				if(step!=1&&ndir!=dir) continue;
				for(j=1;j<=50;j++) {
					if(step!=1&&j>=step) continue;
					int ty=cy+j*d[ndir];
					int tx=cx+j*d[ndir^1];
					if(ty<0||ty>=H||tx<0||tx>=W) continue;
					if(plan[ty][tx]=='#') continue;
					if(dp[ty][tx][ndir][j]>co+1) {
						dp[ty][tx][ndir][j]=co+1;
						Q.push(ty*1000000+tx*10000+ndir*100+j);
					}
					
				}
			}
			
			
		}
		
		
		int mi=1<<30;
		FOR(y,H) FOR(x,W) {
			if(plan[y][x]=='L') {
				FOR(i,4) mi=min(mi,dp[y][x][i][1]);
			}
		}
		if(mi==1<<30) mi=-1;
		return mi;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"T.######",
 "#..#####",
 "##..####",
 "###..###",
 "####..##",
 "#####..#",
 "######..",
 "#######L"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 14; verify_case(0, Arg1, travel(Arg0)); }
	void test_case_1() { string Arr0[] = {"T.######",
 "#..#####",
 "##..####",
 "###..###",
 "####..##",
 "#####..#",
 "######..",
 ".######L"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 14; verify_case(1, Arg1, travel(Arg0)); }
	void test_case_2() { string Arr0[] = {"T.######",
 "#..#####",
 "##..####",
 "###..###",
 "####..##",
 "#####..#",
 ".#####..",
 ".######L"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(2, Arg1, travel(Arg0)); }
	void test_case_3() { string Arr0[] = {"T.######",
 "#..#####",
 "##..####",
 "###..###",
 "####..##",
 "#####..#",
 ".#####..",
 ".#####.L"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, travel(Arg0)); }
	void test_case_4() { string Arr0[] = {".##.",
 "#L##",
 "####",
 ".#T#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(4, Arg1, travel(Arg0)); }
	void test_case_5_() { string Arr0[] = {"T", "#", "#", "L", "#", "#", ".", "."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(5, Arg1, travel(Arg0)); }
	void test_case_5() { string Arr0[] = {"####..#######..###...#############..##..", "...#.#.....#######..##########..######..", ".###.#.############.##########.##.##L.#.", "#..#####.##...#..#..##########....#.....", "#..#.#...####.#.##############....#.....", ".#.#..#######.#.####..###############..#", ".....##..##..######.############...##...", "###############.###.############.####.##", "#.#############.#####################.##", "#.##############################.#######", ".##############..###############.##.###.", ".######..####..###..###########.....#...", "#######....########################T##..", "########.#################.##..###..##..", "########.####.############.############.", "##..###....##.##.#####.#######..#..#..#.", "################.#####..###########.###.", "#..#...###....########..###.##...##..#..", ".##############..##########.##..#######.", ".#######.######.##############.######...", "########.############################.##", "################.####################.##", "################.##############.#####.##", "###########################..##..####..#", "################.###################...#", "########.#######.####################.##", "########.######################.########", "..##########.##################.########", "######.####..#####..##..######..##..####", "######.####################.#####..#..##", "###########################.#######.##..", "###############.###################.####", "####.###.######.###.####################", "####.###.##########.######..####.#######", "#..##############.#########.####.######.", "...##..###.####.#..##################...", "##.#######.####.#####################.#.", "..#############..################..#..#.", "..#############.#...#####..###.###..#.##", ".#..####...####.#######..##.#..##...#...", ".#######...####..#######....####..####.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(5, Arg1, travel(Arg0)); }



// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  JumpingTiger ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

