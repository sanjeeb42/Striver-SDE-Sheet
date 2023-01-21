 int minVal(int a, int b) {
        // code here
        int cnt_a=0,cnt_b=0;
        for(int i=0;i<32;i++)
        {
            if((b & (1<<i))!=0)cnt_b++;
            if((a&(1<<i))!=0)cnt_a++;
        }
        
      //  cout<<cnt_a<<" and "<<cnt_b<<endl;
        if(cnt_a==cnt_b)return a;
        
        else if(cnt_a>cnt_b){
            int diff=cnt_a-cnt_b;
            for(int i=0;i<32;i++){
                int is_set=(a&(1<<i));
                if(is_set)
                {
                    if(diff>0){
                        a-=is_set;
                        diff--;
                    }
                }
                
            }
            
            return a;
        }
        else if(cnt_a<cnt_b){
            int diff=cnt_b-cnt_a;
            for(int i=0;i<32;i++){
                int is_set=(a&(1<<i));
                if(is_set==0)
                {
                    if(diff>0){
                        a+=(1<<i);
                    }
                    diff--;
                }
            }
            return a;
        }
       
    }
