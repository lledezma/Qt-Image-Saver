#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>
#include <QFile>
#include <QMessageBox>
#include <QImage>
#include <QDir>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_clearButton_clicked();

    void on_saveButton_clicked();

private:
    Ui::Dialog *ui;
    QString m_file;
    QString m_filePath;
    void init();
    void save();
};
#endif // DIALOG_H
