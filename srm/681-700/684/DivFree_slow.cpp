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

ll dp[2][50505];
ll* from=dp[0];
ll* to=dp[1];

int mapto[50505];
int rev[50505];
int num[50505];
vector<pair<int,int>> del[505];
ll mo=1000000007;

class DivFree {
	public:
	int N,K;
	int dfcount(int n, int k) {
		N=n;K=k;
		int i,j,x;

		ZERO(dp);
		for(j=1;j<=k;j++) {
			to[j]=k;
			for(x=j*2;x<=k;x+=j) to[j]--;
		}
		int md=0;
		ZERO(num);
		mapto[0]=0;
		for(j=1;j<=k;j++) {
			mapto[j]=mapto[j-1]+(to[j]!=to[j-1]);
			rev[mapto[j]]=j;
			md=max(md,mapto[j]);
			num[mapto[j]]++;
		}
		
		for(i=2;i<=md;i++) {
			del[i].clear();
			int x=rev[i];
			for(j=x*2;j<=k;j+=x) {
				if(del[i].size() && del[i].back().first==mapto[j]) {
					del[i].back().second++;
				}
				else {
					del[i].push_back({mapto[j],1});
				}
			}
		}
		
		
		ZERO(dp);
		for(j=1;j<=md;j++) from[j]++;
		N--;
		while(N--) {
			ll tot=0;
			for(i=1;i<=md;i++) (tot+=from[i]*num[i])%=mo;
			to[1]=1;
			for(i=2;i<=md;i++) {
				to[i]=tot;
				FORR(r,del[i]) to[i]-=from[r.first]*r.second;
				to[i]=to[i]%mo;
				if(to[i]<0) to[i]+=mo;
			}
			swap(from,to);
		}
		
		ll ret=0;
		for(i=1;i<=md;i++) (ret+=from[i]*num[i])%=mo;
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 3; verify_case(0, Arg2, dfcount(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 4; verify_case(1, Arg2, dfcount(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 15; verify_case(2, Arg2, dfcount(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 107; int Arg2 = 107; verify_case(3, Arg2, dfcount(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 6; int Arg2 = 2292; verify_case(4, Arg2, dfcount(Arg0, Arg1)); }
//	void test_case_5() { int Arg0 = 42; int Arg1 = 23; int Arg2 = 301026516; verify_case(5, Arg2, dfcount(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 50000; int Arg1 = 50000; int Arg2 = 301026516; verify_case(5, Arg2, dfcount(Arg0, Arg1)); }


// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DivFree ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
