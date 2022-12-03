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

const ll mo=1000000007;
ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

class ColorfulStrip {
	public:
	int recolor(int N, int C, int Q, int maxL, int seed) {
		ll state = seed;
		int i;
		vector<ll> F;
		ll cur=0;
		map<int,int> M;
		M[-1]=M[N]=0;
		M[0]=0;
		cur=N;
		while(Q--) {
			state = (state * 1103515245 + 12345)%(1LL<<31);
			int qlen = 1 + (state%maxL);
			state = (state * 1103515245 + 12345)%(1LL<<31);
			int L = state%(N+1-qlen);
			int R = L + qlen;
			state = (state * 1103515245 + 12345)%(1LL<<31);
			int NC = state%C;
			if(M.count(L)==0) {
				auto it=M.lower_bound(L);
				it--;
				M[L]=it->second;
			}
			if(M.count(R)==0) {
				auto it=M.lower_bound(R);
				it--;
				M[R]=it->second;
			}
			int CL=L;
			while(CL<R) {
				auto it=M.lower_bound(CL);
				int NCL=next(it)->first;
				(cur-=modpow(10,it->second)*(NCL-CL))%=mo;
				M.erase(CL);
				CL=NCL;
			}
			
			
			M[L]=NC;
			cur+=modpow(10,NC)*(R-L)%mo;
			cur=(cur%mo+mo)%mo;
			F.push_back(cur);
		}
		
		reverse(ALL(F));
		ll ret=0;
		FORR(f,F) (ret=ret*10+f)%=mo;
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 100; int Arg1 = 1; int Arg2 = 12; int Arg3 = 13; int Arg4 = 47; int Arg5 = 111033323; verify_case(0, Arg5, recolor(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 997; int Arg1 = 10; int Arg2 = 5; int Arg3 = 350; int Arg4 = 474747; int Arg5 = 530787752; verify_case(1, Arg5, recolor(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 12345; int Arg2 = 12345; int Arg3 = 2; int Arg4 = 12345; int Arg5 = 473696403; verify_case(2, Arg5, recolor(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ColorfulStrip ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

