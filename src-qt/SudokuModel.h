#ifndef SUDOKU_MODEL_H
#define SUDOKU_MODEL_H

#include <QAbstractTableModel>
#include "sudoku_traits.h"

class SudokuModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    SudokuModel(QObject *parent = 0);

    void populateData(const SudokuTraits::SudokuMatrix& grid_t);

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    SudokuTraits::SudokuMatrix& getGrid() { return grid; };

private:
    SudokuTraits::SudokuMatrix grid;

};

#endif // SUDOKU_MODEL_H
