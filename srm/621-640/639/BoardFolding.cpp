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

int same[260][260],ok[260][260];

class BoardFolding {
	public:
	int paper[500][500];
	
	int ton(char a) {
		if(a>='0' && a<='9') return a-'0';
		if(a>='a' && a<='z') return a-'a'+10;
		if(a>='A' && a<='Z') return a-'A'+36;
		if(a=='#') return 62;
		if(a=='@') return 63;
		return 0;
	}
	
	int dodo(int N,int M) {
		int y1,y2,y,x,h;
		ZERO(same);
		FOR(y1,N) for(y2=y1+1;y2<N;y2++) {
			same[y1][y2]=1;
			FOR(x,M) same[y1][y2] &= paper[y1][x]==paper[y2][x];
		}
		int num=1;
		ZERO(ok);
		ok[0][N-1]=1;
		for(h=N-1;h>=1;h--) FOR(y1,N) {
			y2=y1+h-1;
			if(y2>=N) continue;
			ok[y1][y2]=0;
			for(y=y1-1;y>=0 && ok[y1][y2]==0;y--) {
				if(y1-y>y2-y1+1) break;
				if(same[y][y1+(y1-y-1)]==0) break;
				ok[y1][y2] |= ok[y][y2];
			}
			for(y=y2+1;y<N && ok[y1][y2]==0;y++) {
				if(y-y2>y2-y1+1) break;
				if(same[y2-(y-y2-1)][y]==0) break;
				ok[y1][y2] |= ok[y1][y];
			}
			num += ok[y1][y2];
		}
		return num;
	}
	
	int howMany(int N, int M, vector <string> compressedPaper) {
		int y,x;
		FOR(y,N) FOR(x,M) paper[y][x]=(ton(compressedPaper[y][x/6])>>(x%6))%2;
		int res = dodo(N,M);
		FOR(y,N) FOR(x,M) paper[x][y]=(ton(compressedPaper[y][x/6])>>(x%6))%2;
		return res*dodo(M,N);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; string Arr2[] = {"1", "3"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(0, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 7; string Arr2[] = {"@@", "@@"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 84; verify_case(1, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 4; string Arr2[] = {"6", "9", "9", "6"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 9; verify_case(2, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 1; string Arr2[] = {"0", "2", "6", "@", "4", "A"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; verify_case(3, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 3; int Arg1 = 3; string Arr2[] = {"0", "2", "0"}
; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(4, Arg3, howMany(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BoardFolding ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
