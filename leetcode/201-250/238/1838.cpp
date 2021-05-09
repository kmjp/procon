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


class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
		map<int,int> M;
		FORR(n,nums) M[n]++;
		vector<pair<int,int>> V;
		FORR(m,M) V.push_back(m);
		int ret=0;
		
		int i,j;
		FOR(i,V.size()) {
			int lef=k;
			int num=V[i].second;
			int tar=V[i].first;
			for(j=i-1;j>=0;j--) {
				int cnt=min(V[j].second,lef/(tar-V[j].first));
				if(cnt==0) break;
				lef-=cnt*(tar-V[j].first);
				num+=cnt;
			}
			ret=max(ret,num);
		}
		return ret;
		
        
    }
};
