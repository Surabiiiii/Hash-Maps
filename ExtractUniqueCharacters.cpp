#include <unordered_map>
string uniqueChar(string str) {
	
    	unordered_map<char,bool> ans;
	int n=str.length();
	string s;
	for(int i=0;i<n;i++)
    {
       if(ans.count(str[i])>0)
        continue;
        ans[str[i]]=true;
        s=s+str[i];
    }

 
    return s;
}
