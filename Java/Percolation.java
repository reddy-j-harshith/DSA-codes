import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.WeightedQuickUnionUF;


public class Percolation {

    private boolean[] opened;
    private int n, open = 0;
    private WeightedQuickUnionUF uf;
    private final int start = 0, end;
    // creates n-by-n grid, with all sites initially blocked
    public Percolation(int n) {
        opened = new boolean[n*n + 2];
        this.n = n;
        end = n*n + 1;
        opened[0] = true;
        opened[n*n + 1] = true;
        uf = new WeightedQuickUnionUF(n*n+2);

        for (int i = 1; i <= n; i++) {
            int cur = i;
            uf.union(start, i);
            uf.union(end, n*n - n +i);
        }

    }

    // opens the site (row, col) if it is not open already
    public void open(int row, int col) {
        if (!isOpen(row, col)) {
            int temp = n * (row - 1) + col;
            opened[temp] = true;
            open++;
        }
        int cur = n*(row-1) + col;
        if (row != 1 && isOpen(row-1, col)) {
            uf.union(cur, cur-n);
        }
        if (row != n && isOpen(row+1, col)) {
            uf.union(cur, cur+n);
        }
        if (col != 1 && isOpen(row, col-1)) {
            uf.union(cur, cur-1);
        }
        if (col != n && isOpen(row, col+1)) {
            uf.union(cur, cur+1);
        }
    }

    // is the site (row, col) open?
    public boolean isOpen(int row, int col) {
        int temp = n * (row-1) + col;
        return opened[temp];
    }

    // is the site (row, col) full?
    public boolean isFull(int row, int col) {
        int temp = n * (row-1) + col;
        return uf.find(0) == uf.find(temp);
    }

    // returns the number of open sites
    public int numberOfOpenSites() {
        return open;
    }

    // does the system percolate?
    public boolean percolates() {
        return uf.find(0) == uf.find(end);
    }

    // test client (optional)
    public static void main(String[] args) {
        int n = 20;
//        n = Integer.parseInt(args[0]);
        Percolation percolation = new Percolation(n);

//        int open = percolation.numberOfOpenSites();
//        System.out.println("p* = "+(double) open/(n*n));
//

    }
}