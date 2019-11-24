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
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
		sort(ALL(products));
		vector<vector<string>> R;
		int i,j;
		int cur=0;
		for(i=1;i<=searchWord.size();i++) {
			while(cur<products.size()) {
				if(products[cur].size()<i) {
					cur++;
					continue;
				}
				if(products[cur].substr(0,i)<searchWord.substr(0,i)) {
					cur++;
					continue;
				}
				if(products[cur].substr(0,i)==searchWord.substr(0,i)) {
					break;
				}
				if(products[cur].substr(0,i)>searchWord.substr(0,i)) {
					break;
				}
			}
			vector<string> V;
			FOR(j,3) {
				if(cur+j<products.size() && products[cur+j].size()>=i && products[cur+j].substr(0,i)==searchWord.substr(0,i)) {
					V.push_back(products[cur+j]);
				}
			}
			R.push_back(V);
			
		}
		return R;
		
		
        
    }
};
