class Solution {
public:
    bool isAlphanumeric(char a)
    {
        if(((a <= 'z') && (a >= 'a')) || ((a <= 'Z')&&(a >= 'A')) || isdigit(a))
           return true;
        
        return false;
    }
    bool isPalindrome(string s) {
        
        int i=0, j=s.length()-1;
        while(i<j)
        {
            if(!isAlphanumeric(s[i]))
            {
                i++;
                continue;
            }
            if(! isAlphanumeric(s[j]))
            {
                j--;
                continue;
            }
            if(tolower(s[i]) != tolower(s[j]))
               return false;
            
            i++;
            j--;

        }

        return true;
    }
};