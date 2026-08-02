import java.util.*;
public class MergeSortedArray {
    
    public static void mergesortedArray(int nums1[], int nums2[], int m, int n){
        int i=m-1;
        int j = n-1;
        int x = m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i]<nums2[j]){
                nums1[x] = nums2[j];
                x--; j--;
            }else{
                nums1[x] = nums1[i];
                x--;
                i--;
            }
        }
        while(j>=0){
            nums1[x]=nums2[j];
            x--;j--;
        }
        for(int k=0; k<nums1.length; k++){
            System.out.print(nums1[k]+" ");
        }
    }

    public static void main(String args[]){
        int m=3, n=3;
        int nums1[] = new int[6];
        int nums2[] = new int [3];
        nums1[0] = 1;
        nums1[1] = 2;
        nums1[2] = 3;
        nums1[3] = 0;
        nums1[4] = 0;
        nums1[5] = 0;
        
        nums2[0] = 2;
        nums2[1] = 5;
        nums2[2] = 6;

        mergesortedArray(nums1,nums2,m,n);
    }
}
