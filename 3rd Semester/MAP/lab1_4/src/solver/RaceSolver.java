package solver;

import model.Duck;
import model.Result;
import model.Lane;

public class RaceSolver {

    private AlgStrategy strategy;


    public RaceSolver(Type type) {
        switch (type) {
            case BRUTE_FORCE:
                strategy = new BruteForce();
                break;
        }
    }

    public Result[] solve(Duck[] ducks, Lane[] lanes, int n, int m) {
        return strategy.solve(ducks, lanes, n, m);
    }
}
