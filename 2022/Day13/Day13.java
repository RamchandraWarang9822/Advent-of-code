import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.*;

public class Day13 {
    static List<String> lines;
    static int index;
    static int result = 0;
    static List<Object> mainList = new ArrayList<>();


    public static void main(String[] args) {

        String filePath = "Day13/test.txt";
        Path path = Paths.get(filePath);

        try {
            lines = Files.readAllLines(path);
        } catch (IOException e) {
            e.printStackTrace();
        }

//        part1(lines);
        part2(lines);
    }

    static void part1(List<String> lines) {
        String left, right;
        List<Object> leftList, rightList;
        int indices = 0;

        for (int i = 0; i < lines.size(); i++) {
            indices++;

            left = lines.get(i++);
            right = lines.get(i++);

            index = 0;
            leftList = parseString(left);
            index = 0;
            rightList = parseString(right);

            System.out.print(leftList.get(0) + "  ");
            System.out.println(rightList.get(0));
            Boolean res = compareLeftRight((List<Object>) leftList.get(0), (List<Object>) rightList.get(0));
            if(res == true){
                result += indices;
            }
            System.out.print(res);
        }
        System.out.println("\n" + result);
    }

    static void part2(List<String> lines) {
        String string;
        List<Object> list;

        for (int i = 0; i < lines.size(); i++) {
            string = lines.get(i);
            if(!string.isBlank()){
                list = parseString(string);
                mainList.add(list.get(0));
            }
        }

        System.out.println(mainList);
    }

    static List<Object> parseString(String string){
        List<Object> resultList = new ArrayList<>();
        while(index < string.length()){
            char c = string.charAt(index);

            if(Character.isDigit(c)){
                int num = 0;
                while (index < string.length() && Character.isDigit(string.charAt(index))){
                    num = num * 10 + Character.getNumericValue(string.charAt(index));
                    index++;
                }
                resultList.add(num);
            } else if (c == '['){
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

    static Boolean compareLeftRight(List<Object> leftList, List<Object> rightList){
        for (int i = 0; i < leftList.size(); i++) {
            if (rightList.size() <= i) return Boolean.FALSE;
            if (leftList.get(i) instanceof List || rightList.get(i) instanceof List){
                List innerList1;
                List innerList2;
                if (leftList.get(i) instanceof Integer){
                    innerList1 = wrapList((Integer) leftList.get(i));
                } else {
                    innerList1 = (List)leftList.get(i);
                }
                if ( rightList.get(i) instanceof Integer){
                    innerList2 = wrapList((Integer) rightList.get(i));
                } else {
                    innerList2 = (List)rightList.get(i);
                }
                Boolean res = compareLeftRight(innerList1, innerList2);
                if ( res != null){
                    return res;
                }
            } else {
                if ( (int)leftList.get(i) < (int)rightList.get(i)){
                    return Boolean.TRUE;
                }
                if ( (int)leftList.get(i) > (int)rightList.get(i)){
                    return Boolean.FALSE;
                }
            }
        }
        return leftList.size() != rightList.size() ? Boolean.TRUE : null;
    }

    private static List wrapList(Integer val1) {
        List newList = new ArrayList();
        newList.add(val1);
        return newList;
    }
}
