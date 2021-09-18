#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

ll mo=1000000007;

ll from[105][105];
ll to[105][105];


class RaftingOnDunajec {
	public:
	int count(int S, int C) {
		int i,j;
		ZERO(from);
		from[0][0]=1;
		int L,R,x;
		FOR(L,S) {
			for(R=L+1;R<=S;R++) {
				memmove(to,from,sizeof(from));
				for(int num=0;num<=99;num++) {
					for(x=L;x<=S;x++) {
						(to[max(R,x)][num+1]+=from[x][num])%=mo;
					}
				}
				swap(from,to);
			}
		}
		
		ll f[101]={};
		ll t[101]={};
		f[0]=1;
		ll fact[101]={};
		fact[0]=1;
		for(i=0;i<C;i++) {
			fact[i+1]=fact[i]*(i+1)%mo;
			ZERO(t);
			for(j=0;j<C;j++) {
				(t[j]+=f[j]*j)%=mo;
				(t[j+1]+=f[j])%=mo;
			}
			swap(f,t);
		}
		
		ll ret=0;
		for(i=1;i<=C;i++) {
			ret+=from[S][i]*f[i]%mo*fact[i]%mo;
		}
		return ret%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 7; int Arg1 = 1; int Arg2 = 1; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 7; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 7; int Arg2 = 1; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 20; int Arg2 = 486784378; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RaftingOnDunajec ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

