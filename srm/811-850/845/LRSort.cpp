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

int T[555555];
const ll mo=1000000007;
template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

class LRSort {
	public:
	int simulate(int N, vector <int> Aprefix, int M, int seed, int B) {
		ll L=Aprefix.size();
		vector<ll> A;
		int i;
		FOR(i,L) A.push_back(Aprefix[i]);

		ll state = seed;
		for(i=L;i<N;i++) {
		    state = (state * 1103515245 + 12345)%(1LL<<31);
		    A.push_back(state%M);
		}

		ZERO(bt.bit);
		set<pair<int,int>> S;
		FOR(i,N) {
			bt.add(i,1);
			S.insert({A[i],i});
		}
		
		ll ret=0;
		ll p10=1;
		FOR(i,N-1) {
		    state = (state * 1103515245 + 12345)%(1LL<<31);
		    ll tmp=(state/(1<<20))%100;
		    if(tmp<B) {
				auto p=*S.rbegin();
				S.erase(p);
				int num=bt(N)-bt(p.second);
				ret+=num*p10%mo;
				bt.add(p.second,-1);
			}
			else {
				auto p=*S.begin();
				S.erase(p);
				int num=bt(p.second-1);
				ret+=num*p10%mo;
				bt.add(p.second,-1);
			}
			p10=p10*10%mo;
		}
		return ret%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arr1[] = {70, 60, 50, 40, 30, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; int Arg3 = 47; int Arg4 = 74; int Arg5 = 12345; verify_case(0, Arg5, simulate(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 10; int Arr1[] = {4, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 47; int Arg3 = 47474747; int Arg4 = 74; int Arg5 = 102023400; verify_case(1, Arg5, simulate(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 47000; int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 47; int Arg4 = 47; int Arg5 = 0; verify_case(2, Arg5, simulate(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 15; int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 147; int Arg3 = 777444; int Arg4 = 42; int Arg5 = 466633400; verify_case(3, Arg5, simulate(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  LRSort ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

