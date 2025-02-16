#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

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

vector<int> X;

template<class V,int NV> class SegTree_3 {
public:
	vector<V> cnt, len;
	SegTree_3(){
		int i;
		cnt.resize(NV*2,0); len.resize(NV*2,0);
	};
	
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r||y<=x) return;
		if(x<=l && r<=y) {
			cnt[k]+=v;
			if(cnt[k]>=1) {
				len[k]=X[r]-X[l];
			}
			else {
				if(r-l==1) {
					len[k]=0;
				}
				else {
					len[k]=len[2*k]+len[2*k+1];
				}
			}
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			if(cnt[k]>=1) {
				len[k]=X[r]-X[l];
			}
			else {
				len[k]=len[2*k]+len[2*k+1];
			}
		}
	}
};
SegTree_3<int,1<<17> st;

class Solution {
public:
	
	double separateSquares(vector<vector<int>>& squares) {
		X.clear();
		FORR(a,squares) {
			X.push_back(a[0]);
			X.push_back(a[0]+a[2]);
		}
		sort(ALL(X));
		X.erase(unique(ALL(X)),X.end());
		
		vector<array<int,4>> ev;
		FORR(a,squares) {
			int x1=lower_bound(ALL(X),a[0])-X.begin();
			int x2=lower_bound(ALL(X),a[0]+a[2])-X.begin();
			ev.push_back({a[1],x1,x2,1});
			ev.push_back({a[1]+a[2],x1,x2,-1});
		}
		sort(ALL(ev));
		double ret=-1;
		int prey=0;
		double sum=0,sum2=0;
		FORR(e,ev) {
			int cury=e[0];
			int le=st.len[1];
			sum+=1LL*(cury-prey)*le;
			st.update(e[1],e[2],e[3]);
			prey=cury;
		}
		prey=0;
		FORR(e,ev) {
			int cury=e[0];
			int le=st.len[1];
			if(ret<0&&sum2+1LL*(cury-prey)*le>=sum/2) {
				double L=prey,R=cury;
				int i;
				FOR(i,100) {
					double M=(L+R)/2;
					double tmp=sum2+(M-prey)*le;
					if(tmp<=sum/2) L=M;
					else R=M;
				}
				ret=L;
			}
			sum2+=1LL*(cury-prey)*le;
			st.update(e[1],e[2],e[3]);
			prey=cury;
		}
		
        return ret;
    }
};

