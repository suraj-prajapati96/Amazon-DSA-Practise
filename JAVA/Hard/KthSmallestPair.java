import java.util.*;

public class KthSmallestPair{
    public static int smallestDistancePair(int arr[], int k){
        Arrays.sort(arr);
        int n = arr.length;

        int l=0;
        int r = arr[n-1] - arr[0];
        while(l<r){
            int mid = l + (r-l)/2;
            int cnt =0;
            for(int i=0, j=0; i<n; i++){
                while(j<n && arr[j]-arr[i]<=mid){
                    j++;
                }
                cnt += j-i-1;
            }
            if(cnt<k){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        return l;
    }
    public static void main(String args[]){
        int arr [] = {1,6,1};
        System.out.println(smallestDistancePair(arr,3));
    }
}