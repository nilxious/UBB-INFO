package domain;

import java.util.Objects;

public class Duck extends User{
    TipRata tipRata;
    private double viteza;
    private double rezistenta;

    public Duck(long id, String username, String email, String password,
                TipRata tipRata, double viteza, double rezistenta) {
        super(id, username, email, password);
        this.tipRata = tipRata;
        this.viteza = viteza;
        this.rezistenta = rezistenta;
    }

    public TipRata getTipRata() {
        return tipRata;
    }

    public void setTipRata(TipRata tipRata) {
        this.tipRata = tipRata;
    }

    public double getViteza() {
        return viteza;
    }

    public void setViteza(double viteza) {
        this.viteza = viteza;
    }

    public double getRezistenta() {
        return rezistenta;
    }

    public void setRezistenta(double rezistenta) {
        this.rezistenta = rezistenta;
    }

    @Override
    public String toString() {
        return String.format(
                "%s — Type: %s, Speed: %.1f, Stamina: %.1f",
                super.toString(),
                tipRata,
                viteza,
                rezistenta
        );
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        if (!super.equals(o)) return false;
        Duck duck = (Duck) o;
        return Double.compare(viteza, duck.viteza) == 0 && Double.compare(rezistenta, duck.rezistenta) == 0 && tipRata == duck.tipRata;
    }

    @Override
    public int hashCode() {
        return Objects.hash(super.hashCode(), tipRata, viteza, rezistenta);
    }
}
