typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))

//-------------------------------------------------------


static int const def=1<<30;
template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=comp(v,val[entry]); //上書きかチェック
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

int need[101010];
ll W[101010];
int dp[101010];

class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
		SegTree_1<int,1<<18> st;
        int ret=0;
        int i,j=0;
		ZERO(need);
		FOR(i,boxes.size()) {
			W[i+1]=W[i]+boxes[i][1];
		}
		for(i=boxes.size()-2;i>=0;i--) {
			need[i]=need[i+1];
			if(boxes[i][0]!=boxes[i+1][0]) need[i]++;
		}
		
		dp[0]=0;
		st.update(0,dp[0]+need[0]);
		
		j=0;
		for(i=1;i<=boxes.size();i++) {
			while(i-j>maxBoxes) j++;
			while(W[i]-W[j]>maxWeight) j++;
			dp[i]=st.getval(j,i)-need[i-1]+2;
			st.update(i,dp[i]+need[i]);
		}
		return dp[boxes.size()];
		
		
    }
};
