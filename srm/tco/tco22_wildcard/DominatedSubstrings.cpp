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

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=1<<20;
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v; //上書きかチェック
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
template<class V,int NV> class SegTree_2 {
public:
	vector<V> val;
	static V const def=-(1<<20);
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_2(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v; //上書きかチェック
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

int P[3][303030];
int Q[3][303030];
SegTree_1<int,1<<19> st[3],st2[3];
SegTree_2<int,1<<19> ra;

int R[303030];

class DominatedSubstrings {
	public:
	vector <int> find(int N, string prefix, int seed, int pA, int pB, int pC) {
		ll state=seed;
		vector<int> S;
		FORR(c,prefix) S.push_back(c-'A');
		while(S.size()<N) {
    		state = (state * 1103515245 + 12345) %(1LL<<31);
		    ll v = (state/32)%(pA + pB + pC);
		    if(v<pA) S.push_back(0);
		    else if(v<pA+pB) S.push_back(1);
		    else S.push_back(2);
		}
		
		int i,j,x,y;
		FOR(j,3) {
			FOR(i,N) {
				P[j][i+1]=P[j][i];
				if(S[i]==j) P[j][i+1]++;
				else P[j][i+1]--;
				st[j].update(i+1,P[j][i+1]);
			}
		}
		FOR(j,3) {
			for(i=N-1;i>=0;i--) {
				Q[j][i]=Q[j][i+1];
				if(S[i]==j) Q[j][i]++;
				else Q[j][i]--;
				st2[j].update(i,Q[j][i]);
			}
			
		}
		
		FOR(i,N) {
			j=i;
			y=S[i];
			for(x=18;x>=0;x--) if(j+(1<<x)<=N) {
				if(st[y].getval(i+1,j+(1<<x)+1)>=P[y][i]) j+=1<<x;
			}
			ra.update(i,j);
		}
		int mal=0,cnt=0;
		for(i=N-1;i>=0;i--) {
			j=i;
			y=S[i];
			for(x=18;x>=0;x--) if(j-(1<<x)>=0) {
				if(st2[y].getval(j-(1<<x),i)>=Q[y][i+1]) {
					j-=1<<x;
				}
			}
			y=j;
			if(i-y<mal) continue;
			for(x=18;x>=0;x--) if(y+(1<<x)<=i) {
				if(ra.getval(y,y+(1<<x))<=i) {
					y+=1<<x;
					if(i-y<mal) break;
				}
			}
			if(i-y>mal) mal=i-y, cnt=0;
			if(i-y==mal) cnt++;
		}
		
		return {mal+1,cnt};
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 6; string Arg1 = "ABABBA"; int Arg2 = 47; int Arg3 = 1; int Arg4 = 1; int Arg5 = 1; int Arr6[] = {4, 2 }; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(0, Arg6, find(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 16; string Arg1 = "ABBABAABBABABBBA"; int Arg2 = 42; int Arg3 = 1; int Arg4 = 1; int Arg5 = 1; int Arr6[] = {14, 1 }; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(1, Arg6, find(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 30; string Arg1 = "ABACA"; int Arg2 = 4742; int Arg3 = 5; int Arg4 = 5; int Arg5 = 5; int Arr6[] = {11, 1 }; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(2, Arg6, find(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arg0 = 47000; string Arg1 = ""; int Arg2 = 0; int Arg3 = 1; int Arg4 = 0; int Arg5 = 0; int Arr6[] = {47000, 1 }; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(3, Arg6, find(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4_() { int Arg0 = 18; string Arg1 = "ABCABCABCABCABCABC"; int Arg2 = 18; int Arg3 = 18; int Arg4 = 18; int Arg5 = 18; int Arr6[] = {2, 17 }; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(4, Arg6, find(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { int Arg0 = 300000; string Arg1 = ""; int Arg2 = 47; int Arg3 = 24000; int Arg4 = 47000; int Arg5 = 24000; int Arr6[] = {2, 17 }; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(4, Arg6, find(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DominatedSubstrings ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

