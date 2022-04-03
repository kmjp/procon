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

ll mo;

ll comb(ll N, ll C) {
	if(N-C<C) C=N-C;
	
	vector<int> V;
	int i;
	FOR(i,C) V.push_back(N-i);
	for(i=C;i>=1;i--) {
		int b=i;
		FORR(v,V) {
			int a=__gcd(v,b);
			v/=a;
			b/=a;
		}
	}
	ll ret=1;
	FORR(v,V) ret=ret*v%mo;
	
	return ret;
	
}
ll hcomb(ll P_,ll Q_) { return (P_==0&&Q_==0)?1:comb(P_+Q_-1,Q_);}

class SpaceMission {
	public:
	int count(vector <int> minn, vector <int> maxn, vector <int> parity, int mint, int maxt, int modulus) {
		int N=minn.size();
		int i;
		mo=modulus;
		
		if(mo==1) return 0;
		
		
		FOR(i,N) if(parity[i]) {
			minn[i]--;
			maxn[i]--;
			minn[i]=max(0,minn[i]);
			mint--;
			maxt--;
			if(minn[i]>maxn[i]) return 0;
		}
		mint=max(mint,0);
		if(maxt<mint) return 0;
		mint=(mint+1)/2;
		maxt=maxt/2;
		FOR(i,N) {
			minn[i]=(minn[i]+1)/2;
			maxn[i]=maxn[i]/2;
			if(minn[i]>maxn[i]) return 0;
			mint-=minn[i];
			maxt-=minn[i];
			if(mint<0) mint=0;
			if(maxt<0) return 0;
			maxn[i]-=minn[i];
		}
		cout<<mint<<" "<<maxt<<endl;
		if(mint>maxt) return 0;
		maxn.push_back(maxt-mint);
		
		ll ret=0;
		N++;
		int mask;
		FOR(mask,1<<N) {
			ll sum=0;
			int mul=1;
			FOR(i,N) if(mask&(1<<i)) {
				mul=-mul;
				sum+=maxn[i]+1;
			}
			if(sum>maxt) continue;
			ll pat=hcomb(N,maxt-sum);
			(ret+=mul*pat)%=mo;
		}
		return (ret%mo+mo)%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; int Arg4 = 9; int Arg5 = 10000; int Arg6 = 14; verify_case(0, Arg6, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arr0[] = {0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; int Arg4 = 9; int Arg5 = 10; int Arg6 = 4; verify_case(1, Arg6, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100, 100, 100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; int Arg4 = 8; int Arg5 = 12345; int Arg6 = 1; verify_case(2, Arg6, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arr0[] = {1, 3, 7, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {15, 22, 29, 30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 0, 0, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7; int Arg4 = 28; int Arg5 = 10000; int Arg6 = 210; verify_case(3, Arg6, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { int Arr0[] = {10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 11; int Arg4 = 11; int Arg5 = 12345; int Arg6 = 0; verify_case(4, Arg6, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SpaceMission ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

