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

double dp[51][21][21][21];

class Conquest {
	public:
	
	vector<pair<pair<int,int>,double>> prob(int x,int y) {
		vector<pair<pair<int,int>,double>> R;
		if(x>3&&y>1) {
			R.push_back({{x-2,y-0},2275.0/7776});
			R.push_back({{x-1,y-1},2611.0/7776});
			R.push_back({{x-0,y-2},2890.0/7776});
		}
		if(x>3&&y==1) {
			R.push_back({{x-1,y-0},441.0/1296});
			R.push_back({{x-0,y-1},855.0/1296});
		}
		if(x==3&&y>1) {
			R.push_back({{x-2,y-0},581.0/1296});
			R.push_back({{x-1,y-1},420.0/1296});
			R.push_back({{x-0,y-2},295.0/1296});
		}
		if(x==3&&y==1) {
			R.push_back({{x-1,y-0},91.0/216});
			R.push_back({{x-0,y-1},125.0/216});
		}
		if(x==2&&y>1) {
			R.push_back({{x-1,y-0},161.0/216});
			R.push_back({{x-0,y-1},55.0/216});
		}
		if(x==2&&y==1) {
			R.push_back({{x-1,y-0},21.0/36});
			R.push_back({{x-0,y-1},15.0/36});
		}
		return R;
	}
	
	double dfs(int A,int B,int C,int D) {
		if(B+C+D==0) return 1;
		if(A<2) return 0;
		if(dp[A][B][C][D]>=0) return dp[A][B][C][D];
		double ret=0;
		if(B) {
			double tmp=0;
			auto R=prob(A,B);
			FORR(r,R) tmp+=r.second*dfs(r.first.first-(r.first.second==0),r.first.second,C,D);
			ret=max(ret,tmp);
		}
		if(C) {
			double tmp=0;
			auto R=prob(A,C);
			FORR(r,R) tmp+=r.second*dfs(r.first.first-(r.first.second==0),B,r.first.second,D);
			ret=max(ret,tmp);
		}
		if(D) {
			double tmp=0;
			auto R=prob(A,D);
			FORR(r,R) tmp+=r.second*dfs(r.first.first-(r.first.second==0),B,C,r.first.second);
			ret=max(ret,tmp);
		}
		return dp[A][B][C][D]=ret;
	}
	
	
	
	double bestChance(int armies, vector <int> opponent) {
		
		int x,y,z,i;
		FOR(i,51) FOR(x,21) FOR(y,21) FOR(z,21) dp[i][x][y][z]=-1;
		
		return dfs(armies,opponent[0],opponent[1],opponent[2]);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arr1[] = {1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.15907653892318244; verify_case(0, Arg2, bestChance(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 10; int Arr1[] = {2, 2, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.13552235780217273; verify_case(1, Arg2, bestChance(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 30; int Arr1[] = {5, 5, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.9857787020110442; verify_case(2, Arg2, bestChance(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Conquest ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

