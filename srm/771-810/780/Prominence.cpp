#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

template<class V,int NV> class RMQ {
private:
	V table[NV+1][1<<NV];
	int LG[1<<NV];
	int NV2;
public:
	static V const def=(1<<30);
	V comp(V l,V r){ return min(l,r);};
	RMQ() {
		int i,x;
		NV2=1<<NV;
		LG[1]=0;
		for(i=2;i<NV2;i++) LG[i]=LG[i/2]+1;
		FOR(i,NV) FOR(x,NV2) table[i][x]=def;
	}
	void set(int x,V v){ table[0][x]=v;}
	void build() {
		int i,j,x,y;
		FOR(i,NV) FOR(x,NV2) table[i+1][x]=comp(table[i][x],(x+(1<<i)<NV2)?table[i][x+(1<<i)]:def);
	}
	V query(int L,int R) { //[L,R),
		L=max(0,L), R=min(R,NV2);
		if(R<=L) return def;
		int WL=LG[R-L];
		return comp(table[WL][L],table[WL][R-(1<<WL)]);
	}
	
};

RMQ<int,20> rmq;

int ng[1010101];
vector<ll> H;
vector<pair<int,int>> V;
set<int> S;
class Prominence {
	public:
	long long sumOfProminences(int N, vector <int> coef, vector <int> idx, vector <int> val) {
		int i;
		FOR(i,1<<20) rmq.set(i,1<<30);
		H.clear();
		V.clear();
		S.clear();
		
		FOR(i,N) {
			int p=i%2;
			ll a=coef[3*p];
			ll b=coef[3*p+1];
			ll c=coef[3*p+2];
			H.push_back(((a*i+b)%1000000007*i+c)%1000000007);
		}
		FOR(i,idx.size()) H[idx[i]]=val[i];
		
		FOR(i,N) {
			ng[i]=0;
			if(i&&H[i-1]>=H[i]) ng[i]=1;
			if(i+1<N&&H[i+1]>=H[i]) ng[i]=1;
			V.push_back({-H[i],i});
			rmq.set(i,H[i]);
		}
		
		rmq.build();
		
		
		S.insert(-1);
		S.insert(N);
		ll ret=0;
		sort(ALL(V));
		FOR(i,V.size()) {
			int j=i;
			while(j<V.size()&&V[j].first==V[i].first) j++;
			for(int x=i;x<j;x++) {
				int a=V[x].second;
				if(ng[a]==0) {
					int ma=0;
					auto it=S.lower_bound(a);
					if(*it!=N) ma=max(ma,rmq.query(a+1,*it));
					it--;
					if(*it!=-1) ma=max(ma,rmq.query(*it+1,a));
					ret+=(-V[i].first)-ma;
				}
			}
			for(int x=i;x<j;x++) {
				int a=V[x].second;
				S.insert(a);
			}
			i=j-1;
		}
		return ret;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1000000; int Arr1[] = {0, 0, 47, 0, 0, 47}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 0LL; verify_case(0, Arg4, sumOfProminences(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 8; int Arr1[] = {0, 0, 47, 0, 0, 42}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 188LL; verify_case(1, Arg4, sumOfProminences(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 10; int Arr1[] = {0, 0, 0, 0, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 2, 3, 4, 5, 6, 7, 9, 8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {500, 300, 400, 200, 400, 700, 100, 300, 300, 100}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 1500LL; verify_case(2, Arg4, sumOfProminences(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 16; int Arr1[] = {123456789, 234567890, 345678901, 456789012, 567890123, 678901234}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {890123456}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 4543586810LL; verify_case(3, Arg4, sumOfProminences(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Prominence ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

