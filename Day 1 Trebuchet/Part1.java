import java.io.*;

public class Part1 {
    public static void main(String arg[]) {
        // Lets import the input text first
        try (BufferedReader reader = new BufferedReader(
                new FileReader("C:/Users/Samuel/Desktop/Advent of Code/1/input.txt"))) {
            String line;
            int total = 0;
            while ((line = reader.readLine()) != null) {
                System.err.println(line);
                char firstDigit = '\0';
                char lastDigit = '\0';
                for (char c : line.toCharArray()) {
                    if (Character.isDigit(c)) {
                        if (firstDigit == '\0') {
                            firstDigit = c;
                        }
                        lastDigit = c;
                    }
                }
                int first = Character.getNumericValue(firstDigit);
                int last = Character.getNumericValue(lastDigit);

                int current = (first * 10) + last;
                total += current;
            }
            System.out.println(total);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}