import repoDB.repoDB;
import repository.CardRepo;
import repository.EventRepo;
import repository.UserRepo;
import service.CardService;
import service.EventService;
import service.UserService;
import ui.UI;
import validator.Validator;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class App {
    public static void main(String[] args) {

        repoDB userRepo =new repoDB("jdbc:postgresql://localhost:5432/", "postgres", "parola123");
        CardRepo cardRepo = new CardRepo();
        EventRepo eventRepo = new EventRepo();
        CardService cardService = new CardService(cardRepo);
        EventService eventService = new EventService(eventRepo);
        UserService userService = new UserService(userRepo, new Validator());
        UI ui = new UI(userService, cardService, eventService);
        ui.launch();
    }
}
