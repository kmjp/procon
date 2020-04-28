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

template<int MV> class Bellman_Ford {
public:
	int NV;
	ll cost[MV];
	vector<pair<int,ll> > E[MV];
	
	void add_edge(int from,int to,ll cost){ E[from].push_back(make_pair(to,cost));}
	bool calc(int start,int NV) { // true:ok false:cycle
		int i,j,k;
		FOR(i,NV) cost[i]=1LL<<61;
		cost[start]=0;
		FOR(i,NV) {
			bool up=false;
			FOR(j,NV) FOR(k,E[j].size()) {
				if(cost[E[j][k].first]>cost[j]+E[j][k].second) cost[E[j][k].first]=cost[j]+E[j][k].second, up=true;
			}
			if(!up) return true;
		}
		return false;
	}
};

class LongSeat {
	public:
	ll L;
	int N;
	vector<int> W;
	
	bool can(vector<int> V) {
		int i,j,k,num=0;
		ll left=L*1000;
		vector<int> did;
		Bellman_Ford<14> bf;
		ll rev[10]={};
		
		FOR(i,10) rev[i]=-1;
		FOR(i,N) if(V[i]>=0) rev[V[i]]=1000LL*W[i],num++;
		
		did.push_back(-1);
		did.push_back(num);
		FOR(i,N) {
			if(V[i]==-1) {
				FOR(j,did.size()-1) {
					ll ts=0;
					for(k=did[j]+1;k<did[j+1];k++) ts += rev[k];
					bf.add_edge(did[j+1]+1,did[j]+1,(W[i]*1000LL-ts)-1);
				}
			}
			else {
				if(W[i]*1000LL>left) return false;
				left -= W[i]*1000LL;
				did.push_back(V[i]);
				sort(did.begin(),did.end());
			}
		}
		FOR(i,num+1) bf.add_edge(i,i+1,0);
		bf.add_edge(0,num+1,-left);
		
		return bf.calc(0,num+2);
	}
	
	vector <string> canSit(int L, vector <int> width) {
		this->L=L;
		this->W=width;
		this->N=width.size();
		int i,j;
		int sit[10]={};
		int V[10];
		
		FOR(i,N) V[i]=i;
		
		do {
			vector<int> V2(N,-1);
			for(i=0;i<=N;i++) {
				V2[V[i-1]]=i-1;
				if(can(V2)) FOR(j,N) sit[V[j]]|=1<<(j>=i);
			}
		} while(next_permutation(V,V+N));
		
		vector<string> R;
		FOR(i,N) {
			if(sit[i]==1) R.push_back("Sit");
			if(sit[i]==2) R.push_back("Stand");
			if(sit[i]==3) R.push_back("Unsure");
		}
		return R;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = {1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"Sit", "Unsure" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, canSit(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 10; int Arr1[] = {100, 2, 4, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"Stand", "Sit", "Sit", "Unsure" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, canSit(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 37; int Arr1[] = {3, 7, 5, 6, 4, 4, 1, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"Sit", "Sit", "Sit", "Unsure", "Unsure", "Unsure", "Sit", "Unsure" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, canSit(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 400; int Arr1[] = {92, 65, 99, 46, 24, 85, 95, 84}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"Sit", "Sit", "Unsure", "Unsure", "Unsure", "Unsure", "Stand", "Unsure" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, canSit(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1000000000; int Arr1[] = {1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"Sit", "Stand", "Stand", "Stand", "Stand", "Stand", "Stand", "Stand" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, canSit(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 1; int Arr1[] = {1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"Stand", "Stand", "Stand", "Stand", "Stand", "Stand", "Stand", "Stand" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, canSit(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  LongSeat ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
