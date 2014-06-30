public class Stencil {
    private int n;
    private int[][] in;
    private int[][] out;

    Stencil(int n) {
        this.n = n;
        this.in = new int[n][n];
        this.out = new int[n][n];
    }

    public void compute() {
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                out[i][j] =
                    in[i-1][j-1] + in[i-1][j] + in[i-1][j+1] +
                    in[i  ][j-1] + in[i  ][j] + in[i  ][j+1] +
                    in[i+1][j-1] + in[i+1][j] + in[i+1][j+1];
            }
        }
    }
}
