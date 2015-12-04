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

ll M=1000000007;
ll pos[202020];
int dir[202020];
pair<ll,int> P[202020];
set<int> S;
int order[202020];
vector<ll> L,R;

class FindingKids {
	public:
	long long getSum(int n, int q, int A, int B, int C) {
		int i;
		S.clear();
		L.clear();
		R.clear();
		FOR(i,n) {
			A=(1LL*A*B+C)%M;
			int p=A%(M-n+i+1);
			if(S.count(p)) p=M-n+i;
			pos[i]=p;
			S.insert(p);
			P[i]={p,i};
			if(p%2==0) R.push_back(p);
			else L.push_back(p);
		}
		sort(P,P+n);
		sort(L.begin(),L.end());
		sort(R.begin(),R.end());
		FOR(i,n) order[P[i].second]=i;
		
		ll ret=0;
		while(q--) {
			A=(1LL*A*B+C)%M;
			int id = order[A%n];
			A=(1LL*A*B+C)%M;
			int tim=A;
			
			ll pos=1LL<<32;
			for(i=33;i>=0;i--) {
				int a=lower_bound(L.begin(),L.end(),pos-(1LL<<i)+tim+1)-L.begin();
				int b=lower_bound(R.begin(),R.end(),pos-(1LL<<i)-tim+1)-R.begin();
				if(a+b>=id+1) pos-=(1LL<<i);
			}
			ret += abs(pos);
		}
		return ret;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 2; int Arg2 = 0; int Arg3 = 1; int Arg4 = 1; long long Arg5 = 15LL; verify_case(0, Arg5, getSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 4; int Arg2 = 3; int Arg3 = 2; int Arg4 = 1; long long Arg5 = 43376LL; verify_case(1, Arg5, getSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 200000; int Arg1 = 200000; int Arg2 = 12345; int Arg3 = 67890; int Arg4 = 111213141; long long Arg5 = 133378408428237LL; verify_case(2, Arg5, getSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FindingKids ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
