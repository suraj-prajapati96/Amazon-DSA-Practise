import java.util.*;
@SuppressWarnings("unchecked")

public class CourseSchedule{
    public static boolean canFinish(int n, int [][] prerequisites){
        ArrayList<Integer>[]adj = new ArrayList[n];
        int [] indegree = new int[n];
        Queue<Integer> queue = new LinkedList<>();
        for(int i=0; i<n; i++){
            adj[i] = new ArrayList<Integer>();
        }
        for(int [] x:prerequisites){
            adj[x[1]].add(x[0]);
            indegree[x[0]]++;
        }
        for(int i=0; i<n; i++){
            if(indegree[i]==0){
                queue.add(i);
            }
        }
        int count = 0;
        while(!queue.isEmpty()){
            int c = queue.poll();
            count++;
            for(int j:adj[c]){
                if(--indegree[j] == 0){
                    queue.add(j);
                }
            }
        }
        return count==n;
    }
    public static void main(String args[]){
        int n=4;
        int [][] arr =new  int [n][n];
        arr[0][0] = 1;
        arr[0][1] = 0;
        arr[1][0] = 2;
        arr[1][1] = 0;
        arr[2][0] = 3;
        arr[2][1] = 1;
        arr[3][0] = 0;
        arr[3][1] = 3;

        System.out.println(canFinish(n,arr));
    }
}