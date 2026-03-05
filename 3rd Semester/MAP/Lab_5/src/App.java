import repository.UserRepo;
import service.UserService;
import ui.UI;
import validator.Validator;

public class App {
    public static void main(String[] args) {
        UserRepo repo = new UserRepo("users.txt");
        UserService service = new UserService(repo, new Validator());
        UI ui = new UI(service);
        ui.launch();

    }
}
