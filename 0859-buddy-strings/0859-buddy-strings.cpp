class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int arr[26]={0};
        for(int i=0;i<s.length();i++)
        {
            arr[s[i]-'a']++;
        }
        for(int i=0;i<goal.length();i++)
        {
            arr[goal[i]-'a']--;
        }
        
        for(int i:arr)
        {
            if(i!=0){return false;}
        }
        int first=-1,second=-1;
        int count=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=goal[i])
            {
                if(count==0){first=i;count++;}
                else if(count==1){second=i;count++;}
                else if(count==2){return false;}
            }
        }
        if(count==0) 
        {
            for(int i=0;i<s.length();i++)
            {
                arr[s[i]-'a']++;
            }
            for(int i:arr)
            {
                if(i>=2){return true;}
            }   
            return false;
        }
        else
        {
            char temp=s[first];
            s[first]=s[second];
            s[second]=temp;
            if(s==goal){return true;}
            return false;
        }
        return true;
        
    }
};