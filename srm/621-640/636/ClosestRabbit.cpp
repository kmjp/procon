#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------



double comb(int P_,int Q_) {
	static const int N_=1020;
	static double C_[N_][N_];
	
	if(C_[0][0]==0) {
		int i,j;
		FOR(i,N_) C_[i][0]=C_[i][i]=1;
		for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j]);
	}
	if(P_<0 || P_>N_ || Q_<0 || Q_>P_) return 0;
	return C_[P_][Q_];
}

ll dist[21][21][21][21];

class ClosestRabbit {
	public:
	
	double getExpected(vector <string> B, int r) {
		int H,W,N;
		int y,x,y2,x2,y3,x3;
		H=board.size();
		W=board[0].size();
		N=0;
		
		FOR(y,21) FOR(x,21) FOR(y2,21) FOR(x2,21)
			dist[y][x][y2][x2]=((x2-x)*(x2-x)+(y2-y)*(y2-y))*1000LL+y2*30+x2;
		FOR(y,21) FOR(x,21) dist[y][x][y][x]=0;
		FOR(y,H) FOR(x,W) N+=board[y][x]=='.';
		
		double ret=0;
		FOR(y,H) FOR(x,W) if(B[y][x]=='.') {
			FOR(y2,H) FOR(x2,W) if((y2>y || (y2==y&&x2>x)) && B[y2][x2]=='.') {
				int ok=0;
				FOR(y3,H) FOR(x3,W) if(B[y3][x3]=='.' && dist[y][x][y3][x3] && dist[y2][x2][y3][x3]) {
					if(dist[y][x][y3][x3]<dist[y][x][y2][x2] || dist[y2][x2][y3][x3]<dist[y2][x2][y][x]) ok++;
				}
				if(N-2-ok<r-2) continue;
				ret+=comb(N-2-ok,r-2)/comb(N-2,r-2);
			}
		}
		return ret*r*(r-1)/(N*(N-1));
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".#.#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; double Arg2 = 1.0; verify_case(0, Arg2, getExpected(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"..###.",
 ".###.#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; double Arg2 = 1.6; verify_case(1, Arg2, getExpected(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"..###.",
 ".###.#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; double Arg2 = 2.0; verify_case(2, Arg2, getExpected(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {".....",
 "#...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; double Arg2 = 1.253968253968254; verify_case(3, Arg2, getExpected(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {".#####.#####..#....#",
 "#......#....#.##..##",
 ".####..#####..#.##.#",
 ".....#.#...#..#....#",
 "#####..#....#.#....#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; double Arg2 = 5.77311527122319; verify_case(4, Arg2, getExpected(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ClosestRabbit ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
