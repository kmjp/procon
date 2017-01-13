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

class MovingTokens {
	public:
	
	int move(int n, int m, vector <int> moves) {
		int mat[50][50];
		int ok[50][50]={};
		int did[50][50]={};
		int yes[50]={};
		
		int y,x,i,j;
		FOR(y,n) FOR(x,m) mat[y][x]=moves[x*n+y];
		vector<int> Q;
		FOR(i,n) ok[i][i]=did[i][i]=1, Q.push_back(i*100+i);
		
		while(Q.size()) {
			int a=Q.back()/100;
			int b=Q.back()%100;
			Q.pop_back();
			
			FOR(i,m) {
				FOR(x,n) if(mat[x][i]==a) {
					FOR(y,n) if(mat[y][i]==b && did[x][y]==0) {
						ok[x][y]=did[x][y]=1;
						ok[y][x]=did[y][x]=1;
						Q.push_back(x*100+y);
					}
				}
			}
		}
		
		int cnt=0;
		FOR(i,n) if(yes[i]==0) {
			yes[i]=1;
			cnt++;
			FOR(j,n) if(i!=j && yes[j]==0 && ok[i][j]) {
				yes[j]=1;
				FOR(x,n) if(ok[i][x]==0 || ok[j][x]==0) ok[i][x]=ok[x][i]=0;
			}
		}
		
		return cnt;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
void test_case_0() { int Arg0 = 4; int Arg1 = 2; int Arr2[] = {1,2,0,1,1,2,0,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(0, Arg3, move(Arg0, Arg1, Arg2)); }
//	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arr2[] = {0,1,
//0,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(0, Arg3, move(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arr2[] = {0,0,
1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(1, Arg3, move(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 1; int Arr2[] = {0,1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(2, Arg3, move(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 5; int Arr2[] = {0,0,
 0,0,
 0,0,
 1,1,
 1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(3, Arg3, move(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 3; int Arg1 = 2; int Arr2[] = {0,2,2,
 1,1,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(4, Arg3, move(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MovingTokens ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

