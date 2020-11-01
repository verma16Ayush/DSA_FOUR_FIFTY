

class Solution {
    
    public int[][] merge(int[][] arr) {
        if(arr.length==0)
           return arr;
        
        int n=arr.length;
        
        Arrays.sort(arr, new Comparator<int[]>()
            {
                @Override
                public int compare(int a[],int b[])
                {
                    return Integer.compare(a[0],b[0]);
                }
            });
        
        Stack<Pair>st=new Stack<>();
        st.push(new Pair(arr[0][0],arr[0][1]));
        for(int i=1;i<n;++i)
        {
            if(arr[i][0]<=st.peek().b)
            {
                Pair p=st.pop();
                st.push(new Pair(p.a,Math.max(p.b,arr[i][1])));
            }
            else
                st.push(new Pair(arr[i][0],arr[i][1]));
        }
        
        int brr[][]=new int[st.size()][2];
        int i=0;
        for(Pair p:st)
        {
            brr[i][0]=p.a;
            brr[i][1]=p.b;
            ++i;
        }
        return brr;
    
        
    
        
        
    }
}

 public class Pair
{
    int a,b;
    Pair(int a,int b)
    {
        this.a=a;
        this.b=b;
    }
}