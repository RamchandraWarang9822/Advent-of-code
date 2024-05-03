import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;

public class Day3 {
    static List<String> input;
    static long result = 1;

    public static void main(String[] args) {
        String filePath = "./input.txt";
        Path path = Paths.get(filePath);

        try {
            input = Files.readAllLines(path);
        } catch (IOException e) {
            e.printStackTrace();
        }

        part2(input);
    }

    static void part1(List<String> input) {
        int len = input.get(0).length();
        for (int i = 1; i < input.size(); i++) {
            int rightMove = (i * 3) % len;
            char c = input.get(i).charAt(rightMove);
            if (c == '#') {
                result++;
            }
        }
        System.out.println(result);
    }

    static void part2(List<String> input) {
        int[] slope = { 1, 3, 5, 7 };
        int[] coord = { 0, 0, 0, 0 };
        int[] results = { 0, 0, 0, 0 };
        int len = input.get(0).length();
        for (int i = 1; i < input.size(); i++) {

            for (int j = 0; j < 4; j++) {
                coord[j] = (i * slope[j]) % len;
                char c = input.get(i).charAt(coord[j]);
                if (c == '#') {
                    results[j]++;
                }
            }
        }

        for (int i : results) {
            System.out.println(i);
            result *= i;
        }

        int rightMove = 0;
        int counter = 0;
        for (int i = 2; i < input.size(); i += 2) {
            rightMove = (rightMove + 1) % len;
            char c = input.get(i).charAt(rightMove);
            if (c == '#') {
                counter++;
            }
        }
        System.out.println(counter);
        result *= counter;
        System.out.println(result);

    }
}
