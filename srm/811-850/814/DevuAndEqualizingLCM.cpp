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

map<ll,int> enumpr(ll n) {
	map<ll,int> V;
	
	FORR(p,prime) {
		while(n%p==0) V[p]++, n/=p;
	}
	if(n>1) V[n]++;
	return V;
}

class DevuAndEqualizingLCM {
	public:
	int minimumOperationsNeeded(vector<long long> A, vector<long long> B) {
		map<ll,int> ma,ma2;
		cprime();
		FORR(a,A) {
			auto P=enumpr(a);
			FORR(b,P) ma[b.first]=max(ma[b.first],b.second);
		}
		
		int need=0;
		
		FORR(b,B) {
			auto P=enumpr(b);
			FORR(c,P) ma2[c.first]=max(ma2[c.first],c.second);
			FORR(c,P) {
				if(c.second>ma[c.first]) {
					need++;
					break;
				}
			}
		}
		
		if(need==0) {
			if(ma!=ma2) need++;
		}
		return need;
		
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long Arr0[] = {2, 3}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {6}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(0, Arg2, minimumOperationsNeeded(Arg0, Arg1)); }
	void test_case_1() { long Arr0[] = {2, 6}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {4, 6}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, minimumOperationsNeeded(Arg0, Arg1)); }
	void test_case_2() { long Arr0[] = {4, 6, 10}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {7, 7, 60, 20}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(2, Arg2, minimumOperationsNeeded(Arg0, Arg1)); }
	void test_case_3() { long Arr0[] = {5, 4, 6}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {7, 9, 13}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(3, Arg2, minimumOperationsNeeded(Arg0, Arg1)); }
	void test_case_4() { long Arr0[] = {41,100,28,55,67,34,20,83,45,8,27,95,1,43,7,88,60,71,16,31,89,75,75,3,60,56,76,38,5}
; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {91,15,55,42,46,81,45,27,66,26,83,48,90,100,34,32,31,27}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(4, Arg2, minimumOperationsNeeded(Arg0, Arg1)); }
	void test_case_5() { long Arr0[] = {97540245831,137068896362,514711863869,493787121165,834951815745,37979891065,568618248989,845422774812,388880393645,
985781954575,604319452958,746201820162,231152838059,216843527666,273129662502,182176563686,147497146658,786575259172,809922390313,228908269659,
973967867901,579874670191,125850829414,276107572013,258976667806,661763361945,677932923662,717999289076,640442431523,656032966532,590457054595,416409509380,29284130688,
168848104208,5323300392,526319657599,790307412123,670316357228,14451351458,44944304007,184763758275}
; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {664062862940,371209195826,500760395677,213502574561,407987202195,618243198887,7507868706,982685603451,984624263743,184825285122,691193433687,794873502004,202552646911,
831121828034,117809838201,837979301727,944009960595,875730091573,928487129172,564008033283,19444951901,148407051399,902802383260,727695291915,401932019635,875612048370,
897127364705,602249064193,352855723818,640428054195,306092761693,743561916409,553098062995,711231338004,6626020059,954541653724,144164213750,882628116862,144064233877,
487423289003,627548663637,43271989230,345201595127,141248813704,135109517871}
; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 45; verify_case(5, Arg2, minimumOperationsNeeded(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DevuAndEqualizingLCM ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

