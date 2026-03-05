import io.FileController;
import model.Duck;
import model.Result;
import model.Lane;
import solver.Type;
import solver.RaceSolver;

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        String inputFile = "natatie.in";
        String outputFile = "natatie.out";

        try {
            //scanner care citeste din fisier
            Scanner scanner = new Scanner(new File(inputFile));
            int N = scanner.nextInt();
            int M = scanner.nextInt();

            Duck[] ducks = FileController.citesteRate(scanner, N);
            Lane[] lanes = FileController.citesteCuloare(scanner, M);

            scanner.close();

            RaceSolver solver = new RaceSolver(Type.BRUTE_FORCE);


            Result[] results=solver.solve(ducks,lanes,N,M);
            // calculam best time
                double bestTime = 99999;
                for (Result r : results) {
                    if (r.getTime() < bestTime)
                        bestTime = r.getTime();
                }


                FileWriter writer = new FileWriter(outputFile);
                writer.write("Best time: " + bestTime + "\n");

                for (Result r : results) {
                    writer.write(r.toString() + "\n");
                }

                writer.close();

        } catch (IOException e) {
            System.out.println("Eroare");
        }
    }
}
