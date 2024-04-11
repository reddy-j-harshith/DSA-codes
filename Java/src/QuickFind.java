public class QuickFind {

    private int[] id;

    public QuickFind (int N) {
        id = new int[N];
        for(int i = 0 ; i < N ; i++)
            id[i] = i;
    }
    // N-array accesses, which happens only one time when initializing

    public boolean connected(int p, int q){
        return id[p] == id[q];
    }
    // 2 array accesses; constant time

    public void union (int p, int q){
        int pid = id[p];
        int qid = id[q];
        for(int i = 0 ; i < id.length ; i++) {
            if ( id[i] == pid ) { id[i] = qid; }
        }
    }
    // 2N + 2 array accesses, one operation takes time
    // proportional to N which then takes N-squared time
    // to complete for N operations
}
