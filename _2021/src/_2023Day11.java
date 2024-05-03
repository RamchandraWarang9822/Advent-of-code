import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.*;

class Coordinates implements Comparable<Coordinates> {
    int i;
    int j;

    public Coordinates() {}

    public Coordinates(int i, int j) {
        this.i = i;
        this.j = j;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Coordinates that = (Coordinates) obj;
        return i == that.i && j == that.j;
    }

    @Override
    public int hashCode() {
        return Objects.hash(i, j);
    }

    @Override
    public int compareTo(Coordinates other) {
        if (this.i == other.i) {
            return Integer.compare(this.j, other.j);
        }
        return Integer.compare(this.i, other.i);
    }
}

public class _2023Day11 {
    static List<String> input;

    public static void main(String[] args) {
        String filePath = "_2023Day11/test.txt";
        Path path = Paths.get(filePath);

        try {
            input = Files.readAllLines(path);
        } catch (IOException e) {
            e.printStackTrace();
        }

        part1(input);
    }

    static void part1(List<String> input) {
        for (String line: input){
            System.out.println(line);
        }
    }
}
