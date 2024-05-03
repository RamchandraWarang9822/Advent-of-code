import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.HashSet;
import java.util.List;

public class Day4 {
    static List<String> input;
    static int result = 0;

    public static void main(String[] args) {
        String filePath = "example.txt";
        Path path = Paths.get(filePath);

        try {
            input = Files.readAllLines(path);
        } catch (IOException e) {
            e.printStackTrace();
        }

        part1(input);
    }

    static void part1(List<String> input) {
        HashSet<String> hs = new HashSet<>();

        for (String line : input) {
            if (line.trim().isEmpty()) {
                // if (hs.size() == 7) {
                //     if (hs.contains("cid")) {
                //         System.out.println("Invalid");
                //     } else {
                //         System.out.println("Valid Passport");
                //     }
                // } if ((hs.size() < 8)) {
                //     System.out.println("Invalid");
                // } else if (hs.size() == 8) {
                //     System.out.println("Valid Passport");
                // }
                System.out.println("--------------------------");
                hs = new HashSet<>();
            } else {
                // System.out.println(line);
                String[] parts = line.split(" ");
                for (String string : parts) {
                    String key = string.split(":")[0];
                    String value = string.split(":")[1];

                    hs.add(key);
                }
            }
        }

    }

    static void part2(List<String> input) {

    }
}
