import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.Stopwatch;
import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class Percolation{

    private WeightedQuickUnionUF id;
    private int size, n, count = 0;
    private boolean[] open;


    public Percolation(int n){
        this.size = n * n + 2;
        this.n = n;
        open = new boolean[size];
        id = new WeightedQuickUnionUF(size);

        open[0] = true;

        for(int i = 1 ; i < size ; i++)
            open[i] = false;

        for(int i = 1; i <= n; i++) {
            id.union(0, i);
            open(1, i);
        }
        for(int i = size - 2; i >= size - n - 1; i--)
            id.union(size - 1, i);

    }

    private int map(int rows, int cols){
        return ((rows - 1) * n) + (cols-1);
    }

    private boolean isValidIndex(int rows, int cols){
        return rows >= 1 && rows <= n && cols >= 1 && cols <= n;
    }

    public void open(int rows, int cols){
        int temp = map(rows, cols);

        if(isValidIndex(rows, cols)) {
            if (!isOpen(rows, cols)){
                count++;
            open[temp] = true;
            }
        }
        else {
            throw new IllegalArgumentException();
        }
        if (rows != 1 && isOpen(rows - 1, cols)){
            id.union(temp, temp - n);
        }
        if (rows != n && isOpen(rows + 1, cols)){
            id.union(temp, temp + n);
        }

        if (cols != n && isOpen(rows, cols + 1)){
            id.union(temp, temp + 1);
        }
        if (cols != 1 && isOpen(rows, cols - 1)){
            id.union(temp, temp - 1);
        }

    }

    public boolean isOpen(int rows, int cols){
        if(isValidIndex(rows, cols)){
            int temp = map(rows, cols);
            return open[temp];
        }
        else {
            throw new IllegalArgumentException();
        }
    }

    public boolean isFull(int rows, int cols){
        if (isValidIndex(rows, cols)) {
            int temp = map(rows, cols);
            return id.find(temp) == id.find(0);
        }
        else {
            throw new IllegalArgumentException();
        }
    }

    public int numberOfOpenSites(){
        return count;
    }

    public boolean percolates(){
        return id.find(0) == id.find(size - 1);
    }

    public static void main(String[] args){
        //int n = Integer.parseInt(args[0]);
        int n = 8000;
        Percolation test = new Percolation(n);
        Stopwatch watch = new Stopwatch();
        while (!test.percolates()){
            int randRow = StdRandom.uniformInt(1, n + 1);
            int randCol = StdRandom.uniformInt(1, n + 1);
            test.open(randRow, randCol);
        }
        double time = watch.elapsedTime();
        int size = n * n;
        int open = test.numberOfOpenSites();
        StdOut.print((double)open / size+" time: "+time);
    }

}