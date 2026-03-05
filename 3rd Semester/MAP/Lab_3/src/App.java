import repository.CardRepo;
import repository.EventRepo;
import repository.UserRepo;
import service.CardService;
import service.EventService;
import service.UserService;
import ui.UI;
import validator.Validator;

public class App {
    public static void main(String[] args) {
        UserRepo userRepo = new UserRepo("users.txt");
        CardRepo cardRepo = new CardRepo();
        EventRepo eventRepo = new EventRepo();
        CardService cardService = new CardService(cardRepo);
        EventService eventService = new EventService(eventRepo);
        UserService userService = new UserService(userRepo, new Validator());
        UI ui = new UI(userService, cardService, eventService);
        ui.launch();

    }
}
