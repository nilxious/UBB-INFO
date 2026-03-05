package model;

import java.util.Objects;

public class Duck {
    private int idDuck;
    private double speed;
    private double resistence;

    public Duck(int idDuck, double speed, double resistence) {
        this.idDuck = idDuck;
        this.speed = speed;
        this.resistence = resistence;
    }

    public int getIdDuck() {
        return idDuck;
    }

    public double getSpeed() {
        return speed;
    }

    public double getResistance() {
        return resistence;
    }

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Duck duck = (Duck) o;
        return idDuck == duck.idDuck && Double.compare(speed, duck.speed) == 0 && Double.compare(resistence, duck.resistence) == 0;
    }

    @Override
    public int hashCode() {
        return Objects.hash(idDuck, speed, resistence);
    }

    @Override
    public String toString() {
        return "ID: " + idDuck + ", Speed: " + speed + ", Resistance: " + resistence;
    }
}
