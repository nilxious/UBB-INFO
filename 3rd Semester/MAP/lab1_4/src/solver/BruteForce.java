    package solver;

    import model.Duck;
    import model.Lane;
    import model.Result;

    public class BruteForce implements AlgStrategy {

        @Override
        public Result[] solve(Duck[] ducks, Lane[] lanes, int n, int m) {

            // sortam ratele descrescator dupa viteza
            // ca sa le asociem cu lanne-uri mai lungi
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < n - 1 - i; j++) {
                    if (ducks[j].getSpeed() < ducks[j + 1].getSpeed()) {
                        Duck temp = ducks[j];
                        ducks[j] = ducks[j + 1];
                        ducks[j + 1] = temp;
                    }
                }
            }

            // sortam culoarele descrescator dupa distanta
            //asociam culoarele mai lungi cu ratele mai rapide, pt. a obtine timpul maxim minim
            for (int i = 0; i < m - 1; i++) {
                for (int j = 0; j < m - 1 - i; j++) {
                    if (lanes[j].getDistance() < lanes[j + 1].getDistance()) {
                        Lane temp = lanes[j];
                        lanes[j] = lanes[j + 1];
                        lanes[j + 1] = temp;
                    }
                }
            }

            Result[] results = new Result[m];

            // calculam rezultatele
            for (int i = 0; i < Math.min(n, m); i++) {
                double time = 2.0 * lanes[i].getDistance() / ducks[i].getSpeed();
                results[i] = new Result(ducks[i], lanes[i], time);
            }

            return results;
        }
    }
