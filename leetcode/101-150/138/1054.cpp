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
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
		vector<int> R(barcodes.size(),-1);
        map<int,int> B;
        vector<pair<int,int>> V;
        FORR(b,barcodes) B[b]++;
        FORR(b,B) V.push_back({b.second,b.first});
        sort(ALL(V));
        reverse(ALL(V));
        int cur=0;
        int i;
        FORR(v,V) {
			FOR(i,v.first) {
				R[cur]=v.second;
				cur+=2;
				if(cur>=R.size()) {
					cur=0;
					if(R[cur]!=-1) cur++;
				}
			}
		}
        return R;
        
    }
};

