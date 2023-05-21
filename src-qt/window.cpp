#include "window.h"
#include "isolver.h"
#include "simple.h"
#include "backtracking.h"

#include <QApplication>
#include <QHeaderView>

Window::Window(QWidget *parent):
    QWidget(parent)
{
    setFixedSize(500, 330);

    sudokuModel  = std::make_unique<SudokuModel>();

    // Populate model with data:
    SudokuHelper::Data data;
    sudokuModel->populateData(data.grid);
    tableView  = std::make_unique<QTableView>();
    // Connect model to table view:
    tableView->setModel(sudokuModel.get());
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView->horizontalHeader()->hide();

    // TODO: create a DB for language strings
    buttonSolve  = std::make_unique<QPushButton>("Solve");
    buttonQuit  = std::make_unique<QPushButton>("quit");

    techniquesCombo = std::make_unique<QComboBox>();
    techniquesCombo->addItem("Simple");
    techniquesCombo->addItem("Backtracking");
    labelSolver = std::make_unique<QLabel>("Solver techniques:");

    layout  = std::make_unique<QGridLayout>();
    layout->addWidget(labelSolver.get(), 0 , 0 );
    layout->addWidget(techniquesCombo.get(), 0 , 1);
    layout->addWidget(buttonSolve.get(), 1, 0);
    layout->addWidget(buttonQuit.get(), 1, 1);

    label  = std::make_unique<QLabel>();
    label->setText("Sudoku Solver");
    // TODO: Use qfont
    label->setStyleSheet("font: 18pt; font-weight: bold");

    mainLayout  = std::make_unique<QGridLayout>(this);
    mainLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
    mainLayout->addWidget(label.get(), 0, 0);
    mainLayout->addWidget(tableView.get(), 1, 0);
    mainLayout->addLayout(layout.get(), 1, 1);

    connect(buttonSolve.get(), SIGNAL(clicked()), this, SLOT(solve()));
    connect(buttonQuit.get(), SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));

}
void Window::solve()
{
    std::unique_ptr<ISolver> solver;
    if(techniquesCombo->currentText() == "Simple"){
        solver = std::make_unique<SimpleSolver>();
    }
    else {
        solver = std::make_unique<BtSolver>();
    }
    solver->solve(sudokuModel->getGrid());
    // TODO: think in a different way to update the screen
    tableView->setFocus();
}

