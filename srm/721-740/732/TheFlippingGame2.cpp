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

class TheFlippingGame2 {
	public:
	int hoge(int H,int W,vector<string> S) {
		int mi=10101;
		int sy,sx,x,y;
		FOR(sy,H) FOR(sx,W) {
			int D[20][20];
			FOR(y,H) FOR(x,W) D[y][x]=4040;
			priority_queue<pair<int,int>> Q;
			D[sy][sx]=0;
			Q.push({0,sy*100+sx});
			int ma=0;
			while(Q.size()) {
				int co=-Q.top().first;
				int cy=Q.top().second/100;
				int cx=Q.top().second%100;
				Q.pop();
				if(co!=D[cy][cx]) continue;
				ma=max(ma,co);
				
				int d[4]={1,0,-1,0},i;
				FOR(i,4) {
					int ty=cy+d[i];
					int tx=cx+d[i^1];
					if(ty<0||ty>=H||tx<0||tx>=W) continue;
					if(D[ty][tx]>co+(S[cy][cx]!=S[ty][tx])) {
						D[ty][tx]=co+(S[cy][cx]!=S[ty][tx]);
						Q.push({-D[ty][tx],ty*100+tx});
					}
				}
			}
			mi=min(mi,ma);
		}
		
		
		return mi+1;
	}
	
	int MinimumMoves(int n, int m, vector <string> x) {
		string S="bw";
		int mi=101010;
		FORR(c,S) {
			vector<string> y=x;
			FORR(s2,y) FORR(c2,s2) if(c2=='e') c2=c;
			mi=min(mi,hoge(n,m,y));
		}
		return mi;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 3; string Arr2[] = {"bwe","web","ebw"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(0, Arg3, MinimumMoves(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; string Arr2[] = {"bwe","wbw","ewb"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(1, Arg3, MinimumMoves(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 4; string Arr2[] = {"beww","beww","beww","wewe"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(2, Arg3, MinimumMoves(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 20; int Arg1 = 20; string Arr2[] = {"bwbwbwbwbwbwbwbwbwbw","wbwbwbwbwbwbwbwbwbwb","bwbwbwbwbwbwbwbwbwbw","wbwbwbwbwbwbwbwbwbwb","bwbwbwbwbwbwbwbwbwbw","wbwbwbwbwbwbwbwbwbwb","bwbwbwbwewbwbwbwbwbw","wbwbwbwbebwbwbwbwbwb","bwbwbwbwewbwbwbwbwbw","wbwbwbwbebwbwbwbwbwb","bwbwbwbwewbwbwbwbwbw","wbwbwbwbebwbwbwbwbwb","bwbwbwbwewbwbwbwbwbw","wbwbwbwbebwbwbwbwbwb","bwbwbwbwewbwbwbwbwbw","wbwbwbwbwbwbwbwbwbwb","bwbwbwbwbwbwbwbwbwbw","wbwbwbwbwbwbwbwbwbwb","bwbwbwbwbwbwbwbwbwbw","wbwbwbwbwbwbwbwbwbwe"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 16; verify_case(3, Arg3, MinimumMoves(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 2; int Arg1 = 8; string Arr2[] = {"ewewbbbb","bwebewww"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(4, Arg3, MinimumMoves(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TheFlippingGame2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

