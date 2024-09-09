import java.util.*;

public class Solution {

    public static List<Long> maxMin(List<String> operations, List<Integer> x) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        
        Map<Integer, Integer> frequencyMap = new HashMap<>();

        List<Long> result = new ArrayList<>();

        for (int i = 0; i < operations.size(); i++) {
            String operation = operations.get(i);
            int value = x.get(i);

            if (operation.equals("push")) {
                minHeap.offer(value);
                maxHeap.offer(value);
                frequencyMap.put(value, frequencyMap.getOrDefault(value, 0) + 1);
            } else if (operation.equals("pop")) {
                frequencyMap.put(value, frequencyMap.get(value) - 1);
            }

	            while (!minHeap.isEmpty() && frequencyMap.get(minHeap.peek()) == 0) {
                minHeap.poll();
            }

            while (!maxHeap.isEmpty() && frequencyMap.get(maxHeap.peek()) == 0) {
                maxHeap.poll();
            }

            if (!minHeap.isEmpty() && !maxHeap.isEmpty()) {
                int minVal = minHeap.peek();
                int maxVal = maxHeap.peek();
                result.add((long) minVal * maxVal);
            }
        }

        return result;
    }

    public static void main(String[] args) {
        // Example usage
        List<String> operations = Arrays.asList("push", "push", "push", "pop", "push");
        List<Integer> x = Arrays.asList(1, 2, 3, 1, 5);

        List<Long> results = maxMin(operations, x);

        for (Long res : results) {
            System.out.println(res);
        }
    }
}
