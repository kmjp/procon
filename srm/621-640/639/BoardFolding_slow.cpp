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

int LT[260][260],RB[260][260];
int LD[260][260],RD[260][260];
int TD[260][260],BD[260][260];
int sum[260][260];

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
	
	
	
	int howMany(int N, int M, vector <string> compressedPaper) {
		int y,x,x1,x2,y1,y2,i,j;
		FOR(y,N) FOR(x,M) paper[y][x]=(ton(compressedPaper[y][x/6])>>(x%6))%2;
		
		FOR(y1,N) for(y2=y1+1;y2<N;y2++) {
			LD[y1][y2]=M;
			while(LD[y1][y2]>0&&paper[y1][LD[y1][y2]-1]==paper[y2][LD[y1][y2]-1]) LD[y1][y2]--;
			RD[y1][y2]=-1;
			while(RD[y1][y2]<M-1&&paper[y1][RD[y1][y2]+1]==paper[y2][RD[y1][y2]+1]) RD[y1][y2]++;
		}
		FOR(x1,M) for(x2=x1+1;x2<M;x2++) {
			TD[x1][x2]=N;
			while(TD[x1][x2]>0&&paper[TD[x1][x2]-1][x1]==paper[TD[x1][x2]-1][x2]) TD[x1][x2]--;
			BD[x1][x2]=-1;
			while(BD[x1][x2]<N-1&&paper[BD[x1][x2]+1][x1]==paper[BD[x1][x2]+1][x2]) BD[x1][x2]++;
		}
		
		ZERO(LT);
		ZERO(RB);
		LT[0][0]=RB[N-1][M-1]=1;
		for(i=1;i<=N+M;i++) {
			FOR(y,N) {
				x=i-y;
				if(x<0 || x>=M) continue;
				int ok=1;
				for(y2=y-1;ok && LT[y][x]==0 && y2>=0;y2--) {
					if(y-y2>N-y) ok=0;
					ok &= LD[y2][y+(y-y2-1)]<=x;
					if(ok) LT[y][x] |= LT[y2][x];
				}
				ok=1;
				for(x2=x-1;ok && LT[y][x]==0 && x2>=0;x2--) {
					if(x-x2>M-x) ok=0;
					ok &= TD[x2][x+(x-x2-1)]<=y;
					if(ok) LT[y][x] |= LT[y][x2];
				}
			}
		}
		
		for(i=N+M-3;i>=0;i--) {
			FOR(y,N) {
				x=i-y;
				if(x<0 || x>=M) continue;
				int ok=1;
				for(y2=y+1;ok && RB[y][x]==0 && y2<N;y2++) {
					if(y+1<y2-y) ok=0;
					ok &= RD[y-(y2-y-1)][y2]>=x;
					if(ok) RB[y][x] |= RB[y2][x];
				}
				ok=1;
				for(x2=x+1;ok && RB[y][x]==0 && x2<M;x2++) {
					if(x+1<x2-x) ok=0;
					ok &= BD[x-(x2-x-1)][x2]>=y;
					if(ok) RB[y][x] |= RB[y][x2];
				}
			}
		}
		
		int ret=0;
		ZERO(sum);
		FOR(y,N) FOR(x,M) {
			sum[y+1][x+1]=sum[y][x+1]+sum[y+1][x]-sum[y][x]+LT[y][x];
			if(RB[y][x]) ret += sum[y+1][x+1];
		}
		
		return ret;
		
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
