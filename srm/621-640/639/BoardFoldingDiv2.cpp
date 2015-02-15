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

class BoardFoldingDiv2 {
	public:
	int paper[500][500];
	
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
	
	int howMany(vector <string> papers) {
		int y,x;
		int N=papers.size(), M=papers[0].size();
		FOR(y,N) FOR(x,M) paper[y][x]=papers[y][x]-'0';
		int res = dodo(N,M);
		FOR(y,N) FOR(x,M) paper[x][y]=papers[y][x]-'0';
		return res*dodo(M,N);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"10",
 "11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, howMany(Arg0)); }
	void test_case_1() { string Arr0[] = {"1111111",
 "1111111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 84; verify_case(1, Arg1, howMany(Arg0)); }
	void test_case_2() { string Arr0[] = {"0110",
 "1001",
 "1001",
 "0110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(2, Arg1, howMany(Arg0)); }
	void test_case_3() { string Arr0[] = {"0",
 "0",
 "0",
 "1",
 "0",
 "0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(3, Arg1, howMany(Arg0)); }
	void test_case_4() { string Arr0[] = {"000",
 "010",
 "000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, howMany(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BoardFoldingDiv2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
