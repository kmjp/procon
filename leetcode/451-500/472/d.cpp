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

template<class V,int NV> class SegTree_2 {
public:
	vector<V> val,mi,ma;
	
	SegTree_2(){val.resize(NV*2); mi.resize(NV*2); ma.resize(NV*2);}
	
	int getval(int L,int R,int k) {
		if(mi[k]>0||ma[k]<0) return 1<<20;
		if(L+1==R) return L;
		val[2*k]+=val[k];
		val[2*k+1]+=val[k];
		mi[2*k]+=val[k];
		mi[2*k+1]+=val[k];
		ma[2*k]+=val[k];
		ma[2*k+1]+=val[k];
		val[k]=0;
		int M=(L+R)/2;
		
		if(mi[2*k]<=0&&0<=ma[2*k]) return getval(L,M,2*k);
		else if(mi[2*k+1]<=0&&0<=ma[2*k+1]) return getval(M,R,2*k+1);
		assert(0);
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k]+=v;
			mi[k]+=v;
			ma[k]+=v;
		}
		else if(l < y && x < r) {
			val[2*k]+=val[k];
			val[2*k+1]+=val[k];
			mi[2*k]+=val[k];
			mi[2*k+1]+=val[k];
			ma[2*k]+=val[k];
			ma[2*k+1]+=val[k];
			val[k]=0;
			
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			mi[k]=min(mi[2*k],mi[2*k+1]);
			ma[k]=max(ma[2*k],ma[2*k+1]);
		}
	}
};
SegTree_2<int,1<<17> st;


class Solution {
public:
    int longestBalanced(vector<int>& nums) {
			map<int,int> pre;
			int ret=0;
			int i;
			
			int N=nums.size();
			FOR(i,N) {
				int d=(nums[i]%2)?1:-1;
				st.update(pre[nums[i]],i+1,d);
				pre[nums[i]]=i+1;
				
				int x=st.getval(0,1<<17,1);
				ret=max(ret,i+1-x);
			}
			
			
			FORR2(a,b,pre) {
				int d=(a%2)?1:-1;
				st.update(0,b,-d);
			}
			
			return ret;
			
			
			
        
    }
};

