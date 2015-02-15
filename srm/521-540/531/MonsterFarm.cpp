#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

//-------------------------------------------------------

vector<int> split_int(const string &str, char delim){
	vector<int> res;
	size_t current = 0, found;
	while((found = str.find_first_of(delim, current)) != string::npos){
		string s = string(str, current, found - current);
		res.push_back(atoi(s.c_str()));
		current = found + 1;
	}
	string s = string(str, current, str.size() - current);
	res.push_back(atoi(s.c_str()));
	return res;
}

ll mo=1000000007;

class MonsterFarm {
	public:
	int gen[51][51], mat[51][51], tgen[51];
	int N;
	int vis[51];
	
	int numMonsters(vector <string> transforms) {
		int i,x,y;
		
		N=transforms.size();
		ZERO(gen);
		FOR(x,N) FOR(y,N) mat[x][y]=1;
		
		FOR(i,N) {
			vector<int> V=split_int(transforms[i],' ');
			ITR(it,V) gen[i][*it-1]++, mat[i][*it-1]=0;
			tgen[i]=V.size();
		}
		FOR(i,N) FOR(x,N) FOR(y,N) mat[x][y]=min(mat[x][y],mat[x][i]+mat[i][y]);
		
		FOR(x,N) if(mat[x][x]==0 && mat[0][x]==0) {
			FOR(y,N) if(mat[x][y]==0 && mat[y][x]==0 && tgen[y]>1) return -1;
		}
		
		ll dp[51];
		ZERO(dp);
		dp[0]=1;
		FOR(i,10000) {
			FOR(x,N) {
				ll hoge=dp[x];
				dp[x]=0;
				FOR(y,N) dp[y]=(dp[y]+hoge*gen[x][y])%mo;
			}
		}
		ll ret=0;
		FOR(x,N) ret+=dp[x];
		return ret%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, numMonsters(Arg0)); }
	void test_case_1() { string Arr0[] = {"1 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, numMonsters(Arg0)); }
	void test_case_2() { string Arr0[] = {"2", "3", "1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, numMonsters(Arg0)); }
	void test_case_3() { string Arr0[] = {"1", "3 4", "2", "2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, numMonsters(Arg0)); }
	void test_case_4() { string Arr0[] = {"2 2", "3", "4 4 4", "5", "6", "7 7 7 7", "7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; verify_case(4, Arg1, numMonsters(Arg0)); }
	void test_case_52() { string Arr0[] = {"2 3","5 7","2 4","5","6","4","7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(5, Arg1, numMonsters(Arg0)); }
	void test_case_5() { string Arr0[] = {"2", "4 5", "3", "2 3", "5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(5, Arg1, numMonsters(Arg0)); }
// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MonsterFarm ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
