#include "window.h"
#include "isolver.h"
#include "simple.h"
#include "backtracking.h"

#include <QApplication>
#include <QHeaderView>
#include <QStateMachine>
#include <QEventTransition>
#include <QImage>

Window::Window(QWidget *parent):
    QWidget(parent)
{
    setFixedSize(550, 345);

    sudokuPageWidget = std::make_unique<QWidget>();
    startPageWidget = std::make_unique<QWidget>();

    stackedWidget = std::make_unique<QStackedWidget>();
    stackedWidget->addWidget(startPageWidget.get());
    stackedWidget->addWidget(sudokuPageWidget.get());
    stackedWidget->setCurrentWidget(startPageWidget.get());

    mainLayout  = std::make_unique<QGridLayout>();
    mainLayout->addWidget(stackedWidget.get());
    setLayout(mainLayout.get());

    buildStartPageLayout();

    buildSudokuLayout();
}

void Window::buildStartPageLayout()
{
    QImage image(":/assets/sudoku.jpg");
    image = image.scaled(280, 250);

    labelImage = std::make_unique<QLabel>();
    labelImage->setPixmap(QPixmap::fromImage(image));
    labelImage->adjustSize();

    buttonStartInit  = std::make_unique<QPushButton>("Start");
    buttonQuitInit  = std::make_unique<QPushButton>("Quit");

    labelHeaderInit = std::make_unique<QLabel>("# Sudoku!");

    labelHeaderInit->setStyleSheet("font: 18pt; font-weight: bold");
    initPageLayout  = std::make_unique<QGridLayout>(startPageWidget.get());

    initPageLayout->addWidget(labelHeaderInit.get(), 0, 0, 1, 3, Qt::AlignHCenter);
    initPageLayout->addWidget(labelImage.get(), 1, 0, 2, 1);
    initPageLayout->addWidget(buttonStartInit.get(), 1 , 2, 1, 1);
    initPageLayout->addWidget(buttonQuitInit.get(), 2 , 2, 1, 1);

    connect(buttonStartInit.get(), SIGNAL(clicked()), this, SLOT(startSudoku()));
    connect(buttonQuitInit.get(), SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));
}

void Window::buildSudokuLayout()
{
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
    buttonQuit  = std::make_unique<QPushButton>("Quit");

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

    sudokuPageLayout  = std::make_unique<QGridLayout>(sudokuPageWidget.get());
    sudokuPageLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
    sudokuPageLayout->addWidget(label.get(), 0, 0);
    sudokuPageLayout->addWidget(tableView.get(), 1, 0);
    sudokuPageLayout->addLayout(layout.get(), 1, 1);

    connect(buttonSolve.get(), SIGNAL(clicked()), this, SLOT(solve()));
    connect(buttonQuit.get(), SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));
}

void Window::startSudoku()
{
    stackedWidget->setCurrentWidget(sudokuPageWidget.get());
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

