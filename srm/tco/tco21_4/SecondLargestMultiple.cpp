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


class SecondLargestMultiple {
	public:
	unordered_map<ll,pair<ll,ll>> memo[1<<12];
	ll ret[3]={};
	ll N;
	int B;
	ll p6;
	void add(ll v) {
		ret[0]=v;
		sort(ret,ret+3);
	}

	void small(ll N,int B) {
		ll cand=1;
		int i;
		FOR(i,B) cand*=B;
		add(0);
		for(ll a=N;a<cand;a+=N) {
			int mask=0;
			ll b=a;
			while(b) {
				int x=b%B;
				if(mask&(1<<x)) break;
				mask|=1<<x;
				b/=B;
			}
			if(b==0) add(a);
		}
	}
	
	void dfs1(ll v,int mask) {
		ll mo=v%N;
		if(__builtin_popcount(mask)==6) {
			if(memo[mask].count(mo)==0) {
				memo[mask][mo]={-1,v};
			}
			else {
				ll a[3]={memo[mask][mo].first,memo[mask][mo].second,v};
				sort(a,a+3);
				memo[mask][mo]={a[1],a[2]};
			}
			return;
		}
		if(mo==0) {
			int num=__builtin_popcount(mask);
			ll w=v;
			while(w) num--, w/=B;
			if(num==0) add(v);
		}
		int i;
		FOR(i,B) if((mask&(1<<i))==0) dfs1(v*B+i,mask|(1<<i));
		
		
	}
	void dfs2(ll v,int mask) {
		if(mask==1) return;
		if(v) {
			ll mo=(N-v*p6%N)%N;
			int rm=((1<<B)-1)^mask;
			for(int sm=rm;sm>=0;sm--) {
				sm&=rm;
				if(__builtin_popcount(sm)==6&&memo[sm].count(mo)) {
					auto a=memo[sm][mo];
					if(a.first!=-1) add(a.first+v*p6);
					if(a.second!=-1) add(a.second+v*p6);
				}
			}
			
		}
		
		
		if(__builtin_popcount(mask)==B-6) return;
		int i;
		FOR(i,B) if((mask&(1<<i))==0) dfs2(v*B+i,mask|(1<<i));
	}
	

	void large(ll N,int B) {
		int i,mask;
		FOR(mask,1<<B) memo[mask].clear();
		this->N=N;
		this->B=B;
		p6=1;
		FOR(i,6) p6*=B;
		dfs1(0,0);
		dfs2(0,0);
	}
	
	long long find(long long N, int B) {
		
		ret[0]=ret[1]=ret[2]=-1;
		if(B<=7) {
			small(N,B);
		}
		else {
			large(N,B);
		}
		return ret[1];
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1LL; int Arg1 = 10; long long Arg2 = 9876543201LL; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 12345LL; int Arg1 = 10; long long Arg2 = 9876012345LL; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 12345LL; int Arg1 = 3; long long Arg2 = -1LL; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 2LL; int Arg1 = 2; long long Arg2 = 0LL; verify_case(3, Arg2, find(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 17LL; int Arg1 = 4; long long Arg2 = -1LL; verify_case(4, Arg2, find(Arg0, Arg1)); }
	void test_case_5() { long long Arg0 = 282458553905LL; int Arg1 = 11; long long Arg2 = 0LL; verify_case(5, Arg2, find(Arg0, Arg1)); }
	void test_case_6_() { long long Arg0 = 25LL; int Arg1 = 7; long long Arg2 = 800025LL; verify_case(6, Arg2, find(Arg0, Arg1)); }
	void test_case_6() { long long Arg0 = 6545844607; int Arg1 = 12; long long Arg2 = -1; verify_case(6, Arg2, find(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SecondLargestMultiple ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

