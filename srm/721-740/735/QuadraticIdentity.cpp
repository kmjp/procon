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

class QuadraticIdentity {
	public:
	ll ext_gcd(ll p,ll q,ll& x, ll& y) { // get px+qy=gcd(p,q)
		if(q==0) return x=1,y=0,p;
		ll g=ext_gcd(q,p%q,y,x);
		y-=p/q*x;
		return g;
	}

	ll hoge(ll m,ll a) {
		// ax-1=by -> ax-by=1
		ll x,y;
		ext_gcd(a,m/a,x,y);
		while(x<0) x+=m/a;
		while(x>=m/a) x-=m/a;
		return x*a;
	}
	
	vector<long long> getFixedPoints(long long m) {
		vector<ll> V(1,0);
		if(m==1) return V;
		for(ll a=1;a*a<=m;a++) if(m%a==0 && __gcd(a,m/a)==1) V.push_back(hoge(m,a)),V.push_back(hoge(m,m/a));
		sort(ALL(V));
		V.erase(unique(ALL(V)),V.end());
		while(V.back()>=m) V.pop_back();
		
		while(V.size()>500) {
			vector<ll> V2;
			for(int i=0;i<V.size();i+=2) V2.push_back(V[i]);
			V=V2;
		}
		
		return V;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector<long long> &Expected, const vector<long long> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { long long Arg0 = 20LL; long Arr1[] = {0, 1, 5, 16 }; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getFixedPoints(Arg0)); }
	void test_case_1() { long long Arg0 = 4262046602LL; long Arr1[] = {0, 1, 27391046, 152613648, 180004693, 333799345, 361190390, 513804038, 541195083, 621181264, 648572309, 801185957, 828577002, 941255910, 968646955, 982371654, 1009762699, 1121260603, 1148651648, 1162376347, 1189767392, 1302446300, 1329837345, 1482450993, 1509842038, 1589828219, 1617219264, 1769832912, 1797223957, 1951018609, 1978409654, 2103632256, 2131023301, 2131023302, 2158414347, 2283636949, 2311027994, 2464822646, 2492213691, 2644827339, 2672218384, 2752204565, 2779595610, 2932209258, 2959600303, 3072279211, 3099670256, 3113394955, 3140786000, 3252283904, 3279674949, 3293399648, 3320790693, 3433469601, 3460860646, 3613474294, 3640865339, 3720851520, 3748242565, 3900856213, 3928247258, 4082041910, 4109432955, 4234655557 }; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getFixedPoints(Arg0)); }
	void test_case_2() { long long Arg0 = 7LL; long Arr1[] = {0, 1 }; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getFixedPoints(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  QuadraticIdentity ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

