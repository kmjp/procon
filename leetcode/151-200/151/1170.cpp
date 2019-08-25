
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
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
		int C[11]={};
		FORR(w,words) {
			char mi='z'+1;
			int num=0;
			FORR(c,w) {
				if(c<mi) mi=c,num=0;
				if(c==mi) num++;
			}
			C[num]++;
		}
		
		vector<int> R;
		FORR(q,queries) {
			char mi='z'+1;
			int num=0;
			FORR(c,q) {
				if(c<mi) mi=c,num=0;
				if(c==mi) num++;
			}
			int ret=0,i;
			for(i=num+1;i<=10;i++) ret+=C[i];
			R.push_back(ret);
		}
		return R;
        
    }
};