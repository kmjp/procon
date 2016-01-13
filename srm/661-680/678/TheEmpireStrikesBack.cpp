#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

vector<pair<ll,ll> > V;
pair<ll,ll> P[101010];
ll mo=1000000007;

class TheEmpireStrikesBack {
	public:
	int ok(int T,int M) {
		int x,y;
		x=0;
		for(y=1;y<V.size();y++) if(V[y].second+T<V[x].second) {
			int tar=V[y-1].first+T;
			while(y<V.size() && V[y].first<=tar) y++;
			if(y==V.size()) return 1;
			if(--M<=0) return 0;
			x=y--;
		}
		return 1;
	}
	
	int find(int AX, int BX, int CX, int AY, int BY, int CY, int N, int M) {
		int i;
		P[0].first=AX;
		P[0].second=AY;
		for(i=1;i<N;i++) P[i].first=(P[i-1].first*BX+CX)%mo, P[i].second=(P[i-1].second*BY+CY)%mo;
		sort(P,P+N);
		
		V.clear();
		FOR(i,N) {
			while(V.size() && V.back().first<=P[i].first && V.back().second<=P[i].second) V.pop_back();
			V.push_back(P[i]);
		}
		int v=(1<<30)-1;
		for(i=29;i>=0;i--) if(ok(v-(1<<i),M)) v-=1<<i;
		return v;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; int Arg3 = 2; int Arg4 = 2; int Arg5 = 2; int Arg6 = 2; int Arg7 = 1; int Arg8 = 0; verify_case(0, Arg8, find(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; int Arg3 = 2; int Arg4 = 4; int Arg5 = 1000000000; int Arg6 = 2; int Arg7 = 1; int Arg8 = 1; verify_case(1, Arg8, find(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 3; int Arg2 = 8; int Arg3 = 10000; int Arg4 = 10; int Arg5 = 999910000; int Arg6 = 3; int Arg7 = 1; int Arg8 = 30; verify_case(2, Arg8, find(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_3() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; int Arg6 = 100000; int Arg7 = 1000; int Arg8 = 0; verify_case(3, Arg8, find(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_4() { int Arg0 = 10; int Arg1 = 20; int Arg2 = 30; int Arg3 = 40; int Arg4 = 50; int Arg5 = 60; int Arg6 = 100000; int Arg7 = 10; int Arg8 = 15720; verify_case(4, Arg8, find(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TheEmpireStrikesBack ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
