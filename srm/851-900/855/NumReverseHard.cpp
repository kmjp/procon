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
ll p10[22];
ll p10m[22];

class NumReverseHard {
	public:
	ll rev(ll a) {
		ll v=0;
		while(a) v=v*10+a%10,a/=10;
		return v;
	}
	
	ll hoge(ll v) {
		//íPèÉÇ»òa
		if(v<=0) return 0;
		ll ret=v%mo*((v+1)%mo)%mo*(mo+1)/2%mo;
		int len=to_string(v).size();
		
		int pre,mid,L,R,i,j;
		for(pre=1;pre*2<=len;pre++) for(mid=0;pre*2+mid<=len;mid++) {
			for(L=0;L<=9;L++) {
				if(pre==1&&L==0) continue;
				
				ll mnum=p10m[mid];
				ll num;
				if(pre*2+mid<len) {
					num=(pre==1)?1:(9*p10m[pre-2]);
				}
				else {
					ll pref=v/p10[mid+pre];
					num=(v-p10[len-1])/p10[mid+pre+1]+1;
					if(L>=pref%10) num--;
				}
				num%=mo;
				
				for(R=L+1;R<=9;R++) {
					ll add=(L-R)*p10m[pre-1]+(R-L)*p10m[pre+mid];
					add=(add%mo+mo)%mo;
					(ret+=add*mnum%mo*num%mo)%=mo;
				}
				
				if(pre*2+mid==len&&L==v/p10[mid+pre]%10) {
					pair<ll,ll> from[2]={};
					from[0].first=1;
					from[0].second=L*(p10m[pre-1]-p10m[pre+mid]+mo)%mo;
					for(i=pre+mid-1;i>=pre;i--) {
						pair<ll,ll> to[2]={};
						int d=v/p10[i]%10;
						
						ll m=(p10m[len-1-i]-p10m[i]+mo)%mo;
						
						FOR(j,10) {
							(to[1].first+=from[1].first)%=mo;
							(to[1].second+=from[1].second+from[1].first*j%mo*m)%=mo;
							if(j<d) {
								(to[1].first+=from[0].first)%=mo;
								(to[1].second+=from[0].second+from[0].first*j%mo*m)%=mo;
							}
							else if(j==d) {
								(to[0].first+=from[0].first)%=mo;
								(to[0].second+=from[0].second+from[0].first*j%mo*m)%=mo;
							}
						}
						swap(from,to);
					}
					
					for(int R=L+1;R<=9;R++) {
						ret+=from[1].second;
						ret+=from[1].first*R%mo*(p10m[pre+mid]-p10m[pre-1]+mo)%mo;
						if(R*p10[pre-1]+rev(v)%p10[pre-1]<=v%p10[pre]) {
							ret+=from[0].second;
							ret+=from[0].first*R%mo*(p10m[pre+mid]-p10m[pre-1]+mo)%mo;
						}
					}
					
				}
				
				
			}
			ret%=mo;
		}
		
		
		
		
		cout<<v<<" "<<ret<<endl;
		return ret;
	}
	
	
	int getsum(long long A, long long B) {
		int i;
		p10[0]=1;
		p10m[0]=1;
		FOR(i,19) {
			p10[i+1]=p10[i]*10;
			p10m[i+1]=p10[i+1]%mo;
		}
		return (hoge(B)-hoge(A-1)+mo)%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 21LL; long long Arg1 = 23LL; int Arg2 = 75; verify_case(0, Arg2, getsum(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 12LL; long long Arg1 = 21LL; int Arg2 = 489; verify_case(1, Arg2, getsum(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 97LL; long long Arg1 = 101LL; int Arg2 = 495; verify_case(2, Arg2, getsum(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 123LL; long long Arg1 = 128LL; int Arg2 = 3426; verify_case(3, Arg2, getsum(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 89LL; long long Arg1 = 234LL; int Arg2 = 67841; verify_case(4, Arg2, getsum(Arg0, Arg1)); }
	void test_case_5() { long long Arg0 = 100000000000000000LL; long long Arg1 = 100000000000000000LL; int Arg2 = 300000007; verify_case(5, Arg2, getsum(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  NumReverseHard ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

