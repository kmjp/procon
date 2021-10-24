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
	vector<string> split(const string &str, char delim=' '){
		vector<string> res;
		size_t current = 0, found;
		while((found = str.find_first_of(delim, current)) != string::npos){
			res.push_back(string(str, current, found - current));
			current = found + 1;
		}
		res.push_back(string(str, current, str.size() - current));
		return res;
	}
    int countValidWords(string sentence) {
		vector<string> V=split(sentence);
		int ret=0;
		FORR(v,V) {
			if(v.empty()) continue;
			int h=0;
			int i;
			FOR(i,v.size()) {
				if(v[i]>='0'&&v[i]<='9') h+=3;
				if(v[i]=='-') {
					h++;
					if(i==0||i+1==v.size()) h++;
					else {
						if(v[i-1]<'a'||v[i-1]>'z') h++;
						if(v[i+1]<'a'||v[i+1]>'z') h++;
					}
				}
				if(v[i]=='!'||v[i]=='.'||v[i]==',') {
					if(i+1!=v.size()) h+=3;
				}
			}
			cout<<v<<" "<<h<<endl;
			if(h<=1) ret++;
		}
        return ret;
    }
};
