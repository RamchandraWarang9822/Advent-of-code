import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.Files;
import java.io.IOException;
import java.util.*;

class Coordinates implements Comparable<Coordinates> {
    int i;
    int j;

    public Coordinates() {
    }

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

class Entry{
    Coordinates coords;
    int steps;

    public Entry(){
    }

    public Entry(Coordinates coords, int steps){
        this.coords = coords;
        this.steps = steps;
    }
}

public class Day12 {
    static int rows, columns, steps;
    static Coordinates start = new Coordinates();
    static Coordinates end = new Coordinates();
    static Queue<Entry> queue = new LinkedList<>();
    static HashSet<Coordinates> visited = new HashSet<>();
    static List<String> lines;
    static Entry current;

    public static void main(String[] args) {
        String filePath = "input.txt";
        Path path = Paths.get(filePath);

        try {
            lines = Files.readAllLines(path);

            rows = lines.size();
            columns = lines.get(0).length();
            steps = 0;

            for (String line : lines) {
                System.out.println(line);
            }

            int i = 0;
            for(String line: lines){
                int j = 0;
                for(char c: line.toCharArray()){
                    if (c == 'E'){
                       start.i = i;
                       start.j = j;
                    }

                    if (c == 'S'){
                        end.i = i;
                        end.j = j;
                    }
                    j++;
                }
                i++;
            }

            System.out.println("Start : " + start.i + " " + start.j);
            System.out.println("End : " + end.i + " " + end.j);

            queue.add(new Entry(start, steps));

            int result = 0;


            while (lines.get(queue.peek().coords.i).charAt(queue.peek().coords.j) != 'a') {

                System.out.println(lines.get(queue.peek().coords.i).charAt(queue.peek().coords.j));
                current = queue.poll();
                Coordinates front_coords = current.coords;
                List<Coordinates> neighbours = getNeighbours(front_coords.i, front_coords.j);

                for (Coordinates neighbour : neighbours) {
                    if (isValid(front_coords, neighbour)) {
                        visited.add(neighbour);
                        queue.add(new Entry(neighbour, current.steps + 1));
//                        if (lines.get(neighbour.i).charAt(neighbour.j) == 'a') {
//                            break;
//                        }
                    }
                }
            }

            result = current.steps;


            System.out.println(result);

        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    public static boolean isValid(Coordinates from, Coordinates to) {
        boolean inBounds = to.j >= 0 && to.j < columns
                && to.i >= 0 && to.i < rows;

        if (!inBounds) {
            return false;
        }

        char fromChar = lines.get(from.i).charAt(from.j);
        fromChar = (fromChar == 'E') ? 'z' : fromChar;

        char toChar = lines.get(to.i).charAt(to.j);
        toChar = (toChar == 'S') ? 'a' : toChar;

        return (fromChar - toChar <= 1) && !visited.contains(to);
    }

    public static List<Coordinates> getNeighbours(int i, int j){
        List<Coordinates> neighbours = new ArrayList<>();
        neighbours.add(new Coordinates(i -1,j));
        neighbours.add(new Coordinates(i+1,j));
        neighbours.add(new Coordinates(i,j-1));
        neighbours.add(new Coordinates(i,j+1));
        return neighbours;
    }
}
