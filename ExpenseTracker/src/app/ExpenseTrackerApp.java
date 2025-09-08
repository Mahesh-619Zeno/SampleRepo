package ExpenseTracker.src.app;

import ExpenseTracker.controller.ExpenseController;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.Parent;
import javafx.stage.Stage;
import ExpenseTracker.db.Database;

public class ExpenseTrackerApp extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception {
        Database.initialize(); // Init DB

        Parent root = FXMLLoader.load(getClass().getResource("/view/MainView.fxml"));
        primaryStage.setTitle("Expense Tracker");
        primaryStage.setScene(new Scene(root));
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
