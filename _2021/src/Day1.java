import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.*;

public class Day1 {
    static List<String> input;
    static int result = 0;

    public static void main(String[] args) {
        String filePath = "Day1/input.txt";
        Path path = Paths.get(filePath);

        try {
            input = Files.readAllLines(path);
        } catch (IOException e) {
            e.printStackTrace();
        }

        part2(input);
    }

    static void part1(List<String> input){
        int prevDepth = Integer.parseInt(input.get(0));

        for(int i = 1; i < input.size(); i++ ){
            int currDepth = Integer.parseInt(input.get(i));
            if(currDepth > prevDepth) result++;
            prevDepth = currDepth;
        }

        System.out.println(result);
    }

    static void part2(List<String> input){
        int prevDepth = sumOfThreeDepth(0);

        for(int i = 1; i < input.size() - 2; i++ ){
            int currentDepth = sumOfThreeDepth(i);
            if(currentDepth > prevDepth) result++;
            prevDepth = currentDepth;
        }
        System.out.println(result);
    }

    static int sumOfThreeDepth(int index){
        int sum = 0;
        for(int j = index; j < index + 3; j++){
            sum += Integer.parseInt(input.get(j));
        }
        return sum;
    }

}
