import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;

public class Day1 {
    static List<String> input;
    static int result = 0;

    public static void main(String[] args) {
        String filePath = "./input.txt";
        Path path = Paths.get(filePath);

        try {
            input = Files.readAllLines(path);
        } catch (IOException e) {
            e.printStackTrace();
        }

        part1(input);
        part2(input);
    }

    static void part1(List<String> input) {
        int counter = 0;
        for (String line : input) {
            int keyCount = 0;

            String[] parts = line.split(": ");
            String[] split = parts[0].split(" ");

            String[] bounds = split[0].split("-");
            int min = Integer.parseInt(bounds[0]);
            int max = Integer.parseInt(bounds[1]);
            char key = split[1].charAt(0);
            String password = parts[1];

            for (char c : password.toCharArray()) {
                if (c == key) {
                    keyCount++;
                }
            }

            if (keyCount >= min && keyCount <= max) {
                counter++;
            }

        }
        System.out.println(counter);
    }

    static void part2(List<String> input) {
        int counter = 0;
        for (String line : input) {

            String[] parts = line.split(": ");
            String[] split = parts[0].split(" ");

            String[] bounds = split[0].split("-");
            int min = Integer.parseInt(bounds[0]);
            int max = Integer.parseInt(bounds[1]);
            char key = split[1].charAt(0);
            String password = parts[1];

            if (password.charAt(min - 1) == key ^ password.charAt(max - 1) == key) {
                counter++;
            }

        }
        System.out.println(counter);
    }
}