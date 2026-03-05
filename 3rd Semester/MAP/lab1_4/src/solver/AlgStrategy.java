package solver;

import model.Duck;
import model.Result;
import model.Lane;

public interface AlgStrategy {
    // Returneaza un array cu rezultatele cursei
    Result[] solve(Duck[] ducks, Lane[] lanes, int n, int m);
}
