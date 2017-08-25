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

int N;
int mat[101][101];
ll pat[101][101];
vector<int> CE[101];
ll mo=1000000007;
ll dp[1<<10][101];

class RainbowGraph {
	public:
	int countWays(vector <int> color, vector <int> a, vector <int> b) {
		int i,j,x,y;
		
		N=color.size();
		ZERO(mat);
		ZERO(pat);
		ZERO(dp);
		FOR(i,10) CE[i].clear();
		FOR(i,N) CE[color[i]].push_back(i), mat[i][i]=1;
		
		int al=0;
		FOR(i,10) if(CE[i].empty()) al |= 1<<i;
		
		FOR(i,a.size()) mat[a[i]][b[i]]=mat[b[i]][a[i]]=1;
		FOR(i,10) if(CE[i].size()) {
			do {
				FOR(j,CE[i].size()-1) if(mat[CE[i][j]][CE[i][j+1]]==0) break;
				if(j==CE[i].size()-1) {
					pat[CE[i][0]][CE[i].back()]++;
					dp[al | (1<<i)][CE[i].back()]++;
				}
			} while(next_permutation(ALL(CE[i])));
		}
		for(int mask=1;mask<1<<10;mask++) {
			for(int nc=0;nc<10;nc++) if((mask&(1<<nc))==0) {
				FOR(i,N) if(dp[mask][i]) {
					FORR(a,CE[nc]) if(mat[i][a]) FORR(b,CE[nc]) if(pat[a][b]) (dp[mask|(1<<nc)][b] += dp[mask][i]*pat[a][b])%=mo;
				}
			}
		}
		
		ll ret=0;
		FOR(i,N) ret+=dp[(1<<10)-1][i];
		return ret%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0,0,1,1,1,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,2,3,4,5,6,7,8,0,3,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,0,4,5,3,7,8,6,3,6,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(0, Arg3, countWays(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,0,0,1,1,1,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,2,3,4,5,6,7,8,0,4,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,0,4,5,3,7,8,6,3,7,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 24; verify_case(1, Arg3, countWays(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0,3,9,8,6,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,0,0,0,1,1,1,1,2,2,2,3,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4,5,2,3,4,5,3,4,5,4,5,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 720; verify_case(2, Arg3, countWays(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0,0,0,0,3,3,3,6,6,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9,9,9,9,9,9,9,9,9,7,7,7,7,7,7,7,4,4,4,4,0,1,2,4,5,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,1,2,3,4,5,6,7,8,0,1,2,3,4,5,6,0,1,2,3,1,2,3,5,6,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 64; verify_case(3, Arg3, countWays(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {3,1,4,1,5,9,2,6,5,3,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(4, Arg3, countWays(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {2, 4, 3, 0, 2, 3, 3, 3, 4, 2, 1, 2, 0, 0, 4, 1, 1, 0, 4, 4, 1, 0, 3, 2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5, 7, 23, 20, 10, 9, 23, 7, 7, 17, 0, 20, 1, 24, 7, 5, 11, 13, 14, 9, 0, 13, 4, 9, 5,
24, 22, 24, 14, 12, 7, 4, 6, 19, 13, 5, 6, 10, 0, 2, 6, 20, 22, 2, 10, 19, 2, 24, 21,
20, 21, 2, 23, 24, 9, 19, 19, 21, 22, 2, 7, 14, 13, 12, 2, 11, 19, 12, 0, 8, 8, 1,
18, 20, 10, 1, 13, 21, 14, 1, 18, 21, 13, 15, 14, 15, 7, 6, 21, 10, 6, 24, 21, 4, 24,
3, 2, 18, 1, 24, 6, 20, 8, 16, 0, 12, 5, 11, 4, 13, 3, 16, 19, 15, 24, 24, 16, 20, 13,
18, 5, 4, 6, 23, 8, 6, 18, 15, 19, 3, 16, 17, 18, 10, 14, 14, 23, 6, 13, 7, 13, 18, 10,
19, 22, 18, 23, 5, 16, 17, 23, 4, 14, 24, 5, 20, 11, 3, 17, 23, 12, 6, 22, 8, 4, 17, 16,
8, 17, 17, 1, 4, 6, 7, 17, 17, 21, 23, 0, 15, 21, 16, 12, 20, 19, 23, 7, 21, 18, 5, 24,
24, 8, 6, 5, 9, 21, 15, 8, 11, 10, 19, 5, 24, 19, 10, 11, 0, 23, 12, 15, 18, 20, 10, 15,
13, 3, 18, 6, 22, 0, 4, 24, 19, 16, 0, 17, 7, 4, 0, 9, 4, 10, 0, 23, 16, 17, 8, 5, 12,
22, 11, 11, 5, 13, 5, 4, 20, 17, 20, 0, 10, 4, 18, 3, 3, 6, 21, 9, 7, 18, 1, 14, 5, 20,
10, 12, 20, 9, 15, 18, 5, 12, 11, 11, 20, 11, 15, 6, 2, 6, 19, 13, 15, 15, 21, 22, 9, 19,
16, 8, 9, 15, 8, 21, 22, 19, 18, 9, 2}
; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {21, 1, 11, 19, 24, 1, 7, 17, 20, 20, 8, 6, 12, 21, 13, 2, 13, 15, 22, 11, 17, 19, 0,
5, 14, 3, 7, 11, 2, 15, 18, 5, 16, 12, 3, 8, 8, 3, 2, 24, 14, 23, 6, 23, 2, 1, 4, 6, 13,
9, 17, 6, 12, 20, 23, 16, 9, 10, 21, 11, 14, 3, 1, 2, 9, 21, 21, 7, 19, 4, 13, 10, 6,
15, 19, 0, 9, 23, 10, 6, 1, 2, 2, 18, 20, 16, 19, 10, 4, 9, 19, 14, 7, 10, 9, 16, 1, 16,
8, 16, 4, 3, 9, 11, 23, 5, 19, 4, 14, 20, 2, 7, 22, 5, 4, 7, 5, 1, 23, 4, 23, 23, 21, 1,
19, 15, 8, 22, 11, 1, 14, 13, 17, 20, 1, 8, 18, 7, 22, 3, 14, 0, 12, 14, 10, 5, 3, 1, 13,
8, 15, 13, 18, 1,13, 22, 8, 8, 1, 10, 22, 12, 1, 24, 20, 10, 17, 22, 23, 22, 16, 3, 23, 
11, 3, 14, 18, 8, 14, 2, 0, 9, 3, 2, 23, 22, 9, 8, 9, 11, 0, 15, 15, 5, 24, 4, 20, 9, 12,
6, 16, 18, 22, 12, 15, 15, 18, 9, 24, 18, 4, 22, 12, 13, 1, 12, 0, 3, 9, 0, 7, 1, 17, 17,
23, 16, 12, 15, 12, 6, 22, 17, 7, 11, 14, 20, 2, 2, 17, 16, 2, 22, 1, 0, 0, 3, 19, 8, 11,
11, 12, 8, 22, 24, 22, 21, 3, 16, 12, 4, 13, 21, 12, 10, 0, 0, 21, 5, 3, 14, 10, 7, 11, 14,
10, 18, 3, 0, 17, 16, 13, 24, 24, 3, 17, 15, 16, 21, 3, 4, 16, 14, 11, 7, 14, 24, 2, 2, 17, 7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 983979105; verify_case(5, Arg3, countWays(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RainbowGraph ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

