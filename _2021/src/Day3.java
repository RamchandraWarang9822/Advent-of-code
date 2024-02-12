import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;

public class Day3 {
        static List<String> input;
        static int result = 0;

        public static void main(String[] args) {
            String filePath = "Day3/input.txt";
            Path path = Paths.get(filePath);

            try {
                input = Files.readAllLines(path);
            } catch (IOException e) {
                e.printStackTrace();
            }

            part1(input);
        }

        static void part1(List<String> input){
            StringBuilder gammaRate = new StringBuilder();
            StringBuilder epsilonRate = new StringBuilder();
            int gammaValue, epsilorValue;

            for(int i = 0; i < input.get(0).length(); i++ ){
                int countOne = 0;
                int countZero = 0;

                for(String line: input){
                    char c = line.charAt(i);
                    if(c == '1'){
                        countOne++;
                    } else{
                        countZero++;
                    }
                }

                gammaRate.append((countZero < countOne) ? "1" : "0");
                epsilonRate.append((countZero < countOne) ? "0" : "1");
            }
            gammaValue = Integer.parseInt(gammaRate.toString(), 2);
            epsilorValue = Integer.parseInt(epsilonRate.toString(), 2);

            System.out.println(gammaValue * epsilorValue);

        }

        static void part2(List<String> input){

        }
}
