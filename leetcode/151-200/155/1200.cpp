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
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(ALL(arr));
        int i,N=arr.size();
        int mi=1<<30;
        FOR(i,N-1) mi=min(mi,arr[i+1]-arr[i]);
        vector<vector<int>> V;
        FOR(i,N-1) if(mi==arr[i+1]-arr[i]) V.push_back({arr[i],arr[i+1]});
        return V;
    }
};
