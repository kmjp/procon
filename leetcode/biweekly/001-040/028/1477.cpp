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

int L[101010];

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
		int sum=0;
		unordered_map<int,int> M;
		M[0]=0;
		int i;
		FOR(i,arr.size()) {
			sum+=arr[i];
			if(M.count(sum-target)) L[i+1]=i+1-M[sum-target];
			else L[i+1]=(1<<20);
			M[sum]=i+1;
		}
		M.clear();
		sum=0;
		M[0]=arr.size();
		int mi=1<<20,cmi=(1<<20);
		for(i=arr.size()-1;i>=0;i--) {
			mi=min(mi,L[i+1]+cmi);
			sum+=arr[i];
			if(M.count(sum-target)) cmi=min(cmi,M[sum-target]-i);
			M[sum]=i;
		}
		if(mi>1000000) mi=-1;
        return mi;
    }
};

