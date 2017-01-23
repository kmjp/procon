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

int dist[24][24][401];

class MovingCandies {
	public:
	
	int H,W;
	int minMoved(vector <string> t) {
		H=t.size();
		W=t[0].size();
		int y,x,i;
		int num=0;
		FOR(y,H) FOR(x,W) if(t[y][x]=='#') num++;
		FOR(y,H) FOR(x,W) FOR(i,H*W+2) dist[y][x][i]=1<<20;
		priority_queue<pair<int,int>> Q;
		dist[0][0][1]=(t[0][0]!='#');
		Q.push({-dist[0][0][1],1*10000});
		
		
		while(Q.size()) {
			int cy=Q.top().second%100;
			int cx=Q.top().second/100%100;
			int pass=Q.top().second/10000;
			int cost=-Q.top().first;
			Q.pop();
			if(pass>=num) continue;
			if(dist[cy][cx][pass]!=cost) continue;
			
			FOR(i,4) {
				int dd[4]={1,0,-1,0};
				int ty=cy+dd[i];
				int tx=cx+dd[i^1];
				if(ty<0 || ty>=H || tx<0 || tx>=W) continue;
				int add=t[ty][tx]=='.';
				if(dist[ty][tx][pass+1]>cost+add) {
					dist[ty][tx][pass+1]=cost+add;
					Q.push({-dist[ty][tx][pass+1],ty+tx*100+(pass+1)*10000});
				}
			}
		}
		
		int mi=2020;
		FOR(i,num+1) mi=min(mi,dist[H-1][W-1][i]);
		if(mi>=2020) mi=-1;
		return mi;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
"#...###",
"#...#.#",
"##..#.#",
".#....#"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, minMoved(Arg0)); }
	void test_case_1() { string Arr0[] = {
"#...###",
"#...#.#",
"##..###",
".#....#"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, minMoved(Arg0)); }
	void test_case_2() { string Arr0[] = {
".#..",
"##..",
"..#.",
"..#.",
"..##",
"..##"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, minMoved(Arg0)); }
	void test_case_3() { string Arr0[] = {
".....",
".###.",
"####.",
"....."
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(3, Arg1, minMoved(Arg0)); }
	void test_case_4() { string Arr0[] = {
".#...#.###.#",
"#.#.##......",
".#.#......#.",
"..#.......#.",
"##.........."
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(4, Arg1, minMoved(Arg0)); }
	void test_case_5() { string Arr0[] = {
"###.#########..#####",
".#######.###########"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(5, Arg1, minMoved(Arg0)); }
	void test_case_6() { string Arr0[] = {
"..",
".."
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(6, Arg1, minMoved(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MovingCandies ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

