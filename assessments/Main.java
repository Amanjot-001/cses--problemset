import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) {
        String s = "hello";
        char k = 'l';

        int consecLen = 0;
        int maxConsec = 0;
        List<Integer> lengths = new ArrayList<>();

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch == k) {
                consecLen++;
            } else if (consecLen != 0) {
                lengths.add(consecLen);
                maxConsec = Math.max(consecLen, maxConsec);
                consecLen = 0;
            }
        }

        if (consecLen != 0) {
            lengths.add(consecLen);
            maxConsec = Math.max(consecLen, maxConsec);
        }

        int ans = 0;
        boolean maxUsed = false;
        for (int len : lengths) {
            if (!maxUsed && len == maxConsec) {
                maxUsed = true;
            } else {
                ans += len;
            }
        }

        System.out.println(ans);
    }
}
