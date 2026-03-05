package validator;
import exceptions.ExceptieValidare;
import domain.User;
import java.util.ArrayList;
import java.util.List;

public class Validator implements ValidatorInterface<User> {
    @Override
    public void validare(User user) throws ExceptieValidare {
        List<String> erori = new ArrayList<>();

        if (user.getId() < 0) {
            erori.add("Id invalid (Id >= 0)");
        }

        if (user.getUsername() == null || user.getUsername().isEmpty()) {
            erori.add("Username invalid");
        }

        if (user.getEmail() == null || !user.getEmail().contains("@")) {
            erori.add("Email invalid");
        }

        if (user.getPassword() == null || user.getPassword().length() < 3) {
            erori.add("Password invalid (password >= 3 caractere)");
        }

        if (!erori.isEmpty()) {
            String mesaj = "";
            for (String e : erori) {
                if (!mesaj.isEmpty()) mesaj += "\n";
                mesaj += e;
            }
            throw new ExceptieValidare(mesaj);
        }

    }
}
