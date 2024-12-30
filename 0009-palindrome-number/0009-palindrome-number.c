bool isPalindrome(int x){
    if(x<0)
        return false;
    else
    {
        long long int rev=0, n, rem;
        n=x;
        while(n!=0)
        {
            rem=n%10;
            n=n/10;
            rev=rev*10+rem;
        }
        if(rev==x)
            return true;
        else 
            return false;
    }      
}

