public class TriangleScenario {

    public static double area(int x1, int y1, int x2, int y2, int x3, int y3) {
        return Math.abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;
    }

    public static boolean isInside(int x1, int y1, int x2, int y2, int x3, int y3, int px, int py) {
        double A = area(x1, y1, x2, y2, x3, y3);
        double A1 = area(px, py, x2, y2, x3, y3);
        double A2 = area(x1, y1, px, py, x3, y3);
        double A3 = area(x1, y1, x2, y2, px, py);
        
        return (A == A1 + A2 + A3);
    }

    public static int pointsBelong(int x1, int y1, int x2, int y2, int x3, int y3, int xp, int yp, int xq, int yq) {
        double A = area(x1, y1, x2, y2, x3, y3);

        if (A == 0) {
            return 0;
        }

        boolean pInside = isInside(x1, y1, x2, y2, x3, y3, xp, yp);
        boolean qInside = isInside(x1, y1, x2, y2, x3, y3, xq, yq);

        if (pInside && qInside) {
            return 3;
        } else if (pInside) {
            return 1;
        } else if (qInside) {
            return 2;
        } else {
            return 4;
        }
    }

    public static void main(String[] args) {
        // Example usage
        int x1 = 3, y1 = 1, x2 = 7, y2 = 1, x3 = 5, y3 = 5;
        int xp = 3, yp = 1, xq = 0, yq = 0;

        int scenario = pointsBelong(x1, y1, x2, y2, x3, y3, xp, yp, xq, yq);
        System.out.println("Scenario: " + scenario); // Expected output: 1
    }
}
