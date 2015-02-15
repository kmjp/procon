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

class ConnectingCars {
	public:
	pair<ll,ll> P[101];
	ll dist[101][101];
	int N;
	long long minimizeCost(vector <int> positions, vector <int> lengths) {
		int i,j,x,y;
		N=positions.size();
		FOR(i,N) P[i]=make_pair(positions[i],lengths[i]);
		sort(P,P+N);
		FOR(y,N) FOR(x,y) {
			ll tot=P[y].first-P[x].first;
			for(i=x;i<y;i++) tot-=P[i].second;
			dist[x][y]=dist[y][x]=tot;
		}
		
		ll mi=1LL<<60;
		FOR(i,N) {
			ll tot=0;
			FOR(j,N) tot+=dist[i][j];
			mi=min(mi,tot);
		}
		
		return mi;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 3, 10, 20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 2, 5, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 15LL; verify_case(0, Arg2, minimizeCost(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {100, 50, 1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 96LL; verify_case(1, Arg2, minimizeCost(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {4, 10, 100, 13, 80}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5, 3, 42, 40, 9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 66LL; verify_case(2, Arg2, minimizeCost(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {5606451, 63581020, 81615191, 190991272, 352848147, 413795385, 468408016, 615921162, 760622952, 791438427}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {42643329, 9909484, 58137134, 99547272, 39849232, 15146704, 144630245, 604149, 15591965, 107856540}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1009957100LL; verify_case(3, Arg2, minimizeCost(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ConnectingCars ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
