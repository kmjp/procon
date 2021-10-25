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

vector<pair<int,ll>> patterns[100];
static const int N_=1020;
static __int128 C_[N_][N_];


class IntrospectiveNumbers {
	public:
	string nth(long long N) {
		int mask;
		int i,j;
		FOR(i,100) patterns[i].clear();
		FOR(i,N_) C_[i][0]=C_[i][i]=1;
		for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=min(C_[i-1][j-1]+C_[i-1][j],(__int128)1LL<<60);
		FOR(mask,1<<9) if(mask) {
			int sum=0;
			__int128 pat=1;
			FOR(i,9) if(mask&(1<<i)) {
				sum+=(i+1);
				pat=min(pat*C_[sum][i+1],(__int128)1LL<<60);
			}
			patterns[sum].push_back({mask,(ll)pat});
		}
		
		FOR(i,55) {
			ll sum=0;
			FORR(v,patterns[i]) {
				sum+=v.second;
				if(sum>=1LL<<60) break;
			}
			if(sum-1>=N) break;
			N-=sum;
		}
		int cur=i,x;
		N++;
		string R;

		int D[111]={};
		FOR(i,cur) {
			for(j=1;j<=9;j++) {
				if(D[j]==j) continue;
				D[j]++;
				__int128 sum=0;
				FORR(v,patterns[cur]) {
					int a=v.first;
					int lef=cur-i-1;
					__int128 p=1;
					FOR(x,9) {
						if((a&(1<<x))==0) {
							if(D[x+1]) {
								p=0;
								break;
							}
						}
					}
					if(p==0) continue;
					FOR(x,9) if((a&(1<<x))) {
						p=min(p*C_[lef][x+1-D[x+1]],(__int128)1LL<<60);
						lef-=x+1-D[x+1];
					}
					if(p) assert(lef==0);
					sum+=p;
				}
				if(sum>=N) break;
				N-=sum;
				
				D[j]--;
			}
			assert(j<=9);
			R.push_back('0'+j);
		}
		
		
		
		return R;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 0LL; string Arg1 = "1"; verify_case(0, Arg1, nth(Arg0)); }
	void test_case_1() { long long Arg0 = 5LL; string Arg1 = "333"; verify_case(1, Arg1, nth(Arg0)); }
	void test_case_2() { long long Arg0 = 128LL; string Arg1 = "2144424"; verify_case(2, Arg1, nth(Arg0)); }
	void test_case_3() { long long Arg0 = 266960LL; string Arg1 = "999299999912"; verify_case(3, Arg1, nth(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  IntrospectiveNumbers ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

