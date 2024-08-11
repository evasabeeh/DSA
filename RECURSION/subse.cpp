void printSub(int i, string str, vector<char>&ans){
    if(i>=str.size()){
        for(char i: ans)
        cout<<i;
        cout<<endl;
        return;
    }
    ans.push_back(str[i]);
    printSub(i+1, str, ans);   //take
    ans.pop_back();
    printSub(i+1, str, ans);   //not take
}