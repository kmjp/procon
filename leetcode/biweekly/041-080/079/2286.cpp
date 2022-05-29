#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------
// LeetCodeはtemplateでstatic値を取るとき注意。FORR2も使えない。


int C[50505];

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,0);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return 0;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<int,1<<18> st;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,18> bt;
class BookMyShow {
public:
int M;
set<int> alive;
ll sum;
    BookMyShow(int n, int m) {
		FORR(c,st.val) c=0;
		ZERO(bt.bit);
        ZERO(C);
        M=m;
        int i;
		alive.clear();
        FOR(i,n) {
			st.update(i,m);
			alive.insert(i);
			bt.add(i,m);
		}
    }
    
    vector<int> gather(int k, int maxRow) {
        if(st.getval(0,maxRow+1)<k) return {};
        int i;
        int cur=maxRow;
        for(i=20;i>=0;i--) {
			int tmp=cur-(1<<i);
			if(tmp<0) continue;
 	        if(st.getval(0,tmp+1)>=k) cur=tmp;
		}
		vector<int> R={cur,C[cur]};
		C[cur]+=k;
		st.update(cur,M-C[cur]);
		bt.add(cur,-k);
		return R;
    }
    
    bool scatter(int k, int maxRow) {
		if(bt(maxRow)<k) return 0;
		while(k) {
			int cur=*alive.begin();
			if(M-C[cur]<=k) {
				alive.erase(alive.begin());
				k-=M-C[cur];
				st.update(cur,0);
				bt.add(cur,-(M-C[cur]));
				C[cur]=M;
			}
			else {
				C[cur]+=k;
				st.update(cur,M-C[cur]);
				bt.add(cur,-k);
				break;
			}
		}
		return 1;
    }
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */
 