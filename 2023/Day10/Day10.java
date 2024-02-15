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


public class Day10 {
    static List<String> input;
    static int result = 1;
    static Coordinates S = new Coordinates();
    static Coordinates prevFirst, prevSecond;
    static int row, column;

    public static void main(String[] args) {
        String filePath = "2023Day10/input.txt";
        Path path = Paths.get(filePath);

        try {
            input = Files.readAllLines(path);
        } catch (IOException e) {
            e.printStackTrace();
        }

        part1(input);
    }

    static void part1(List<String> input) {
        row = input.size();
        column = input.get(0).length();

        for (String line : input) {
            System.out.println(line);
        }
        S = findPositionOfS();
//        Coordinates temp = new Coordinates(S.i + 2, S.j + 2);
        List<Coordinates> startList = goFromSTo(S);
//        for(Coordinates coord: startList){
//            System.out.println(coord.i + " " + coord.j);
//        }
        prevFirst = S;
        prevSecond = S;

        while(!startList.get(0).equals(startList.get(1))){
            Coordinates first = startList.get(0);
            Coordinates second = startList.get(1);


            startList.set(0, findNext(prevFirst, first));
            startList.set(1, findNext(prevSecond ,second));
            prevFirst = first;
            prevSecond = second;
            result++;
        }

        System.out.println(result);

    }

    static Coordinates findPositionOfS(){
        Coordinates S = new Coordinates();
        for(int i = 0; i < input.size(); i++ ){
            for(int j = 0; j < input.get(0).length(); j++ ){
                char c = input.get(i).charAt(j);
                if(c == 'S')  {
                    S.i = i;
                    S.j = j;
                }
            }
        }
        return S;
    }

    static List<Coordinates> goFromSTo(Coordinates S){
        List<Coordinates> startList = new ArrayList<>();
        int i = S.i, j = S.j;

        // TOP
        if (valid(i - 1,j)) {
            Coordinates temp = new Coordinates(i - 1, j) ;
            for (Coordinates coords: findNeighbours(temp)) {
                if(coords.equals(S)){
                    startList.add(temp);
                }
            }
        }
        // BOTTOM
        if (valid(i + 1,j)) {
            Coordinates temp = new Coordinates(i + 1, j) ;
            for (Coordinates coords: findNeighbours(temp)) {
                if(coords.equals(S)){
                    startList.add(temp);
                }
            }
        }
        // LEFT
        if (valid(i,j - 1)) {
            Coordinates temp = new Coordinates(i, j - 1) ;
            for (Coordinates coords: findNeighbours(temp)) {
                if(coords.equals(S)){
                    startList.add(temp);
                }
            }
        }
        // RIGHT
        if (valid(i,j + 1)) {
            Coordinates temp = new Coordinates(i, j + 1) ;
            for (Coordinates coords: findNeighbours(temp)) {
                if(coords.equals(S)){
                    startList.add(temp);
                }
            }
        }
        return startList;
    }

    static boolean valid(int i, int j) {
        boolean inBounds = j >= 0 && j < column
                && i >= 0 && i < row;
        return inBounds;
    }

    static Coordinates findNext(Coordinates prev, Coordinates coords){
        Coordinates next = new Coordinates();
        List<Coordinates> neighbours = findNeighbours(coords);
        if(prev.equals(neighbours.get(0))){
            next = neighbours.get(1);
        } else {
            next = neighbours.get(0);
        }
        return next;
    }

    static List<Coordinates> findNeighbours(Coordinates coord){
        List<Coordinates> neighbours = new ArrayList<>();
        int i = coord.i;
        int j = coord.j;

        char c = input.get(coord.i).charAt(coord.j);
        switch (c){
            case '-':
                if (valid( i, j - 1)) neighbours.add(new Coordinates(i, j - 1));
                if (valid( i, j + 1)) neighbours.add(new Coordinates(i, j + 1));
                break;
            case 'L':
                if (valid(i - 1, j)) neighbours.add(new Coordinates(i - 1, j));
                if (valid( i, j + 1)) neighbours.add(new Coordinates(i, j + 1));
                break;
            case '|':
                if (valid(i - 1, j)) neighbours.add(new Coordinates(i - 1, j));
                if (valid( i + 1, j)) neighbours.add(new Coordinates(i + 1, j));
                break;
            case '7':
                if (valid(i, j - 1)) neighbours.add(new Coordinates(i, j - 1));
                if (valid( i + 1, j)) neighbours.add(new Coordinates(i + 1, j));
                break;
            case 'J':
                if (valid(i, j - 1)) neighbours.add(new Coordinates(i, j - 1));
                if (valid( i - 1, j)) neighbours.add(new Coordinates(i - 1, j));
                break;
            case 'F':
                if (valid(i, j + 1)) neighbours.add(new Coordinates(i, j + 1));
                if (valid( i + 1, j)) neighbours.add(new Coordinates(i + 1, j));
                break;
            default:
                System.out.println("Something went wrong at postion :" + i + " " + j);
                break;
        }
        return neighbours;
    }

    static void part2(List<String> input) {

    }
}
