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

vector<int> V[10101];
class RangeFreqQuery {
public:
    RangeFreqQuery(vector<int>& arr) {
        int i;
        FOR(i,10100) V[i].clear();
        FOR(i,arr.size()) V[arr[i]].push_back(i);
        
    }
    
    int query(int left, int right, int value) {
        return lower_bound(ALL(V[value]),right+1)-lower_bound(ALL(V[value]),left);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
 