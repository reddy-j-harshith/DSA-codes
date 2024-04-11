import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;
import edu.princeton.cs.algs4.Stopwatch;

public class PercolationStats {

    private final double[] data;
    private double mean, stdDev;

    private final double CONFIDENCE_95 = 1.96;

    private final int trials;
    // perform independent trials on an n-by-n grid
    public PercolationStats(int n, int trials) {
        this.trials = trials;
        data = new double[trials];

        for (int i = 0; i < trials; i++) {
            Percolation percolation = new Percolation(n);

            // Open sites and calculate percolation threshold
            while (!percolation.percolates()) {
                int row = StdRandom.uniform(1, n + 1);
                int col = StdRandom.uniform(1, n + 1);
                percolation.open(row, col);
            }

            int open = percolation.numberOfOpenSites();
            double p = (double) open / (n * n);
            data[i] = p;
        }
    }


    // sample mean of percolation threshold
    // sample mean of percolation threshold
    public double mean() {
        mean = StdStats.mean(data);
        return mean;
    }


    // sample standard deviation of percolation threshold
    public double stddev() {
        stdDev = StdStats.stddev(data);
        return stdDev;
    }

    // low endpoint of 95% confidence interval
    public double confidenceLo() {
        return mean - (CONFIDENCE_95*stdDev)/Math.sqrt(trials);
    }

    // high endpoint of 95% confidence interval
    public double confidenceHi() {
        return mean + (CONFIDENCE_95*stdDev)/Math.sqrt(trials);
    }

    // test client (see below)
    public static void main(String[] args) {
//        int n = Integer.parseInt(args[0]);
//        int trials = Integer.parseInt(args[1]);
        int n = 1000, trials = 10000;
        Stopwatch watch = new Stopwatch();
        PercolationStats stats = new PercolationStats(n, trials);
        double time = watch.elapsedTime();
        System.out.println("mean\t\t= " + stats.mean());
        System.out.println("stddev\t\t= " + stats.stddev());
        System.out.println("95% confidence interval = [" + stats.confidenceLo() + ", " + stats.confidenceHi() + "]");
        System.out.println("time\t\t= "+time);
    }
}