package model;

import solver.Type;
import solver.RaceSolver;

public class RaceTask extends Task{
    private Duck[] ducks;
    private Lane[] lanes;
    private int n;
    private int m;
    private RaceSolver solver;

    public RaceTask(String taskId, String description, Duck[] ducks, Lane[] lanes, int n, int m, Type type) {
        super(taskId,description);
        this.ducks = ducks;
        this.lanes = lanes;
        this.n = n;
        this.m = m;
        //creez solver
        this.solver = new RaceSolver(type);
    }

    @Override
    public void execute() {
        solver.solve(ducks,lanes,n,m);
    }

    public Duck[] getDucks() {
        return ducks;
    }

    public Lane[] getLanes() {
        return lanes;
    }

    public int getN() {
        return n;
    }

    public int getM() {
        return m;
    }



}

