//faltu Constrains -
//wasted 2 hours 


double findNthRootOfM(int n, long long m) {
    // Write your code here. 
   long  double low = 0, high = m;
   long double ans;
   long double eps=1e-9;
    while (high-low>eps)
    {
        // cnt++;
       long double mid = low + (high - low) / 2;
        //  cout << "Low and high: " << low << " " << high << endl;
        if (pow(mid,n)<=double(m))
        {
          //  ans = mid;
            low = mid ;
        } 
        else
        {
            high = mid ;
        }
    }

    return low;
    
}



