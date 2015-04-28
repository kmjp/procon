#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll mo=1000000007;
const int prime_max = 10000;
int NP,prime[100000],divp[prime_max];

void cprime() {
	NP=0;
	ZERO(divp);
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		prime[NP++]=i;
		for(int j=i*i;j>i&&j<prime_max;j+=i) divp[j]=i;
	}
}

class PolynomialGCD {
	public:
	int val(int p,string& s) {
		int i,N=s.size();
		int mi=1000000000;
		
		if(p>N) return 0;
		FOR(i,N) {
			int tot=0;
			int cand=100000;
			for(int P=p;cand>=p;P*=p) {
				cand=1;
				tot+=s[i];
				for(int d=P;d<N;d+=P) {
					if(i+d<N) tot += s[i+d], cand++;
					if(i-d>=0) tot += s[i-d], cand++;
				}
			}
			mi=min(mi,tot);
		}
		return mi;
	}
	
	int gcd(string s) {
		int i,x;
		cprime();
		FORR(r,s) r-='0';
		
		ll ret=1;
		FOR(i,NP) {
			int num=val(prime[i],s);
			FOR(x,num) ret = ret*prime[i]%mo;
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "111"; int Arg1 = 6; verify_case(0, Arg1, gcd(Arg0)); }
	void test_case_1() { string Arg0 = "00000"; int Arg1 = 1; verify_case(1, Arg1, gcd(Arg0)); }
	void test_case_2() { string Arg0 = "2014"; int Arg1 = 16; verify_case(2, Arg1, gcd(Arg0)); }
//	void test_case_3() { string Arg0 = "31415926535"; int Arg1 = 659897170; verify_case(3, Arg1, gcd(Arg0)); }
	void test_case_3() { string Arg0 = "5056556046294091012486650305522195891012093267230286739137848830274466995003650170831569074204605131116628660685010110841621035949067567711130643126933602091557230993614840809174721355273486282757647813928405233451410548470055305071555325161453765739215479090218528438978180795667253546657299044476806425583556689304797902996967507853169232281490511408745024498472357523294120070441743484104458417745904645623673747417994765837287902423102985798473679899054054881182825448018698933756372218631866095321414140382435850846530377401783975990012238171043197646026568581982452810363106728760936403110622035909173526976272846038319061076997521469208053681528888177281221706856203989804352890241320725886438038249253885116296801739025914350611272277102994395256174605256328337598815469852996996415602362398818387855656850836901577773286597537120406868620983393143746461812262266584614650441879861167680556473927167950099265211116523933811432265954527393932006403821308982651836615556917825106546009136515353"; int Arg1 = 333402496; verify_case(3, Arg1, gcd(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PolynomialGCD ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
