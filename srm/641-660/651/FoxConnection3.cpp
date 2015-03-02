#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


class FoxConnection3 {
	public:
	int N;
	set<vector<pair<int,int> > > P;
	
	void dfs(int left,set<pair<int,int> >& S) {
		if(left==0) {
			vector<pair<int,int> > p;
			int mx=1<<30,my=1<<30;
			ITR(it,S) mx=min(mx,it->first),my=min(my,it->second);
			ITR(it,S) p.push_back(make_pair(it->first-mx,it->second-my));
			P.insert(p);
			return;
		}
		
		set<pair<int,int> > next;
		int i;
		ITR(it,S) {
			int cx=it->first,cy=it->second;
			FOR(i,4) {
				int dd[4]={1,0,-1,0};
				int ty=cy+dd[i],tx=cx+dd[i^1];
				if(S.count(make_pair(tx,ty))) continue;
				next.insert(make_pair(tx,ty));
			}
		}
		
		ITR(it,next) {
			S.insert(*it);
			dfs(left-1,S);
			S.erase(*it);
		}
	}
	
	ll tot(vector<ll>& V,ll dif) {
		ll tot=0;
		ITR(it,V) tot+=abs(*it+dif);
		return tot;
	}
	
	ll mini(vector<ll>& V) {
		int i;
		ll L=-1LL<<30,R=1LL<<30;
		ll mi=1LL<<50;
		while(R-L>=4) {
			ll m1=(L*2+R)/3;
			ll m2=(L+R*2)/3;
			ll v1=tot(V,m1);
			ll v2=tot(V,m2);
			if(v1==v2) L=m1,R=m2;
			if(v1<v2) R=m2;
			if(v1>v2) L=m1;
		}
		for(ll a=L;a<=R;a++) mi=min(mi,tot(V,a));
		return mi;
	}
	
	long long minimalSteps(vector <int> X, vector <int> Y) {
		int N=X.size();
		ll mi=1LL<<60;
		int i,j;
		
		P.clear();
		set<pair<int,int> > S;
		S.insert(make_pair(0,0));
		dfs(N-1,S);
		ITR(it,P) {
			vector<int> V;
			vector<pair<int,int> > C=*it;
			vector<ll> xs(N,0),ys(N,0);
			FOR(i,N) V.push_back(i);
			do {
				
				FOR(i,N) xs[i]=C[V[i]].first-X[i];
				FOR(i,N) ys[i]=C[V[i]].second-Y[i];
				mi=min(mi,mini(xs)+mini(ys));
			} while(next_permutation(V.begin(),V.end()));
		}
		
		return mi;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0,1,-2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,-1,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 2LL; verify_case(0, Arg2, minimalSteps(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(1, Arg2, minimalSteps(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {-123456789,-58585858,-47474747,123,456,789012345}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,0,0,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1018530309LL; verify_case(2, Arg2, minimalSteps(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,7,3,5,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,7,5,3,7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 12LL; verify_case(3, Arg2, minimalSteps(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {-3,0,1,-2,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,-3,0,1,-1,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 10LL; verify_case(4, Arg2, minimalSteps(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {-96277832,507856257,-86306299,-806700273,-775932643,-273209838}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-955536464,-599634138,399850429,-165706338,-537800480,738983556}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 5247213600LL; verify_case(5, Arg2, minimalSteps(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(6, Arg2, minimalSteps(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FoxConnection3 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
