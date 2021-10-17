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


vector<int> P,M,O;
int Z;
ll K;

class Solution {
public:
	ll hoge(ll v) {
		ll ret=0;
		if(v>=0) {
			ret+=1LL*Z*O.size();
		}
		
		int R=-1;
		FORR(a,P) {
			while(R<(int)O.size()-1&&1LL*a*O[R+1]<=v) R++;
			while(R!=-1&&1LL*a*O[R]>v) R--;
			while(R<(int)O.size()-1&&1LL*a*O[R+1]<=v) R++;
			while(R!=-1&&1LL*a*O[R]>v) R--;
			ret+=R-(-1);
		}
		R=0;
		FORR(a,M) {
			while(R>0&&1LL*a*O[R-1]<=v) R--;
			while(R!=(int)O.size()&&1LL*a*O[R]>v) R++;
			while(R>0&&1LL*a*O[R-1]<=v) R--;
			while(R!=(int)O.size()&&1LL*a*O[R]>v) R++;
			ret+=O.size()-R;
		}
		return ret;
	}
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
		int i;
		P.clear();
		M.clear();
		Z=0;
		FORR(a,nums1) {
			if(a>0) P.push_back(a);
			if(a<0) M.push_back(a);
			if(a==0) Z++;
		}
		O=nums2;
		
		ll ret=(1LL<<36);
		for(i=36;i>=0;i--) if(hoge(ret-(1LL<<i))>=k) ret-=1LL<<i;
		return ret;
		
		
		
		
        
    }
};


