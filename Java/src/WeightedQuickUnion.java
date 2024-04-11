public class WeightedQuickUnion {

    private int[] id, sz;
    public WeightedQuickUnion(int N){
        id = new int[N];
        sz = new int[N];
        for(int i = 0 ; i < N ; i++)
            id[i] = i;

        for(int i = 0 ; i < N ; i++)
            sz[0] = 1;
    }

    private int root(int p){
        while (p != id[p]){
            id[p] = id[id[p]]; // path compression for flattening the tree
            p = id[p];
        }
        return p;
    }

    public boolean connected(int p, int q){
        return root(p) == root(q);
    }
    // One operation could take time proportional to Lg N
    // as the Depth of any node x is at most lg N

    public void union(int p, int q){
        int i = root(p);
        int j = root(q);
        if (sz[i] <= sz[j]) { id[i] = j; sz[j] += sz[i]; }
        else                { id[j] = i; sz[i] += sz[j]; }
    }
}
