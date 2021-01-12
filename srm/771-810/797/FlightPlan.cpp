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

int Z[50][50];
ll dp[50][50][2500];

class FlightPlan {
	public:
	long long fly(int R, int C, vector <int> H, int cup, int cdn, int clr) {
		vector<ll> Y;
		FORR(h,H) Y.push_back(h);
		sort(ALL(Y));
		Y.erase(unique(ALL(Y)),Y.end());
		int y,x,z;
		FOR(y,R) FOR(x,C) {
			FOR(z,R*C) dp[y][x][z]=1LL<<60;
			Z[y][x]=lower_bound(ALL(Y),H[y*C+x])-Y.begin();
		}
		dp[0][0][Z[0][0]]=0;
		priority_queue<pair<ll,int>> Q;
		Q.push({0,Z[0][0]*2500});
		while(Q.size()) {
			ll co=-Q.top().first;
			int cy=Q.top().second%2500/50;
			int cx=Q.top().second%2500%50;
			int ct=Q.top().second/2500;
			Q.pop();
			if(dp[cy][cx][ct]!=co) continue;
			int dy[]={1,-1,0,0,0,0};
			int dx[]={0,0,1,-1,0,0};
			int dt[]={0,0,0,0,1,-1};
			int i;
			FOR(i,6) {
				int ty=cy+dy[i];
				int tx=cx+dx[i];
				int tt=ct+dt[i];
				if(ty<0||ty>=R||tx<0||tx>=C) continue;
				if(tt<Z[ty][tx]||tt>=Y.size()) continue;
				ll nco=co;
				if(dt[i]==-1) nco+=cdn*(Y[ct]-Y[tt]);
				if(dt[i]==1) nco+=cup*(Y[tt]-Y[ct]);
				if(dt[i]==0) nco+=clr;
				if(dp[ty][tx][tt]>nco) {
					dp[ty][tx][tt]=nco;
					Q.push({-nco,tt*2500+ty*50+tx});
				}
			}
			
		}
		return dp[R-1][C-1][Z[R-1][C-1]];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 5; int Arr2[] = {10, 8, 6, 8, 10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 40; int Arg4 = 10; int Arg5 = 20; long long Arg6 = 80LL; verify_case(0, Arg6, fly(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 6; int Arg1 = 1; int Arr2[] = {10, 8, 16, 18, 8, 12}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 40; int Arg4 = 10; int Arg5 = 20; long long Arg6 = 480LL; verify_case(1, Arg6, fly(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 5; int Arr2[] = {  100, 1000,  100,  100,  100,
    97, 9999, 9999, 9999,  100,
    93, 9999,    0, 9999,  100,
    99, 9999,   83,   65,  100,
    98,   93,   90, 9999,   95}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1000; int Arg4 = 1000; int Arg5 = 1; long long Arg6 = 5010LL; verify_case(2, Arg6, fly(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 5; int Arr2[] = {  100, 1000,  100,  100,  100,
    97, 9999, 9999, 9999,  100,
    93, 9999,    0, 9999,  100,
    99, 9999,   83,   65,  100,
    98,   93,   90, 9999,   95}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; int Arg4 = 1; int Arg5 = 1000; long long Arg6 = 9805LL; verify_case(3, Arg6, fly(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 1; int Arr2[] = {47}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 123; int Arg4 = 234; int Arg5 = 345; long long Arg6 = 0LL; verify_case(4, Arg6, fly(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FlightPlan ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

