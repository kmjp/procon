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

int N;
vector<pair<int,int>> VP;
vector<int> V[15];

bool cmp(pair<int,int> A, pair<int,int> B) {
	return B.first*A.second<A.first*B.second;
}

class Moneymanager {
	public:
	int X;
	ll getget(vector<int> x) {
		int i,j;
		ll mask=0;
		FOR(i,11) FOR(j,x[i]) mask |= 1LL<<V[i][j];
		int tot=0;
		int se=0;
		FOR(i,N) if(mask & (1LL<<i)) se+=VP[i].first, tot+=se*VP[i].second;
		se+=X;
		FOR(i,N) if((mask & (1LL<<i))==0) se+=VP[i].first, tot+=se*VP[i].second;
		return tot;
	}
	
	ll dfs(int cur,int left1,int left2,vector<int>& x) {
		if(left1==0) return getget(x);
		if(left2==0) return 0;
		if(left1>left2) return 0;
		ll ma=0;
		if(x[cur]<V[cur].size()) {
			x[cur]++;
			ma=dfs(cur,left1-1,left2-1,x);
			x[cur]--;
		}
		return max(ma,dfs(cur+1,left1,left2-(V[cur].size()-x[cur]),x));
		
	}
	
	int getbest(vector <int> a, vector <int> b, int X) {
		N=a.size();
		this->X=X;
		int i;
		VP.clear();
		FOR(i,N) VP.push_back({a[i],b[i]});
		sort(VP.begin(),VP.end(),cmp);
		FOR(i,11) V[i].clear();
		FOR(i,N) V[VP[i].second].push_back(i);
		
		vector<int> x(11,0);
		return dfs(1,N/2,N,x);
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 5; verify_case(0, Arg3, getbest(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; int Arg3 = 61; verify_case(1, Arg3, getbest(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {4,4,6,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,2,3,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; int Arg3 = 726; verify_case(2, Arg3, getbest(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {30,13,28,59,26,62,48,75,6,69,94,51}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,6,4,5,4,3,1,5,6,5,2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 62; int Arg3 = 22096; verify_case(3, Arg3, getbest(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Moneymanager ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
