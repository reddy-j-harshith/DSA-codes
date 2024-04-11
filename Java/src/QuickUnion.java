public class QuickUnion {
    private int[] id;
    private int count;

    public QuickUnion (int N){
        this.count = N;
        id = new int[N];
        for(int i = 0 ; i < N ; i++){
            id[i] = i;
        }
    }
    // N-array accesses for initialization

    public boolean connected (int p, int q){
        return root(p) == root(q);
    }
    //check if p and q have same root
    //(depth of p and q array accesses)

    private int root(int p){
        while(p != id[p]){ p = id[p]; } return p;
    }
    // chase parent pointers until reach root
    // (depth of i array accesses)

    public void union (int p, int q) {
        int i = root(p);
        int j = root(q);
        if ( i != j ) {
            count--;
            id[i] = j;
        }
    }
    // The worst-case time takes around N array for one operation
    // the trees can get too tall and the root method has to undergo
    // N iterations to find the root of the node.

    public int count(){ return count; }
    //Constant time, as the count variable
    // was implicitly implemented along with union.
}
