package Day13;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.*;

public class Day13 {
    static List<String> lines;
    static int index;

    public static void main(String[] args) throws Exception {

        String filePath = "Day13/test.txt";
        Path path = Paths.get(filePath);

        try {
            lines = Files.readAllLines(path);
        } catch (IOException e) {
            e.printStackTrace();
        }

        part1(lines);
    }

    static void part1(List<String> lines) {
        String left, right;
        List<Object> leftList, rightList;
        int indices = 0;

        for (int i = 0; i < lines.size(); i++) {
//            boolean flag = false;
            indices++;

            left = lines.get(i++);
            right = lines.get(i++);
            index = 0;
            leftList = parseString(left);
            index = 0;
            rightList = parseString(right);

            boolean flag = compareLeftRight((List<Object>) leftList.get(0), (List<Object>) rightList.get(0));
            System.out.println(flag);
        }
    }

    static List<Object> parseString(String string){
        List<Object> resultList = new ArrayList<>();
        while(index < string.length()){
            char c = string.charAt(index);

            if(Character.isDigit(c)){
                int num = 0;
                while(index < string.length() && Character.isDigit(string.charAt(index))){
                    num = num * 10 + Character.getNumericValue(string.charAt(index));
                    index++;
                }
                resultList.add(num);
            } else if(c == '['){
                index++;
                List<Object> nestedList = parseString(string);
                resultList.add(nestedList);
            } else if (c == ','){
                index++;
            } else if (c == ']'){
                index++;
                return resultList;
            } else {
                index++;
            }
        }
        return resultList;
    }

    static boolean compareLeftRight(List<Object> leftList, List<Object> rightList){
        int pointer = 0;
        while(pointer < leftList.size()){
            Object element1 = leftList.get(pointer);
            Object element2 = rightList.get(pointer);

            if(element1 instanceof Integer && element2 instanceof Integer){
                if((int) element1 < (int) element2){
                    return false;
                } else if ((int) element1 == (int) element2){
                    pointer ++;
                    continue;
                }
            } else if ( element1 instanceof List<?> && element2 instanceof List<?>){
                if(((List<?>) element1).size() > ((List<?>) element2).size()){
                    return false;
                }
                if (!compareLeftRight((List<Object>) element1, (List<Object>) element2)) {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }
}
