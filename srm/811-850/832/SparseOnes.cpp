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


ll pat[100];
ll sum[100];
int N;

class SparseOnes {
	public:
	int hoge2(ll v) {
		ll ov=v;
		ll val=0;
		ll id=0;
		v--;
		int i,j;
		for(i=1;i<=N;i++) {
			if(v>=i*pat[i]) {
				v-=i*pat[i];
			}
			else {
				id=v%i;
				val=1LL<<(i-1);
				int la=i-1;
				v/=i;
				v++;
				while(v) {
					v--;
					if(v==0) break;
					for(j=0;j<la-1;j++) {
						if(v<=pat[j+1]) {
							val|=1LL<<j;
							la=j;
							break;
						}
						v-=pat[j+1];
					}
				}
				break;
			}
		}
		int cnt=0;
		int ret=0;
		for(i=60;i>=0;i--) {
			if(val&(1LL<<i)) cnt=1;
			if(cnt) {
				if(id==0) {
					ret=(val>>i)&1;
					break;
				}
				id--;
			}
		}
		
		return ret;
	}
	ll hoge(ll v) {
		if(v<=0) return 0;
		ll ov=v;
		
		ll ret=0;
		int i,j;
		for(i=1;i<=N&&v;i++) {
			if(v>=i*pat[i]) {
				ret+=sum[i];
				v-=i*pat[i];
			}
			else {
				ll num=v/i;
				ll lef=v%i;
				if(lef) {
					int add=i-lef;
					num++;
					for(j=1;j<=add;j++) ret-=hoge2(ov+j);
				}
				ll cur=1LL<<(i-1);
				int la=i-1;
				int bit=1;
				while(num) {
					num--;
					ret+=bit;
					if(num==0) break;
					for(j=0;j<la-1;j++) {
						if(num<=pat[j+1]) {
							cur|=1LL<<j;
							la=j;
							bit++;
							break;
						}
						else {
							ret+=sum[j+1]+bit*pat[j+1];
							num-=pat[j+1];
						}
					}
				}
				break;
			}
		}
		return ret;
	}
	long long count(long long A, long long B) {
		ZERO(pat);
		ZERO(sum);
		pat[1]=sum[1]=1;
		int i,j;
		for(i=2;i<=99;i++) {
			pat[i]=1;
			sum[i]=1;
			for(j=1;j<=i-2;j++) {
				pat[i]+=pat[j];
				sum[i]+=sum[j]+pat[j];
			}
			if(pat[i]>=1LL<<50) {
				N=i;
				break;
			}
		}
		return hoge(B-1)-hoge(A-1);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 0LL; long long Arg1 = 22LL; long long Arg2 = 10LL; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 1LL; long long Arg1 = 22LL; long long Arg2 = 10LL; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 5LL; long long Arg1 = 21LL; long long Arg2 = 7LL; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_2_() { long long Arg0 = 500LL; long long Arg1 = 210000000000LL; long long Arg2 = 7LL; verify_case(2, Arg2, count(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SparseOnes ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

