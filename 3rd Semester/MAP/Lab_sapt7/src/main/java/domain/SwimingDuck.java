package domain;

public class SwimingDuck extends Duck implements Inotator {

    public SwimingDuck(long id, String username, String email, String password,
                       TipRata tipRata, double viteza, double rezistenta) {
        super(id,username,email,password,tipRata,viteza,rezistenta);
    }

    @Override
    public void inoata() {
        System.out.println("Rata cu username:" + getUsername() + " si id :" + getId() + " inoata cu viteaza:" +getViteza());
    }

}
