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


ll from[1<<13];
vector<pair<int,ll>> C[1<<13];
vector<int> order[1<<13];

class ChargingACarFleet {
	public:
	vector<long long> charge(vector <int> chargingTime, vector <int> penalty, vector <int> carSize, vector <int> spotAvailable, vector <int> spotSize) {
		int N=chargingTime.size();
		int M=spotAvailable.size();
		
		int i,j,k,s;
		int mask;
		FOR(mask,1<<N) {
			C[mask].clear();
			from[mask]=1LL<<60;
			order[mask].clear();
			if(mask) {
				FOR(i,N) if(mask&(1<<i)) order[mask].push_back(i);
				FOR(i,N) FOR(j,order[mask].size()-1) {
					if(1LL*chargingTime[order[mask][j+1]]*penalty[order[mask][j]]<1LL*chargingTime[order[mask][j]]*penalty[order[mask][j+1]]) {
						swap(order[mask][j],order[mask][j+1]);
					}
				}
			}
		}
		from[0]=0;
		FOR(i,N) C[0].push_back({0,0});
		FOR(i,M) {
			int can=0;
			FOR(j,N) if(carSize[j]<=spotSize[i]) can|=1<<j;
			for(mask=(1<<N)-1;mask>=0;mask--) if(from[mask]<1LL<<60) {
				int cand=((1<<N)-1)^mask;
				for(int sm=cand;sm>=0;sm--) {
					sm&=cand;
					if(sm==0) break;
					if((sm&can)!=sm) continue;
					ll add=0;
					ll now=spotAvailable[i];
					FORR(c,order[sm]) {
						now+=chargingTime[c];
						add+=now*penalty[c];
					}
					if(from[mask|sm]>from[mask]+add) {
						from[mask|sm]=from[mask]+add;
						vector<pair<int,ll>> nex=C[mask];
						now=spotAvailable[i];
						FORR(c,order[sm]) {
							nex[c].first=i;
							nex[c].second=now;
							now+=chargingTime[c];
						}
						C[mask|sm]=nex;
					}
				}
				
			}
		}

		vector<ll> R(2*N+1);
		R[0]=from[(1<<N)-1];
		FOR(i,N) {
			R[i+1]=C[(1<<N)-1][i].first;
			R[i+N+1]=C[(1<<N)-1][i].second;
		}
		return R;
		
		
		
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector<long long> &Expected, const vector<long long> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {100, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5000, 7000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 0, 1000}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {3000, 6000, 7000}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); long Arr5[] = {1200, 1, 2, 0, 1000 }; vector<long long> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(0, Arg5, charge(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arr0[] = {1000, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 10000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {7000, 7000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 10, 10000}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {7000, 7000, 7000}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); long Arr5[] = {91009, 0, 0, 9, 0 }; vector<long long> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(1, Arg5, charge(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arr0[] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 0, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {100, 101, 102}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); long Arr5[] = {300000, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0, 0, 100, 200, 300, 0, 100, 200, 300, 0, 100, 200, 300 }; vector<long long> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(2, Arg5, charge(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arr0[] = {100, 100, 100, 100, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100, 100, 100, 100, 100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5000, 5500, 6000, 6500, 7000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 0, 0, 0, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {5300, 7100, 5500, 6666, 6123}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); long Arr5[] = {50000, 0, 2, 4, 3, 1, 0, 0, 0, 0, 0 }; vector<long long> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(3, Arg5, charge(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ChargingACarFleet ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

