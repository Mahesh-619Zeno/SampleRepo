package controller;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import model.Expense;
import service.ExpenseService;

import java.time.LocalDate;

public class ExpenseController {

    @FXML private TextField categoryInput;
    @FXML private TextField amountInput;
    @FXML private DatePicker dateInput;
    @FXML private TableView<Expense> expenseTable;
    @FXML private TableColumn<Expense, String> categoryColumn;
    @FXML private TableColumn<Expense, Double> amountColumn;
    @FXML private TableColumn<Expense, String> dateColumn;

    private ObservableList<Expense> expenseList;

    @FXML
    public void initialize() {
        categoryColumn.setCellValueFactory(data -> new javafx.beans.property.SimpleStringProperty(data.getValue().getCategory()));
        amountColumn.setCellValueFactory(data -> new javafx.beans.property.SimpleDoubleProperty(data.getValue().getAmount()).asObject());
        dateColumn.setCellValueFactory(data -> new javafx.beans.property.SimpleStringProperty(data.getValue().getDate()));

        loadExpenses();
    }

    public void loadExpenses() {
        expenseList = FXCollections.observableArrayList(ExpenseService.getAllExpenses());
        expenseTable.setItems(expenseList);
    }

    @FXML
    public void handleAddExpense() {
        String category = categoryInput.getText();
        double amount = Double.parseDouble(amountInput.getText());
        String date = dateInput.getValue().toString();

        ExpenseService.addExpense(category, amount, date);
        loadExpenses();

        categoryInput.clear();
        amountInput.clear();
        dateInput.setValue(LocalDate.now());
    }

    @FXML
    public void handleDeleteExpense() {
        Expense selected = expenseTable.getSelectionModel().getSelectedItem();
        if (selected != null) {
            ExpenseService.deleteExpense(selected.getId());
            loadExpenses();
        }
    }
}
