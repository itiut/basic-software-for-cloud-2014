public class Main {
    public static void main(String[] args) {
        int trial = 10;
        int n = 10000;
        if (args.length > 0) {
            trial = Integer.parseInt(args[0]);
        }
        if (args.length > 1) {
            n = Integer.parseInt(args[1]);
        }

        for (int i = 0; i < trial; i++) {
            long t0 = System.nanoTime();
            Stencil stencil = new Stencil(n);
            long t1 = System.nanoTime();
            stencil.compute();
            long t2 = System.nanoTime();
            System.out.format("%2d %f %f%n", i + 1, (t1 - t0) / 1e9, (t2 - t1) / 1e9);
            // System.gc();
        }
    }
}
