package model;

import java.util.Objects;

public class Result {
    private Duck duck;
    private Lane lane;
    private double time;
    public Result(Duck duck, Lane lane, double time) {
        this.duck = duck;
        this.lane = lane;
        this.time = time;
    }
    public Duck getDuck() {
        return duck;
    }
    public Lane getLane() {
        return lane;
    }
    public double getTime() {
        return time;
    }

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Result that = (Result) o;
        return Double.compare(time, that.time) == 0 && Objects.equals(duck, that.duck) && Objects.equals(lane, that.lane);
    }

    @Override
    public int hashCode() {
        return Objects.hash(duck, lane, time);
    }

    @Override
    public String toString() {
        return "Duck " + duck.getIdDuck() + " on lane " + lane.getIdLane() + ": t=" + time + " secunde";
    }

}
