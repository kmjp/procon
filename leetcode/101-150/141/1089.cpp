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
    void duplicateZeros(vector<int>& arr) {
        vector<int> V=arr;
        arr.clear();
        FORR(v,V) {
			arr.push_back(v);
			if(v==0) arr.push_back(v);
		}
		arr.resize(V.size());
		
        
    }
};

