#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QTableView>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QComboBox>

#include <memory>

#include "SudokuModel.h"

class Window : public QWidget
{
    Q_OBJECT
    public:
        explicit Window(QWidget *parent = 0);
        ~Window() = default;

    private:
        std::unique_ptr<QGridLayout> mainLayout;
        std::unique_ptr<QGridLayout> layout;
        std::unique_ptr<QLabel> label;
        std::unique_ptr<QPushButton> buttonSolve;
        std::unique_ptr<QPushButton> buttonQuit;
        std::unique_ptr<SudokuModel> sudokuModel;
        std::unique_ptr<QTableView> tableView;
        std::unique_ptr<QLabel> labelSolver;
        std::unique_ptr<QComboBox> techniquesCombo;

    public slots:
        void solve();
};


#endif// WINDOW_H
