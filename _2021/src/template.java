import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;

public class template {
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

        part1(input);
    }

    static void part1(List<String> input){
        for (String line: input ) {
            System.out.println(line);
        }
    }

    static void part2(List<String> input){

    }
}
