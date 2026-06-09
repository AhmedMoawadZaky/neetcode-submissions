class Solution {
public:
    bool isPalindrome(int x) 
    {
        int reversed = 0 , y = x;
        if(x < 0)
        {
            return false;
        }

        while(x)
        {
            reversed = (reversed * 10) + (x % 10);
            x /= 10;
        }
        return reversed == y;
    }
};