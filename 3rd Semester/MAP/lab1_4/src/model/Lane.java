package model;

import java.util.Objects;

public class Lane {
    private int idLane;
    private double distance;

    public Lane(int idLane, double distance) {
        this.idLane = idLane;
        this.distance = distance;
    }

    public int getIdLane() {
        return idLane;
    }
    public double getDistance() {
        return distance;
    }

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Lane lane = (Lane) o;
        return idLane == lane.idLane && Double.compare(distance, lane.distance) == 0;
    }

    @Override
    public int hashCode() {
        return Objects.hash(idLane, distance);
    }

    public String toString() {
        return "ID: " + idLane + ", Distance: " + distance ;
    }
}
