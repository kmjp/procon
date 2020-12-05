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

int N;
vector<int> X,Y;

class FloodFill {
	public:
	ll num(ll v) {
		vector<ll> ys;
		int i;
		vector<pair<int,int>> ev;
		FOR(i,N) {
			ys.push_back(Y[i]-v);
			ys.push_back(Y[i]+v+1);
			ev.push_back({X[i]-v,i});
			ev.push_back({X[i]+v+1,i+N});
		}
		sort(ALL(ys));
		ys.erase(unique(ALL(ys)),ys.end());
		int D[30],U[30];
		FOR(i,N) {
			D[i]=lower_bound(ALL(ys),Y[i]-v)-ys.begin();
			U[i]=lower_bound(ALL(ys),Y[i]+v+1)-ys.begin();
		}
		
		int bt[66]={};
		ll sum=0;
		sort(ALL(ev));
		int px=-1<<29;
		FORR(e,ev) {
			ll ysum=0;
			int i;
			FOR(i,ys.size()-1) if(bt[i]) ysum+=ys[i+1]-ys[i];
			sum+=ysum*(e.first-px);
			px=e.first;
			if(e.second<N) {
				for(i=D[e.second];i<U[e.second];i++) bt[i]++;
			}
			else {
				for(i=D[e.second-N];i<U[e.second-N];i++) bt[i]--;
			}
		}
		return sum;
	}
	
	vector<int> get(ll v,ll A) {
		vector<ll> ys;
		int i;
		map<int,vector<int>> ev;
		FOR(i,N) {
			ys.push_back(Y[i]-v);
			ys.push_back(Y[i]-v+1);
			ys.push_back(Y[i]+v);
			ys.push_back(Y[i]+v+1);
			ev[X[i]-v].push_back(i);
			ev[X[i]+v].push_back(i+N);
		}
		sort(ALL(ys));
		ys.erase(unique(ALL(ys)),ys.end());
		int D[30],U[30];
		FOR(i,N) {
			D[i]=lower_bound(ALL(ys),Y[i]-v)-ys.begin();
			U[i]=lower_bound(ALL(ys),Y[i]+v+1)-ys.begin();
		}
		
		int bt[140]={};
		ll sum=0;
		int px=-1<<29;
		FORR(e,ev) {
			ll ysum=0;
			int i;
			FOR(i,ys.size()-1) if(bt[i]>0&&bt[i]<100) ysum+=ys[i+1]-ys[i];
			
			if(A<=ysum*(e.first-px)) {
				int cx=px;
				if(A%ysum==0) {
					cx+=A/ysum-1;
					A=ysum;
				}
				else {
					cx+=A/ysum;
					A%=ysum;
				}
				FOR(i,ys.size()-1) if(bt[i]>0&&bt[i]<100) {
					if(--A==0) return {cx,(int)ys[i]};
				}
			}
			A-=ysum*(e.first-px);
			
			FORR(v,e.second) {
				
				if(v<N) {
					for(i=D[v];i<U[v];i++) bt[i]++;
				}
				else {
					for(i=D[v-N]+1;i<U[v-N]-1;i++) bt[i]-=99;
				}
			}
			FOR(i,ys.size()-1) if(bt[i]>0&&bt[i]<100) {
				if(ys[i+1]-ys[i]>=A) {
					return {e.first,ys[i]+A-1};
				}
				else {
					A-=ys[i+1]-ys[i];
				}
			}
			px=e.first+1;
			FORR(v,e.second) {
				
				if(v<N) {
					for(i=D[v]+1;i<U[v]-1;i++) bt[i]+=99;
				}
				else {
					for(i=D[v-N];i<U[v-N];i++) bt[i]--;
				}
			}
		}
		cout<<A<<endl;
		assert(0);
		return {0,0};
	}
	
	vector <int> getCell(vector <int> X, vector <int> Y, long long A) {
		::X=X;
		::Y=Y;
		N=X.size();
		ll tim=1<<28;
		int i;
		for(i=27;i>=0;i--) if(num(tim-(1<<i))>=N+A) tim-=1<<i;
		cout<<tim<<" "<<num(tim)<<" "<<num(tim-1)<<endl;
		A=A+N-num(tim-1);
		
		return get(tim,A);
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {4, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1LL; int Arr3[] = {3, 6 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, getCell(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {4, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 8LL; int Arr3[] = {4, 8 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, getCell(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {4, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 17LL; int Arr3[] = {2, 5 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, getCell(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {4, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 53LL; int Arr3[] = {1, 8 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, getCell(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {4, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 84LL; int Arr3[] = {8, 5 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, getCell(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 123456789012LL; int Arr3[] = {64258, -175682 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(5, Arg3, getCell(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arr0[] = {0, 0, 0, 1, 1, 2, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 2, 0, 2, 0, 1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 17LL; int Arr3[] = {3, 3 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(6, Arg3, getCell(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FloodFill ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

