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

const int prime_max = 1000000;
vector<int> prime;
int NP,divp[prime_max];

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime.push_back(i); NP++;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

//‘f””»’è
bool isprime(ll v) {
	cprime();
	int p;
	if(v==1) return 0;
	if(v==2) return 1;
	FORR(p,prime) {
		if(v%p==0) return 0;
		if(1LL*p*p>=v) return 1;
	}
	return 1;
}



const ll mo=1000000007;
class PrettyPrimes {
	public:
	string P;
	vector<string> pat[13];
	
	void dfs(int D,string C) {
		if(C.size()==D) {
			int i;
			int oc=0;
			for(i=0;i+P.size()<=C.size();i++) {
				if(C.substr(i,P.size())==P) oc++;
			}
			pat[oc].push_back(C);
			return;
			
		}
		C+="?";
		dfs(D,C);
		C.back()=P[0];
		dfs(D,C);
		if(P.size()==2&&P[0]!=P[1]) {
			C.back()=P[1];
			dfs(D,C);
		}
		
	}
	
	ll hoge(string& p,int cur,ll v) {
		if(cur==p.size()) {
			if(isprime(v)) {
				return v;
			}
			else return 0;
		}
		if(p[cur]=='?') {
			ll sum=0;
			for(int i=0;i<10;i++) {
				if(cur==0&&i==0) continue;
				if(i==P[0]-'0') continue;
				if(i==P.back()-'0') continue;
				sum+=hoge(p,cur+1,v*10+i);
			}
			return sum%mo;
		}
		else {
			if(cur==0&&p[cur]=='0') return 0;
			return hoge(p,cur+1,v*10+p[cur]-'0');
		}
		
	}
	
	int solve(int pattern, int D) {
		int i,j,x;
		FOR(i,12) pat[i].clear();
		
		P=to_string(pattern);
		dfs(D,"");
		for(i=D;i>=0;i--) {
			ll sum=0;
			ll ok=0;
			FORR(a,pat[i]) {
				ll v=hoge(a,0,0);
				if(v) {
					(sum+=v)%=mo;
					ok=1;
				}
			}
			if(ok) return sum;
		}
		return 0%mo;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 17; int Arg1 = 5; int Arg2 = 125285; verify_case(0, Arg2, solve(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 42; int Arg1 = 5; int Arg2 = 12818536; verify_case(1, Arg2, solve(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 44; int Arg1 = 10; int Arg2 = 444444419; verify_case(2, Arg2, solve(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 14; int Arg1 = 1; int Arg2 = 17; verify_case(3, Arg2, solve(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PrettyPrimes ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

