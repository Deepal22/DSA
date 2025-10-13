class Solution {
public:
bool f(string str1, string str2) {

    if (str1.length() != str2.length())
        return false;

   sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    return str1 == str2;}
    vector<string> removeAnagrams(vector<string>& w) {
        int a=0;vector<string>v;
        for(int i=1;i<w.size();i++){
            if(f(w[a],w[i])){
                w[i]="1";
            }
            else {
                a=i;
            }
        }
        for(int i=0;i<w.size();i++){
            if(w[i]!="1")v.push_back(w[i]);
        }
        return v;
    }
};