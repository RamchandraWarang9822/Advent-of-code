import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;

public class Day2 {
    static List<String> input;
    static int result = 0;

    public static void main(String[] args) {
        String filePath = "Day2/input.txt";
        Path path = Paths.get(filePath);

        try {
            input = Files.readAllLines(path);
        } catch (IOException e) {
            e.printStackTrace();
        }

        part2(input);
    }

    static void part1(List<String> input){
        int horizontal = 0, depth = 0;

        for(String line: input){
            String[] position = line.split(" ");
            String direction = position[0];
            int value = Integer.parseInt(position[1]);

            switch (direction){
                case "forward":
                    horizontal += value;
                    break;
                case "down":
                    depth -= value;
                    break;
                case "up":
                    depth += value;
                    break;
                default:
                    System.out.println("Something is wrong");
            }
        }
        System.out.println(Math.abs(horizontal * depth));
    }

    static void part2(List<String> input){
        int horizontal = 0, depth = 0, aim = 0;

        for(String line: input){
            String[] position = line.split(" ");
            String direction = position[0];
            int value = Integer.parseInt(position[1]);

            switch (direction){
                case "forward":
                    horizontal += value;
                    depth += (aim * value);
                    break;
                case "down":
                    aim += value;
                    break;
                case "up":
                    aim -= value;
                    break;
                default:
                    System.out.println("Something is wrong");
            }
        }
        System.out.println(Math.abs(horizontal * depth));
    }
}
