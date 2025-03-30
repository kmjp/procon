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

int N;
int S[101010];

int L[1010101],L2[101010];
int R[1010101];
int ma[1010101];

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=0;
	// static V const def=1LL<<60; min
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<int,1<<20> st;

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
		vector<int> cand;
        N=s.size();
        int i,j;
        FOR(i,N) S[i+1]=S[i]+(s[i]=='1');
        FOR(i,N) {
			st.update(i,-1000000);
			if(i&&s[i-1]=='0'&&s[i]=='1') {
				cand.push_back(i);
				int num=0;
				for(j=i-1;j>=0;j--) {
					if(s[j]=='1') break;
					num++;
					L[i]=j;
				}
				for(j=i;j<N;j++) if(s[j]=='0') break;
				L2[i]=j-1;
				if(j<N) {
					for(;j<N;j++) {
						if(s[j]=='1') break;
						num++;
						R[i]=j;
					}
					st.update(i,num);
					
				}
			}
		}
        
        
        vector<int> ret;
        FORR(q,queries) {
			int X=q[0],Y=q[1];
			Y++;
			if(S[Y]-S[X]==Y-X || S[Y]-S[X]==0) {
				ret.push_back(S[N]-S[0]);
				continue;
			}
			int a=lower_bound(ALL(cand),X)-cand.begin();
			int b=lower_bound(ALL(cand),Y)-cand.begin();
			int r=0;
			if(a+1==b) {
				if(cand[a]>X&&L2[cand[a]]<Y-1) {
					r=Y-X-(S[Y]-S[X]);
				}
			}
			else if(b-a>=2) {
				if(b-a>=3) {
					r=max(r,st.getval(cand[a+1],cand[b-1]));
				}
				a=cand[a];
				b=cand[b-1];
				if(a>max(L[a],X)) {
					r=max(r,R[a]-L2[a]+a-max(L[a],X));
				}
				if(L2[b]<min(R[b],Y-1)) r=max(r,min(R[b],Y-1)-L2[b]+b-L[b]);
			}
			ret.push_back(S[N]-S[0]+r);
			
		}
		return ret;
        
    }
};

