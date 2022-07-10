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

int pre[2020],nex[2020];


class FroggerAndNets {
	public:
	int jump(string stones, int C, int minW, int seed) {
		ll state=seed;
		int N=stones.size();
		int maxW=N-1;
		int i;
		
		int p=-1;
		FOR(i,N) {
			if(stones[i]=='O') p=i;
			pre[i]=p;
		}
		p=N;
		for(i=N-1;i>=0;i--) {
			if(stones[i]=='O') p=i;
			nex[i]=p;
		}
		
		ll LL,RR;
		ll from[2]={0,0};
		FOR(i,C) {
			state = (state * 1103515245 + 12345)%(1LL<<31);
		    int w = minW + (state % (maxW - minW + 1));
			state = (state * 1103515245 + 12345)%(1LL<<31);
		    int L = state % (N - w);
		    int R = L + w;
			
			
			if(nex[L]>R) return -1;
			ll to[2];
			ll NL=nex[L];
			ll NR=pre[R];
			if(i==0) {
				to[0]=to[1]=0;
			}
			else {
				to[0]=max(from[0]+abs(LL-NL),from[1]+abs(RR-NL));
				to[1]=max(from[0]+abs(LL-NR),from[1]+abs(RR-NR));
			}
			LL=NL;
			RR=NR;
			swap(from,to);
		}
		
		return max(from[0],from[1]);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "=O=========O=="; int Arg1 = 11; int Arg2 = 13; int Arg3 = 4747; int Arg4 = 100; verify_case(0, Arg4, jump(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arg0 = "=O=O=O=O=O=O="; int Arg1 = 10; int Arg2 = 2; int Arg3 = 4747; int Arg4 = 64; verify_case(1, Arg4, jump(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arg0 = "=O=O=====O=O="; int Arg1 = 10; int Arg2 = 2; int Arg3 = 4747; int Arg4 = -1; verify_case(2, Arg4, jump(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arg0 = "=====O======="; int Arg1 = 123456; int Arg2 = 9; int Arg3 = 4242; int Arg4 = 0; verify_case(3, Arg4, jump(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FroggerAndNets ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

