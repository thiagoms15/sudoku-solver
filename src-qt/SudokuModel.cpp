#include "SudokuModel.h"
//#include <qnamespace.h>

SudokuModel::SudokuModel(QObject *parent) : QAbstractTableModel(parent)
{

}

void SudokuModel::populateData(const SudokuTraits::SudokuMatrix &grid_t)
{
    grid = grid_t;
}

int SudokuModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return SudokuTraits::lines;
}

int SudokuModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return SudokuTraits::columns;
}

QVariant SudokuModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole) {
        return QVariant();
    }
    if(index.column() < SudokuTraits::columns && index.row() < SudokuTraits::lines){
        return (grid[index.row()][index.column()]) ?
            QString("%1").arg(grid[index.row()][index.column()])
            : QString();
    }
    return QVariant();
}

QVariant SudokuModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        return QString("#%1").arg(section+1);
    }
    return QVariant();
}

