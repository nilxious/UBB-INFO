package io;

import model.Duck;
import model.Lane;

import java.util.Scanner;

public class FileController {

    public static Duck[] citesteRate(Scanner scanner, int n) {
        double[] speeds = new double[n];
        double[] resistances = new double[n];

        // citim viteze
        for (int i = 0; i < n; i++)
            speeds[i] = scanner.nextDouble();

        // citim rezistente
        for (int i = 0; i < n; i++)
            resistances[i] = scanner.nextDouble();

        Duck[] ducks = new Duck[n];
        for (int i = 0; i < n; i++)
            ducks[i] = new Duck(i + 1, resistances[i], speeds[i]);

        return ducks;
    }

    public static Lane[] citesteCuloare(Scanner scanner, int M) {
        Lane[] lanes = new Lane[M];
        for (int i = 0; i < M; i++) {
            double distance = scanner.nextDouble();
            lanes[i] = new Lane(i + 1, distance);
        }
        return lanes;
    }

}
